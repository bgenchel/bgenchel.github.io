$(document).ready(function() {
    var navbar = $("#mynavbar");
    var page_head = $("#page-head");
    var menubtn_bg = $("#menubtn-bg");

    var navbar_bottom_0 = page_head.offset().top + navbar.height();
    var page_head_bottom = page_head.position().top + page_head.height();
    var full_dist = page_head_bottom - navbar_bottom_0;

    var setNavbarBackground = function(){
        console.log("running setNavbarBackground");
        var curr_navbar_bottom = navbar.offset().top + navbar.height();
        var curr_dist = curr_navbar_bottom - navbar_bottom_0;
        var pct = curr_dist / full_dist;
        console.log('pct: ' + pct);
        if(pct >= 0){
            navbar.css('background-color', 'rgba(0, 0, 0, ' + pct + ')'); 
            menubtn_bg.css("background-color", "rgba(255, 255, 255, " + pct + ")");
        }
    }

    $("#menubtn").hover(function(e) {
        if(e.type === "mouseenter") {
            menubtn_bg.css("opacity", 1);
        } else if(e.type === "mouseleave") {
            menubtn_bg.css("opacity", 0);
        }
    });

    setNavbarBackground();

    $(window).scroll(function(e) {
        setNavbarBackground();
        // if($(window).scrollTop() > page_head_top + page_head_len / 10){;
        //     $("#navbar").addClass(

        // if($(window).scrollTop() >= static_nav_line){
        //     $("#navbar").addClass("static-navbar");
        //     $("#navbar-spacer").height($("#navbar").height());
        // }

        // if($(window).scrollTop() < static_nav_line){
        //     $("#navbar").removeClass("static-navbar");
        //     $("#navbar-spacer").height(0);
        // }
    });
});

