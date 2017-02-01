using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MelbourneCupSweepstakes.Models
{
    public class Horse : IComparable
    {
        [Required]
        public int HorseID { get; set; }
        public int? PlayerID { get; set; }
        public int Place { get; set; }
        [Required]
        public string Name { get; set; }
        public int BetPayout { get; set; }

        public virtual Player Player { get; set; }

        //Comparable used to organize the horses by race position
        public int CompareTo(object obj)
        {
            return (this.Place > (obj as Horse).Place) ? 1 : -1;
        }
    }
}