<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AddSighting.aspx.cs" Inherits="AddSighting" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html>
<head id="Head1" runat="server">
    <link rel="Stylesheet" type="text/css" href="Styles/home.css" />
    <link rel="Stylesheet" type="text/css" href="Styles/add-sighting.css" />
    <title>Add Sighting</title>
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
            <form id="addSightingForm" runat="server">
                <!-- Form Title -->
                <div class="titleWrapper" runat="server">
                    <asp:Label ID="lblTitle" runat="server" class="titleLabel" Text="Enter Sighting"></asp:Label>
                </div>
                <!-- choose member dropdown-->
                <div class="controlWrapper" runat="server">
                    <!-- Label -->
                    <asp:Label ID="chooseMemberLabel" class="nameLabel" runat="server" Text="Choose Member:"></asp:Label>
                    <!-- DropDownList -->
                    <asp:DropDownList ID="memberListDropDown" class="inputFont" runat="server" Width="240px"></asp:DropDownList>
                </div>
                <!-- Radio Button choose bird from list -->
                <div class="controlWrapper" runat="server">
                    <asp:RadioButton ID="rbBirdFromList" class="rButtonStyle" runat="server" Text="Choose Existing Bird." Checked="True" GroupName="birdInputGroup" />
                </div>
                <!-- choose bird drop down -->
                <div class="controlWrapper" runat="server">
                    <!-- Label -->
                    <asp:Label ID="chooseBirdLabel" class="nameLabel" runat="server" Text="Choose Bird:"></asp:Label>
                    <!-- DropDownList -->
                    <asp:DropDownList ID="birdListDropDown" class="inputFont" runat="server" Width="240px"></asp:DropDownList>
                </div>
                <!-- Radio button enter new bird-->
                <div class="controlWrapper" runat="server">
                    <asp:RadioButton ID="rbNewBird" class="rButtonStyle" runat="server" 
                        Text="Enter New Bird (all fields must be filled out)." 
                        GroupName="birdInputGroup" />
                </div>
                <!-- english-->
                <div class="controlWrapper" runat="server">
                    <!-- Label -->
                    <asp:Label ID="birdEnglish" class="nameLabel" runat="server" Text="English name:"></asp:Label>
                    <!-- TextBox -->
                    <asp:TextBox ID="tbBirdEnglish" class="inputFont" runat="server" Width="240px" MaxLength="30"></asp:TextBox>
                </div>
                <!-- maori-->
                <div class="controlWrapper" runat="server">
                    <!-- Label -->
                    <asp:Label ID="birdMaori" class="nameLabel" runat="server" Text="Maori name:"></asp:Label>
                    <!-- TextBox -->
                    <asp:TextBox ID="tbBirdMaori" class="inputFont" runat="server" Width="240px" MaxLength="30"></asp:TextBox>
                </div>
                <!-- scientific-->
                <div class="controlWrapper" runat="server">
                    <!-- Label -->
                    <asp:Label ID="birdScientific" class="nameLabel" runat="server" Text="Scientific name:"></asp:Label>
                    <!-- TextBox -->
                    <asp:TextBox ID="tbBirdScientific" class="inputFont" runat="server" Width="240px" MaxLength="30"></asp:TextBox>
                </div>
                <!-- submit button-->
                <div class="controlWrapper" runat="server">
                    <input type="submit" id="submitBtn" value="submit" runat="server"/>
                </div>
            </form>
        </div>
    </div>
</body>
</html>
