import numpy as np
import math



###Aus Kapitel 4###

class VectorError(Exception):

    """
    Für eigene Fehler, die mit Vektoren auftreten können.
    """
    pass

class Vector:
    """
    Diese Klasse repräsentiert einfache Vektoren.
    """
    def __init__(self, vec):
        self.vec = np.array(vec)
        self.length = len(vec)

    def __eq__(self, other):
         """
         Teste, ob zwei Vektoren gleich sind.
         """
         if type(self)!=type(other):
             return False
         if self.length != other.length:
             return False
         for i in range(self.length):
             if self.vec[i]!=other.vec[i]:
                 return False
         return True

    def __str__(self):
        """
        Konvertiere einen Vector in einen zur Ausgabe geeigneten
        String.
        """
        return "<"+", ".join([str(i) for i in self.vec])+">"

    def __repr__(self):
        """
        Konvertiere Vector in eine eindeutige String-Repräsentation.
        """
        return "Vector("+str(self.vec)+")"


    def check_compat(self, other):
        if type(self)!=type(other):
            raise VectorError("Both arguments need to be vectors")
        if self.length != other.length:
            raise VectorError("Both arguments need to be the same length")

    def __bool__(self):
        """
        Nur der 0-Vector ist "False"
        """
        for i in self.vec:
            if i!=0:
                return True
        return False

    def __len__(self):
        """
        Dimension des Vektors, nicht geometrische Länge.
        """
        return self.length

    def __neg__(self):
        """
        Negiere einen Vektor, d.h. berechne das inverse Element in
        Bezug auf die Addition.
        """
        return Vector([-i for i in self.vec])

    def __add__(self, other):
        """
        Vektoren werden komponentenweise addiert.
        """
        self.check_compat(other)
        return Vector([self.vec[i]+other.vec[i] for i in range(len(self))])

    def __sub__(self, other):
        """
        Subtraktion ist einfach Addition mit dem negierten Vektor.
        """
        return self+ -other

    def skalar_multiplication(self, skalar):
        """Skaliere einen Vektor

        Multiplikation zwischen Vektor und Skalar.
        """
        return Vector([i*skalar for i in self.vec])

    def inner_product(self, vector):
        """Skalarprodukt oder inneres Produkt.

        Multipliziere zwei Vektoren, gibt einen Skalar zurück.
        """
        self.check_compat(vector)
        return sum([self.vec[i]*vector.vec[i] for i in
                    range(len(self))])

    def cross_product(self, vector):
        """Keuzprodukte gibt es nur im R^3, die implementieren wir
        nicht.
        """
        return NotImplementedError

    def __mul__(self, other):
        """
        Multiplikation geht mit Skalar und Vektor - Matrizen machen
        wir später.
        """
        if type(other)==type(self):
            return self.inner_product(other)
        elif type(other) in [type(1), type(1.0)]:
            return self.skalar_multiplication(other)
        return NotImplementedError

    def __rmul__(self, other):
        """
        ...wir können Skalare auch von vorne anmultiplizieren. Bei
        Vektor-Vektor-Operationen hat automatisch __mul__() Vorrang.
        """
        return self*other

    def __getitem__(self, key):
        return self.vec[key].item()

    def is_zero(self):
        for i in self.vec:
            if i != 0:
                return False
        return True

    def norm(self):
        """
        Die (euklidsche) Länge des Vektors.
        """
        s = sum([x*x for x in self.vec])
        return math.sqrt(s)

    def euclid_dist(self, other):
        """
        Euklidscher Abstand zwischen zwei Vektoren.
        """
        self.check_compat(other)
        return (self-other).norm()

    def manhattan_dist(self, other):
        """
        Abstand zweier Vektoren in der Manhattan-Metrik.
        """
        self.check_compat(other)
        return sum([abs(self.vec[i]-other.vec[i]) for i in range(self.length)])

    def cosine_similarity(self, other):
        """
        Kosinus-Ähnlichkeit (cos() des Winkels zwischen den Vektoren -
        1 heißt paralell, 0 heisst orthogonal, -1 heißt antiparallel.
        """
        if self.is_zero() or other.is_zero():
            raise VectorError("Cosine similarity is only defined for two non-zero-vectors")
        return self.inner_product(other)/(self.norm()*other.norm())

### SOLUTION END



###Aus Kapitel 5###

class MatrixError(Exception):

    """
    Für eigene Fehler, die mit Matrizen auftreten können.
    """
    pass

