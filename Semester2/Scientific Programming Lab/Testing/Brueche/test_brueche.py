# !/usr/bin/env python

"""Dieses Modul implementiert (exakte) Bruchzahlen.

Bruchzahlen bestehen aus zwei Komponenten, dem Zähler z und dem Nenner
n (Englisch: "numerator" und "denominator", und haben die Form
z/n. Der Wert von z ist eine beliebige ganze Zahl, n ist eine positive
Ganzzahl. In normalisierter Darstellung sind Zähler und Nenner
teilerfremd, d.h. der Bruch kann nicht weiter gekürzt werden.

Bruchzahlen können addiert, subtrahiert, multipliziert und dividiert
werden. Für Addition und Subtraktion müssen sie dazu auf einen
gemeinsamen Nenner gebracht werden (durch Erweitern), danach wieder
normalisiert. Multiplikation kann direkt ausgeführt werden, das
Ergebnis muss aber auch wieder normalisiert werden. Division ist
Multiplikation mit dem Kehrwert.
"""

import unittest
import re
from brueche import Fraction, gcd, FractionError

# Tests in der Reihenfolge, wie sie programmiert sind, ausführen
unittest.TestLoader.sortTestMethodsUsing = None

# Platz für Ihren Code

# YOUR CODE HERE
# raise NotImplementedError()

