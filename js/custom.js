
$(document).ready(function() {

    // $(document).on("click", "#fly-with-the-wind-frame", function(e) {
    //     console.log("clicked frame");
    //     $(this).src = "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/293870832&amp;color=#888888&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true";
    // });

    $(window).scroll(function(e) {
        var musicDiv = $("#music");
        var codeDiv = $("#code");
        var designDiv = $("#design");
        var sectionLinks = $(".section-link");
        var windowCenter = $(window).scrollTop() + $(window).height()/2;

        var link_id;
        if(musicDiv.position().top <= windowCenter && windowCenter <= codeDiv.position().top){
            link_id = "music-link";
        } else if(codeDiv.position().top <= windowCenter  && windowCenter <= designDiv.position().top){
            link = "code-link";
        } else if(designDiv.position().top <= windowCenter){
            link = "design-link";
        }
        for(var i = 0; i < sectionLinks.length; i++){
            if(sectionLinks[i].id == link_id){
                sectionLinks[i].classList.add("section-link-on");
            } else {
                sectionLinks[i].classList.remove("section-link-on");
            }
        }
    });
});
