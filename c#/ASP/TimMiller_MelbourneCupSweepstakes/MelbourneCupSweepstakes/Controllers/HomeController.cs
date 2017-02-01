using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MelbourneCupSweepstakes.Models;

namespace MelbourneCupSweepstakes.Controllers
{

    /******************************************************************
     * Home Controller for Melbourne Cup Office Sweepstakes assignment.
     * 
     * Created by Tim Miller, 2014. 
     ******************************************************************/
    public class HomeController : Controller
    {
        private const int REG_SPACES = 12;
        private const string VIEW_INDEX = "Index";
        private const string VIEW_CONFIRM_REG = "ConfirmRegistration";
        
        private const string FEEDBACK_NAME = "Name Missing";
        private const string FEEDBACK_EMAIL = "Email missing";
        private const string FEEDBACK_RACE_COMPLETE = "Race has finished";
        private const string FEEDBACK_REG_FULL = "No registration space left";
        private const string FEEDBACK_NEED_HORSES = "Waiting for players to register";
        
        private const string BTN_SUBMIT_STRING = "Submit";

        private HorseRaceDbContext raceDb = new HorseRaceDbContext();

        /// <summary>
        /// Returns the "Home" Page.
        /// </summary>
        /// <returns>See summary</returns>
        [HttpGet]
        public ActionResult Index()
        {
            //Get a view of the database (all data from all tables).
            DbView dbView = GetDbView();

            ProcessIndex();

            //Return the Index view with the database view model
            return View(dbView);
        }//End HttpGet Index.

        /// <summary>
        /// Checks if all the horses have been bet on.
        /// </summary>
        /// <returns>true if there are no more horses left to bet on, otherwise false.</returns>
        private bool RegistrationFull()
        {
            int freeHorses = GetHorseTable().FindAll(x => x.PlayerID != null).Count();
            bool rBool = freeHorses == REG_SPACES;
            return rBool;
        }//End RegistrationFull.
        
        /// <summary>
        /// Checks how many horses have placed.
        /// </summary>
        /// <returns>true if any horses have got a placing better than default(0), otherwise false.</returns>
        private bool RaceDone()
        {
            return GetHorseTable().FindAll(h => h.Place > 0).Count() > 0;
        }//End RaceDone.

        /// <summary>
        /// Returns a Select list that holds the number of horses the player can bet on.
        /// </summary>
        /// <returns>See summary.</returns>
        private List<SelectListItem> GetBetSelectList()
        {
            List<Horse> horseTable = GetHorseTable();
            List<SelectListItem> myList = new List<SelectListItem>();
            SelectListItem newItem;

            //get a count of how many horses are still available to be bet on
            int freeHorses  = horseTable.FindAll(x => x.PlayerID == null).Count();

            //Check if the amount of free horses equals or exceeds the max bet limit.
            if (freeHorses > 2)
                //Set freeHorses to 3 for the dropdown list (3 is the max bet limit).
                freeHorses = 3;            
            //Check if there are no free horses left.
            else if (freeHorses == 0)
            {
                //if all the horses have been bet on, set the select list to null and return it
                myList = null;
                return myList;
            }
            //Cycle through each free horse(bet number).
            for (int i = 1; i <= freeHorses; i++)
            {
                //Create a select list item and add it to the select list.
                string betNumToString = Convert.ToString(i);
                newItem = new SelectListItem { Text = betNumToString, Value = betNumToString };
                myList.Add(newItem);
            }
            //Set the first item in the select list to selected.
            myList[0].Selected = true;

            return myList;
        }//End GetBetSelectList.

        /// <summary>
        /// Returns a View of the tables in the database.
        /// </summary>
        /// <returns></returns>
        private DbView GetDbView()
        {
            //Get a list of all horses in the database.
            List<Horse> horseTable = GetHorseTable();

            //Get a list of all players in the database.
            List<Player> playerTable = GetPlayerTable();

            //Put these lists in a DbView object.
            DbView dbView = new DbView
            {
                allHorses = horseTable,
                allPlayers = playerTable,
            };
            return dbView;
        }//End GetDbView.