class TestFractions(unittest.TestCase):
    """
    Unittests für den Bruchzahl-Datentyp.
    """

    def setUp(self):
        """
        Initialisiere Variablen für den Test.
        """
        self.m = Fraction(2, 4)
        self.n = Fraction(2, 5)
        self.o = Fraction(0, 100)
        self.p = Fraction(-13, 2)

    def test_01_numerator_denominator(self):
        """
        Teste, ob Zähler und Nenner richtig gesetzt sind.
        """
        self.assertEqual(self.n.get_numerator(), 2)
        self.assertEqual(self.n.get_denominator(), 5)
        self.assertEqual(self.p.get_numerator(), -13)
        self.assertEqual(self.p.get_denominator(), 2)

    def test_02_numerator_denominator_normalized(self):
        """
        Teste, ob Zähler und Nenner richtig gesetzt und normalisiert sind.
        """
        self.assertEqual(self.m.get_numerator(), 1)
        self.assertEqual(self.m.get_denominator(), 2)
        self.assertEqual(self.o.get_numerator(), 0)
        self.assertEqual(self.o.get_denominator(), 1)

    def in_normalform(self, fraction):
        """
        Hilfsmethode (KEIN TEST): Teste, ob eine Bruchzahl in Normalform ist.
        """
        self.assertTrue(fraction.get_denominator() > 0)
        self.assertEqual(gcd(abs(fraction.get_numerator()),
                             fraction.get_denominator()), 1)

    def test_03_testd_creation(self):
        """
        Teste, ob Bruchzahlen richtig erzeugt wurden und Fehlerfälle
        abgefangen werden.
        """
        self.in_normalform(self.n)
        self.in_normalform(self.m)
        self.in_normalform(self.o)
        self.in_normalform(self.p)

        testflag = False
        try:
            nogood = Fraction(1, 0)
        except FractionError as err:
            testflag = True

        self.assertTrue(testflag)

    def test_04_test_output(self):
        self.assertEqual("Fraction(2,5)", repr(self.n))
        self.assertEqual("Fraction(1,2)", repr(self.m))
        self.assertEqual("Fraction(0,1)", repr(self.o))
        self.assertEqual("Fraction(-13,2)", repr(self.p))
        self.assertEqual("2/5", str(self.n))
        self.assertEqual("1/2", str(self.m))
        self.assertEqual("0/1", str(self.o))
        self.assertEqual("-13/2", str(self.p))

    def test_05_equal(self):
        self.assertTrue(self.m == self.m)
        self.assertTrue(self.n == self.n)
        self.assertTrue(self.o == self.o)
        self.assertTrue(self.p == self.p)

        self.assertFalse(self.m == self.n)
        self.assertFalse(self.n == self.o)
        self.assertFalse(self.o == self.p)
        self.assertFalse(self.p == self.m)

    # Achtung: Alle tests mit assertEqual funktionieren nur, wenn Fraction auch __eq__ implementiert hat (test_05)

    def test_06_addition(self):
        self.assertEqual(self.n + self.m, Fraction(9, 10))

        # Addition sollte die Ursprungswerte nicht verändern
        self.assertEqual(self.n.get_numerator(), 2)
        self.assertEqual(self.n.get_denominator(), 5)
        self.assertEqual(self.m.get_numerator(), 1)
        self.assertEqual(self.m.get_denominator(), 2)

        self.assertEqual(self.n + self.n, Fraction(4, 5))
        self.assertEqual(self.n + self.o, Fraction(2, 5))
        self.assertEqual(self.m + self.p, Fraction(-12, 2))

    def test_07_subtraction(self):
        self.assertEqual(self.n - self.n, Fraction(0, 1))
        self.assertEqual(self.n - self.m, Fraction(-1, 10))
        self.assertEqual(self.n - self.o, Fraction(2, 5))
        self.assertEqual(self.m - self.p, Fraction(14, 2))

    def test_08_multiplication(self):
        self.assertEqual(self.n * self.n, Fraction(4, 25))
        self.assertEqual(self.n * self.m, Fraction(4, 20))
        self.assertEqual(self.n * self.o, Fraction(0, 1))
        self.assertEqual(self.m * self.p, Fraction(-13, 4))

    def test_09_reciprocal(self):
        self.assertEqual(self.m.reciprocal(), Fraction(4, 2))
        self.assertEqual(self.p.reciprocal(), Fraction(-2, 13))

    def test_10_division(self):
        self.assertEqual(self.n / self.n, Fraction(1, 1))
        self.assertEqual(self.n / self.m, Fraction(4, 5))

        testflag = False
        try:
            res = self.n / self.o
        except FractionError as err:
            testflag = True
        self.assertTrue(testflag)

        self.assertEqual(self.m / self.p, Fraction(-1, 13))

    def test_11_comparison(self):
        self.assertTrue(self.m <= self.m)
        self.assertTrue(self.n <= self.n)
        self.assertTrue(self.o <= self.o)
        self.assertTrue(self.p <= self.p)

        self.assertTrue(self.m >= self.m)
        self.assertTrue(self.n >= self.n)
        self.assertTrue(self.o >= self.o)
        self.assertTrue(self.p >= self.p)

        self.assertTrue(self.m > self.n)
        self.assertTrue(self.n > self.o)
        self.assertTrue(self.o > self.p)

        self.assertTrue(self.n < self.m)
        self.assertTrue(self.o < self.n)
        self.assertTrue(self.p < self.o)

    def test_12_bool(self):
        self.assertTrue(self.m)
        self.assertTrue(self.n)
        self.assertFalse(self.o)
        self.assertTrue(self.p)

    def test_13_float_conversion(self):
        self.assertEqual(float(Fraction(2, 1)), 2.0)
        self.assertEqual(float(Fraction(1, 2)), 0.5)
        self.assertEqual(float(Fraction(0, 9)), 0)

    def test_14_misc(self):
        self.assertEqual(-self.m, Fraction(-1, 1) * self.m)


# Durchführung der Tests
loader = unittest.TestLoader()
suite = unittest.TestSuite()

# Hier können einzelne Tests auskommentiert werden
suite.addTest(TestFractions("test_01_numerator_denominator"))
suite.addTest(TestFractions("test_02_numerator_denominator_normalized"))
suite.addTest(TestFractions("test_03_testd_creation"))
suite.addTest(TestFractions("test_04_test_output"))
suite.addTest(TestFractions("test_05_equal"))
suite.addTest(TestFractions("test_06_addition"))
suite.addTest(TestFractions("test_07_subtraction"))
suite.addTest(TestFractions("test_08_multiplication"))
suite.addTest(TestFractions("test_09_reciprocal"))
suite.addTest(TestFractions("test_10_division"))
suite.addTest(TestFractions("test_11_comparison"))
suite.addTest(TestFractions("test_12_bool"))
suite.addTest(TestFractions("test_13_float_conversion"))
suite.addTest(TestFractions("test_14_misc"))

runner = unittest.TextTestRunner()
runner.run(suite)



