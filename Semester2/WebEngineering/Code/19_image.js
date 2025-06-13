let currentIndex = 1;
const totalImages = 8;

function showImage(index) {
    for (let i = 1; i <= totalImages; i++) {
        document.getElementById(i + "_" + getImageName(i)).style.display = (i === index) ? "block" : "none";
    }
}

function getImageName(index) {
    const names = [
        "chrys",
        "desert",
        "hydra",
        "jellyfish",
        "koala",
        "lighthouse",
        "penguins",
        "tulips"
    ];
    return names[index - 1];
}

function gallery(event) {
    if (event.keyCode === 37) { // Left arrow
        currentIndex = (currentIndex === 1) ? totalImages : currentIndex - 1;
        showImage(currentIndex);
    } else if (event.keyCode === 39) { // Right arrow
        currentIndex = (currentIndex === totalImages) ? 1 : currentIndex + 1;
        showImage(currentIndex);
    }
}

// Show the first image on load
window.onload = function() {
    showImage(currentIndex);
};

// Attach the event listener to the document
document.body.onkeydown = gallery;