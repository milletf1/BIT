using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace DiscreteEventSimulator
{
    public partial class Form1 : Form
    {
        //Default values for the simulation.
        private const int DEFAULT_SIM_TIME = 120;
        private const int DEFAULT_MAX_HOLD = 10;
        private const int DEFAULT_SLEEP = 500;
        private const int DEFAULT_CAR_AUDIO_REPS = 1;
        private const int DEFAULT_OTHER_REPS = 2;
        private const int DEFAULT_EXCESS_WAIT = 5;
        private const int DEFAULT_PERCENT_CAR_STEREO = 17;

        //Double values for time rolls.
        private const double TIME_0_3 = 0.333;
        private const double TIME_2_12 = 1;
        private const double TIME_3_18 = 1.5;
        private const double TIME_4_24 = 2;
        private const double TIME_5_30 = 2.5;
        private const double TIME_6_36 = 3;

         //Create a calendar display.
        private CalendarDisplay calendarOut; 

        //Create a display for other queue.
        private CalendarDisplay otherQueue;

        //Create a display for car stereo queue.
        private CalendarDisplay carStereoQueue;

        //Graphical display for the simulation.
        private GraphicDisplay visualDisplay;

        //Create a display for the statistics handler
        private StatisticsDisplay statistics;

        //Create a dedicated thread for the RunSimulation() process.
        private Thread tRunSim;
        private ThreadStart tsRunSim;

        //Master random number generator.
        private Random r;

        //the simulation.
        private Simulation sim;

        public Form1()
        {
            InitializeComponent();
        }

        /************
         * Form Load.
         ***********/
        private void Form1_Load(object sender, EventArgs e)
        {
            //Initialize random number generator.
            r = new Random();

            //Position in top left corner of screen.
            Left = 0;
            Top = 0;
            
            //Set the user input options to default.
            SetDefaultOptions();    
        }//End FormLoad.

        /*************************************
         * Sets user input options to default.
         ************************************/
        private void SetDefaultOptions()
        {
            //Maiximum number of entities in queue.
            selectMaxHoldLen.Value = DEFAULT_MAX_HOLD;

            //Time considered excessive for waiting.
            selectExcessWait.Value = DEFAULT_EXCESS_WAIT;

            //Number of car-stereo desk service representatives.
            selectCarStereoReps.Value = DEFAULT_CAR_AUDIO_REPS;

            //number of other desk service representatives.
            selectOtherReps.Value = DEFAULT_OTHER_REPS;

            //the percentage of calls that want service for car stereos.
            selectPercentCarStereo.Value = DEFAULT_PERCENT_CAR_STEREO;

            //Check the default radio buttons for time taken to perform an event.
            rbArrival16.Checked = true;
            rbCompleteIvr16.Checked = true;
            rbCompleteCarStereo424.Checked = true;
            rbCompleteOther212.Checked = true;

            //Set the default pause between event time.
            selectEventPause.Value = DEFAULT_SLEEP;

            //Set the default run time of the simulation.
            selectSimTime.Value = DEFAULT_SIM_TIME;
        }//End SetDefaultOptions.

        /************************************************************************
         * Initializes all the data and components necessary to run a simulation.
         ***********************************************************************/
        private void LoadSimulation()
        {
            //Get the user input values from number selectors
            //for the global variables used in the simulation.
            int maxHold = Convert.ToInt16(selectMaxHoldLen.Value);
            int excessWait = Convert.ToInt16(selectExcessWait.Value);
            int carStereoReps = Convert.ToInt16(selectCarStereoReps.Value);
            int otherReps = Convert.ToInt16(selectOtherReps.Value);            
            int eventPause = Convert.ToInt16(selectEventPause.Value);
            int simTime = Convert.ToInt16(selectSimTime.Value);
            int percentCarStereo = Convert.ToInt16(selectPercentCarStereo.Value);

            //Get the user input values from radio buttons
            //for the global variables used in the simulation.
            double delayArrivals = FetchDelayArrival();
            double delayIvr = FetchDelayIvr();
            double delayCarStereo = FetchDelayCarStero();
            double delayOther = FetchDelayOther();

            //Initialize a product type list.
            string[] productTypes = new string[] { ProductData.CAR_STEREO_PRODUCT, ProductData.OTHER_PRODUCT };

            //Create a new simulation.
            sim = new Simulation(simTime, maxHold, eventPause, carStereoReps, otherReps,
                delayCarStereo, delayOther, delayArrivals, delayIvr,
                r, percentCarStereo, excessWait, productTypes);

            //Create a calendar display.
            calendarOut = new EventDisplay(eventDisplay, sim.Calendar);

            //Create a display for other queue.
            otherQueue = new QueueDisplay(otherDisplay, sim.Calendar, ProductData.OTHER_PRODUCT);

            //Create a display for car stereo queue.
            carStereoQueue = new QueueDisplay(carDisplay, sim.Calendar, ProductData.CAR_STEREO_PRODUCT);

            //Create a graphical display for the simulation.
            visualDisplay = new GraphicDisplay(displayPanel, sim.Calendar, maxHold, carStereoReps, otherReps, displayPanel.Width, displayPanel.Height);
            
            //Create a text display for the statistics handler.
            statistics = new StatisticsDisplay(statsDisplay, sim.stats);
        }//End LoadSimulation.

        /*************************************************
         * Retrieves the time modifier for the event delay
         * in the other product service desk.
         ************************************************/
        private double FetchDelayOther()
        {
            double rValue = 0;

            if (rbCompleteOther16.Checked)
                rValue = TIME_0_3;
            else if (rbCompleteOther212.Checked)
                rValue = TIME_2_12;
            else if (rbCompleteOther318.Checked)
                rValue = TIME_3_18;
            else if (rbCompleteOther424.Checked)
                rValue = TIME_4_24;
            else if (rbCompleteOther530.Checked)
                rValue = TIME_5_30;
            else if (rbCompleteOther636.Checked)
                rValue = TIME_6_36;

            return rValue;
        }//End FetchDelayOther.

        /*************************************************
         * Retrieves the time modifier for the event delay
         * in the car-stereo product service desk.
         ************************************************/
        private double FetchDelayCarStero()
        {
            double rValue = 0;

            if (rbCompleteCarStereo16.Checked)
                rValue = TIME_0_3;
            else if (rbCompleteCarStereo212.Checked)
                rValue = TIME_2_12;
            else if (rbCompleteCarStereo318.Checked)
                rValue = TIME_3_18;
            else if (rbCompleteCarStereo424.Checked)
                rValue = TIME_4_24;
            else if (rbCompleteCarStereo530.Checked)
                rValue = TIME_5_30;
            else if (rbCompleteCarStereo636.Checked)
                rValue = TIME_6_36;
            
            return rValue;
        }//End FetchDelayCarStereo.

        /*************************************************
         * Retrieves the time modifier for the event delay 
         * in the IVR unit.
         ************************************************/
        private double FetchDelayIvr()
        {
            double rValue = 0;

            if (rbCompleteIvr16.Checked)
                rValue = TIME_0_3;
            else if (rbCompleteIvr212.Checked)
                rValue = TIME_2_12;
            else if (rbCompleteIvr318.Checked)
                rValue = TIME_3_18;
            else if (rbCompleteIvr424.Checked)
                rValue = TIME_4_24;
            else if (rbCompleteIvr530.Checked)
                rValue = TIME_5_30;
            else if (rbCompleteIvr636.Checked)
                rValue = TIME_6_36;

            return rValue;
        }//End FetchDelayIvr.

        /**********************************************
         * Retrieves the time modifier for the delay
         * before an entity arrives at the call center.
         *********************************************/
        private double FetchDelayArrival()
        {
            double rValue = 0;

            if (rbArrival16.Checked)
                rValue = TIME_0_3;
            else if (rbArrival212.Checked)
                rValue = TIME_2_12;
            else if (rbArrival318.Checked)
                rValue = TIME_3_18;
            else if (rbArrival424.Checked)
                rValue = TIME_4_24;
            else if (rbArrival530.Checked)
                rValue = TIME_5_30;
            else if (rbArrival636.Checked)
                rValue = TIME_6_36;

            return rValue;
        }//End FetchDelayArrival.
        
        /**************************************************************
         * Kills the simulation thread when the main window has closed.
         *************************************************************/
        private void KillThread()
        {
            //If the run simulation thread is running, kill it.
            if (tRunSim != null)
            {
                tRunSim.Abort();
                tRunSim = null;
            }
        }//End KillThread.
        
        /*************************************
         * Event handler for form close event.
         ************************************/
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            KillThread();
        }//End Form1_FormClosing.
        
        /***************************************
         * Event handler for button click event.
         **************************************/
        private void btnStop_Click(object sender, EventArgs e)
        {
            KillThread();
        }//End btnStop_Click.   
        
        /***************************************
         * Event handler for button click event.
         **************************************/
        private void btnStart_Click(object sender, EventArgs e)
        {
            //stop the run simulation thread if it exists.
            KillThread();

            //Load the simulation.
            LoadSimulation();

            //Create a thread to run the simulation.
            tsRunSim = new ThreadStart(sim.RunSimulation);
            tRunSim = new Thread(tsRunSim);

            //Execute thread.
            tRunSim.Start();
        }//End btnStart_Click.     
    }
}
