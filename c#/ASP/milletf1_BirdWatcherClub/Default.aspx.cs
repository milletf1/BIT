using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;

/// <summary>
/// Code to generate the home page of the BIT Bird Watchers club.
/// </summary>
public partial class _Default : System.Web.UI.Page
{
    //path to the txt file that contains the home page's welcome message
    private const string MSG_WELCOME_PATH = "Text Files/Welcome.txt";

    /// <summary>
    /// Page Load event handler.
    /// </summary>
    protected void Page_Load(object sender, EventArgs e)
    {
        //Display a welcome message.
        DisplayWelcomeMessage();
    }/////////////////////////////////////////////

    /// <summary>
    /// Displays the welcome message on the home page.
    /// </summary>
    private void DisplayWelcomeMessage()
    {
        //Create a stream reader to read the welcome message text file.
        StreamReader sr = new StreamReader(Server.MapPath(MSG_WELCOME_PATH));

        //Put the text from the welcome message text file in a string variable.
        string message = sr.ReadToEnd();
        sr.Close();

        //Display the welcome message.
        formBody.InnerHtml = message;
    }/////////////////////////////////////////////
}
