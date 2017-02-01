using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /***************************************************************************
     * ArriveAtCallCenter simulates an entity placing a call at the call center.
     **************************************************************************/
    class ArriveAtCallCenter : SimEvent
    {
        //Event name.
        private const string EVENT_NAME = "Arrive at Call Center";

        //Maximum length of queue.
        private int maxQueueLength;

        //All the queues in the simulation.
        private List<Queue> queueList;  
        
        //The simulation's ivr unit.  
        private IVRUnit ivr;

        /*************
         * Constructor
         ************/
        public ArriveAtCallCenter(Entity eventEntity, DateTime eventTime, StatisticsHandler stats, 
            Calendar calendar, List<Queue> queueList, int maxQueueLength, IVRUnit ivr)
            : base(eventEntity, eventTime, stats, calendar) 
        {
            this.eventName = EVENT_NAME;
            this.queueList = queueList;
            this.ivr = ivr;
            this.maxQueueLength = maxQueueLength;
        }//End Constructor.

        /*******************************************************************************************        
         * Determines how many entities are waiting in queues.  If there are less entities 
         * waiting than the maximum waiting length, forward to IVR unit, otherwise leave simulation.
         ******************************************************************************************/
        public override int? ExecuteEvent()
        {
            //Return value.  Returns null when there is no room in the waiting queues.
            int? result = null;

            //Increment total calls recieved.
            stats.TotalCalls++;

            //Set the entities start time to the current simulation time.
            DateTime entityStartTime = new DateTime(calendar.SimClock.Year, calendar.SimClock.Month, calendar.SimClock.Day, 
                calendar.SimClock.Hour, calendar.SimClock.Minute, calendar.SimClock.Second);

            eventEntity.StartTime = entityStartTime;
            
            //totalWaiting is used to determine how many entities are waiting in queue.
            int totalWaiting = 0;
            
            //Add the total number of entities waiting in each queue to the totalWaiting count.
            foreach (Queue q in queueList)
                totalWaiting += q.EntitiesInQueue.Count();

            //Add the entities in the IVR.
            totalWaiting += ivr.GetEntitiesInIVR.Count();

            //If there is room in the wait queues, set the return value to complete ivr service.
            if (totalWaiting < maxQueueLength)
                result = EventCode.CompleteIVRService;

            //If there isn't any room, increment the busy signal count in the statistics handler.
            else
                stats.IncrementBusySignalCount();

            return result;
        }//End ExecuteEvent.
    }
}
