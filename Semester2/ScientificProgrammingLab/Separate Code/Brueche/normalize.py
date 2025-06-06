def gcd(a, b):
    """
    Berechne den größten gemeinsamen Teiler (greatest common divisor)
    von zwei positiven Ganzzahlen mit dem Algorithmus von Euklid.
    """
    if a == 0:
        return b
    if b == 0:
        return a
    c = a - b

    if a < 0:
        a = a * -1
    if b < 0:
        b = b * -1
    if c < 0:
        c = c * -1

    if a <= b:
        return gcd(c, a)
    else:
        return gcd(c, b)

def normalize(inputNumerator, inputDenominator):
    gcdValue = gcd(inputNumerator, inputDenominator)

    if gcdValue != 1:
        inputNumerator = inputNumerator / gcdValue
        inputDenominator = inputDenominator / gcdValue

    if inputDenominator < 0 and inputNumerator > 0:
        inputDenominator *= -1
        inputNumerator *= -1
    if inputDenominator < 0 and inputNumerator < 0:
        inputDenominator *= -1
        inputNumerator *= -1

    return inputNumerator, inputDenominator

numerator, denominator = normalize(5,10)
print(numerator)
print(denominator)
