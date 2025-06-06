<script>
    function calculate() {
    var value1 = Number(document.getElementById("number1").value)
    var value2 = Number(document.getElementById("number2").value)
    var operation = document.getElementById("operation").value
    console.log(value1.valueOf(), value2.valueOf(), operation.valueOf())

    switch (operation) {
    case "add":
    console.log(value1 + value2)
}
}

    calculate();
</script>