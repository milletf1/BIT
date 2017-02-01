using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /****************************************************************************************************************
     * IVRUnit is used to simulate an entity choosing the product they wish to speak to a service representative for.
     ***************************************************************************************************************/
    class IVRUnit
    {
        private const int TO_SECONDS = 60;
        
        //Time modifier to determine the time an entity spends in this IVR unit.
        private double timeMod;
        private Dice dice;

        //List of all entities in this IVR unit.
        private List<Entity> entitiesInIVR;

        /*************
         * Constructor
         ************/
        public IVRUnit(double timeMod, Dice dice)
        {
            this.timeMod = timeMod;
            this.dice = dice;
            entitiesInIVR = new List<Entity>();
        }//End Constructor.

        //Getter for entities in IVR
        public List<Entity> GetEntitiesInIVR
        {
            get { return entitiesInIVR; }
        }//End GetEntitiesInIVR.


        /**********************************
         * Adds an entity to this IVR unit.
         *********************************/
        public void AddEntity(Entity e)
        {
            entitiesInIVR.Add(e);
        }//End AddEntity.

        /***************************************
         * Removes an entity from this IVR unit.
         **************************************/
        public void RemoveEntity(Entity e)
        {
            entitiesInIVR.Remove(e);
        }//End RemoveEntity.

        /**********************************************************************************
         * Returns a random time (in seconds) used to determine the time taken to perform a 
         * CompleteIVRService event. 
         *********************************************************************************/
        public int GetDelayTime()
        {
            return (int)(dice.RollDice() * timeMod * TO_SECONDS);
        }//End GetDelayTime.
    }
}
