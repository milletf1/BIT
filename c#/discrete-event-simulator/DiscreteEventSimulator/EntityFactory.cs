using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /*************************************************
     * EntityFactory creates and returns a new entity.
     ************************************************/
    class EntityFactory
    {
        //The top bounds used by rand to determine the product type a 
        //entity has placed a call for.
        private const int RNG_BOUNDS = 100;

        //Index of the different products in productTypes array.
        private const int CAR_STEREO_INDEX = 0;
        private const int OTHER_INDEX = 1;

        //ID value of the next entity that is produced.
        private int nextEntityID;
        private Random rand;
        
        //The product types.
        private string[] productTypes;

        //productDecided is used to determine if a new entity has placed a call about 
        //car stereo or other products.
        private int productDecider;

        /*************
         * Constructor
         ************/
        public EntityFactory(Random rand, string[] productTypes, int productDecider)
        {
            this.nextEntityID = 1;
            this.rand = rand;
            this.productTypes = productTypes;
            this.productDecider = productDecider;
        }//End Constructor.

        /***********************************
         * Creates and returns a new entity.
         **********************************/
        public Entity MakeEntity()
        {
            //Determine the new entitie's product type.
            string productType = GetProductType();

            //Create a new entity.
            Entity newEntity = new Entity(nextEntityID, productType);

            //Increment the next entity ID
            nextEntityID++;

            return newEntity;
        }//End MakeEntity.

        /*************************************************************
         * GetProductType randomly chooses and returns a product type.
         ************************************************************/
        private string GetProductType()
        {           
            int randomNumber = rand.Next(RNG_BOUNDS);
         
            //Determine if the the entity is calling about a car stereo
            //or other product.
            string product = (randomNumber < productDecider) ?
                productTypes[CAR_STEREO_INDEX] : productTypes[OTHER_INDEX];
            
            return product;
        }//End GetProductType.
    }
}
