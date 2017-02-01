using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /********************************************************************************************
     * Entity is used to simulate a phone call to the call center taking place in the simulation.
     * It's responsibilities include:
     * 
     * 1. Recording information for use by the statistics handler.
     * 2. Providing data to determine what action is to take place during certain events.
     *    More specifically, what type of service desk and queue this entity will be placed in 
     *    during the simulation.
     *******************************************************************************************/
    public class Entity
    {
        //The entities ID.
        private int entityID;

        //The product type that caused the entity to place the call to the call center.
        private string productType;

        //The time that the entity arrives at the call center.
        private DateTime? startTime;

        //The time the call leaves the IVR unit and joins one of the queues.
        private DateTime? beginWait;

        //The delegate used to set the event time of an EndQueueWait event.
        public delegate void SetEventTimeHandler(object sender, EventArgs e);

        //The event used to call the SetEventTimeHandler delegate.
        public event SetEventTimeHandler SetEventTime;

        /*************
         * Constructor
         ************/
        public Entity(int entityID, string productType)
        {
            this.entityID = entityID;
            this.productType = productType;
        }//End Constructor.

        /**********************
         * Getters and setters.
         *********************/

        //entityID
        public int EntityID
        {
            get { return entityID; }
        }

        //productType
        public string ProductType
        {
            get { return productType; }
        }

        //startTime
        public DateTime? StartTime
        {
            get { return startTime; }
            set { startTime = value; }
        }

        //beginWait
        public DateTime? BeginWait
        {
            get { return beginWait; }
            set { beginWait = value; }
        }
        //End Getters and setters.
         
        /********************************************************************
         * OnSetEventTime fires a SetEventTime event if it has any observers. 
         *******************************************************************/
        public void OnSetEventTime()
        {
            if(SetEventTime != null)
                SetEventTime(this, null);
        }//End OnSetEventTime.
    }
}
