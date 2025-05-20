import unittest
import numpy as np
import math
from vektor import Vector, VectorError


class TestVectors(unittest.TestCase):
    """
    Unittests für den Vector-Datentyp.
    """

    def setUp(self):
        """
        Initialisiere Variablen für den Test.
        """
        self.a = Vector([0, 0, 1])
        self.b = Vector([0, 1, 0])
        self.c = Vector([1, 0, 0])
        self.d = Vector([1, 1, 0])
        self.e = Vector([1, 2, 3])
        self.f = Vector([3, 2, 1])
        self.fn = Vector([-3, -2, -1])
        self.g = Vector([-1, -2, 3])
        self.n = Vector([0, 0, 0])
        self.o = Vector([1, 1, 1])
        self.p = Vector([1, 2])
        self.q = Vector([1, 2, -3, 4])

    def test_01_basics(self):
        """
        Testet Basiseigenschaften - Gleichheit,
        Ausgabe.
        """
        self.assertEqual(self.a, self.a)
        self.assertNotEqual(self.a, self.b)
        self.assertEqual(str(self.e), "<1, 2, 3>")

    def test_02_dims(self):
        """
        Testet Dimensionen und den Umgang mit
        Unterschieden.
        """
        self.assertNotEqual(self.a, self.p)
        self.assertNotEqual(self.p, self.q)
        self.assertNotEqual(self.q, self.p)
        self.assertEqual(len(self.a), 3)
        self.assertEqual(len(self.p), 2)
        self.assertEqual(len(self.q), 4)

    def test_03_bool(self):
        """
        Testet die Umwandlung zu bool.
        """
        self.assertTrue(self.a)
        self.assertTrue(self.b)
        self.assertTrue(self.p)
        self.assertTrue(self.q)
        self.assertFalse(self.n)

    def test_04_addition(self):
        """
        Testet Addition.
        """
        self.assertEqual(self.b + self.c, self.d)
        self.assertEqual(self.f + self.n, self.f)
        self.assertEqual(self.f + self.fn, self.n)
        self.assertEqual(self.a + self.b + self.c, self.o)

    def test_05_subtraction(self):
        """
        Testet Subtraktion.
        """
        self.assertEqual(self.d - self.c, self.b)
        self.assertEqual(self.a - self.a, self.n)
        self.assertEqual(self.f - self.n, self.f)
        self.assertEqual(self.o - self.d, self.a)
        self.assertEqual(self.a - self.b - self.c, self.a - self.d)

    def test_06_negation(self):
        """
        Testet das unäre Minus.
        """
        self.assertEqual(-self.f, self.fn)
        self.assertEqual(-self.fn, self.f)
        self.assertEqual(self.a + -self.a, self.n)
        self.assertEqual(self.f + -self.n, self.f)
        self.assertEqual(self.d + -self.c, self.b)

    def test_07_multiplikation(self):
        """
        Testet Skalarmultiplikation (nicht Skalarprodukt!)
        """
        self.assertEqual(self.a, 1 * self.a)
        self.assertEqual(self.a + self.a, 2 * self.a)
        self.assertEqual(self.f * 2, 2 * self.f)
        self.assertNotEqual(self.a * 2, self.a)
        self.assertEqual(self.a * 0, self.n)

    def test_08_is_zero(self):
        """
        Testet is_zero().
        """
        self.assertFalse(self.a.is_zero())
        self.assertTrue(self.n.is_zero())

    def test_09_norm(self):
        """
        Testet  norm() und Skalarprodukt.
        """
        self.assertEqual(self.a.norm(), 1)
        self.assertEqual(self.b.norm(), 1)
        self.assertEqual(self.c.norm(), 1)
        self.assertEqual(self.a * self.b, 0)
        self.assertEqual(self.a * self.a, 1)
        self.assertAlmostEqual(self.f * self.f, self.f.norm() * self.f.norm())
        self.assertAlmostEqual(self.o * self.o, self.o.norm() * self.o.norm())

    def test_10_similarity_euclid(self):
        """
        Testet Ähnlichkeitsmaß und Abstandsmaße.
        """
        self.assertEqual(self.a.euclid_dist(self.a), 0)
        self.assertAlmostEqual(self.a.euclid_dist(self.b), 1.4142135623730951)
        self.assertAlmostEqual(self.f.euclid_dist(self.fn), 2 * self.f.norm())

    def test_11_similarity_manhattan(self):
        """
        Testet Ähnlichkeitsmaß und Abstandsmaße.
        """
        self.assertEqual(self.a.manhattan_dist(self.a), 0)
        self.assertEqual(self.a.manhattan_dist(self.b), 2)
        self.assertAlmostEqual(self.f.manhattan_dist(self.fn), 12)

    def test_12_similarity_cosine(self):
        """
        Testet Ähnlichkeitsmaß und Abstandsmaße.
        """
        self.assertEqual(self.a.cosine_similarity(self.a), 1)
        self.assertEqual(self.a.cosine_similarity(self.b), 0)
        self.assertAlmostEqual(self.f.cosine_similarity(self.fn), -1)

    def addition_dim_mismatch(self):
        self.p + self.q

    def addition_type_mismatch(self):
        self.p + "Kein Vektor"

    def multiplikation_dim_mismatch(self):
        self.p * self.q

    def cosine_similarity_with_zero(self):
        self.n.cosine_similarity(self.a)

    def test_13_error_handling(self):
        """
        Testet die Fehlerbehandlung
        """
        self.assertRaises(VectorError, self.addition_dim_mismatch)
        self.assertRaises(VectorError, self.addition_type_mismatch)
        self.assertRaises(VectorError, self.multiplikation_dim_mismatch)
        self.assertRaises(VectorError, self.cosine_similarity_with_zero)


