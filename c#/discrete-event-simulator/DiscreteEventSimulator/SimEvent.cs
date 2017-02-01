using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{   
    /******************************************************
     * Base class for the event classes in this simulation.
     *****************************************************/
    abstract class SimEvent : IComparable
    {
        //Entity that is involved in the event.
        protected Entity eventEntity;

        //Time that the event takes place.
        protected DateTime? eventTime;

        //Name of the event.
        protected string eventName;

        //The simulation's statistic handler
        protected StatisticsHandler stats;

        //The simulation's calendar.
        protected Calendar calendar;     

        /**********************
         * SimEvent constructor
         *********************/
        public SimEvent(Entity eventEntity, DateTime? eventTime, StatisticsHandler stats, Calendar calendar)
        {
            this.eventEntity = eventEntity;
            this.eventTime = eventTime;
            this.stats = stats;
            this.calendar = calendar;
        }//End constructor.

        /*********************
         * Getters and Setters
         ********************/

        //eventEntity
        public Entity EventEntity
        {
            get { return eventEntity; }
        }

        //eventTime
        public DateTime? EventTime
        {
            get { return eventTime; }
        }

        //eventName
        public string EventName
        {
            get { return eventName; }
        }
        //End Getters and Setters
        
        /**********************************
         * ExecuteEvent performs the event.
         *********************************/
        public abstract int? ExecuteEvent();


        /*********************
         * Comparator Override
         ********************/
        public int CompareTo(object obj)
        {
            //Return value.
            int r = 0;

            //Check if the entites' event times are the same.
            if ((obj as SimEvent).EventTime == this.EventTime)
            {
                //If they are, sort by the entities' start time.
                if ((obj as SimEvent).EventEntity.StartTime > this.EventEntity.StartTime)
                    r = -1;
                else if ((obj as SimEvent).EventEntity.StartTime < this.EventEntity.StartTime)
                    r = 1;  
            }              
            else
            {
                //If the event times are different, sort by event time.
                if ((obj as SimEvent).EventTime > this.EventTime || (obj as SimEvent).EventTime == null)
                    r = -1;
                else if ((obj as SimEvent).EventTime < this.EventTime || eventTime == null)
                    r = 1;
            }

            return r;
        }//End CompareTo.
    }
}
