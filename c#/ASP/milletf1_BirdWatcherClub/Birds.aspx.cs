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

public partial class Birds : System.Web.UI.Page
{
    //Database connection data string.
    private const string CONNECTION =
        "";

    //SQLquery to get list of members.
    private const string GET_BIRDS = "SELECT * from dbo.tblBird";

    //Name used to reference the members table when it is put in the dataset.
    private const string DATASET_TABLE = "birds";

    //Field names that hold each birds data.
    private const string BIRD_ID = "birdID";
    private const string ENGLISH_NAME = "englishName";
    private const string MAORI_NAME = "maoriName";
    private const string SCIENTIFIC_NAME = "scientificName";

    //String to specify a div html element.
    private const string DIV = "div";
    
    //String used to specify an html elements class attribute.
    private const string CLASS_ATTRIBUTE = "class";

    //Strings used to specify the classes used by the html elements.
    private const string CLASS_BIRD_DIV = "birdDiv";
    private const string CLASS_BIRD_DIV_IMAGE = "birdDivImage";
    private const string CLASS_BIRD_INNER = "innerDiv";
    
    //String used to the classes used by the html elements.
    private const string CLASS_NAME_LABEL = "nameLabel";    
    private const string CLASS_HEADER_LABEL = "headerLabel";
    private const string CLASS_FIELD_LABEL = "fieldLabel";

    //String to display the naming types.
    private const string MAORI_HEADER = "Maori Name: ";
    private const string SCIENTIFIC_HEADER = "Scientific Name: ";

    //Path prefix and suffix to the bird images.
    private const string BIRD_IMAGE_PREFIX = "images/birds/bird";
    private const string BIRD_IMAGE_SUFFIX = ".jpg";

    //Width and height of the birds image.
    private const int BIRD_IMAGE_SIZE = 130;

    //placeholder picture used when the birds image is not found. 
    private const string GENERIC_BIRD_IMG = "images/generic_user_image.png";

    //Connection to the database
    private SqlConnection bitDevConnection;

    //The data used to build the page.
    DataSet dataSet;

    /// <summary>
    /// Page Load event handler.
    /// </summary>
    protected void Page_Load(object sender, EventArgs e)
    {
        //Initialize connection to database.
        InitializeConnection();

        //Store the tblBird table in a dataset.
        dataSet = RetrieveDataSet();

        //Initialze the html that is returned to the user.
        InitializeHTML();
    }/////////////////////////////////////////////

    /// <summary>
    /// Initializes the connection to the bitdev database.
    /// </summary>
    private void InitializeConnection()
    {
        bitDevConnection = new SqlConnection();
        bitDevConnection.ConnectionString = CONNECTION;
    }/////////////////////////////////////////////

    /// <summary>
    /// Initializes the web page's dynamic html.
    /// </summary>
    private void InitializeHTML()
    {
        //Cycle through each row in the dataset.
        foreach (DataRow row in dataSet.Tables[DATASET_TABLE].Rows)
        {
            //Create a div to display the member data in the current row.
            GenerateBirdDiv(row);
        }
    }/////////////////////////////////////////////

    /// <summary>
    /// Generates a div that displays the data of a bird.
    /// </summary>
    /// <param name="row">The table row that contains the bird's data.</param>
    private void GenerateBirdDiv(DataRow row)
    {
        //Create a div for the bird and add it to the html document.
        HtmlGenericControl div = new HtmlGenericControl(DIV);
        div.Attributes[CLASS_ATTRIBUTE] = CLASS_BIRD_DIV;
        formBody.Controls.Add(div);

        //Create a div for the birds image and add it to the html document.
        HtmlGenericControl imageDiv = new HtmlGenericControl(DIV);
        imageDiv.Attributes[CLASS_ATTRIBUTE] = CLASS_BIRD_DIV_IMAGE;

        //Add the bird image to the div. 
        Image birdImage = new Image();
        string imageUrl = BIRD_IMAGE_PREFIX + Convert.ToString(row[BIRD_ID]) + BIRD_IMAGE_SUFFIX;
        
        //check if the file exists
        if (!File.Exists(Server.MapPath(string.Format(imageUrl))))
        {
            //if it doesn't exist set imageUrl to a placeholder image.
            imageUrl = GENERIC_BIRD_IMG;
        }
        //Add bird image to the bird image div.
        birdImage.ImageUrl =imageUrl;
        birdImage.Width = BIRD_IMAGE_SIZE;
        birdImage.Height = BIRD_IMAGE_SIZE;
        imageDiv.Controls.Add(birdImage);
        div.Controls.Add(imageDiv);

        //Add the birds name to the div.
        Label lblName = new Label();
        lblName.Attributes[CLASS_ATTRIBUTE] = CLASS_NAME_LABEL;
        lblName.Text = row[ENGLISH_NAME].ToString();
        div.Controls.Add(lblName);

        //Create an inner div to contain general data about the bird.
        HtmlGenericControl innerDiv = new HtmlGenericControl(DIV);
        innerDiv.Attributes[CLASS_ATTRIBUTE] = CLASS_BIRD_INNER;
        div.Controls.Add(innerDiv);
                
        /**************************************
         * Add the birds Maori name to the div.
         *************************************/
        
        //Title.
        Label lblMaoriHeader = new Label();
        lblMaoriHeader.Attributes[CLASS_ATTRIBUTE] = CLASS_HEADER_LABEL;
        lblMaoriHeader.Text = MAORI_HEADER;
        innerDiv.Controls.Add(lblMaoriHeader);
        
        //Name.
        Label lblMaoriName = new Label();
        lblMaoriName.Attributes[CLASS_ATTRIBUTE] = CLASS_FIELD_LABEL;
        lblMaoriName.Text = row[MAORI_NAME].ToString();
        innerDiv.Controls.Add(lblMaoriName);
                
        /*******************************************
         * Add the birds scientific name to the div.
         ******************************************/

        //Title.
        Label lblScientificHeader = new Label();
        lblScientificHeader.Attributes[CLASS_ATTRIBUTE] = CLASS_HEADER_LABEL;
        lblScientificHeader.Text = SCIENTIFIC_HEADER;
        innerDiv.Controls.Add(lblScientificHeader);

        //Title.
        Label lblScientificName = new Label();
        lblScientificName.Attributes[CLASS_ATTRIBUTE] = CLASS_FIELD_LABEL;
        lblScientificName.Text = row[SCIENTIFIC_NAME].ToString();
        innerDiv.Controls.Add(lblScientificName);
    }/////////////////////////////////////////////

    /// <summary>
    /// Retrieves the tblBird table from the bitdev database.
    /// </summary>
    /// <returns>tblBird table as a DataSet.</returns>
    private DataSet RetrieveDataSet()
    {
        //Dataset that gets returned.
        DataSet dataSet = new DataSet();

        //Open the bitdev connection.
        bitDevConnection.Open();

        //SQL query to retrieve the data.
        SqlCommand cmd = new SqlCommand(GET_BIRDS, bitDevConnection);

        //Data adapter used to fill the dataset.
        SqlDataAdapter mySqlDataAdapter = new SqlDataAdapter(cmd);

        //Retrieve bird data from bitdev database.
        mySqlDataAdapter.Fill(dataSet, DATASET_TABLE);

        //Close the bitdev connection.
        bitDevConnection.Close();

        return dataSet;
    }/////////////////////////////////////////////
}