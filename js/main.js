$(document).ready(function() {
    var static_nav_line = $("#navbar").position().top;
    $(window).scroll(function(e) {
        if($(window).scrollTop() >= static_nav_line){
            $("#navbar").addClass("static-navbar");
            $("#navbar-spacer").height($("#navbar").height());
        }

        if($(window).scrollTop() < static_nav_line){
            $("#navbar").removeClass("static-navbar");
            $("#navbar-spacer").height(0);
        }
    });
});

