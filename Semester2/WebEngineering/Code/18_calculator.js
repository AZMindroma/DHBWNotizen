
function calculate() {
    var value1 = Number(document.getElementById("number1").value)
    var value2 = Number(document.getElementById("number2").value)
    var operation = document.getElementById("operation").value
    console.log(value1.valueOf(), value2.valueOf(), operation.valueOf())

    switch (operation) {
        case "add":
            res = value1 + value2
            break
        case "subtract":
            res = value1 - value2
            break
        case "multiply":
            res = value1 * value2
            break
        case "divide":
            res = value1 / value2
            break
        case "power":
            res = value1 ** value2
            break
        case "sin":
            res = Math.sin(value1)
            break
        case "tan":
            res = Math.tan(value1)
            break
    }
    document.getElementById("result").textContent = "The result is " + res
}

calculate();