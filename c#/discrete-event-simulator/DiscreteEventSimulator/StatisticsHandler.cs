using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;

namespace DiscreteEventSimulator
{
    /********************************************************
     * StatisticsHandlers responsibilities include:
     * 
     * 1.Calculating statistics relating to a simulation run.      
     *******************************************************/    
    class StatisticsHandler
    {
        //Total seconds in a minute.
        private const int TO_SECONDS = 60;
        //Simulation run time.
        private int observeTime;

        //Excessive queue wait time.
        private int excessiveWaitTime;

        //Total calls made in the simulation.
        private int totalCalls;

        //Total busy signal counts triggered in the simulation.
        private int busySignalCount;

        //Product types that the service desks in the simulation support.
        private string[] productTypes;

        //Total service desk completions for each product.
        private Dictionary<string, int> completionCount;

        //Total excessive queue wait count for each product type.
        private Dictionary<string, int> excessiveWaitCount;

        //Service desk representative utilization for each product type.
        private Dictionary<string, double> repUtilization;

        //Samples of number of entities waiting in queues for each product type.
        //Taken when an entity completes ivr service. Used to calculate the average
        //number waiting in queue for each product type.
        private Dictionary<string, List<double>> numberWaitingSamples;  
        
        //Average number waiting in each queue.
        private Dictionary<string, double> averageNumberWaiting;

        //Samples of entities waiting time.  Taken when an entity leaves a wait queue.  
        //Used to calculate the average waiting time.
        private List<double> waitTimeSample; 
        
        //Average queue waiting time.                      
        private double averageWaitTime;                                 

        //Samples of entities time spent in simulation.  Taken when an entities completes
        //service at a service desk.  Used to calculate the average system time.
        private List<double> systemTimeSample;                             
   
        //Average time spent by an entity in the simulation.
        private double averageSystemTime; 

        //DisplayHandler is used by observers to perform actions when this class fires an event.
        public delegate void DisplayHandler(object sender, EventArgs e);

        //StatisticsDisplay is an observable event to fire observers' events.
        public event DisplayHandler StatisticsDisplay;
        
        /*************
         * Constructor
         ************/
        public StatisticsHandler(int excessiveWaitTime, string[] productTypes)
        {
            this.excessiveWaitTime = excessiveWaitTime;
            this.totalCalls = 0;
            this.busySignalCount = 0;
            this.observeTime = 0;
            this.productTypes = productTypes;
            this.averageWaitTime = 0;
            this.averageSystemTime = 0;            

            //Initialize Lists and Dictionaries used by this class.
            InitListsAndDictionaries();
        }//End Constructor.

        /**********************
         * Getters and setters.
         *********************/

        //Observe time
        public int ObserveTime
        {
            set { observeTime = value; }
            get { return observeTime; }
        }

        //Excess wait time
        public int ExcessiveWaitTime
        {
            get { return excessiveWaitTime; }
        }

        //Busy signal count 
        public int BusySignalCount
        {
            get { return busySignalCount; }
        }

        //Product types
        public string[] ProductTypes
        {
            get { return productTypes; }
        }

        //Completion count
        public Dictionary<string, int> CompletionCount
        {
            get { return completionCount; }
        }

        //Excessive wait count
        public Dictionary<string, int> ExcessiveWaitCount
        {
            get { return excessiveWaitCount; }
        }

        //Representative utilization
        public Dictionary<string, double> RepUtilization
        {
            get { return repUtilization; }
        }

        //Average number waiting
        public Dictionary<string, double> AverageNumberWaiting
        {
            get { return averageNumberWaiting; }
        }
        //Average waiting time
        public double AverageWaitTime
        {
            get { return (double.IsNaN(averageWaitTime)) ? 0 : averageWaitTime; }
        }
            
        //Average system time
        public double AverageSystemTime
        {
            get { return (double.IsNaN(averageSystemTime)) ? 0 : averageSystemTime; }
        }

        public int TotalCalls
        {
            set { totalCalls = value; }
            get { return totalCalls; }
        }
        //End getters and setters.
        
        /***************************************************
         * Calculates the average wait time of all entities.
         **************************************************/
        private void CalculateAverageWaitTime()
        {
            //totalTimeWaiting is used to store the total of all wait
            //times in the waitTimeSample List.
            double totalTimeWaiting = 0;

            //Iterate through waitTimeSample, adding the values to totalTimeWaiting.
            foreach (double i in waitTimeSample)
                totalTimeWaiting += i;

            //Set averageWaitTime equal to totalTimeWaiting divided by the number of wait time samples.
            try
            {
                averageWaitTime = totalTimeWaiting / waitTimeSample.Count();
            }
            catch (DivideByZeroException e) { }
        }//End CalculateAverageWaitTime.

        /**********************************************************************
         * Calculates the average time spent in the simulation by all entities.
         *********************************************************************/
        private void CalculateAverageSystemTime()
        {
            //totalSystemTime is used to store the total of all system times
            //in the systemTimeSample List.
            double totalSystemTime = 0;

            //Iterate through systemTimeSample, adding the values to totalSystemTime.
            foreach (double i in systemTimeSample)
                totalSystemTime += i;

            //Set averageSystemTime equal to totalSystemTime divided by the number of system time samples.
            try
            {
                averageSystemTime = totalSystemTime / systemTimeSample.Count();
            }
            catch (DivideByZeroException e) { }
        }//End CalculateAverageSystemTime.

