using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MelbourneCupSweepstakes.Models;
using System.IO;

namespace MelbourneCupSweepstakes.Controllers
{
    /******************************************************************
     * Home Controller for Melbourne Cup Office Sweepstakes assignment.
     * 
     * Created by Tim Miller, 2014. 
     ******************************************************************/
    public class RaceController : Controller
    {
        private const int BET_SIZE = 10;
        private const int HORSE_NAME_INDEX = 0;
        private const int HORSE_PLACE_INDEX = 1;

        private const string RESULTS_PATH = "/Content/results/results.csv";
        private const string VIEW_INDEX = "Index";
        
        private HorseRaceDbContext raceDb = new HorseRaceDbContext();
        
        /// <summary>
        /// Controller method for generating Race Index.
        /// </summary>
        /// <returns>View of Race Index</returns>
        [HttpGet]
        public ActionResult Index()
        {   
            //Get the total Prize pool.
            ViewBag.PrizePool =
                GetHorseTable().FindAll(h => h.PlayerID != null).Count() * BET_SIZE;

            DbView dbView = GetDbView();            
            return View(dbView);
        }//End Index

        /// <summary>
        /// Controller method for performing race and generating the race index.
        /// </summary>
        /// <returns>View of Race Index</returns>
        [HttpGet]
        public ActionResult Race()
        {
            //Determine if the players have been paid.
            int paidPlayers = GetPlayerTable().FindAll(p => p.PrizeMoney > 0).Count();

            //Check the number of paid players.
            if (paidPlayers == 0)
            {
                //If none have been paid, run the race and save the results.
                PerformRace();
                raceDb.SaveChanges();                
            }
            //Get the total Prize pool.
            ViewBag.PrizePool =
                GetHorseTable().FindAll(h => h.PlayerID != null).Count() * BET_SIZE;

            DbView dbView = GetDbView();
            return View(VIEW_INDEX, dbView);
        }//End Race

        /// <summary>
        /// "Performs" the horse race.
        /// </summary>
        private void PerformRace()
        {
            List<Horse> horseTable = GetHorseTable();

            //Set a stream reader to read the results file
            StreamReader sr = new StreamReader(Server.MapPath(RESULTS_PATH));
            
            //Cycle through each line in the results file
            string line;
            while((line  = sr.ReadLine()) != null)
            {
                //Split the current file line into horse name and horse placing.
                string[] horseResult = line.Split(',');

                //Find the horse name from the horse result string array, and set its place to the array value for the horses place.
                horseTable.Find(h => h.Name.CompareTo(horseResult[HORSE_NAME_INDEX]) == 0)
                    .Place = Convert.ToInt16(horseResult[HORSE_PLACE_INDEX]);
            }
            sr.Close();

            //Get a list of all horses that have been bet on.
            List<Horse> horsesBetOn = horseTable.FindAll(h => h.PlayerID != null);

            //Sort the list by place.
            horsesBetOn.Sort();

            //Set the horses and the players payment (horse payment is only the value of the horse).
            PayoutHorses(horsesBetOn);                        
            PayoutPlayers(horsesBetOn);            
        }//End PerformRace

        /// <summary>
        /// Determines what each horse who was bet on pays to their bettor.
        /// </summary>
        /// <param name="horsesBetOn">A list of all horses that had bets.</param>
        private void PayoutHorses(List<Horse> horsesBetOn)
        {
            //Determine the prize pool.
            int prizePool = 10 * horsesBetOn.Count();

            //Set payment value of horse that came first.
            horsesBetOn[0].BetPayout += Convert.ToInt16(.5 * prizePool);

            //Set payment value of horse that came second.
            horsesBetOn[1].BetPayout += Convert.ToInt16(.25 * prizePool);

            //Set payment value of horse that came third.
            horsesBetOn[2].BetPayout += Convert.ToInt16(.15 * prizePool); 

            //Set playment value of horse that came last.
            horsesBetOn[horsesBetOn.Count() -1].BetPayout += Convert.ToInt16(.1 * prizePool);
        }//End PayoutHorses

        /// <summary>
        /// Determines the players who won money from the race result.
        /// </summary>
        /// <param name="horsesBetOn">A list of all horses that had bets.</param>
        private void PayoutPlayers(List<Horse> horsesBetOn)
        {

            //Get a list of all registered players.
            List<Player> playerTable = GetPlayerTable();

            //Determine the prize pool.
            int prizePool = 10 * horsesBetOn.Count();

            //Payout the first place winner.
            playerTable.Find(p => p.PlayerID == horsesBetOn[0].PlayerID).PrizeMoney
                += Convert.ToInt16(.5 * prizePool);

            //Payout the second place winner.
            playerTable.Find(p => p.PlayerID == horsesBetOn[1].PlayerID).PrizeMoney
                += Convert.ToInt16(.25 * prizePool);

            //Payout the third place winner.
            playerTable.Find(p => p.PlayerID == horsesBetOn[2].PlayerID).PrizeMoney
                += Convert.ToInt16(.15 * prizePool);

            //Payout the last place winner.
            playerTable.Find(p => p.PlayerID == horsesBetOn[horsesBetOn.Count() - 1].PlayerID).PrizeMoney
                += Convert.ToInt16(.1 * prizePool);
        }//End PayoutPlayers

        /// <summary>
        /// Returns a View of the players that won money, and the horses that participated in the race
        /// with their finishing position.
        /// </summary>
        /// <returns></returns>
        private DbView GetDbView()
        {
            //Get a list of all horses.
            List<Horse> horseTable = GetHorseTable();
            //Sort by placing.
            horseTable.Sort();

            //Get a list of all players that placed winning bets.
            List<Player> playerTable = GetPlayerTable();
            playerTable.Reverse();
            
            //Create a db view and return it.
            DbView dbView = new DbView
            {
                allHorses = horseTable,
                allPlayers = playerTable,
            };
            return dbView;
        }//End GetDbView

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
