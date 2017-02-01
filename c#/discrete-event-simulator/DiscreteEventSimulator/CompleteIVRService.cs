using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /********************************************************************************
     * CompleteIVRService simulates a entity choosing a product type in the IVR Unit.
     * Responsibilites include.
     * 
     * 1. storing the time that the event occurs.
     * 2. storing the entity involved in the event.
     * 3. Using the simulations statistic handler to take a sample of the number of 
     *    entities currently waiting in queue to talk to a service rep about the given
     *    product type.
     * 4. Returning an event code to create the next event in the simulation.
     *******************************************************************************/
    class CompleteIVRService : SimEvent
    {
        //Display name of the event.
        private const string EVENT_NAME = "Complete IVR Service";

        //The product queue for the entities product type.  Used to take number waiting in queue sample.
        private Queue queue;

        //The simulation's IVR unit.
        private IVRUnit ivr;

        /**************
         * Constructor.
         *************/
        public CompleteIVRService(Entity eventEntity, DateTime eventTime, StatisticsHandler stats, Queue queue, Calendar calendar, IVRUnit ivr)
            : base(eventEntity, eventTime, stats, calendar) 
        {
            this.eventName = EVENT_NAME;
            this.queue = queue;
            this.ivr = ivr;

            //Add the event entity to the IVR's entity list.
            this.ivr.AddEntity(eventEntity);
        }//End Constructor.
        
        /***************************************************************************************
         * ExecuteEvent removes the entity from the IVR's entity list, takes a number waiting in 
         * queue sample for the statistics handler, and returns an end wait in queue event code.
         **************************************************************************************/
        public override int? ExecuteEvent()
        {
            //Set the entities begin wait value.
            DateTime entityBeginWait = new DateTime
            (calendar.SimClock.Year, calendar.SimClock.Month, calendar.SimClock.Day, calendar.SimClock.Hour, calendar.SimClock.Minute, calendar.SimClock.Second);
            eventEntity.BeginWait = entityBeginWait;            

            //Remove the entity from the IVR's entity list.
            ivr.RemoveEntity(eventEntity);
            
            //Take sample of entities waiting in queue.
            stats.TakeNumberWaitingSample(EventEntity.ProductType, queue.EntitiesInQueue.Count());

            //Return a end wait in queue event code.
            return EventCode.EndWaitInQueue;
        }//End ExecuteEvent.
    }
}
