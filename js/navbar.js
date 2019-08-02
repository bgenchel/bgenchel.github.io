var navbar = $("#mynavbar");
navbar.addClass("navbar navbar-expand navbar-expand-lg");

navbar.html(`
    <a class="navbar-brand" href="#">
        <img src="res/images/8bit-self.png" id="mynavbar-pic">
        <span id="mynavbar-name"></span>
    </a>
    <div class="navbar-nav ml-auto">
        <div class="navbar-holder">
            <a class="navbar-sm-icon" href="http://linkedin.com/in/benjamingenchel">
                <img class="sn-smb" src="css/res/icons/linkedin.svg">
            </a>
            <a class="navbar-sm-icon" href="http://github.com/bgenchel">
                <img class="sn-smb" src="css/res/icons/github.svg"></a>
            </a>
            <a class="navbar-sm-icon" href="http://soundcloud.com/bgenchel">
                <img class="sn-smb" src="css/res/icons/soundcloud.svg">
            </a>
        </div>
        <div id="menubtn-holder" class="navbar-holder" onClick="openNav()">
            <div id="menubtn" class="btn">&#9776;   Menu</div>
        </div>
    </div>
`);

navbar.after(`
    <div id="mySidenav" class="sidenav">
        <a href="javascript:void(0)" class="closebtn" onClick="closeNav()">&times</a>
        <a class="mynavbutton" href="index.html">Home</a>
        <a class="mynavbutton" href="projects.html">Projects</a>
        <a class="mynavbutton" href="sounds.html">Sounds</a>
        <a class="mynavbutton" href="sheets.html">Sheets</a>
        <a class="mynavbutton" href="res/docs/BenjaminGenchel_Resume.pdf" download>Resume</a>
        <a class="mynavbutton" href="contact.html">Contact</a>
    </div>
`);


/* Set the width of the side navigation to 250px */
function openNav() {
  document.getElementById("mySidenav").style.width = "250px";
}

/* Set the width of the side navigation to 0 */
function closeNav() {
  document.getElementById("mySidenav").style.width = "0";
}

$(".breaker").css("height", navbar.outerHeight());
