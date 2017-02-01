using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace MelbourneCupSweepstakes.Models
{
    public class DbView
    {
        public List<Horse> allHorses { get; set; }
        public List<Player> allPlayers { get; set; }
    }
}