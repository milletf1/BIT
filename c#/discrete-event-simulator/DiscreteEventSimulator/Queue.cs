using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /*****************************************************************************
     * Queue stores a list of all entities waiting to use a service desk resource.
     ****************************************************************************/
    public class Queue
    {
        //The product type that this queue provides a wait area for.
        private string productType;

        //The entities currently waiting in this queue.
        private List<Entity> entitiesInQueue;

        //The service desk that recieves entities waiting in this queue.
        private ServiceDesk serviceDesk;

        /*************
         * Constructor
         ************/
        public Queue(ServiceDesk serviceDesk, string productType)
        {
            entitiesInQueue = new List<Entity>();
            this.serviceDesk = serviceDesk;
            this.productType = productType;
            
            //Observe when a service rep is made available at the service desk.
            serviceDesk.ResourceFree += new ServiceDesk.ResourceFreeHandler(GetEntityReady);            
        }//End Constructor.

        /*********************
         * Getters and setters
         ********************/

        //productType
        public string ProductType
        {
            get { return productType; }
        }

        //entitiesInQueue
        public List<Entity> EntitiesInQueue
        {
            get { return entitiesInQueue; }
        }
        //End getters and setters.

        /***********************************************************
         * Adds an entity to the entitiesInQueue list and orders it.
         **********************************************************/
        public void AddEntity(Entity e)
        {
            //Add entity to list.
            entitiesInQueue.Add(e);

            //Order the list by the entitie's beginWait time.
            entitiesInQueue.OrderBy(entity => entity.BeginWait);
        }//End AddEntity.

        /*****************************************
         * Removes the given entity from the list.
         ****************************************/
        public void RemoveEntity(Entity e)
        {
            entitiesInQueue.Remove(e);
        }//End RemoveEntity.

        /***********************************************************
         * Tells the first entity in the entitiesInQueue list to set 
         * fire a set SetEventTime event.
         **********************************************************/
        public void GetEntityReady(object sender, EventArgs e)
        {
            if(entitiesInQueue.Count > 0)
                entitiesInQueue[0].OnSetEventTime();        
        }//End GetEntityReady.
    }
}
