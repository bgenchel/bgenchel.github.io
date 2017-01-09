$(document).ready(function() {
    // alert(
    //     "This is a long page! To navigate quickly, use the menu floating at the bottom of the page. Hovering" \
    //     "over (or tapping on mobile) the individual section buttons reveals menus for hopping through" \
    //     "subsections"
    // );

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

    $(".section-link-buffer").mouseenter(function(e) {
        $("#music-links").css("display", "none");
        $("#project-links").css("display", "none");
    });

    $("#section-menu").mouseleave(function(e) {
        $("#music-links").css("display", "none");
        $("#project-links").css("display", "none");
    });
});

