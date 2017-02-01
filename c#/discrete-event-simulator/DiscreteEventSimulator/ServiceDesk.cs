using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /****************************************************************************************
     *  Service desk is used to simulate an entity recieving service for their product query.
     ***************************************************************************************/
    public class ServiceDesk
    {
        //Total seconds in a minute.
        private const int TO_SECONDS = 60;

        //The product type call serviced by this service desk.
        private string productType;

        //The entities currently using this service desk.
        private List<Entity> entitiesInServiceDesk;

        //The service reps working at this service desk.
        private List<ServiceRep> serviceReps;

        //Time modifier to determine the time an entity spends at this service desk.
        private double timeMod;

        private Dice dice;

        //Delegate used to fire tell observing queues that a space is available at this service desk.
        public delegate void ResourceFreeHandler(object sender, EventArgs e);

        //ResourceFree calls the ResourceFreeHandler delegate.
        public event ResourceFreeHandler ResourceFree;

        /*************
         * Constructor
         ************/
        public ServiceDesk(string productType, int totalServiceReps, double timeMod, Dice dice)
        {
            this.productType = productType;
            this.timeMod = timeMod;
            this.dice = dice;
            entitiesInServiceDesk = new List<Entity>();
            
            //Initialize the service reps list.
            InitServiceReps(totalServiceReps);
        }//End Constructor.

        /*********************
         * Getters and setters
         ********************/

        //serviceReps
        public List<ServiceRep> ServiceReps
        {
            get { return serviceReps; }
        }

        //productType
        public string ProductType
        {
            get { return productType; }
        }
        //End getters and setters.

        /*******************************************************
         * Initializes the service reps that work at this desks. 
         ******************************************************/
        private void InitServiceReps(int totalServiceReps)
        {
            serviceReps = new List<ServiceRep>();

            //Create service reps equal to the totalServiceReps integer.
            for (int i = 0; i < totalServiceReps; i++)
            {
                //Create service rep.
                ServiceRep sr = new ServiceRep();

                //Add to service reps list.
                serviceReps.Add(sr);
            }
        }//End InitServiceReps.
               
        /**************************************
         * Adds an entity to this service desk.
         *************************************/
        public void AddEntity(Entity e, int serviceTime)
        {
            //Add entity to the entitiesInServiceDesl list.
            entitiesInServiceDesk.Add(e);

            //Make a free service rep start working.
            serviceReps.Find(sr => !sr.IsWorking).StartWork(e, serviceTime);
        }

        /*******************************************
         * Removes an entity from this service desk.
         ******************************************/
        public void RemoveEntity(Entity e)
        {
            //Make the service rep that is helping the given entity stop working.
            serviceReps.Find(sr => sr.Customer.Equals(e)).StopWork(); 
           
            //Remove the entity from the service desk.
            entitiesInServiceDesk.Remove(e);

            //Fire a resource free event.
            OnResourceFree();
        }//End RemoveEntity.

        /**********************************************************************************
         * Returns a random time (in seconds) used to determine the time taken to perform a 
         * CompleteServiceDesk event. 
         *********************************************************************************/
        public int GetDelayTime()
        {
            return (int)(dice.RollDice() * timeMod * TO_SECONDS);
        }//End GetDelayTime.

        /*************************************************
         * Checks if there are any available service reps.
         ************************************************/
        public bool IsResourceBusy() 
        {
            //Get the total service reps.
            int totalReps = serviceReps.Count();

            //get the total working service reps.
            int inUseReps = serviceReps.FindAll(sr => sr.IsWorking).Count();
                        
            return inUseReps >= totalReps; 
        }//End IsResourceBusy.

        /*********************************************************
         * Fires a resource free event if their are any observers.
         ********************************************************/
        public void OnResourceFree()
        {            
            if (ResourceFree != null)
                ResourceFree(this, null);
        }//End OnResourceFree.
    }
}
