using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Web.UI.HtmlControls;
using System.Text.RegularExpressions;

public partial class AddSighting : System.Web.UI.Page
{
    //Database connection data string.
    private const string CONNECTION =
        "";

    

    //Sql queries used to retrieve and create rows.
    private const string GET_BIRD_TABLE = "SELECT * FROM dbo.tblBird";
    private const string GET_MEMBER_TABLE = "SELECT * FROM dbo.tblMember";
    private const string ADD_SIGHTING = "INSERT INTO dbo.tblBirdMember(memberID, birdID ) VALUES(";
    private const string ADD_BIRD = "INSERT INTO dbo.tblBird(englishName, maoriName, scientificName) VALUES('";
    private const string SELECT_NEW_BIRD = "SELECT birdID FROM dbo.tblBird WHERE englishName ='";

    private const string CHECK_BIRD_1 = "SELECT * FROM dbo.tblBird WHERE englishName = '";
    private const string CHECK_BIRD_2 = "' OR maoriName = '";
    private const string CHECK_BIRD_3 = "' OR scientificName = '";

    //Field names used to reference data in the database and dataset.
    private const string MEMBER_PK = "memberID";
    private const string BIRD_PK = "birdID";
    private const string MEMBER_FIRST = "firstName";
    private const string MEMBER_LAST = "lastName";
    private const string BIRD_ENGLISH = "englishName";
    private const string BIRD_MAORI = "maoriName";
    private const string BIRD_SCIENTIFIC = "scientificName";
        
    //Strings used to specify the dropdown boxes text and value fields
    private const string DATA_TEXT_FIELD = "Value";
    private const string DATA_VALUE_FIELD = "Key";

   
    //Connection to the database.
    private SqlConnection bitDevConnection;

    //Regular expression to check if the user has entered a valid bird name.
    private Regex textCheck = new Regex("^[a-zA-Z ]*$");

    //The data used to build the page.
    DataSet dataSet;

    //The name of the tables as stored in the data set
    private const string BIRD_TABLE = "bird";
    private const string MEMBER_TABLE = "member";

    //Dictionaries used to reference the birds and members in the database.
    private Dictionary<int, string> memberDictionary;
    private Dictionary<int, string> birdDictionary;

    /// <summary>
    /// Page Load event handler.
    /// </summary>
    protected void Page_Load(object sender, EventArgs e)
    {
        PageInit();

        //Check if the page has been rendered already.
        if (!IsPostBack)

            //Bind the dictionary entries to the drop down boxes.
            AddDataToDropDownBoxes();
        else
            //Add a new sighting.
            AddNewSighting();       
    }/////////////////////////////////////////////

    /// <summary>
    /// 
    /// </summary>
    private void PageInit()
    {
        //Initialize connection to database.
        InitializeConnection();

        //Store the tblBirdMember table in a dataset.
        dataSet = RetrieveDataSet();

        //Create a dictionary of all members in the database
        InitializeMemberDictionary();

        //Create a dictionary of all birds in the database.
        InitializeBirdDictionary();
    }/////////////////////////////////////////////

    /// <summary>
    /// Adds data to the dropdown boxes on the page.
    /// </summary>
    private void AddDataToDropDownBoxes()
    {
        //Set and bind the member list dropdown box data.
        memberListDropDown.DataSource = memberDictionary.Values;
        memberListDropDown.DataBind();

        //Set and bind the bird list dropdown box data.
        birdListDropDown.DataSource = birdDictionary.Values;
        birdListDropDown.DataBind();
    }/////////////////////////////////////////////

