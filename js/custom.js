
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

    //     var musicDiv = $("#music");
    //     var projectsDiv = $("#projects");
    //     var otherDiv = $("#other");
    //     var sectionLinks = $(".section-link");
    //     var windowCenter = $(window).scrollTop() + $(window).height()/2;

    //     var link_id;
    //     if(musicDiv.position().top <= windowCenter && windowCenter <= projectsDiv.position().top){
    //         link_id = "music-link";
    //     } else if(projectsDiv.position().top <= windowCenter  && windowCenter <= otherDiv.position().top){
    //         link_id = "projects-link";
    //     } else if(otherDiv.position().top <= windowCenter){
    //         link_id = "other-link";
    //     }
    //     for(var i = 0; i < sectionLinks.length; i++){
    //         if(sectionLinks[i].id == link_id){
    //             sectionLinks[i].classList.add("section-link-on");
    //         } else {
    //             sectionLinks[i].classList.remove("section-link-on");
    //         }
    //     }

    //     if($("#music-link").hasClass("section-link-on")){
    //         $(".song-link").css("background-color", "#344666");
    //     } else {
    //         $(".song-link").css("background-color", "#7f3c05");
    //     }

    //     if($("#projects-link").hasClass("section-link-on")){
    //         $(".project-link").css("background-color", "#344666");
    //     } else {
    //         $(".project-link").css("background-color", "#230254");
    //     }
    });

    $("#music-link").mouseenter(function(e) {
        $("#music-links").css("display", "inline-block");
        $("#project-links").css("display", "none");
    });

    $("#projects-link").mouseenter(function(e) {
        $("#music-links").css("display", "none");
        $("#project-links").css("display", "inline-block");
    });

    $("#other-link").mouseenter(function(e) {
        $("#project-links").css("display", "none");
    });

    $("#section-menu").mouseleave(function(e) {
        $("#music-links").css("display", "none");
        $("#project-links").css("display", "none");
    });
});

