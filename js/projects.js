$(document).ready(function() {
    let projects = $("#projects");
    DATA["content"]["items"].forEach(function(item, idx) {
        projects.append(`<div id="project-${idx}"></div>`);
        let project = $(`#project-${idx}`);

        let years = String(item["year"]["begin"]) + ((item["year"]["end"] !== null) ? " - " + String(item["year"]["end"]): "");
        project.append(`
            <div class="item-title"><h3>
                ${item["title"]}<br>(${years})
            </h3></div>
        `);

        project.append(`<div id="project-${idx}-content" class="row item-row"></div>`);
        let projectContent = $(`#project-${idx}-content`);

        if (item["media"] === null) {
            projectContent.append(`
                <div class="col-lg-8 item-col proj-left-col">
                    <p>${item["description"].join("<br><br>")}</p>
                </div>
            `);
            projects.append("<hr>");
            return;
        }

        projectContent.append(`
            <div class="col-lg-6 item-col proj-left-col">
                <p>${item["description"].join("<br><br>")}</p>
            </div>
        `);

        projectContent.append(`<div id="project-${idx}-content-media" class="col-lg-6 item-col">`);
        let pcMedia = $(`#project-${idx}-content-media`);

        let mediaType = item["media"]["type"];
        if (mediaType === "document") {
            for (var i in item["media"]["items"]) {
                pcMedia.append(`
                    <div class="media-holder document-holder">
                        <a href="${item["media"]["download"]}" download>
                            <img class="document" src="${item["media"]["items"][i]}" alt="">
                        </a>
                    </div>
                `);
            }
        }

        if (mediaType === "image") {
            for (var i in item["media"]["items"]) {
                pcMedia.append(`
                    <div class="media-holder image-holder">
                        <img class="image" src="${item["media"]["items"]}" alt="">
                    </div>
                `);
            }
        }

        if (mediaType === "carousel") {
            let cId = `project-${idx}-carousel`;
            pcMedia.append(`
                <div class="media-holder">
                    <div id="${cId}" class="carousel slide" data-ride="carousel">
                        <ol class="carousel-indicators"></ol>
                        <div class="carousel-inner"></div>
                        <a class="carousel-control-prev" href="${cId}" role="button" data-slide="prev"> 
                            <span class="carousel-control-prev-icon" aria-hidden="true"></span> 
                            <span class="sr-only">Previous</span> 
                        </a> 
                        <a class="carousel-control-next" href="#${cId}" role="button" data-slide="next"> 
                            <span class="carousel-control-next-icon" aria-hidden="true"></span> 
                            <span class="sr-only">Next</span> 
                        </a> 
                    </div>
                </div>
            `);
            let indicators = $(`#${cId} .carousel-indicators`);
            let inner = $(`#${cId} .carousel-inner`);
            for (var i in item["media"]["items"]) {
                let cl = i == 0 ? "active" : "";
                indicators.append(`
                    <li data-target="#${cId}" data-slide-to="${i} class="${cl}"></li>
                `);
                inner.append(`
                    <div class="carousel-item ${cl}" style="height: fit-content;">
                        <img class="d-block w-100" src="${item["media"]["items"][i]}" alt="Slide ${i}">
                    </div>
                `);
            }
        }

        if (mediaType == "youtube") {
            for (var i in item["media"]["items"]) {
                pcMedia.append(`
                    <div class="media-holder">
                        <iframe class="youtube-vid" width="504" height="283.5" src="${item["media"]["items"][i]}"
                            frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture"
                            allowfullscreen>
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

        projects.append("<hr>");
    });
});
