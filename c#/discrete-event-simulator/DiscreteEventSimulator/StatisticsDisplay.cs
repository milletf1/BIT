﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DiscreteEventSimulator
{
    /************************************************************************
     * StatisticsDisplay is responsible for:
     * 
     * 1. Displaying the statistics generated by the StatisticsHandler class
     *    in a rich text box.
     ***********************************************************************/
    class StatisticsDisplay
    {
        //String constants used to label the displayed statistics.
        private const string NEWLINE = "\n";
        private const string COLON = ":";
        private const string TOTAL = "Total:";
        private const string AVERAGE = "Average:";
        private const string DOUBLE_FORMAT = "{0:0.000}";
        private const string OBSERVE = "Observation time:";
        private const string TOTAL_CALLS = "Total calls:";
        private const string HANGUPS = "Hangups:";
        private const string EXCESSIVE_WAIT = "Excessive Wait Time";
        private const string COMPLETION_COUNT = "Completed Calls";
        private const string REP_UTILIZATION = "Representative Utilization";
        private const string AVERAGE_WAIT = "Average wait time (minutes):";
        private const string AVERAGE_SYSTEM = "Average system time (minutes):";
        private const string AVERAGE_CUSTOMERS_WAITING = "Customers waiting average";

        //Char used to section off a statistic title
        private const char TITLE_SPACER = '-';
        
        //Padding value used to provide space between a statistic key and its value.
        private const int DISPLAY_PADDING = 90;
        
        //Padding value used to determine how many - chars to display after a statistic title.
        private const int TITLE_PADDING = 95;

        //Delegate used to access a StatisticsHandler object that's running on another thread.
        private delegate void DisplayDelegate();

        //Displays statistics.
        private RichTextBox displayOutput;
        
        //The StatisticsHandler object to watch (StatisticDisplay's subject).
        private StatisticsHandler stats;

        /**************
         * Constructor.
         *************/
        public StatisticsDisplay(RichTextBox displayOutput, StatisticsHandler stats)
        {
            this.displayOutput = displayOutput;
            this.displayOutput.Clear();
            this.stats = stats;

            //"Observe" the statistics handler so this class knows when to display statistics.
            stats.StatisticsDisplay += new StatisticsHandler.DisplayHandler(RecieveStatistics);
        }//End Constructor.
        
        /**********************************************************************************
         * Calls DisplayStatistics after determining if the StatisticsHandler is running in
         * another thread.
         *********************************************************************************/
        private void DisplayControl()
        {
            //Check if the display output needs to be invoked before use.
            if (this.displayOutput.InvokeRequired)
            {
                //If it does, initialize a DisplayDelegate and invoke it.
                DisplayDelegate displayHandler = new DisplayDelegate(DisplayStatistics);
                this.displayOutput.Invoke(displayHandler);
            }
            else
                //Otherwise just call DisplayStatistics.
                DisplayStatistics();
        }//End DisplayControl.

        /**************************************************************
         * Displays the statistics generated by the statistics handler. 
         *************************************************************/
        private void DisplayStatistics()
        {    
            //Clear the display output.
            displayOutput.Clear();

            //Display the observation time.
            displayOutput.Text += OBSERVE.PadRight(DISPLAY_PADDING) + stats.ObserveTime + NEWLINE;

            //Display the total phone calls.
            displayOutput.Text += TOTAL_CALLS.PadRight(DISPLAY_PADDING) + stats.TotalCalls + NEWLINE;
            
            //Display the total number of hangups.
            displayOutput.Text += HANGUPS.PadRight(DISPLAY_PADDING) + stats.BusySignalCount + NEWLINE;

            //Display average wait time.
            displayOutput.Text += AVERAGE_WAIT.PadRight(DISPLAY_PADDING) + string.Format(DOUBLE_FORMAT, stats.AverageWaitTime) + NEWLINE;
                        
            //Display average time in simulation.
            displayOutput.Text += AVERAGE_SYSTEM.PadRight(DISPLAY_PADDING) + string.Format(DOUBLE_FORMAT, stats.AverageSystemTime) + NEWLINE;  
            
            //Display excessive wait count.
            DisplayExcessiveWaitCount();
            
            //Display phone call completion count.
            DisplayCompletionCount();
            
            //Display representative utilization.
            DisplayRepUtilization();
            
            //Display average customers waiting.
            DisplayAverageNumWaiting();
        }//End DisplayStatistics.
        
        /***********************************************************
         * Displays the average number of entities waiting in queue.
         **********************************************************/
        private void DisplayAverageNumWaiting()
        {
            //averageCustomersWaiting is used to calculate the average number of 
            //entities waiting over all queues.
            double averageCustomersWaiting = 0;

            //Display the title.
            displayOutput.Text += NEWLINE + AVERAGE_CUSTOMERS_WAITING.PadRight(TITLE_PADDING, TITLE_SPACER) + NEWLINE + NEWLINE;

            //Iterate through each product type.
            for (int i = 0; i < stats.ProductTypes.Length; i++)
            {
                //put the value of the average number waiting in queue for the given product type in a local variable.
                //This is done to handle cases when the product queues average number waiting is not a number.
                double averageWaiting = (Double.IsNaN(stats.AverageNumberWaiting[stats.ProductTypes[i]])) ? 0 : stats.AverageNumberWaiting[stats.ProductTypes[i]];
                
                //Create a string to display the product type.
                string s = stats.ProductTypes[i] + COLON;
                
                //display the product type and the value of averageWaiting.
                displayOutput.Text += s.PadRight(90) + string.Format(DOUBLE_FORMAT, averageWaiting) + NEWLINE;
                
                //add averageWaiting to the averageCustomersWaiting total.
                averageCustomersWaiting += averageWaiting;
            }

            //Calculate the total average customers waiting.
            averageCustomersWaiting = averageCustomersWaiting / stats.ProductTypes.Length;

            //display the total average customers waiting.
            displayOutput.Text += NEWLINE + AVERAGE.PadRight(90) + string.Format(DOUBLE_FORMAT, averageCustomersWaiting) + NEWLINE;                   
        }//End DisplayAverageNumWaiting.

        /************************************************************
         * Displays the representative utilization for service desks.
         ***********************************************************/
        private void DisplayRepUtilization()
        {
            //repUtilization is used to calculate the representative utilization over all service desks.
            double repUtilization = 0;

            //Display the title.
            displayOutput.Text += NEWLINE + REP_UTILIZATION.PadRight(TITLE_PADDING, TITLE_SPACER) + NEWLINE + NEWLINE;

            //Iterate through each product type.
            for (int i = 0; i < stats.ProductTypes.Length; i++)
            {
                //Create a string to display the product type.
                string s = stats.ProductTypes[i] + COLON;
                
                //Display the product type and the value of its representative utilization.
                displayOutput.Text += s.PadRight(DISPLAY_PADDING) + string.Format(DOUBLE_FORMAT, stats.RepUtilization[stats.ProductTypes[i]]) + NEWLINE;
                
                //Add the value of repUtilization to the repUtilization total.
                repUtilization += stats.RepUtilization[stats.ProductTypes[i]];
            }

            //Calculate the average representative utilization for all service desks.
            repUtilization = repUtilization / stats.ProductTypes.Length;

            //Display the average representative utilization for all service desks.
            displayOutput.Text += NEWLINE + AVERAGE.PadRight(DISPLAY_PADDING) + string.Format(DOUBLE_FORMAT, repUtilization) + NEWLINE;
        }//End DisplayRepUtilization.

        /****************************************************************
         * Displays the number of entities that completed the simulation.
         ***************************************************************/
        private void DisplayCompletionCount()
        {
            //A count of the total entites that completed the simulation.
            int completionCountTotal = 0;

            //Display the title.
            displayOutput.Text += NEWLINE + COMPLETION_COUNT.PadRight(TITLE_PADDING, TITLE_SPACER) + NEWLINE + NEWLINE;

            //Iterate through each product type.
            for (int i = 0; i < stats.ProductTypes.Length; i++)
            {
                //Create a string to display the given product type.
                string s = stats.ProductTypes[i] + COLON;

                //Display the entity completion total for the given product type.
                displayOutput.Text += s.PadRight(DISPLAY_PADDING) + stats.CompletionCount[stats.ProductTypes[i]] + NEWLINE;
                
                //Add the completion total for the given product type to the completion count total.
                completionCountTotal += stats.CompletionCount[stats.ProductTypes[i]];
            }
            //Display the total completion count.
            displayOutput.Text += NEWLINE + TOTAL.PadRight(DISPLAY_PADDING) + completionCountTotal + NEWLINE;
        }//End DisplayCompletionCount.

        /***************************************************************************
         * Displays the number of entites who had an excessive wait time in a queue.
         **************************************************************************/
        private void DisplayExcessiveWaitCount()
        {
            //A count of the total entities that had an excessive wait in queue.
            int waitCountTotal = 0;

            //Display the title.
            displayOutput.Text += NEWLINE + EXCESSIVE_WAIT.PadRight(TITLE_PADDING, TITLE_SPACER) + NEWLINE + NEWLINE;

            //Iterate through each product type.
            for (int i = 0; i < stats.ProductTypes.Length; i++)
            {
                //Create a string to display the given product type.
                string s = stats.ProductTypes[i] + COLON;

                //display the excessive wait count for the given product type.
                displayOutput.Text += s.PadRight(DISPLAY_PADDING) + stats.ExcessiveWaitCount[stats.ProductTypes[i]] + NEWLINE;

                //add the excessive wait count for the given product to the excessive wait count total.
                waitCountTotal += stats.ExcessiveWaitCount[stats.ProductTypes[i]];
            }
            //Display the total excessive wait count.
            displayOutput.Text += NEWLINE + TOTAL.PadRight(DISPLAY_PADDING) + waitCountTotal + NEWLINE;
        }//End DisplayExcessiveWaitCount.

        /************************************************************************************
         * RecieveStatistics watches for the statistics handler to fire a StatsDisplay event.
         ***********************************************************************************/
        public void RecieveStatistics(object sender, EventArgs e)
        {
            //Call the display control to determine if displayOutput needs invoked.
            DisplayControl();
        }//End RecieveStatistics.
    }
}