    /// <summary>
    /// Adds a new bird sighting to the database.
    /// </summary>
    private void AddNewSighting()
    {
        int birdKey;

        //Get the name of the selected member.
        string selectedMember = memberListDropDown.SelectedValue;
        
        //Get the members primary key value.
        int memberKey = memberDictionary.FirstOrDefault(x => x.Value.CompareTo(selectedMember) == 0).Key;
       
        /*************************************
         * Determine the checked radio button.
         ************************************/

        //Choose a bird from list radio button.
        if (rbBirdFromList.Checked)
        {
            //Get the name of the bird from the bird dropdown box selected value.
            string selectedBird = birdListDropDown.SelectedValue;

            //Get the selected birds primary key from the bird dictionary.
            birdKey = birdDictionary.FirstOrDefault(x => x.Value.CompareTo(selectedBird) == 0).Key;

            //Add the bird sighting to the database and redirect to the sightings page.
            AddSightingToDB(memberKey, birdKey);
            Response.Redirect("Sightings.aspx");
        }
        //Enter a new bird value.
        else
        {
            //Run a method to add a new bird to the database. Will return true if it gets entered.
            if (AddBirdToDataBase())
            {
                //Get the new birds primary key (needs its own method since it's not in the dictionary).
                birdKey = GetNewBirdPK();

                //Add the bird sighting to the database and redirect to the sightings page.
                AddSightingToDB(memberKey, birdKey);
                Response.Redirect("Sightings.aspx");
            }            
        }       
    }/////////////////////////////////////////////

    /// <summary>
    /// Adds a new bird sighting to the database.
    /// </summary>
    /// <param name="memberKey">The primary key of the sighting member.</param>
    /// <param name="birdKey">The primary key of the sighted bird.</param>
    private void AddSightingToDB(int memberKey, int birdKey)
    {
        //Sql command used to enter the bird into the database.
        string sqlCommand = ADD_SIGHTING + Convert.ToString(memberKey) + "," + Convert.ToString(birdKey) + ")";

        //Open database connection.
        bitDevConnection.Open();

        //Add sighting to database.
        SqlCommand cmd = new SqlCommand(sqlCommand, bitDevConnection);
        cmd.ExecuteNonQuery();

        //Close database connection.
        bitDevConnection.Close();
    }/////////////////////////////////////////////

    /// <summary>
    /// Gets the primary key of a bird that has just been stored in the database.
    /// </summary>
    /// <returns>The new birds primary key.</returns>
    private int GetNewBirdPK()
    {
        int birdPK;

        //The bird's english name.
        string englishName = tbBirdEnglish.Text;

        //Sql query to retrieve the birds primary key.
        string sqlQuery = SELECT_NEW_BIRD + englishName + "'";

        //Open database connection.
        bitDevConnection.Open();

        //Get the bird's primary key and store as an integer.
        SqlCommand cmd = new SqlCommand(sqlQuery, bitDevConnection);
        birdPK = Convert.ToInt16(cmd.ExecuteScalar());

        //Close the connection to the database.
        bitDevConnection.Close();

        return birdPK;
    }/////////////////////////////////////////////

    /// <summary>
    /// Adds a new bird to the database.
    /// </summary>
    /// <returns>A boolean value indicating wether the new bird was to the database or not.</returns>
    private bool AddBirdToDataBase()
    {
        //store the text from the text boxes in string variables.
        string englishName = tbBirdEnglish.Text;
        string maoriName = tbBirdMaori.Text;
        string scientificName = tbBirdScientific.Text;

        //Check that the given names match the textCheck regex.
        bool addBird = CheckTextFields(englishName, maoriName, scientificName);   

        //Check that none of the given names are already in the database.
        if(BirdInDatabase(englishName, maoriName, scientificName))
            addBird = false;
        
        //If birdAdded is true by this stage, add it to the database.
        if (addBird)
        {
            //Sql command to enter the new bird into the database.
            string sqlQuery = ADD_BIRD + englishName + "','" + maoriName + "','" + scientificName + "')";
            
            bitDevConnection.Open();
            
            //Add the new bird row to the database.
            SqlCommand cmd = new SqlCommand(sqlQuery, bitDevConnection);
            cmd.ExecuteNonQuery();
            
            bitDevConnection.Close();
        }
        return addBird;
    }/////////////////////////////////////////////

    /// <summary>
    /// Checks that the text entered by the user passes the textCheck regex when the 
    /// user chooses to add a sighting for a new bird.
    /// </summary>
    /// <param name="englishName">The bird's english name.</param>
    /// <param name="maoriName">The bird's Maori name.</param>
    /// <param name="scientificName">The birds scientific name.</param>
    /// <returns>a boolean value indicating wether the names passed or not.</returns>
    private bool CheckTextFields(string englishName, string maoriName, string scientificName)
    {
        bool textFieldsOK = true;
        
        /**********************************************************************
         * Check that each string matches the TEXT_CHECK regex and isn't empty.
         *********************************************************************/

        //English name.
        if (!textCheck.IsMatch(englishName) || englishName.Length == 0)
            textFieldsOK = false;
        //Maori name.
        else if (!textCheck.IsMatch(maoriName) || maoriName.Length == 0)
            textFieldsOK = false;
        //Scientific name.
        else if (!textCheck.IsMatch(scientificName) || scientificName.Length == 0)
            textFieldsOK = false;

        return textFieldsOK;
    }/////////////////////////////////////////////

