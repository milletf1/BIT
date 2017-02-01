<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Birds.aspx.cs" Inherits="Birds" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html>
<head id="Head1" runat="server">
    <link rel="Stylesheet" type="text/css" href="Styles/home.css" />
    <link rel="Stylesheet" type="text/css" href="Styles/birds.css" />
    <title>Bird Watchers Club</title>
</head>
<body id="Body1" runat="server">
    <div id="container" runat="server">
        <div id="header" runat="server">        
        </div>
        <div id="navBar" runat="server">
            <div id="Div1" class="navLinkElement" runat="server">
                <a class="navLink" href="Default.aspx">Home</a>
            </div>
            <div id="Div2" class="navLinkElement" runat="server">
                <a class="navLink" href="Members.aspx">Members</a>
            </div>
            <div id="Div3" class="navLinkElement" runat="server">
                <a class="navLink" href="Birds.aspx">Birds</a>
            </div>
            <div id="Div4" class="navLinkElement" runat="server">
                <a class="navLink" href="Sightings.aspx">Sightings</a>
            </div>
            <div id="Div5" class="navLinkElement" runat="server">
                <a class="navLink" href="AddSighting.aspx">Add Sighting</a>
            </div>
        </div>
        <div id="formBody" runat="server">
        </div>
    </div>
</body>
</html>
