using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiscreteEventSimulator
{
    /***********************************************************************************
     * When an event is executed, it will return either null or an event code integer to 
     * let the event factory determine what type of event to create. 
     **********************************************************************************/
    public static class EventCode
    {
        public const int ArriveAtCallCenter = 0;
        public const int CompleteIVRService = 1;
        public const int EndWaitInQueue = 2;
        public const int CompleteServiceDesk = 3;
    }
}
