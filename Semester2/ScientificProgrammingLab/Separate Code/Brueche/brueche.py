class FractionError(Exception):
    """
    Für eigene Fehler, die mit Bruchzahlen auftreten können.
    """
    pass

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


class Fraction:
    def __init__(self, numerator, denominator):
        self.numerator = numerator
        self.denominator = denominator

        gcd_value = gcd(self.numerator, self.denominator)

        if gcd_value != 1:
            self.numerator //= gcd_value
            self.denominator //= gcd_value

        if self.denominator < 0:
            self.denominator *= -1
            self.numerator *= -1

        if self.numerator == 0:
            self.denominator = 1

        if self.denominator == 0:
            raise FractionError("Denominator cannot be zero")

    def get_numerator(self):
        return self.numerator

    def get_denominator(self):
        return self.denominator

    def __repr__(self):
        return f"Fraction({self.numerator},{self.denominator})"

    def __str__(self):
        return f"{self.numerator}/{self.denominator}"

    def reciprocal(self):
        return Fraction(self.denominator, self.numerator)

    def same_denominator(self, self_numerator, self_denominator, other_numerator, other_denominator):
        if self_denominator != other_denominator:
            new_self_numerator = self_numerator * other_denominator
            new_other_numerator = other_numerator * self_denominator

            new_denominator = self_denominator * other_denominator

            return new_self_numerator, new_other_numerator, new_denominator
        else:
            return self_numerator, other_numerator, self_denominator

    def __lt__(self, other):
        new_self_numerator, new_other_numerator, new_denominator = self.same_denominator(self.numerator, self.denominator, other.numerator, other.denominator)
        return new_self_numerator < new_other_numerator

    def __le__(self, other):
        new_self_numerator, new_other_numerator, new_denominator = self.same_denominator(self.numerator, self.denominator, other.numerator, other.denominator)
        return new_self_numerator <= new_other_numerator

    def __gt__(self, other):
        new_self_numerator, new_other_numerator, new_denominator = self.same_denominator(self.numerator, self.denominator, other.numerator, other.denominator)
        return new_self_numerator > new_other_numerator

    def __ge__(self, other):
        new_self_numerator, new_other_numerator, new_denominator = self.same_denominator(self.numerator, self.denominator, other.numerator, other.denominator)
        return new_self_numerator >= new_other_numerator

    def __eq__(self, other):
        return self.numerator == other.numerator and self.denominator == other.denominator

    def __add__(self, other):
        new_self_numerator, new_other_numerator, new_denominator = self.same_denominator(self.numerator, self.denominator, other.numerator, other.denominator)

        result_numerator = new_self_numerator + new_other_numerator
        result_denominator = new_denominator

        return Fraction(result_numerator, result_denominator)

    def __sub__(self, other):
        new_self_numerator, new_other_numerator, new_denominator = self.same_denominator(self.numerator, self.denominator, other.numerator, other.denominator)

        result_numerator = new_self_numerator - new_other_numerator
        result_denominator = new_denominator

        return Fraction(result_numerator, result_denominator)

    def __mul__(self, other):
        result_numerator = self.numerator * other.numerator
        result_denominator = self.denominator * other.denominator

        return Fraction(result_numerator, result_denominator)

    def __truediv__(self, other):
        result_numerator = self.numerator * other.reciprocal().numerator
        result_denominator = self.denominator * other.reciprocal().denominator

        return Fraction(result_numerator, result_denominator)

    def __bool__(self):
        return self.numerator != 0

    def __float__(self):
        return float(self.numerator) / float(self.denominator)

    def __neg__(self):
        return Fraction(-self.numerator, self.denominator)
