## Grundbegriffe Mengen
### Definition 2.2 (Mächtigkeit)
|M| --> Anzahl der Elemente von M aka: Wie viele Elemente sind in M drin?
|{a, b, c}|  
  1   2  3
  --> |{a, b, c}| = 3

|ℕ| = |ℤ| = |ℚ| < |ℝ| (es sind genauso viele Elemente in den natürlichen Zahlen wie in den ganzen und rationalen Zahlen (unendlich), aber in den reellen Zahlen sind noch mehr als unendlich Elemente drin.)

### Definition 2.3 (Teilmenge)
Eine Menge M1 heißt Teilmenge von M2 (M1 ⊆ M2), wenn für alle x ∈ M1 auch x ∈ M2 gilt.
#### Beispiele:
Die natürlichen Zahlen sind eine Teilmenge von den reellen Zahlen, da für alle natürlichen Zahlen gilt, dass sie auch reelle Zahlen sind. 
**(ℕ ⊆ ℝ)**

Die Menge {3, 5, 8, 4} ist eine Teilmenge von {1, 3, 4, 5, 7, 8, 9}, da alle Elemente von {3, 5, 8, 4} in {1, 3, 4, 5, 7, 8, 9} vorhanden sind. 
**({3, 5, 8, 4} ⊆ {1, 3, 4, 5, 7, 8, 9})**

Aber {3, 5, 8, 4} ist keine Teilmenge von {1, 4, 5, 7, 8, 9}, da die 3 von der ersten Menge nicht in der zweiten Menge vorhanden ist und deswegen nicht für alle x ∈ {3, 5, 8, 4} auch x ∈ {1, 4, 5, 7, 8, 9} gilt. 
**({3, 5, 8, 4} ⊈ {1, 4, 5, 7, 8, 9})**

### Definition 2.4 (Mengengleichheit)
Zwei Mengen M1 und M2 sind einander gleich (M1 = M2), wenn für alle Elemente x gilt: x ∈ M1 gdw. x ∈ M2, d.h. wenn M1 und M2 die gleichen Elemente enthalten.

Es gilt: M1 = M2 gdw. M1 ⊆ M2 und M2 ⊆ M1

**gdw** bedeutet **genau denn, wann** (dann und nur dann, wenn)
A gdw. B: B gilt nur genau dann, wenn A gilt.
#### Beispiele
{3, 5, 8, 4} = {8, 4, 3, 5}, da Mengen ungeordnet sind und alle Elemente von der ersten Menge in der zweiten, und alle Elemente von der zweiten Menge in der ersten vorhanden sind.

ℕ ≠ ℝ, da zwar alle natürlichen Zahlen in den reellen Zahlen vorhanden sind, aber nicht alle reellen Zahlen in den natürlichen Zahlen. 5 (ℕ) ∈ ℝ, aber π (ℝ) ∉ ℕ.

### Defintition 2.5 (Echte Teilmenge)
Eine Menge M1 heißt echte Teilmenge von M2 (M1 ⊂ M2), wenn M1 ⊆ M2 und M1 ≠ M2 gilt.

Die natürlichen Zahlen sind ebenfalls eine echte Teilmenge von den reellen Zahlen, da für alle natürlichen Zahlen gilt, dass sie auch reelle Zahlen sind, aber es nicht für alle reellen Zahlen gilt, dass sie natürliche Zahlen sind. 
**(ℕ ⊂ ℝ)**

{3, 5, 8, 4} ist keine echte Teilmenge von {8, 4, 3, 5}, da alle Elemente von der ersten Menge in der zweiten Menge sind, **ABER** ebenfalls alle Elemente von der zweiten Menge in der ersten Menge sind! 
**{3, 5, 8, 4} ⊄ {8, 4, 3, 5}**

In einer Nussschale: Alle Teilmengen sind echt, außer die, bei denen die beiden Mengen gleich sind!
#### Obermengen
M1 ⊇ M2 gdw. M2 ⊆ M1
M1 ist eine Obermenge von M2, da M2 eine Teilmenge von M1 ist.

