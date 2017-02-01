using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace MelbourneCupSweepstakes.Models
{
    public class DbInit : DropCreateDatabaseAlways<HorseRaceDbContext>
    {
        protected override void Seed(HorseRaceDbContext context)
        {
            BuildHorseTable(context);

            context.SaveChanges();
        }        

        /// <summary>
        /// Seeds the Horses  table in the database.
        /// </summary>
        private void BuildHorseTable(HorseRaceDbContext context)
        {
            var horseList = new List<Horse>
            {
                new Horse {Name="GLASS HARMONIUM", BetPayout=0},
                new Horse {Name="DUNADEN", BetPayout=0},
                new Horse {Name="DRUNKEN SAILOR", BetPayout=0},
                new Horse {Name="MANIGHAR", BetPayout=0},
                new Horse {Name="UNUSUAL SUSPECT", BetPayout=0},
                new Horse {Name="FOX HUNT", BetPayout=0},
                new Horse {Name="LUCAS CRANACH", BetPayout=0},
                new Horse {Name="RED CADEAUX", BetPayout=0},
                new Horse {Name="PRECEDENCE", BetPayout=0},
                new Horse {Name="LOST IN THE MOMENT", BetPayout=0},
                new Horse {Name="AT FIRST SIGHT", BetPayout=0},
                new Horse {Name="NIWOT", BetPayout=0}
            };
            foreach (Horse h in horseList)
            {
                context.Horses.Add(h);
            }
        }
    }
}