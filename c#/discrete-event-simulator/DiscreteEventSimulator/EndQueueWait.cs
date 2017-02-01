using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /***************************************************
     * EndQueueWait simulates an entity leaving a queue.
     **************************************************/
    class EndQueueWait : SimEvent
    {
        //Event name.
        public const string EVENT_NAME = "Wait in queue";
        
        //The queue that the entity waits in.
        private Queue queue;

        /*************
         * Constructor
         ************/
        public EndQueueWait(Entity eventEntity, StatisticsHandler stats, Queue queue, Calendar calendar)
            : base(eventEntity, null, stats, calendar) 
        {
            this.eventName = EVENT_NAME;
            this.queue = queue;
            this.queue.AddEntity(eventEntity);

            //Create an event handler that will set the event time for this event.
            this.eventEntity.SetEventTime += new Entity.SetEventTimeHandler(EndQueueWaitHandler);
        }//End Constructor

        /*************************************************************************************
         * Removes the entity from the queue's entity list, increments the statistics handler's
         * excessive wait time count if necessary, adds a sample to the statistics handler's
         * wait time sample list, and returns a CompleteServiceDesk event code.
         ************************************************************************************/
        public override int? ExecuteEvent()
        {
            //Remove the entity from the queue's entity list.
            queue.RemoveEntity(eventEntity);

            //Calculate the time the entity spent waiting in queue.
            TimeSpan timeTaken = (TimeSpan)(calendar.SimClock - eventEntity.BeginWait);

            //If the time spent waiting in queue was greater or equal to the 
            //excessive wait time, increment the excessive wait count.
            if (timeTaken.Minutes >= stats.ExcessiveWaitTime)
                stats.IncrementExcessiveWaitCount(queue.ProductType);

            //Take a sample of the wait time.
            stats.TakeWaitTimeSample(timeTaken.Minutes);

            //Return CompleteServiceDesk event code so the simulation can create the next
            //event involiving the event entity.
            return EventCode.CompleteServiceDesk;
        }//End ExecuteEvent.

        /***********************************************************************
         * EndQueueWaitHandler is used by the entities SetEventTime event to set 
         * the time for this event to execute.
         **********************************************************************/
        public void EndQueueWaitHandler(object sender, EventArgs e)
        {
            //Set the event time using the time of the sim clock.
            eventTime = new DateTime(calendar.SimClock.Year, calendar.SimClock.Month, calendar.SimClock.Day,
                calendar.SimClock.Hour, calendar.SimClock.Minute, calendar.SimClock.Second);
        }//End EndQueueWaitHandler.
    }
}