        /**********************************************************************************
         * Calculate the average number of entities waiting in queue for the given product.
         *********************************************************************************/        
        private void CalculateAverageNumberWaiting(string product)
        {
            //totalNumberWaiting is used to store the total of all values in 
            //numberWaitingSamples for the given product.
            double totalNumberWaiting = 0;

            //Iterate through numberWaitingSamples for the given product,
            //adding the values to totalNumberWaiting.
            foreach (double i in numberWaitingSamples[product])
                totalNumberWaiting += i;

            //Set averageNumberWaiting for the given product equal to totalNumberWaiting
            //divided by the length of numberWaitingSamples.
            try
            {
                averageNumberWaiting[product] = totalNumberWaiting / numberWaitingSamples[product].Count();
            }
            catch (DivideByZeroException e) 
            { }
        }//End CalculateAverageNumberWaiting.

        /************************************************************
         * Initializes all lists and dictionaries used in this class.
         ***********************************************************/
        private void InitListsAndDictionaries()
        {
            //Initialize dictionaries.
            completionCount = new Dictionary<string, int>();
            excessiveWaitCount = new Dictionary<string, int>();
            repUtilization = new Dictionary<string, double>();
            numberWaitingSamples = new Dictionary<string, List<double>>();
            averageNumberWaiting = new Dictionary<string, double>();

            //Initialize lists.
            waitTimeSample = new List<double>();
            systemTimeSample = new List<double>();

            //Iterate through each product type.
            foreach (string s in productTypes)
            {
                //Set completionCount to 0.
                completionCount.Add(s, 0);

                //Set excessiveWaitCount to 0.
                excessiveWaitCount.Add(s, 0);
                
                //Set repUtilization to 0.
                repUtilization.Add(s, 0);

                //Create a new list for the current product type in numberWaitingSamples.
                numberWaitingSamples.Add(s, new List<double>());
                
                //set averageNumberWait to 0.
                averageNumberWaiting.Add(s, 0);
            }
        }//End InitListsAndDictionaries.        

        /***********************************
         * Increments the busy signal count.
         **********************************/
        public void IncrementBusySignalCount()
        {
            busySignalCount++;
        }//End IncrementBusySignalCount.

        /************************************************************
         * Increments the excessive wait count for the given product.
         ***********************************************************/
        public void IncrementExcessiveWaitCount(string product)
        {
            excessiveWaitCount[product]++;
        }//End IncrementExcessiveWaitCount.

        /********************************************************
         * Increments the completion count for the given product.
         *******************************************************/
        public void IncrementCompletionCount(string product)
        {
            completionCount[product]++;
        }//End IncrementCompletionCount.

        /*************************************************************************************
         * Adds a sample of the number of entites waiting in queue for the given product type.
         ************************************************************************************/
        public void TakeNumberWaitingSample(string product, int numWaiting)
        {
            numberWaitingSamples[product].Add(numWaiting);
        }//End TakeNumberWaitingSample.

        /************************************************************
         * Takes a sample of an entities time spent waiting in queue.
         ***********************************************************/
        public void TakeWaitTimeSample(int waitTime)
        {
            waitTimeSample.Add(waitTime);
        }//End TakeWaitTimeSample.

        /*************************************************************
         * Takes a sample of an entities time spent in the simulation.
         ************************************************************/
        public void TakeSystemTimeSample(int sysTime)
        {
            systemTimeSample.Add(sysTime);
        }//end TakeSystemTimeSample.

        /************************************************************************
         * Performs statistics calculations at the end of a simulation run.
         * Takes a list of service desks to calculate representative utilization.
         ***********************************************************************/
        public void PerformSimEndCalculations(List<ServiceDesk> serviceDesks)
        {
            //Calculate representative utilization.
            foreach (ServiceDesk sd in serviceDesks)
                CalculateRepUtiliziation(sd);

            //Calculate average number waiting.
            foreach (string s in productTypes)
                CalculateAverageNumberWaiting(s);

            //Caculate average wait time.
            CalculateAverageWaitTime();

            //Calculate average system time.
            CalculateAverageSystemTime();

            //Fire event.
            OnStatisticsDisplay();
        }//End PerformSimEndCalculations.

        /*******************************************************************
         * Calculates representative utilization for the given service desk.
         ******************************************************************/
        private void CalculateRepUtiliziation(ServiceDesk serviceDesk)
        {            
            //Get the sum of total workable seconds.
            double totalTime = observeTime * serviceDesk.ServiceReps.Count() * TO_SECONDS;

            //workTime is the total seconds worked for all service reps combined.
            double workTime = 0;

            //Get the total seconds worked for each service rep and put in workTime.
            foreach (ServiceRep rep in serviceDesk.ServiceReps)
                workTime += rep.WorkTime;

            //Calculate the representative utilization and store in the dictionary.
            try
            {
                double utilization = workTime / totalTime;
                repUtilization[serviceDesk.ProductType] = utilization;
            }
            catch (DivideByZeroException e)
            {
              //  repUtilization[serviceDesk.ProductType] = 0;
            }
        }//End CalculateRepUtilization.

        /*********************************************************************
         * Fires an event to let observers know that the simulation has ended.
         * Called from PerformSimEndCalculations.
         ********************************************************************/
        public void OnStatisticsDisplay()
        {
            //Check for any observers...
            if (StatisticsDisplay != null)
                //and fire event if they exist.
                StatisticsDisplay(this, null);
        }//End OnStatisticsDisplay.        
    }
}