        /// <summary>
        /// Processes the player signup form on the home page.
        /// </summary>
        /// <param name="playerName">The name of the player.</param>
        /// <param name="playerEmail">The players email.</param>
        /// <param name="numBets">the number of horses the player is betting on.</param>
        /// <returns>Either the confirm registration page, or the home page if the user hasn't filled out
        /// the signup form.</returns>
        [HttpPost]
        public ActionResult Index(string playerName, string playerEmail, string numBets, string prizeMoney)
        {
            string view = "";

            //Initialize a DbView.
            DbView dbView = GetDbView();

            //Check that the user entered the required data, and is not already registered as a player.
            if (DataEnteredCorrectly(playerName, playerEmail) && 
                !PlayerAlreadyInDb(playerName, playerEmail))
                //If the check passes, set the view to the Confirm Registration page.
                view = VIEW_CONFIRM_REG;
            else
                //If it didn't, set the view to Index.
                view = VIEW_INDEX;
                            
            //Check if the post data has failed (which would set view to Index).
            if (view.CompareTo(VIEW_INDEX) == 0)
            {                
                //Create the bets select item list.
                ViewBag.numBets = GetBetSelectList();

                //Check if there are enough horses to start a race and provide feedback if needed.
                SetHorseBetFeedback();

                //Return Index view.
                return View(view, dbView);
            }
            else
            {
                //If the post data passed the previous checks, create a new player...
                Player regPlayer = BuildPlayer(playerName, playerEmail, numBets);

                //and return it with the ConfirmRegistration view.
                return View(view, regPlayer);  
            }
        }//End HttpPost Index.

        /// <summary>
        /// Creates and returns a new Player object
        /// </summary>
        /// <param name="playerName">The name of the player.</param>
        /// <param name="playerEmail">The player's email.</param>
        /// <param name="numBets">The number of bets placed by the player</param>
        /// <returns>See summary.</returns>
        private Player BuildPlayer(string playerName, string playerEmail, string numBets)
        {
            //Create a new Player.
            Player regPlayer = new Player();

            //Set the new player's attributes.
            regPlayer.Name = playerName;
            regPlayer.EmailAddress = playerEmail;
            regPlayer.TotalBets = Convert.ToInt16(numBets);
            regPlayer.PrizeMoney = 0;

            return regPlayer;
        }//End BuildPlayer.

        /// <summary>
        /// Check if the user filled out all the required details in the sign-up form.
        /// Provides feedback if they didn't.
        /// </summary>
        /// <param name="playerName">The player's name.</param>
        /// <param name="playerEmail">The player's email.</param>
        /// <returns>The result of the check (true/false).</returns>
        private bool DataEnteredCorrectly(string playerName, string playerEmail)
        {
            bool rBool = true;

            //Check that the user has entered a name.
            if (String.IsNullOrEmpty(playerName))
            {
                //Set name missing feedback in the View Bag.
                ViewBag.NameFeedback = FEEDBACK_NAME;
                rBool = false;
            }
            //Check that the user has entered an email address.
            if (String.IsNullOrEmpty(playerEmail))
            {
                //Set email missing feedback in the View Bag.
                ViewBag.EmailFeedback = FEEDBACK_EMAIL;
                rBool = false;
            }
            return rBool;
        }//End DataEnteredCorrectly.

        /// <summary>
        /// Processes the result of the player's confirmation of registration.
        /// Adds the player to the database if needed.
        /// </summary>
        /// <param name="p">The Player object that holds the player's details.</param>
        /// <param name="submit">The button result.  Determines if the player gets added to the database.</param>
        /// <returns>the Index view.</returns>
        public ActionResult ConfirmProcess(Player p, string submit)
        {
            //Error checking to prevent the player being re-entered into the database 
            //when the user clicks on refresh after submission
            bool playerInDb = PlayerAlreadyInDb(p.Name, p.EmailAddress);

            //Check if they clicked the submit button...   
            if (submit.CompareTo(BTN_SUBMIT_STRING) == 0 && !playerInDb)
            {                
                //if they did, add the user to the database.
                raceDb.Players.Add(p);
                raceDb.SaveChanges();

                //Get the player's primary key and use that to randomly assign the horse's 
                //the player bets on.
                int playerID = GetPlayerID(p);
                SelectRandomHorses(playerID, p.TotalBets);                
            }

            ProcessIndex();
            //Get the database view and the bets select item list.
            DbView dbView = GetDbView();
            

            return View(VIEW_INDEX, dbView);
        }//End ConfirmProcess
        
