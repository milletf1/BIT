using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MelbourneCupSweepstakes.Models
{
    public class Player : IComparable
    {
        public int PlayerID { get; set; }
        [Required]
        public string Name { get; set; }
        [Required]
        public string EmailAddress { get; set; }
        public int PrizeMoney { get; set; }
        public int TotalBets { get; set; }
        public virtual List<Horse> Horses { get; set; }

        //Comparable used to organize the player's by prize money won.
        public int CompareTo(object obj)
        {
            return (this.PrizeMoney > (obj as Player).PrizeMoney) ? 1 : -1;
        }
    }
}