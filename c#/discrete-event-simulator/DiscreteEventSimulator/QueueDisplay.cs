using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DiscreteEventSimulator
{
    /*********************************************************************
     * QueueDisplay displays the statistics of an entity waiting in queue.
     ********************************************************************/
    class QueueDisplay :CalendarDisplay
    {
        //The product type to observe for.
        private string productType;

        /*************
         * Constructor
         ************/
        public QueueDisplay(ListBox displayOutput, Calendar calendar, string productType)
            : base (displayOutput, calendar)
        {
            this.productType = productType;
        }//End Constructor.  

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
                //If the event is a wait in queue event with the same product type as this class, display it.
                if (se is EndQueueWait && se.EventEntity.ProductType.CompareTo(productType) == 0)
                    DisplayRowData(se);
            }
        }//End DisplayEvents.
    }
}