M1 ⊃ M2 gdw. M2 ⊂ M1
M1 ist eine echte Obermenge von M2, da M2 eine echte Teilmenge von M1 ist.

### Wichtige Mengen
Leere Menge = { }, Symbol: ∅
--> ∅ ⊆ M (alle Mengen M) (Teilmenge, keine echte Teilmenge, denn ∅ ⊆ ∅, aber ∅ = ∅, also ∅ ⊄ ∅)
ℕ = {0, 1, 2, 3, ...} MIT 0
$$
\begin{flalign}
&\mathbb{N}^≥¹ = \{1, 2, 3, ...\}\text{ OHNE 0}&\\
&ℤ = \{..., -2, -1, 0, 1, 2, ...\}&\\
&Q = \left\{ \frac{p}{q} | p ∈ ℤ, q ∈ \mathbb{N}^≥¹\right\}&\\
\end{flalign}
$$
ℝ Reelle Zahlen
$$
\begin{flalign}
&\mathbb{B} = \{0, 1\} \text{, die Boole'sche Menge}&\\
\end{flalign}
$$
### Übung 2.6
**Wichtig: Zahlen sind Teilmengen der natürlichen Zahlen!**
Gerade Zahlen: Zahlen, die durch 2 teilbar sind (in der Logik wird 2n benutzt)
$$
\begin{flalign}
&A= \{2x |x \in \mathbb{N}\}\\
&A=\left\{ \frac{x}{2} \in \mathbb{N}\right\}&\\
\end{flalign}
$$
Quadratzahlen: Zahl, die durch das Quadrieren einer natürlichen Zahl entsteht 
$$
\begin{flalign}
&B=\{x² | x \in \mathbb{N}\}&\\
&B=\{\sqrt{x }|\sqrt{x } \in \mathbb{N}\}&\\
\end{flalign}
$$
Alle Zahlen, die eine gerade Anzahl von Teilern haben 
-> Primzahlen haben eine gerade Anzahl, da sie nur durch 1 und sich selber teilbar sind. 
10: 1, 2, 5, 10
15: 1, 3, 5, 15
13: 1, 13
11: 1, 11
4: 1, 2, 4
16: 1, 2, 4, 8, 16
--> Alle Quadratzahlen haben eine ungerade Anzahl an Teilern, alle Zahlen, die nicht Quadratzahlen sind haben sie aber!
$$
\begin{flalign}
&C = \{n|n \in \mathbb{N}, \sqrt{n} ∉ \mathbb{N}\}&\\
&C = \left\{ x | Dx = \left\{ \frac{x}{t} \in \mathbb{N} \right\},|Dx| mod2 = 0 \right\}&\\
\end{flalign}
$$
|Dx| bezeichnet die Mächtigkeit von Dx (also die Anzahl der Elemente in Dx, ALSO die Teiler)
### MUI-System
Es gilt:
- Jede Ableitung beginnt mit MI
- Ableitungsregeln:
1. xI -> xIU
2. xIIIy -> xUy
3. xUUy -> xy
4. Mx -> Mxx

### Übung 1.2
Geben Sie, falls möglich, für die folgenden Wörter Ableitungen an:

**MUIU**
M I ->4 M II
M II ->4 M IIII
M III I ->2 M U I
MU I ->1 MU IU

**MIIIII**
M I ->4 M II
M II ->4 M IIII
M IIII ->4 M IIIIIIII
M IIIIIII I ->1 M IIIIIII IU (!)
MIIIII III U ->2 MIIIII U U
MIIIII UU ->3 MIIIII

**MUUUI**
M I ->4 M II
M II ->4 M IIII
M IIII ->4 M IIIIIIII
M IIIIII II ->2 M UU II
M UUII ->4 M UUIIUUII
M UUII UU II ->3 MUUII II
MUU III I ->2 MUU U I

**MU**
MI -> nicht möglich!

**Warum?**
**Invariante:** Die Anzahl der I's ist nie ohne Rest durch 3 teilbar
### Nochmal wegen Invariante fragen!
**Beobachtung:** 
1. Am Anfang ein I (nicht durch 3 teilbar)
2. Mit Regel 4 wird es verdoppelt (auch nicht durch 3 teilbar)
3. Mit Regel 2 wird die Anzahl um 3 verringert, und das Abziehen einer Zahl, die nicht durch 3 teilbar ist, macht es trotzdem nicht teilbar durch 3.
4. Regel 1 ändert die Anzahl der I's nicht.
5. Regel 3 ändert sie auch nicht.
-> Die Anzahl der I's ist nie durch 3 teilbar, egal was man tut.
**Deutung:**
-> Es ist nicht möglich, aus MI ein MU zu machen, da man 3 I's braucht, was aber wegen der Tatsache, dass die Anzahl der I's nie durch 3 teilbar sein kann, kann 4 nie gehen!

Anwendung: Die Compiler validieren z.B. print-Funktionen oder andere Funktionen mit Parametern mithilfe dieser Systeme.
Validierung wichtig, damit es andernsfalls terminieren kann, und nicht extrem lang compiled.

## Mengenoperationen
**Teilmenge = Menge, von denen die Mengen darunter Teil dieser Menge sein müssen.**
d.h. T = ℕ bedeutet dass alle Mengen die das als Teilmenge haben natürliche Zahlen haben.
#### Vereinigung
M1 ⋃ M2 = {x | x ∈ M1 *oder* x ∈ M2}
**x ∈ M1 ⋃ M2** gdw. x ∈ M1 *oder* x ∈ M2
#### Schnitt
M1 ⋂ M2 = {x | x ∈ M1 *und* x ∈ M2}
**x ∈ M1 ⋂ M2** gdw. x ∈ M1 *und* x ∈ M2
#### Differenz
M1 \ M2 = {x | x ∈ M1 und x ∉ M2}
x ∈ M1 \ M2 gdw. x ∈ M1 und x ∉ M2

**Wichtig!**
$$
\begin{flalign}
&\text{d.h. } M_{1} \setminus M_{2} = M_{1} ⋂ \overline{M_{2}}&\\
\end{flalign}
$$
#### Komplement
$$
\begin{flalign}
&\overline{M_{1}} =\{x|x∉M_{1}\}&\\
&x \in \overline{M_{1}} \text{ gdw. } x∉M_{1}&\\
\end{flalign}
$$
### Übung 2.7
**Teilaufgabe 1**
T = {1,2,3,4,5,6,7,8,9,10,11,12}
M1 = {1,2,3,4,5,6,7,8}
M2 = {2,4,6,8,10,12}

a) M1 ⋃ M2 = {1,2,3,4,5,6,7,8,10,12}
b) M1 ⋂ M2 = {2,4,6,8}
c) M1 \ M2 = {1,3,5,7}
d) M̅1̅ = {9,10,11,12}
e) M̅2̅ = {1,3,5,7,9,11}
![[VennDiagrammUebung271.jpg]]

