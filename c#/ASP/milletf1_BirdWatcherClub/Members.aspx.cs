using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Web.UI.HtmlControls;

/// <summary>
/// Code to generate the Members.aspx page.
/// </summary>
public partial class Members : System.Web.UI.Page
{
    //Database connection data string.
    private const string CONNECTION =
        "";

    //SQL query to get list of members.
    private const string GET_MEMBERS = "SELECT * from dbo.tblMember";
	
	//Name used to reference the members table when it is put in the dataset.
	private const string DATASET_TABLE = "members";
	
	//Field names that hold each members data.
	private const string FIELD_FIRST_NAME = "firstName";
	private const string FIELD_LAST_NAME = "lastName";
	private const string FIELD_SUBURB = "suburb";
	
    //String to specify a div html element.
	private const string DIV = "div";
	
    //String used to specify an html elements class attribute.
	private const string CLASS_ATTRIBUTE = "class";

    //Strings used to specify the classes used by the html elements.
	private const string CLASS_MEMBER_DIV = "memberDiv";
	private const string CLASS_MEMBER_DIV_IMAGE = "memberDivImage";
	private const string CLASS_NAME_LABEL = "nameLabel";	
    private const string CLASS_SUBURB_LABEL = "suburbLabel";

    //Path to the members image. 
	private const string MEMBER_IMAGE_URL = "images/generic_user_image.png";
    
    //Width and height of the members image.
	private const int MEMBER_IMAGE_SIZE = 130;
	
    //Connection to the database.
    private SqlConnection bitDevConnection;

    //The data used to build the page.
    private DataSet dataSet;

    /// <summary>
    /// Page Load event handler.
    /// </summary>
    protected void Page_Load(object sender, EventArgs e)
    {
        //Initialize connection to database.
        InitializeConnection();

        //Store the tblMember table in a dataset.
        dataSet = RetrieveDataSet();

        //Initialze the html that is returned to the user.
        InitializeHTML();
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
            GenerateMemberDiv(row);
        }
    }/////////////////////////////////////////////

    /// <summary>
    /// Retrieves the tblMember table from the bitdev database.
    /// </summary>
    /// <returns>tblMember table as a DataSet.</returns>
    private DataSet RetrieveDataSet()
    {
        //Dataset that gets returned.
        DataSet dataSet = new DataSet();

        //Open the bitdev connection.
        bitDevConnection.Open();

        //SQL query to retrieve the data.
        SqlCommand cmd = new SqlCommand(GET_MEMBERS, bitDevConnection);

        //Data adapter used to fill the dataset.
        SqlDataAdapter mySqlDataAdapter = new SqlDataAdapter(cmd);

        //Retrieve member data from bitdev database.
        mySqlDataAdapter.Fill(dataSet, DATASET_TABLE);

        //Close the bitdev connection.
        bitDevConnection.Close();

        return dataSet;
    }/////////////////////////////////////////////

    /// <summary>
    /// Generates a div that displays the data of a bird watchers club member.
    /// </summary>
    /// <param name="row">The table row that contains the members data.</param>
    private void GenerateMemberDiv(DataRow row)
    {
        //Create a div for the member and add it to the html document.
        HtmlGenericControl div = new HtmlGenericControl(DIV);
        div.Attributes[CLASS_ATTRIBUTE] = CLASS_MEMBER_DIV;
        formBody.Controls.Add(div);

        //Create a div for the members image and add it to the html document.
        HtmlGenericControl imageDiv = new HtmlGenericControl(DIV);
        imageDiv.Attributes[CLASS_ATTRIBUTE] = CLASS_MEMBER_DIV_IMAGE;

        //Add the members image to the div.            
        Image memberImage = new Image();
        memberImage.ImageUrl = MEMBER_IMAGE_URL;
        memberImage.Width = MEMBER_IMAGE_SIZE;
        memberImage.Height = MEMBER_IMAGE_SIZE;
        
        //Add to the html document.
        imageDiv.Controls.Add(memberImage);
        div.Controls.Add(imageDiv);

        //Create a label to display the members name and add it to the html document.
        Label lblName = new Label();
        lblName.Attributes[CLASS_ATTRIBUTE] = CLASS_NAME_LABEL;
        lblName.Text = row[FIELD_FIRST_NAME] + " " + row[FIELD_LAST_NAME];
        div.Controls.Add(lblName);

        //Create a label to display the members suburb and add it to the html document.
        Label lblSuburb = new Label();
        lblSuburb.Attributes[CLASS_ATTRIBUTE] = CLASS_SUBURB_LABEL;
        lblSuburb.Text = row[FIELD_SUBURB].ToString();
        div.Controls.Add(lblSuburb);
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