function gallery() {
    if (event.keyCode === 37) {
        console.log("left")
        document.firstElementChild.style.display = "block"
    }
    else if (event.keyCode === 39) {
        console.log("right")
    }
}