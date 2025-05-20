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


# Platz für Ihren Code

# YOUR CODE HERE
class Vector:
    def __init__(self, vec):
        self.vec = np.array(vec)

    def __str__(self):
        return f"<{', '.join(str(x) for x in self.vec)}>"

    def __repr__(self):
        return f"Vector({self.vec})"

    #def __bool__(self):
    def __eq__(self, other):
        return (self.vec == other.vec).all()

    def __len__(self):
        return self.vec.size

vector = Vector([1,2,3])
vector2 = Vector([1,2,3])