#!/usr/bin/env python

"""Einführung Vektoren

In der Physik sind Vektoren Objekte, die durch eine Länge und eine
Richtung beschrieben werden. In der Mathematik sind Vektoren Elemente
eines Vektorraums. Ein Vektorraum ist eine mathematische Struktur,
konkret eine abelsche Gruppe (von "Vektoren") über einem Körper K (von
"Skalaren"), bei der eine zusätzliche Verknüpfung (die
Skalarmultiplikation) das Verknüpfen von Vektoren und Skalaren
ermöglicht. Für diese Skalarmultiplikation werden zusätzlich
Distributivgesetze und Assoziativgesetz gefordert.

In dieser Vorlesung bewegen wir uns zwischen diesen beiden
Definitionen. Für uns sind Vektoren Elemente von $R^n$, also $n$-Tupel
von reelen Zahlen. Dabei ist $n$ fest - d.h. jeder gegebene Vektorraum
enthält nur Vektoren mit $n$ Elementen.  Die reelen Zahlen R bilden
den Skalarkörper, und sind die zugehörigen Skalare.

Einfache Spezialfälle sind R^2 - dann reden wir über Vektoren in der
Ebene, und R^3 - Vektoren im 3-dimensionalen Raum. Diese beiden Fälle
haben eine Vielzahl von Anwendungen in Technik und Physik.

Wenn wir ein karthesisches Koordinatensystem annehmen, dann
repräsentiert der Vektor <1, 2, 3> die Verschiebung eines Punktes um
eine Einheit in der X-Koordinate, zwei Einheiten in der Y-Koordinate,
und drei Einheiten in der Z-Koordinate.

Analog können Vektoren aber auch selbst als Punkte in Raum
interpretiert werden. Der Übergang zwischen beiden Sichtweisen ist
einfach - der Vektor entspricht dem Punkt, auf dem er den
Koordinatenursprung verschieben würde.

"""

import unittest
import numpy as np
import math


class VectorError(Exception):
    """
    Für eigene Fehler, die mit Vektoren auftreten können.
    """
    pass

# Notes:
# print(0.0 == 0) -> True
# print(vector.__len__()) for Vector([1,2,3]) -> 3
# print(repr(vector)) für repr

# Variablen aus NumPy Array:
# variables = [val for i, val in enumerate(self.vec)]

# Simples printing:
# for value in self.vec:
# print(value)

# technical_str returns:
# [np.int64(-1), np.int64(2), np.int64(3)]


# YOUR CODE HERE
class Vector:
    def __init__(self, vec):
        self.vec = np.array(vec)

    def check_dims(self, other):
        if not isinstance(self, Vector):
            raise VectorError("No Vector")
        if not isinstance(other, Vector):
            raise VectorError("No Vector")
        if self.vec.size != other.vec.size:
            raise VectorError("Vectors aren't the same size!")

    def technical_str(self):
        return [val for i, val in enumerate(self.vec)]

    def __str__(self):
        return f"<{', '.join(str(x) for x in self.vec)}>"

    def __repr__(self):
        return f"Vector({self.vec})"

    def __eq__(self, other):
        return np.all(self.vec == other.vec)

    def __len__(self):
        return self.vec.size

    def __bool__(self):
        for value in self.vec:
            if value != 0:
                return True
        return False
    # Better solution (thx AI): return np.any(self.vec != 0)

    def __neg__(self):
        return Vector(-self.vec)

    def __add__(self, other):
        self.check_dims(other)
        return Vector(self.vec + other.vec)

    def __sub__(self, other):
        self.check_dims(other)
        return Vector(self.vec - other.vec)

    def __mul__(self, other):
        if isinstance(other, Vector):
            raise VectorError("Its a Vector")
        return Vector(self.vec * other)

    def __rmul__(self, other):
        if isinstance(self, Vector):
            raise VectorError("Its a Vector")
        return Vector(other * self.vec)

    def is_zero(self):
        return np.all(self.vec == 0)

    def norm(self):
        # norm = 0
        #
        # for value in self.vec:
        #     norm += value*value
        #
        # return math.sqrt(norm)

        return np.linalg.norm(self.vec)

    def euclid_dist(self, other):
        self.check_dims(other)
        return np.linalg.norm(self.vec - other.vec)

    def manhattan_dist(self, other):
        self.check_dims(other)
        return np.linalg.norm(self.vec - other.vec, ord=1)

    def cosine_similarity(self, other):
        self.check_dims(other)
        return np.dot(self.vec, other.vec) / (np.linalg.norm(self.vec) * np.linalg.norm(other.vec))



print( Vector( [0, 0, 1] ) == Vector ( [0, 1, 0] ) )