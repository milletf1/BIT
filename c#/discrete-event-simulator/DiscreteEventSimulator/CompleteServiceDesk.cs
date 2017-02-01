using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /*************************************************************************************
     * CompleteServiceDesk simulates an entity completing their enquiry at a service desk.
     ************************************************************************************/
    class CompleteServiceDesk : SimEvent
    {
        //Event name.
        private const string EVENT_NAME = "Complete Service Desk";

        //Event service desk.
        private ServiceDesk serviceDesk;

        /**************
         * Constructor.
         *************/
        public CompleteServiceDesk(Entity eventEntity, DateTime eventTime, StatisticsHandler stats, Calendar calendar, ServiceDesk serviceDesk, int serviceTime)
            : base(eventEntity, eventTime, stats, calendar) 
        {
            this.eventName = EVENT_NAME;
            this.serviceDesk = serviceDesk;            
            this.serviceDesk.AddEntity(eventEntity, serviceTime);
        }//End Constructor.

        /*************************************************************************************
         * Remove an entity from the service desk's list, takes a system time sample for 
         * the statistics handler, and increments the statistics handlers completion count for
         * the entitie's product type.
         ************************************************************************************/
        public override int? ExecuteEvent()
        {
            //Calculate the time the entity has spent in the simulation
            //and pass it to the statistics handler as a sample.
            TimeSpan timeTaken = (TimeSpan)(calendar.SimClock - eventEntity.StartTime);

            //int systemTime = calendar.SimClock - eventEntity.StartTime;
            stats.TakeSystemTimeSample(timeTaken.Minutes);

            //Increment the statistics handler's completion count.
            stats.IncrementCompletionCount(EventEntity.ProductType);

            //Remove the entity from the service desk.
            serviceDesk.RemoveEntity(eventEntity);
            return null;
        }//End ExecuteEvent.
    }
}
