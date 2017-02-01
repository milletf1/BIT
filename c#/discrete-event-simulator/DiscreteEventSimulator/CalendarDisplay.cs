using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DiscreteEventSimulator
{
    /******************************************************************************
     * CalendarDisplay is an abstract class for classes that wish to display events
     * stored in a Calendar object.  EventDisplay and QueueDisplay inherit from
     * this class.
     *****************************************************************************/
    abstract class CalendarDisplay
    {
        //String used to display the column names.
        protected const string TITLE_HEADER = "  ID\t\tEvent\t\tEvent Time   Begin Wait   Start Time   Product Type";

        //string.format used to display the row values.
        protected const string FORMAT = "  {0}{1}{2}{3}{4}{5}";   
     
        //Format used to display time values in the calendarDisplay
        protected const string TIME_FORMAT = "HH:mm:ss";
        
        //String used to display a null value.
        private const string NULL_VALUE = "--:--:--";
        
        //Padding used between row attributes.
        protected const int ENTITY_ID_PAD = 6;
        protected const int EVENT_NAME_PAD = 25;
        protected const int EVENT_TIME_PAD = 13;
        protected const int BEGIN_WAIT_PAD = 13;
        protected const int START_TIME_PAD = 13;
        protected const int PRODUCT_TYPE_PAD = 12;

        //Delegate used to access a Calendar object that's running on another thread.
        protected delegate void DisplayDelegate();

        //Display for the events.
        protected ListBox displayOutput;

        //The Calendar object to watch (CalendarDisplay's subject).
        protected Calendar calendar;

        /**************
         * Constructor.
         *************/
        public CalendarDisplay(ListBox displayOutput, Calendar calendar)
        {
            this.displayOutput = displayOutput;
            this.calendar = calendar;

            //"Observe" the calendar so this class knows when to display the calendar's events.
            this.calendar.CalendarUpdate += new Calendar.UpdateHandler(RecieveCalendarUpdate);
        }//End Constructor.

        //DisplayEvents is used by descendants of this class to determine which events to display.
        protected abstract void DisplayEvents();

        /*********************************************************************
         * Calls DisplayEvents after determining if the calendar is running in
         * another thread.
         ********************************************************************/
        private void DisplayControl()
        {
            //Check if the display output needs to be invoked before use.
            if (this.displayOutput.InvokeRequired)
            {
                //If it does, initialize a DisplayDelegate and invoke it.
                DisplayDelegate displayHandler = new DisplayDelegate(DisplayEvents);
                this.displayOutput.Invoke(displayHandler);
            }
            else
                //Otherwise just call DisplayEvents.
                DisplayEvents();
        }//End DisplayControl.

        /****************************************************
        * Formats the event in a row of data and displays it.
        ****************************************************/
        protected void DisplayRowData(SimEvent se)
        {
            //Convert the event's entity id value to string.
            string entityID = Convert.ToString(se.EventEntity.EntityID);

            string eventName = se.EventName;

            //Convert the event time to string.
            string eventTime = (se.EventTime != null ? se.EventTime.Value.ToString(TIME_FORMAT) : NULL_VALUE);
            

            //Convert the event's entity begin wait value to string.
            string beginWait = (se.EventEntity.BeginWait != null ?se.EventEntity.BeginWait.Value.ToString(TIME_FORMAT) : NULL_VALUE);

            //Convert the event's entity start time value to string.
            string startTime = (se.EventEntity.StartTime != null ? se.EventEntity.StartTime.Value.ToString(TIME_FORMAT) : NULL_VALUE);
            
            //Put the event's entity product type value in a local string.
            string productType = se.EventEntity.ProductType;
            
            //Create a display string.
            string s = string.Format(FORMAT, entityID.PadRight(ENTITY_ID_PAD, ' '), 
                eventName.PadRight(EVENT_NAME_PAD, ' '), eventTime.PadRight(EVENT_TIME_PAD, ' '), beginWait.PadRight(BEGIN_WAIT_PAD, ' '), 
                startTime.PadRight(START_TIME_PAD, ' '), productType.PadRight(PRODUCT_TYPE_PAD, ' '));
            
            //Display the row data.
            displayOutput.Items.Add(s);
        }//End DisplayRowData.

        /*******************************************************************************************
         * RecieveCalendarUpdate watches for the simulation calendar to fire a CalendarUpdate event.
         ******************************************************************************************/
        public void RecieveCalendarUpdate(object sender, EventArgs e)
        {
            //Call the display control to determine if displayOutput needs invoked.
            DisplayControl();
        }//End RecieveCalendarUpdate.
    }
}
