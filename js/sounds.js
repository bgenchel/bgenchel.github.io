var injectData = function (section, sectionName, item, idx) {
    section.append(`<div id="${sectionName}-${idx}"></div>`);
    let project = $(`#${sectionName}-${idx}`);

    let years = String(item["year"]["begin"]) + ((item["year"]["end"] !== null) ? " - " + String(item["year"]["end"]): "");
    project.append(`
        <div class="item-title"><h3>
            ${item["title"]}<br>(${years})
        </h3></div>
    `);

    project.append(`<div id="${sectionName}-${idx}-content" class="row item-row"></div>`);
    let projectContent = $(`#${sectionName}-${idx}-content`);

    if (item["media"] === null) {
        projectContent.append(`
            <div class="col-lg-8 item-col description">
                <p>${item["description"].join("<br><br>")}</p>
            </div>
        `);
        project.append("<hr>");
        return;
    }

    projectContent.append(`<div id="${sectionName}-${idx}-content-media" class="col-lg-6 item-col proj-left-col">`);
    let pcMedia = $(`#${sectionName}-${idx}-content-media`);
    let mediaType = item["media"]["type"];

    if (mediaType == "soundcloud") {
        for (var i in item["media"]["items"]) {
            pcMedia.append(`
                <div class="media-holder">
                    <iframe width="100%" height="300" scrolling="no" frameborder="no" allow="autoplay"
                        src=${item["media"]["items"][i]}>
                    </iframe>
                </div>
            `);
        }
    }

    if (mediaType == "spotify") {
        for (var i in item["media"]["items"]) {
            pcMedia.append(`
                <div class="media-holder">
                    <iframe src="${item["media"]["items"][i]}" width="504" height="283.5" 
                        frameborder="0" allowtransparency="true" allow="encrypted-media">
                    </iframe>           
                </div>
            `);
        }
    }

    if (item["media"]["caption"] !== null) {
        pcMedia.append(`<p class="caption">${item["media"]["caption"]}</p>`);
    }

    projectContent.append(`
        <div class="col-lg-6 item-col">
            <p>${item["description"].join("<br><br>")}</p>
        </div>
    `);

    project.append("<hr>");
}

$(document).ready(function() {
    let production = $("#production");
    DATA["production"]["items"].forEach(function(item, idx) {
        injectData(production, "production", item, idx);
    });

    let live = $("#live");
    DATA["livePerformance"]["items"].forEach(function(item, idx) {
        injectData(live, "live", item, idx);
    });
});