**Teilaufgabe 2**
T = ℕ, M1 = {3i | i ∈ ℕ}, M2 = {2i + 1 | i ∈ ℕ}
M1 = {0, 3, 6, 9, 12, 15, ...}
M2 = {1, 3, 5, 7, 9, 11, 13, 15, ...}

a) M1 ⋂ M2: Alle ungeraden Zahlen, die durch 3 geteilt werden können.
b) M1 \ M2: Alle geraden Zahlen, die durch 3 geteilt werden können.
c) M1 \ M̅2̅: Alle ungeraden Zahlen, die durch 3 geteilt werden können.*
![[VennDiagrammUebung272.jpg]]
$$
\begin{flalign}
&A = \{6i+3|i\in\mathbb{N}\}&\\
&B = \{6i|i\in\mathbb{N}\}&\\
&C = \{6i+3|i\in\mathbb{N}\}&\\
\end{flalign}
$$
$$
\begin{flalign}
&\text{*Warum ist } M_{1} \setminus \overline{M_{2}} = M_{1} \cap M_{2}?\\
&M_{1} \setminus M_{2} = M_{1} \cap \overline{M_{2}}\\
&\text{Also:}\\ 
&M_{1} \setminus \overline{M_{2}} =M_{1} \cap \overline{\overline{M_{2}}} = M_{1} \cap M_{2}&
\end{flalign}
$$