def zero_2d_array(m, n):
    res = np.zeros(m*n,dtype='float64')
    return res.reshape(m,n)





class Matrix:
    """
    Diese Klasse repräsentiert einfache Vektoren.
    """
    def __init__(self, data):
        """Konstruktor der Matrix-Klasse

        Wir stützen uns auf np.ndarray(). Um die üblichen
        Python-Konventionen auszunutzen, laufen unsere Indices von
        [0..m-1] und [0..n-1]. Das muss bei allen Algorithmen
        berücksichtigt werden, spielt aber zum Glück nirgendwo
        eine große Rolle.
        """
        if(type(data)==type(self)):
            data = data.matrix
        try:
            self.matrix = np.array(data, dtype='float64')
        except ValueError:
            raise MatrixError("Data for a matrix must be compatible with a 2d float64 ndaary, e.g. a list of lists of integers")
        if self.matrix.ndim != 2:
            raise MatrixError("Data for a matrix must be two-dimensional only")

    def __eq__(self, other):
         """
         Teste, ob zwei Matrizen gleich sind.
         """
         return np.array_equal(self.matrix, other.matrix)

    def __str__(self):
        """Nutzer-freundliche Ausgabe.

        """
        return str(self.matrix)

    def __repr__(self):
        """Eindeutige String-Repräsentation

        Konvertiere Matrix in eine eindeutige
        String-Repräsentation.

        """
        return "Matrix("+str(self.matrix)+")"


# Platz für Ihren Code (Aufgabe Basisoperationen)

### SOLUTION BEGIN

    def get_type(self):
        """Typ ist (m,n) für eine mxn Matrix.

        """
        return self.matrix.shape

    def get_row_no(self):
        """Anzahl der Zeilen ('m')

        """
        return self.matrix.shape[0]

    def get_col_no(self):
        """Anzahl der Spalten ('n')

        """
        return self.matrix.shape[1]

    def get_row_view(self,i):
        """Returns view of the ith row of the matrix.
        """
        return self.matrix[i,:]

    def get_col_view(self,i):
        """Returns view of the ith column of the matrix.
        """
        return self.matrix[:,i]

    def get_value_at(self,col,row):
        """Returns the value at column and row
        """
        return self.matrix[row,col]

    def is_zero(self):
        """Sind alle Matrixelemente 0?
        """
        return np.all(self.matrix==0)

    def transpose(self):
        """Berechne die transponierte Matrix.
        """
        res = [self.get_col_view(i) for i in range(self.get_col_no())]
        return Matrix(res)

### SOLUTION END

# Platz für Ihren Code (Aufgabe Matrizenalgebra)

### SOLUTION BEGIN
    def check_type(self, other):
        if type(self)!=type(other):
            raise MatrixError("Both arguments need to be matrices")
        if self.get_type() != other.get_type():
            raise MatrixError("Both arguments need to be the same type")

    def __neg__(self):
        """
        Negiere die Matrix, d.h. berechne das inverse Element in
        Bezug auf die Addition.
        """
        return Matrix(self.matrix*-1)

    def __add__(self, other):
        """
        Matrizen werden komponentenweise addiert.
        """
        self.check_type(other)
        return Matrix(self.matrix+other.matrix)

    def __sub__(self, other):
        """
        Subtraktion ist einfach Addition mit der negierten Matrix.
        """
        self.check_type(other)
        return self+ -other

    def skalar_multiplication(self, skalar):
        """Multiplikation zwischen Skalar und Matrix

        Multiplikation zwischen Vektor und Skalar.
        """
        return Matrix(self.matrix*skalar)

    def matrix_mul(self,other):
        """Multipliziere zwei Matrizen.
        """

        if self.get_col_no()!=other.get_row_no():
            raise MatrixError("Matrices are not compatible for multiplication")
        res = zero_2d_array(self.get_row_no(), other.get_col_no())
        for i in range(self.get_row_no()):
            for j in range(other.get_col_no()):
                res[i,j] = sum(self.get_row_view(i)*other.get_col_view(j))
        return Matrix(res)

    def __mul__(self, other):
        """
        Multiplikation geht mit Skalar und Matrix.
        """
        if type(other)==type(self):
            return self.matrix_mul(other)
        elif type(other) in [type(1), type(1.0)]:
            return self.skalar_multiplication(other)
        raise MatrixError

    def __rmul__(self, other):
        """
        ...wir können Skalare auch von vorne anmultiplizieren. Bei
        Matrix-Matrix-Operationen hat automatisch __mul__() Vorrang.
        """
        return self*other
        
    def __getitem__(self, key):
        key1, key2 = key
        return self.matrix[key1, key2].item()