if __name__ == '__main__':
    # Durchführung der Tests
    loader = unittest.TestLoader()
    suite = unittest.TestSuite()

    # Hier können einzelne Tests auskommentiert werden
    suite.addTest(TestVectors("test_01_basics"))
    suite.addTest(TestVectors("test_02_dims"))
    suite.addTest(TestVectors("test_03_bool"))
    suite.addTest(TestVectors("test_04_addition"))
    suite.addTest(TestVectors("test_05_subtraction"))
    suite.addTest(TestVectors("test_06_negation"))
    suite.addTest(TestVectors("test_07_multiplikation"))
    suite.addTest(TestVectors("test_08_is_zero"))
    suite.addTest(TestVectors("test_09_norm"))
    suite.addTest(TestVectors("test_10_similarity_euclid"))
    suite.addTest(TestVectors("test_11_similarity_manhattan"))
    suite.addTest(TestVectors("test_12_similarity_cosine"))
    suite.addTest(TestVectors("test_13_error_handling"))

    runner = unittest.TextTestRunner()

    runner.run(suite)
    '''
    print("Hacky unorganised tests ;-)")
    a = Vector([1, 2, 3])
    e = Vector([-7, 2, 1])
    b = Vector([3, 2, 1])
    c = Vector([1, 1, 0])
    d = Vector([0, 0, 1])
    n = Vector([0, 0, 0])
    print(a)
    print(repr(a))
    print(a+b)
    print(a+-a)
    print(a-a)
    print(a-b)
    print(a*a)
    print(a*b)
    print(4*a)
    print(a*4)
    print(a*n)
    print("0*a:", 0*a)
    print(c*d)
    print(a*e)
    print(a.norm())
    print(b.norm())
    print(n.norm())
    print(a.euclid_dist(b))
    print(a.euclid_dist(n))
    print(a.euclid_dist(a))
    print(a.manhattan_dist(b))
    print(a.cosine_similarity(a))
    print(a.cosine_similarity(b))
    print(c.cosine_similarity(d))
    print(c.cosine_similarity(-c))
    print(b.cosine_similarity(-b))
    '''