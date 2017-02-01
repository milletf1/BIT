using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /****************************************************************************************
     * Dice is used to simulate the result of rolling two dice.  It's multiplied by
     * different time modifiers to determine how long it takes an entity to perform an event.
     ***************************************************************************************/
    public class Dice
    {
        //Top and bottom bounds used by the RNG for rolling one dice.
        private const int RNG_TOP = 7;
        private const int RNG_BOT = 1;

        private Random rand;

        /************
         * Contructor
         ***********/
        public Dice(Random rand)
        {
            this.rand = rand;
        }//End Constructor.

        /*******************************************
         * Returns a random number between 2 and 12.
         ******************************************/
        public int RollDice()
        {
            int rValue = rand.Next(RNG_BOT, RNG_TOP) + rand.Next(RNG_BOT, RNG_TOP);
            return rValue;
        }//End RollDice.
    }
}
