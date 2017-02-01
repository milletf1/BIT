using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Web.UI.HtmlControls;
using System.IO;

public partial class Sightings : System.Web.UI.Page
{
    //Database connection data string.
    private const string CONNECTION =
        "";

    //SQL query to get tblBirdMember.
    private const string GET_BIRD_MEMBERS = "SELECT * FROM dbo.tblBirdMember";

    //SQL query to get the name of the member from the members ID.
    private const string GET_MEMBERS = "SELECT * FROM dbo.tblMember";

    //SQL query to get the english and maori name of the bird from the birds ID.
    private const string GET_BIRDS = "SELECT * FROM dbo.tblBird";

    //Name used to reference the database tables when it is put in the dataset.
    private const string SIGHTINGS_TABLE = "sightings";
    private const string MEMBER_TABLE = "members";
    private const string BIRD_TABLE = "birds";

    //Field names used to retrieve data from the database.
    private const string MEMBER_PK = "memberID";
    private const string BIRD_PK = "birdID";
    private const string MEMBER_FIRST = "firstName";
    private const string MEMBER_LAST = "lastName";
    private const string BIRD_ENGLISH = "englishName";
    private const string BIRD_MAORI = "maoriName";

    //String to specify a div html element.
    private const string DIV = "div";

    //String used to specify an html elements class attribute.
    private const string CLASS_ATTRIBUTE = "class";

    //String used to specify the classes used by the html elements.
    private const string CLASS_SIGHTING_DIV = "sightingDiv";
    private const string CLASS_INNER_DIV = "innerDiv";
    private const string CLASS_BIRD_IMAGE_DIV = "imageDiv birdImageDiv";
    private const string CLASS_MEMBER_IMAGE_DIV = "imageDiv memberImageDiv";
    private const string CLASS_NAME_LABEL = "nameLabel";

    //Image paths.
    private const string MEMBER_IMAGE_URL = "images/generic_user_image.png";
    private const string BIRD_IMAGE_PREFIX = "images/birds/bird";
    private const string BIRD_IMAGE_SUFFIX = ".jpg";

    //placeholder picture used when the birds image is not found. 
    private const string GENERIC_BIRD_IMG = "images/generic_user_image.png";

    //Array slots that hold a birds english and Maori names
    private const int BIRD_ENGLISH_INDEX = 0;
    private const int BIRD_MAORI_INDEX = 1;

    //Width and height of the images.
    private const int IMAGE_SIZE = 130;
    
    //Connection to the database.
    private SqlConnection bitDevConnection;

    //Dictionaries used to reference the birds and members in the database.
    private Dictionary<int, string> memberDictionary;
    private Dictionary<int, string> birdDictionary;

    //The data used to build the page.
    private DataSet dataSet;

    /// <summary>
    /// Page Load event handler.
    /// </summary>
    protected void Page_Load(object sender, EventArgs e)
    {
        //Initialize connection to database.
        InitializeConnection();

        //Store the tblBirdMember table in a dataset.
        dataSet = RetrieveDataSet();
        
        //Create a dictionary of all birds in the database.
        InitializeBirdDictionary();

        //Create a dictionary of all members in the database
        InitializeMemberDictionary();

        //Initialze the html that is returned to the user.
        InitializeHTML();
    }/////////////////////////////////////////////

    /// <summary>
    /// Initializes the web page's dynamic html.
    /// </summary>
    private void InitializeHTML()
    {
        //Cycle through each row in the dataset.
        foreach (DataRow row in dataSet.Tables[SIGHTINGS_TABLE].Rows)
        {
            //Create a div to display the member data in the current row.
            GenerateSightingDiv(row);
        }
    }/////////////////////////////////////////////

