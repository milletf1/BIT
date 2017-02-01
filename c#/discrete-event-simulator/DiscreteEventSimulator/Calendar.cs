using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /**************************************************************
     * Calendar is responsible for:
     * 
     * 1. Storing a list of events.
     * 2. Sorting events by event time.
     * 3. Updating the simulation clock.
     * 4. Returning the next event to be executed. 
     ************************************************************/
    class Calendar
    {
        //List of every unexecuted event in the simulation.  
        private List<SimEvent> eventList;

        //The simulation clock.
        private DateTime simClock;  
        
        //UpdateHandler and CalendarUpdate are used by observers to recieve events.
        public delegate void UpdateHandler(object sender, EventArgs e);
        public event UpdateHandler CalendarUpdate;

        /***********************
         * Calendar constructor.
         **********************/
        public Calendar(DateTime simClock)
        {
            eventList = new List<SimEvent>();
            this.simClock = new DateTime(simClock.Year, simClock.Month, simClock.Day, simClock.Hour, simClock.Minute, simClock.Second);
        }//End constructor.

        /*********************
         * Getters and Setters
         ********************/

        //eventList
        public List<SimEvent> EventList
        {
            get { return eventList; }
        }

        //simClock
        public DateTime SimClock
        {
            get { return simClock; }
        }
        //End getters and setters.

        /****************************************
         * Sets the clock to the next event time.
         ***************************************/
        public void UpdateClock()
        {
            //Check that an event exists in the system.
            if (eventList.Count() > 0)
            {
                //Check that the event time is not null.
                if (eventList[0].EventTime != null)
                {
                    //Calculate the difference in time betwen the simulation clock and the event time.
                    TimeSpan eventTime = (TimeSpan)(eventList[0].EventTime - simClock);

                    //Set the sim clock's time to that of the event time.
                    simClock = simClock.AddSeconds(eventTime.Seconds);
                    simClock = simClock.AddMinutes(eventTime.Minutes);
                }
            }
        }//End UpdateClock

        /***************************************************
         * Add the given event to the calendar's event list.
         **************************************************/
        public void AddEvent(SimEvent newEvent)
        {            
            eventList.Add(newEvent);
            //Sort the events by time.
            eventList.Sort();

            //Fire calendar update event.
            OnCalendarUpdate();
        }//End AddEvent.        

        /****************************************
         * Returns the next event to be executed.
         ***************************************/
        public SimEvent FetchEvent()
        {
            SimEvent curEvent = null;

            //Sort the events by time.
            eventList.Sort();

            //Check that an event exists in the system...
            if (eventList.Count() > 0)
            {
                //Set the return event to the next event to be executed.
                curEvent = eventList[0];
             
                //Remove the return event from the event list.
                eventList.Remove(curEvent);

                //Fire calendar update event.
                OnCalendarUpdate();
            }
            return curEvent;
        }//End FetchEvent.

        /*****************************
         * Sends updates to observers.
         ****************************/
        public void OnCalendarUpdate()
        {
            //If CalendarUpdate has been set...
            if (CalendarUpdate != null)
                //Fire it.
                CalendarUpdate(this, null);
        }//End OnCalendarUpdate.
    }
}
