using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /******************************************************************************************
     * SimEventFactory's responsibilities include: 
     * 
     * 1. Creating and returning a new SimEvent object.
     * 2. Determining if a service desk is full before creating a CompleteServiceDesk SimEvent.
     *****************************************************************************************/
    class SimEventFactory
    {
        //Total seconds to a minute.
        private const int TO_SECONDS = 60;

        //The Simulation that hosts instantiations of this class.
        private Simulation sim;

        //The time modifier used to determine when a new entity arrives at the call center.
        private double arrivalTimeMod;

        /*************
         * Constructor
         ************/
        public SimEventFactory(Simulation sim, double arrivalTimeMod)
        {
            this.sim = sim;
            this.arrivalTimeMod = arrivalTimeMod;
        }//End Constructor.

        /***********************************************************
         * Takes an event code and an entity and returns a SimEvent.
         **********************************************************/
        public SimEvent CreateEvent(int eventCode, Entity e)
        {
            SimEvent newEvent = null;
            
            //Determine the type of event to return based on the given event code.
            switch(eventCode)
            {
                //ArriveAtCallCenter event.
                case EventCode.ArriveAtCallCenter:
                    newEvent = CreateArriveAtCallCenter(e);
                    break;

                //CompleteIVRServiceEvent.
                case EventCode.CompleteIVRService:
                    newEvent = CreateCompleteIVRService(e);
                    break;

                //EndWaitInQueue and CompleteServiceDesk event.  To determine the return event,
                //this factory has to check if their is room in the service desk for the entity.
                case EventCode.EndWaitInQueue:
                case EventCode.CompleteServiceDesk:
                    newEvent = CheckDesk(e);
                    break;                      
            }
            return newEvent;
        }//End CreateEvent.

        /**************************************************************************************
         * Checks to see if the service desk that supports the entitie's product type has space
         * available to service the entity.  If it does it returns a CompleteServiceDesk event,
         * otherwise it returns a EndQueueWait event.
         *************************************************************************************/
        private SimEvent CheckDesk(Entity e)
        {
            SimEvent newEvent;

            //Find the target service desk.
            ServiceDesk target = sim.serviceDeskList.Find(sd => sd.ProductType == e.ProductType);

            //Check if its busy.
            if (target.IsResourceBusy())
                //If it is, place entity in wait queue.
                newEvent = CreateEndQueueWait(e);
            else
                //If it isn't, place entity on service desk.
                newEvent = CreateCompleteServiceDesk(e);

            return newEvent;
        }//End CheckDesk.

        /*************************************************
         * Creates and returns a CompleteIVRService event.
         ************************************************/
        private SimEvent CreateCompleteIVRService(Entity e)
        {
            //Find the queue that hosts entities with the entitie's product type.
            Queue queue = sim.QueueList.Find(q => q.ProductType.CompareTo(e.ProductType) == 0);

            //Calculate the amount of time until this event is completed.
            int eventTimeSeconds = sim.Ivr.GetDelayTime();
            
            //Create a new event time.
            DateTime eventTime = new DateTime(sim.Calendar.SimClock.Year, sim.Calendar.SimClock.Month, sim.Calendar.SimClock.Day,
                sim.Calendar.SimClock.Hour, sim.Calendar.SimClock.Minute, sim.Calendar.SimClock.Second);
            eventTime = eventTime.AddSeconds(eventTimeSeconds);

            //Create a new CompleteIVRService event and return it.
            SimEvent newEvent = new CompleteIVRService(e, eventTime, sim.Stats, queue, sim.Calendar, sim.Ivr);
            
            return newEvent;
        }//End CreateCompleteIVRService.

        /**************************************************
         * Creates and returns an ArriveAtCallCenter event.
         *************************************************/
        private SimEvent CreateArriveAtCallCenter(Entity e)
        {
            //Calculate the amount of time until this event is completed.
            int eventTimeSeconds = (int)(sim.Dice.RollDice() * arrivalTimeMod * TO_SECONDS);
            
            //Create a new event time.
            DateTime eventTime = new DateTime(sim.Calendar.SimClock.Year, sim.Calendar.SimClock.Month, sim.Calendar.SimClock.Day,
                sim.Calendar.SimClock.Hour, sim.Calendar.SimClock.Minute, sim.Calendar.SimClock.Second);
            eventTime = eventTime.AddSeconds(eventTimeSeconds);

            //Create a new ArriveAtCallCenter event and return it.
            SimEvent newEvent = new ArriveAtCallCenter(e, eventTime, sim.Stats, sim.Calendar, sim.QueueList, sim.MaxOnHold, sim.Ivr);

            return newEvent;
        }//End CreateArriveAtCallCenter.

        /********************************************
         * Creates and returns an EndQueueWait event.
         *******************************************/
        private SimEvent CreateEndQueueWait(Entity e)
        {
            //Find the queue that hosts entities with the entitie's product type.
            Queue queue = sim.QueueList.Find(q => q.ProductType.CompareTo(e.ProductType) == 0);
            
            //Create and return a new EndQueueWait event.
            SimEvent newEvent = new EndQueueWait(e, sim.Stats, queue, sim.Calendar);
            
            return newEvent;
        }//End CreateEndQueueWait.

        /**************************************************
         * Creates and returns a CompleteServiceDesk event. 
         *************************************************/
        private SimEvent CreateCompleteServiceDesk(Entity e)
        {
            //Find the target service desk.
            ServiceDesk desk = sim.serviceDeskList.Find(sd => sd.ProductType == e.ProductType);

            //Calculate the amount of time until this event is complete.
            int eventTimeSeconds = desk.GetDelayTime();

            //Create a new event time.
            DateTime eventTime = new DateTime(sim.Calendar.SimClock.Year, sim.Calendar.SimClock.Month, sim.Calendar.SimClock.Day,
                sim.Calendar.SimClock.Hour, sim.Calendar.SimClock.Minute, sim.Calendar.SimClock.Second);
            eventTime = eventTime.AddSeconds(eventTimeSeconds);


            //The time the service rep will be working with this client.
            int serviceRepWorkTime;

            //Check that the event time happens within the bounds of the simulation time.
            if(eventTime <= sim.simEndTime)
                //If it does, the service rep work time will be equal to the event time seconds.
                serviceRepWorkTime = eventTimeSeconds;               
            else
            {
                //If it isn't, the service rep work time equals the difference between the end time and now.                
                //This is done to prevent errors calculating representative utiliziation.
                TimeSpan span = (TimeSpan)(sim.simEndTime - sim.Calendar.SimClock);
                serviceRepWorkTime = span.Seconds;
            }

            //Create and return a new CompleteServiceDesk event.
            SimEvent newEvent = new CompleteServiceDesk(e, eventTime, sim.Stats, sim.Calendar, desk, serviceRepWorkTime);

            return newEvent;
        }//End CreateCompleteServiceDesk.
    }
}