    /// <summary>
    /// Creates a div that displays the image of the member, the bird sighted,
    /// the members name, the sighted birds english name, and the sighted birds
    /// Maori name.
    /// </summary>
    /// <param name="row">The table row that contains the key for the bird and the member.</param>
    private void GenerateSightingDiv(DataRow row)
    {
        //Create a div for the member and add it to the html document.
        HtmlGenericControl div = new HtmlGenericControl(DIV);
        div.Attributes[CLASS_ATTRIBUTE] = CLASS_SIGHTING_DIV;
        formBody.Controls.Add(div);

        //Create a div for the members image and add it to the html document.
        HtmlGenericControl memberImageDiv = new HtmlGenericControl(DIV);
        memberImageDiv.Attributes[CLASS_ATTRIBUTE] = CLASS_MEMBER_IMAGE_DIV;

        //Create the image.
        Image memberImage = new Image();
        memberImage.ImageUrl = MEMBER_IMAGE_URL;
        memberImage.Width = IMAGE_SIZE;
        memberImage.Height = IMAGE_SIZE;

        //Add to the div.
        memberImageDiv.Controls.Add(memberImage);
        div.Controls.Add(memberImageDiv);
                
        //Create a div for the birds image and add it to the html document.
        HtmlGenericControl birdImageDiv = new HtmlGenericControl(DIV);
        birdImageDiv.Attributes[CLASS_ATTRIBUTE] = CLASS_BIRD_IMAGE_DIV;


        //Create the bird image. 
        Image birdImage = new Image();

        string imageUrl = BIRD_IMAGE_PREFIX + Convert.ToString(row[BIRD_PK]) + BIRD_IMAGE_SUFFIX;

        //check if the file exists
        if (!File.Exists(Server.MapPath(string.Format(imageUrl))))
        {
            //if it doesn't exist set imageUrl to a placeholder image.
            imageUrl = GENERIC_BIRD_IMG;
        }
        //Add bird image to the bird image div.
        birdImage.ImageUrl = imageUrl;
        birdImage.Height = IMAGE_SIZE;
        birdImage.Width = IMAGE_SIZE;
        birdImageDiv.Controls.Add(birdImage);
        div.Controls.Add(birdImageDiv);

        //Create an inner div to contain the bird and member names.
        HtmlGenericControl innerDiv = new HtmlGenericControl(DIV);
        innerDiv.Attributes[CLASS_ATTRIBUTE] = CLASS_INNER_DIV;
        div.Controls.Add(innerDiv);

        //Write the name of the member who sighted the bird in the inner div.
        Label memberName = new Label();
        memberName.Attributes[CLASS_ATTRIBUTE] = CLASS_NAME_LABEL;
        memberName.Text = memberDictionary[(int)row[MEMBER_PK]];
        innerDiv.Controls.Add(memberName);

        //Write the english and Maori names of the sighted bird.
        Label birdName = new Label();
        birdName.Attributes[CLASS_ATTRIBUTE] = CLASS_NAME_LABEL;
        //split the bird string in the dictionary to its english and Maori names.
        string[] birdNames = birdDictionary[(int)row[BIRD_PK]].Split(':');
        birdName.Text = birdNames[BIRD_ENGLISH_INDEX] + " (" + birdNames[BIRD_MAORI_INDEX] + ")";
        innerDiv.Controls.Add(birdName);
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
            string birdNames = row[BIRD_ENGLISH] + ":" + row[BIRD_MAORI];
            int pk = (int)row[BIRD_PK];

            birdDictionary.Add(pk, birdNames);
        }
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
    /// Retrieves all the tables from the bitdev database.
    /// </summary>
    /// <returns>All bitdev database tables in a dataset.</returns>
    private DataSet RetrieveDataSet()
    {
        //Dataset that gets returned.
        DataSet dataSet = new DataSet();

        //Open the bitdev connection.
        bitDevConnection.Open();

        /******************************************************
         *  Retrieve the tblBirdMember table from the database.
         *****************************************************/

        //SQL query to retrieve the data.
        SqlCommand cmd = new SqlCommand(GET_BIRD_MEMBERS, bitDevConnection);

        //Data adapter used to fill the dataset.
        SqlDataAdapter adapter = new SqlDataAdapter(cmd);

        //Retrieve data from bitdev database.
        adapter.Fill(dataSet, SIGHTINGS_TABLE);

        /*************************************************
         * Retrieve the tblMember table from the database.
         ************************************************/

        //SQL query to retrieve the data.
        cmd = new SqlCommand(GET_MEMBERS, bitDevConnection);

        //Data adapter used to fill the dataset.
        adapter = new SqlDataAdapter(cmd);

        //Retrieve data from bitdev database.
        adapter.Fill(dataSet, MEMBER_TABLE);

        /***********************************************
         * Retrieve the tblBird table from the database.
         **********************************************/

        //SQL query to retrieve the data.
        cmd = new SqlCommand(GET_BIRDS, bitDevConnection);

        //Data adapter used to fill the dataset.
        adapter = new SqlDataAdapter(cmd);

        //Retrieve data from bitdev database.
        adapter.Fill(dataSet, BIRD_TABLE);

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