    /// <summary>
    /// Checks wether the given bird names are already stored in the database.
    /// </summary>
    /// <param name="englishName">The bird's english name.</param>
    /// <param name="maoriName">The bird's Maori name.</param>
    /// <param name="scientificName">The birds scientific name.</param>
    /// <returns>a boolean value indicating wether the names are present or not.</returns>
    private bool BirdInDatabase(string englishName, string maoriName, string scientificName)
    {        
        //Sql query to count the amount of birds that share any of the given names.
        string sqlQuery = CHECK_BIRD_1 + englishName + CHECK_BIRD_2 + maoriName + CHECK_BIRD_3 + scientificName + "'";

        bitDevConnection.Open();

        //Perform the query.
        SqlCommand cmd = new SqlCommand(sqlQuery, bitDevConnection);
        
        //Store the returned count as an int.
        int count = Convert.ToInt16(cmd.ExecuteScalar());

        //Set the return boolean to false if count is greater than 0.
        bool birdInDatabase = (count > 0)? true : false;

        bitDevConnection.Close();

        return birdInDatabase;
    }/////////////////////////////////////////////
    
    /// <summary>
    /// Creates a dictionary of every member in the database.
    /// </summary>
    private void InitializeMemberDictionary()
    {
        memberDictionary = new Dictionary<int, string>();

        //Cycle through the member table dataset, adding member data to the dictionary.
        foreach (DataRow row in dataSet.Tables[MEMBER_TABLE].Rows)
        {
            string memberName = row[MEMBER_FIRST] + " " + row[MEMBER_LAST];
            int pk = (int)row[MEMBER_PK];

            memberDictionary.Add(pk, memberName);
        }
    }/////////////////////////////////////////////

    /// <summary>
    /// Creates a dictionary of every bird in the database.
    /// </summary>
    private void InitializeBirdDictionary()
    {
        birdDictionary = new Dictionary<int, string>();

        //Cycle through the bird table dataset, adding bird data to the dictionary.
        foreach (DataRow row in dataSet.Tables[BIRD_TABLE].Rows)
        {
            string birdName = (string)row[BIRD_ENGLISH];
            int pk = (int)row[BIRD_PK];

            birdDictionary.Add(pk, birdName);
        }
    }/////////////////////////////////////////////

    /// <summary>
    /// Retrieves the tblBird and tblMember tables from the bitdev database.
    /// </summary>
    /// <returns>tblMember and tblBird tables in a DataSet.</returns>
    private DataSet RetrieveDataSet()
    {
        //Dataset that gets returned.
        DataSet dataSet = new DataSet();

        //Open the bitdev connection.
        bitDevConnection.Open();

        /******************************************
         * Get the tblBird table from the database.
         *****************************************/

        //SQL query to retrieve the data.
        SqlCommand cmd = new SqlCommand(GET_BIRD_TABLE, bitDevConnection);

        //Data adapter used to fill the dataset.
        SqlDataAdapter adapter = new SqlDataAdapter(cmd);

        //Retrieve bird data from bitdev database.
        adapter.Fill(dataSet, BIRD_TABLE);

        /********************************************
         * Get the tblMember table from the database.
         *******************************************/
        
        //SQL query to retrieve the data.
        cmd = new SqlCommand(GET_MEMBER_TABLE, bitDevConnection);

        //Data adapter used to fill the dataset.
        adapter = new SqlDataAdapter(cmd);

        //Retrieve bird data from bitdev database.
        adapter.Fill(dataSet, MEMBER_TABLE);

        //Close the bitdev connection.
        bitDevConnection.Close();

        return dataSet;
    }/////////////////////////////////////////////

    /// <summary>
    /// Initializes the connection to the bitdev database.
    /// </summary>
    private void InitializeConnection()
    {
        bitDevConnection = new SqlConnection();
        bitDevConnection.ConnectionString = CONNECTION;
    }/////////////////////////////////////////////
}