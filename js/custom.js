
$(document).ready(function() {

    // $(document).on("click", "#fly-with-the-wind-frame", function(e) {
    //     console.log("clicked frame");
    //     $(this).src = "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/293870832&amp;color=#888888&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true";
    // });

    // $(window).scroll(function(e) {
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
    // });

    $("#music-link").mouseenter(function(e) {
        $("#music-links").css("display", "inline-block");
        $("#project-links").css("display", "none");
        if($("#music-link").hasClass("section-link-on")){
            $(".song-link").css("background-color", "#344666");
        } else {
            $(".song-link").css("background-color", "#7f3c05");
        }
    });

    $("#projects-link").mouseenter(function(e) {
        $("#music-links").css("display", "none");
        $("#project-links").css("display", "inline-block");
        if($("#projects-link").hasClass("section-link-on")){
            $(".project-link").css("background-color", "#344666");
        } else {
            $(".project-link").css("background-color", "#230254");
        }
    });

    $("#other-link").mouseenter(function(e) {
        $("#project-links").css("display", "none");
    });

    $("#section-menu").mouseleave(function(e) {
        $("#music-links").css("display", "none");
        $("#project-links").css("display", "none");
    });
});