### SOLUTION END

# Platz für Ihren Code (Aufgabe Determinatenberechnung)

### SOLUTION BEGIN

    def reduce_by_row(self, row):
        """Entferne eine Zeile.

        Erzeugt neue Matrix ohne den angegebenen Zeilenvektor.
        """
        sel=[x for x in range(self.get_row_no()) if x!=row]
        return Matrix(self.matrix[sel, :])

    def reduce_by_col(self, col):
        """Entferne eine Spalte.

        Erzeugt neue Matrix ohne den angegebenen Spaltenvektor.
        """
        sel=[x for x in range(self.get_col_no()) if x!=col]
        return Matrix(self.matrix[:, sel])


    def compute_determinant_simple(self):
        """Berechne Determinate

        Verwendet den Determinaten-Entwicklungssatz zunächst mit
        fester Entwicklung nach der ersten Zeile.
        """
        print(self)
        if self.get_row_no()!=self.get_col_no():
            raise MatrixError("Determinants are only defined on square matrices")

        if self.get_row_no()==1:
            return self.matrix[0,0]
        row0 = self.get_row_view(0)
        rest = self.reduce_by_row(0)
        res = 0
        for i in range(self.get_col_no()):
            submatrix = rest.reduce_by_col(i)
            res += ((-1)**i)*row0[i]*submatrix.compute_determinant_simple()
        return res

### SOLUTION END

# Platz für Ihren Code (Aufgabe Gaußscher Eleminationsalgorithmus)

### SOLUTION BEGIN

    ################################################################
    # Die folgenden Methoden sind destruktiv, d.h. sie modifizieren
    # die ursprüngliche Matrix!
    ################################################################

    def mult_row(self, row, scalar):
        """ Multiplziere selektierte Zeile mit dem Skalar
        """
        self.matrix[row,:]  = self.get_row_view(row)*scalar

    def mult_col(self, col, scalar):
        """ Multiplziere selektierte Spalte mit dem Skalar
        """
        self.matrix[:,col] = self.get_col_view(col)*scalar

    def swap_rows(self, row1, row2):
        """Vertausche zwei Zeilen der Matrix
        """
        tmp = np.array(self.get_row_view(row1))
        self.matrix[row1,:] = self.get_row_view(row2)
        self.matrix[row2,:] = tmp

    def add_to_row(self, target, source, scalar):
        """Add a multiple of one row to another.
        Adds scalar*source row to target row.
        """
        self.matrix[target,:] = self.get_row_view(target)+\
            scalar*self.get_row_view(source)

    def find_pivot_row(self, i):
        cand = i
        for j in range(i+1, self.get_row_no()):
            if abs(self.matrix[j,i]) > abs(self.matrix[cand,i]):
                cand = j
        return cand

    def gaussian_elimination(self):
        """Convertiert eine Matrix in Stufenform.

        Verwendet den Gausschen Eliminationalgrithmus mit
        Zeilenpivotisierung, um eine Matrix in Dreiecksform zu
        bringen. Diese einfache Variante garantiert
        Stufenform nur für Matrizen mit unabhängigen
        Zeilenvektoren.
        """
        sign = 1
        for i in range(self.get_row_no()):
            pivot = self.find_pivot_row(i)
            if pivot != i:
                self.swap_rows(pivot,i)
                sign = sign*-1

            if self.matrix[i,i] == 0:
                # Alle Einträge der aktuellen Spalte müssen schon 0
                # sein -> soweit sind wir fertig
                pass
            else:
                for j in range(i+1, self.get_row_no()):
                    self.add_to_row(j, i, -self.matrix[j,i]/self.matrix[i,i])
                    # Should be unnecessary, but lets avoid
                    # rounding errors:
                    self.matrix[j,i] = 0
        return sign

    def main_diag_product(self):
        """Berechne das Produkt der Hauptdiagonalen-Einträge.
        """
        res = 1
        for i in range(min(self.get_row_no(), self.get_col_no())):
            res = res*self.matrix[i,i]
        return res

    def compute_determinant_gauss(self):
        """Berechne die Determinante über obere Dreiecksmatrix.
        """
        if self.get_row_no()!=self.get_col_no():
            raise MatrixError("Determinants are only defined on square matrices")
        sign = self.gaussian_elimination()
        return sign*self.main_diag_product()

### SOLUTION END