using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace DiscreteEventSimulator
{
    /******************************************************************************************************
     * Simulations responsibilities include:
     * 
     * 1. Initializing and storing all the objects and variables needed to run a discrete event simulation.
     * 2. Executing simulation events within the given simulation time.
     *****************************************************************************************************/
    class Simulation
    {
        //Values used to set the initial sim clock and end time.
        private const int CONTROL_YEAR = 9999;
        private const int CONTROL_MONTH = 1;
        private const int CONTROL_DAY = 1;

        //Max number that can wait in queue.
        private int maxOnHold;

        //Master dice.
        private Dice dice;

        //Simulation start time. 
        public DateTime simStartTime;

        //Time the simulation ends.  
        public DateTime simEndTime;

        //Pause time between each simulation event.
        private int threadSleepTime;

        //List of all entities in the system.
        public List<Entity> entityList;

        //List of all queues in the simulation.
        public List<Queue> queueList;

        //List of all service desks in the simulation
        public List<ServiceDesk> serviceDeskList;

        //Main statistic handler for the simultion.
        public StatisticsHandler stats;

        //Main calendar for the simulation.
        private Calendar calendar;

        //Main IVR unit for the simulation.
        public IVRUnit ivr;

        //Main sim event factory for the simulation.
        private SimEventFactory eventFactory;

        //Main entity factory for the simulation.
        private EntityFactory entityFactory;
        
        /*************
         * Constructor
         ************/
        public Simulation(int simTime, int maxOnHold, int eventSleepLength, int serviceRepsCarAudio, int serviceRepsOther,
                          double timeModCarStereoService, double timeModOtherService, double timeModCallArrival, double timeModIvr,
                          Random r, int percentCarStereoCalls, int excessiveWaitMinutes, string[] productTypes)
        {           
            
            this.maxOnHold = maxOnHold;
            this.threadSleepTime = eventSleepLength;
            this.simStartTime = new DateTime(CONTROL_YEAR, CONTROL_MONTH, CONTROL_DAY, 0, 0, 0);     
            this.simEndTime = new DateTime(CONTROL_YEAR, CONTROL_MONTH, CONTROL_DAY, 0, 0, 0);
            this.simEndTime = simEndTime.AddMinutes(simTime);
            this.dice = new Dice(r);
            this.entityList = new List<Entity>();
            this.stats = new StatisticsHandler(excessiveWaitMinutes, productTypes);
            this.calendar = new Calendar(simStartTime);
            this.ivr = new IVRUnit(timeModIvr, dice);

            //Initialize the factories used in this simulation.
            InitFactories(timeModCallArrival, percentCarStereoCalls, r, productTypes);            

            //Initialize the service desks and queues used in this simulation.
            InitServiceDesksAndQueues(serviceRepsCarAudio, serviceRepsOther, timeModCarStereoService, timeModOtherService);
        }//End constructor.
                
        /*********************
         * Getters and setters
         ********************/
        
        //maxOnHold
        public int MaxOnHold
        {
            get { return maxOnHold; }
        }

        //dice
        public Dice Dice
        {
            get { return dice; }
        }

        //calendar
        public Calendar Calendar
        {
            get { return calendar; }
        }

        //stats
        public StatisticsHandler Stats
        {
            get { return stats; }
        }

        //queueList
        public List<Queue> QueueList
        {
            get { return queueList; }
        }

        //ivr
        public IVRUnit Ivr
        {
            get { return ivr; }
        }
        //End getters and setters.

        /*********************************************************************
         * Initializes the event and entity factories used in this simulation.
         ********************************************************************/
        private void InitFactories(double timeModCallArrival, int percentCarStereoCalls, Random r, string[] productTypes)
        {
            eventFactory = new SimEventFactory(this, timeModCallArrival);
            entityFactory = new EntityFactory(r, productTypes, percentCarStereoCalls);
        }//End InitFactories.

        /*************************************************************************************************
         * Initializes the service desks and queues used in this simulation, and adds them to their lists.
         ************************************************************************************************/
        private void InitServiceDesksAndQueues(int serviceRepsCarAudio, int serviceRepsOther, double timeModCarStereoService, double timeModOtherService)
        {
            //Initialize the service desk and queue lists.
            this.serviceDeskList = new List<ServiceDesk>();
            this.queueList = new List<Queue>();

            //Initialize the service desks.
            ServiceDesk carStereoDesk = new ServiceDesk(ProductData.CAR_STEREO_PRODUCT, serviceRepsCarAudio, timeModCarStereoService, dice);
            ServiceDesk otherDesk = new ServiceDesk(ProductData.OTHER_PRODUCT, serviceRepsOther, timeModOtherService, dice);

            //Initialize the queues.
            Queue carStereoQueue = new Queue(carStereoDesk, ProductData.CAR_STEREO_PRODUCT);
            Queue otherQueue = new Queue(otherDesk, ProductData.OTHER_PRODUCT);

            //Add the servce desks to the service desk list.
            serviceDeskList.Add(carStereoDesk);
            serviceDeskList.Add(otherDesk);

            //Add the queues to the queue list.
            queueList.Add(carStereoQueue);
            queueList.Add(otherQueue);
        }//End InitServiceDesksandQueues.

        /************************************************************************************************************
         * Runs the discrete event simulator.  Responible for adding events to the calendar and executing the current
         * event until the simulation clock reaches the end time.
         ************************************************************************************************************/
        public void RunSimulation()
        {
            //Add the first entity/event to the simulation.
            AddEntity();

            //Run the simulation...
            while (calendar.SimClock.TimeOfDay <= simEndTime.TimeOfDay)
            {
                //Set the simulation time to that of the next event.
                calendar.UpdateClock();
                
                //Retrieve the next event to be executed from the calendar.
                SimEvent curEvent = calendar.FetchEvent();

                //Check if the current event falls within the simulation time 
                //(prevents a bug that lets events run after the simEndTime).
                if (curEvent.EventTime <= simEndTime)
                {

                    //Execute the event and set result equal to the return code.
                    int? result = curEvent.ExecuteEvent();

                    //If the result is not null...
                    if (result != null)
                    {
                        //Create an event code equal to the event result.
                        int eventCode = Convert.ToInt16(result);

                        //Create a new event using the entity from the current event and the returned event code.
                        SimEvent newEvent = eventFactory.CreateEvent(eventCode, curEvent.EventEntity);

                        //Add the new event to the calendar.
                        calendar.AddEvent(newEvent);
                    }
                    else
                        //If the result is null, remove the entity from the master entity list.
                        entityList.Remove(curEvent.EventEntity);

                    //If the executed event was an arrive at call center event...
                    if (curEvent is ArriveAtCallCenter)
                        //Add a new entity/event to the simulation.
                        AddEntity();
                    
                    //Pause.
                    Thread.Sleep(threadSleepTime);
                }                
            }
            //Update the statistics handler observe time.
            TimeSpan span = simEndTime - simStartTime;
            stats.ObserveTime = (int)span.TotalMinutes;

            //Perform the calculations required at the end of a simulation.
            stats.PerformSimEndCalculations(serviceDeskList);            
        }//End RunSimulation.

        /***********************************************************************************************
         * Creates a new entity, puts it in an arrive at call center event, and adds it to the calendar.
         **********************************************************************************************/
        private void AddEntity()
        {
            //Create a new entity.
            Entity newEntity = entityFactory.MakeEntity();

            //Use the new entity to create an arrive at call center event.
            SimEvent newEvent = eventFactory.CreateEvent(EventCode.ArriveAtCallCenter, newEntity);

            //Add the event to the calendar.
            calendar.AddEvent(newEvent);

            //Add the entity to the master entity list.
            entityList.Add(newEntity);
        }//End AddEntity.
    }
}
