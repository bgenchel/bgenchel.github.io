$(document).ready(function() {
    var navbar = $("#mynavbar");
    var navbarName = $("#mynavbar-name");
    var page_head = $("#page-head");
    // var menubtn_bg = $("#menubtn-bg");

    var navbar_bottom_0 = page_head.offset().top + navbar.height();
    var page_head_bottom = page_head.position().top + page_head.height();
    var full_dist = page_head_bottom - navbar_bottom_0;

    var setNavbarBackground = function(){
        var curr_navbar_bottom = navbar.offset().top + navbar.height();
        var curr_dist = curr_navbar_bottom - navbar_bottom_0;
        var pct = curr_dist / full_dist;
        if(pct >= 0){
            navbar.css('background-color', 'rgba(0, 0, 0, ' + pct + ')'); 
            navbarName.css('opacity', pct);
            // menubtn_bg.css("background-color", "rgba(255, 255, 255, " + pct + ")");
        }
    }

//     $("#menubtn").hover(function(e) {
//         if(e.type === "mouseenter") {
//             menubtn_bg.css("opacity", 1);
//         } else if(e.type === "mouseleave") {
//             menubtn_bg.css("opacity", 0);
//         }
//     });

    setNavbarBackground();
    $(window).scroll(function(e) {
        setNavbarBackground();
    });

    $("#breaker").css("height", $("#mynavbar").outerHeight());

    $("#go-down-arrow").click(function() {
        $([document.documentElement, document.body]).animate({
            scrollTop: $("#breaker").offset().top
        }, 1000);
    });

    DATA["carousel"]["items"].forEach(function(element, index) {
        let indicatorClasses, imageClasses;
        if (index === 0) {
            indicatorClasses = "active";
            imageClasses = "carousel-item carousel-image active";
        } else {
            indicatorClasses = "";
            imageClasses = "carousel-item";
        }
        $("#slideshow-indicators").append(`
            <li data-target="#carouselExampleIndicators" data-slide-to="${index}" class="${indicatorClasses}"></li>
        `);

        $("#slideshow-images").append(`
            <div id="carousel-${index + 1}" class="${imageClasses}">
                <div class="carousel-item-bg" style="background-image: url('${element["image"]}')"></div>
                <div class="carousel-caption d-none d-md-block my-carousel-caption">
                    <p><i>${element["title"]}<br>${element["location"]}<br>${element["year"]}</i></p>
                </div>
            </div>
        `)
    });

    $("#bio").html(DATA["about_me"]["text"]);
});

