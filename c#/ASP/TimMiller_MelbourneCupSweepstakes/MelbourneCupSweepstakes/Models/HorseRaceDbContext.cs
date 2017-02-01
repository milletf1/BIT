using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace MelbourneCupSweepstakes.Models
{
    public class HorseRaceDbContext : DbContext
    {
        public DbSet<Horse> Horses { get; set; }
        public DbSet<Player> Players { get; set; }
    }
}