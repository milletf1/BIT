using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DiscreteEventSimulator
{
    /***************************************************************************
     * EventDisplay displays all events in the calendar that have an event value
     * that is not null.
     **************************************************************************/
    class EventDisplay :CalendarDisplay
    {   
        /*************
         * Constructor
         ************/
        public EventDisplay(ListBox displayOutput, Calendar calendar)
            : base(displayOutput, calendar)
        { }//End Constructor.

        /*****************************************************************************
         * Overridden DisplayEvents chooses which events to display from the calendar.
         ****************************************************************************/
        protected override void DisplayEvents()
        {
            //Clear the display output.
            displayOutput.Items.Clear();

            //Display the title header.
            displayOutput.Items.Add(TITLE_HEADER);
            displayOutput.Items.Add("");

            //Iterate through the events in the calendar's event list.
            foreach (SimEvent se in calendar.EventList)
            {
                //If the current event is not an EndQueueWait SimEvent, display it.
                if (!(se is EndQueueWait))
                    DisplayRowData(se);
            }
        }//End DisplayEvents.
    }
}
