using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;
using System.Web.Mvc;

namespace MVCDogSelector.Models
{
    public class Dog
    {
        public string BreedName { get; set; }
        public string DisplayName { get; set; }
        public string ImageName { get; set; }

        [Required(ErrorMessage = "Please fill out this information.")]
        public bool GoodWithChildren { get; set; }
        [Required(ErrorMessage = "Please fill out this information.")]
        public bool Drools { get; set; }
        [Required(ErrorMessage = "Please fill out this information.")]
        public EScale ActivityLevel { get; set; }
        [Required(ErrorMessage = "Please fill out this information.")]
        public EScale SheddingLevel { get; set; }
        [Required(ErrorMessage = "Please fill out this information.")]
        public EScale GroomingLevel { get; set; }
        [Required(ErrorMessage = "Please fill out this information.")]
        public EScale IntelligenceLevel { get; set; }
        [Required(ErrorMessage = "Please fill out this information.")]
        public ELength CoatLength { get; set; }
        public ESize Size { get; set; }
        
    }
    public enum EScale { 
        [Display(Name="Low")]
        Low,
        [Display(Name = "Medium")]
        Medium,
        [Display(Name = "High")]
        High, 
        [Display(Name="No preference")]
        NoPref
    }
    public enum ELength {
        [Display(Name = "Short")]
        Short,
        [Display(Name = "Medium")]
        Medium,
        [Display(Name = "Long")]
        Long 
    }
    public enum ESize
    {
        [Display(Name = "Pocket")]
        Pocket = 0,
        [Display(Name = "Tiny")]
        Tiny = 1,
        [Display(Name = "Miniature")]
        Miniature = 2,
        [Display(Name = "Small")]
        Small = 3,
        [Display(Name = "Medium")]
        Medium = 4,
        [Display(Name = "Large")]
        Large = 5,
        [Display(Name = "")]
        Giant = 6
    }
}