        /// <summary>
        /// processes the data for the Home/Index page.
        /// Includes setting feedback data, setting max number of bets allowed for the signup form,
        /// and pairs the horse to it's bettor.
        /// </summary>
        private void ProcessIndex()
        {
            //Check if the race has been completed.
            if (RaceDone())
            {
                //If it has, use the viewbag to provide feedback
                ViewBag.NoSignupMessage = FEEDBACK_RACE_COMPLETE;
                ViewBag.RaceCompleted = true;
            }
            //Check if the registration is full.
            else if (RegistrationFull())
            {
                ViewBag.NoSignupMessage = FEEDBACK_REG_FULL;
            }
            //If the race hasn't been completed, build the bet select list and check 
            //if their are enough horses bet on to start the race.
            else
            {
                //Get a select list of the number of bets a player can place.
                ViewBag.numBets = GetBetSelectList();

                //Check if there are enough horses to start a race and provide feedback if needed.
                SetHorseBetFeedback();
            }
            //Check if there are enough horses to start a race and provide feedback if needed.
            SetHorseBetFeedback(); ;
        }//End ProcessIndex

        /// <summary>
        /// Sets feedback to display to the user that their are not enough bets placed 
        /// to run the race.
        /// </summary>
        private void SetHorseBetFeedback()
        {
            //Determine the total number of bets that have been placed.
            int totalBets = raceDb.Horses.ToList().FindAll(h => h.PlayerID != null).Count();

            //Check if enough bets have been placed to allow a race to be run.
            if (totalBets < 3)
                ViewBag.notEnoughHorses = FEEDBACK_NEED_HORSES;
        }//End SetHorseBetFeedback

        /// <summary>
        /// Finds and returns a player's primary key.
        /// </summary>
        /// <param name="p">The search player.</param>
        /// <returns>See summary.</returns>
        private int GetPlayerID(Player p)
        {
            //Find and return the player's primary key.
            return (from player in raceDb.Players
                    where player.Name.CompareTo(p.Name) == 0
                    && player.EmailAddress.CompareTo(p.EmailAddress) == 0
                    select player.PlayerID
                    ).FirstOrDefault();
        }//End GetPlayerID.


        /// <summary>
        /// Checks if a given player exists in the database.
        /// </summary>
        /// <param name="p">The search player.</param>
        /// <returns>The search result (true/false)</returns>
        private bool PlayerAlreadyInDb(string playerName, string playerEmail)
        {
            //Find and return the status of the player search.
            return GetPlayerTable().FindAll(
                player => player.Name.CompareTo(playerName) == 0 &&
                player.EmailAddress.CompareTo(playerEmail) == 0
                ).Count() == 1;
        }//End PlayerAlreadyInDb.


        /// <summary>
        /// Selects a number of random horses and assigns them a betting player's primary key.
        /// </summary>
        /// <param name="playerID">The bettor's primary key.</param>
        /// <param name="numBets">The total number of horses to select.</param>
        private void SelectRandomHorses(int playerID, int numBets)
        {
            Random r = new Random();

            //Cycle through each net number.
            for (int i = 0; i < numBets; i++)
            {
                //Get a list of all the currently free horses.
                List<Horse> freeHorses = raceDb.Horses.Where(h => h.PlayerID == null).ToList();

                //Choose a random horse from the given list...
                int pick = r.Next(freeHorses.Count());
                
                //and set it's PlayerID foreign key to the given primary key.
                freeHorses[pick].PlayerID = playerID;
                System.Diagnostics.Debug.WriteLine(freeHorses[pick].Name);

                raceDb.SaveChanges();
            }
        }//End SelectRandomHorses

        /// <summary>
        /// Gets a list of all horses in the database.
        /// </summary>
        /// <returns>See summary.</returns>
        private List<Horse> GetHorseTable()
        {
            return raceDb.Horses.ToList();
        }//End GetHorseTable

        /// <summary>
        /// Gets a list of all players in the database.
        /// </summary>
        /// <returns>See summary.</returns>
        private List<Player> GetPlayerTable()
        {
            return raceDb.Players.ToList();
        }//End GetPlayerTable
    }
}
