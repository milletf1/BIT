using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /***************************************************************************
     * Service rep is responsible for:
     * 
     * 1. Keeping track of the time they have worked for the statistics handler.
     **************************************************************************/
    public class ServiceRep
    {
        //The entity the service rep is helping (when the service rep is working).
        private Entity customer;
        
        //The time the service rep has spent working (in seconds).
        private int workTime;
        
        //A boolean value used to determine if the service rep is working,
        private bool isWorking;

        /*************
         * Constructor
         ************/
        public ServiceRep()
        {
            isWorking = false;
            workTime = 0;
        }//End Constructor.

        /**********************
         * Getters and setters.
         *********************/

        //workTime
        public int WorkTime
        {
            get { return workTime; }
        }

        //isWorking
        public bool IsWorking
        {
            get { return isWorking; }
        }

        //customer
        public Entity Customer
        {
            get { return customer; }
        }
        //End Getters and Setters.

        /*************************************************
         * Makes the service representative start working.
         ************************************************/
        public void StartWork(Entity e, int workTime)
        {
            //Set the service reps customer to the given entity.
            customer = e;

            //Set the service rep's isWorking bool to true.
            isWorking = true;

            //Increment the service reps work time.
            this.workTime += workTime;
        }//End StartWork.
        
        /************************************************
         * Makes the service representative stop working.
         ***********************************************/
        public void StopWork()
        {
            isWorking = false;         
        }//End StopWork.
        
    }
}
