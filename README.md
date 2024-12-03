Fragen: 
Folien nur für private Nutzung nutzbar oder auch redistributierbar? Sonst könnte ich nämlich die Folien direkt ins Repo packen.
--> Nicht klar, wird evtl noch geklärt

## Einführung Logik
Bauchgefühl nicht schlecht, aber man muss logisch denken können, um dieses Bauchgefühl zu bestätigen.

*Syntax: "Rechtschreibung"
Semantik: "Logik"*

Sachen mit -logie kommen von Logos (Wort, Sprechen, usw)

**Es gibt unlösbare Probleme, die selbst der Computer nicht lösen kann.**

**DIE NATÜRLICHEN ZAHLEN SIND HIER MIT 0!!!**

Formale Beschreibung: z.B. {n|n element N}
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
$$
\begin{flalign}
&\text{Leere Menge = { }, Symbol: ∅}\\
&\text{--> ∅ ⊆ M (alle Mengen M) (Teilmenge, keine echte Teilmenge, denn ∅ ⊆ ∅, aber ∅ = ∅, also ∅ ⊄ ∅)}\\
&\text{ℕ = {0, 1, 2, 3, ...} MIT 0}\\
&ℕ^≥¹ = \{1, 2, 3, ...\}\text{ OHNE 0}\\
&ℤ = \{..., -2, -1, 0, 1, 2, ...\}\\
&Q = \left\lbrace \frac{p}{q} | p ∈ ℤ, q ∈ ℕ^≥¹\right\rbrace\\
&\text{ℝ Reelle Zahlen}\\
&\mathbb{B} = \{0, 1\} \text{, die Boole'sche Menge}&
\end{flalign}
$$
## Übung 2.6
**Wichtig: Zahlen sind Teilmengen der natürlichen Zahlen!**
Gerade Zahlen: Zahlen, die durch 2 teilbar sind (in der Logik wird 2n benutzt)<br>
$$
\begin{flalign}
&A= \{2x |x \in \mathbb{N}\}\\
&A=\left\lbrace  \frac{x}{2} \in \mathbb{N}\right\rbrace &
\end{flalign}
$$

Quadratzahlen: Zahl, die durch das Quadrieren einer natürlichen Zahl entsteht<br>
$$
\begin{flalign}
&B=\{x² | x \in \mathbb{N}\}\\
&B=\{\sqrt{x }|\sqrt{x } \in \mathbb{N}\}&
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
&C = \{n|n \in \mathbb{N}, \sqrt{n} ∉ \mathbb{N}\}\\
&C = \left\{ x | Dx = \left\{ \frac{x}{t} \in N \right\},|Dx| mod2 = 0 \right\}&
\end{flalign}
$$
|Dx| bezeichnet die Mächtigkeit von Dx (also die Anzahl der Elemente in Dx, ALSO die Teiler)
## In der Vorlesung

1. xI -> xIU
2. xIIIy -> xUy
3. xUUy -> xy
4. Mx -> Mxx

1
M I ->4 M II
M II ->4 M IIII
M III I ->2 M U I
MU I ->1 MU IU

**Ab hier nacharbeiten!**
2
M I ->4 M II
M II ->4 M IIII
M IIII ->4 M IIIIIIII
M IIIIIIII ->1 M IIIIIIIIU (!)
M IIIIIIIIU ->2 MIIIIIUU
MIIIIIUU ->3 MIIIII

3
M I ->4 M II
M II ->4 M IIII
M IIII ->4 M IIIIIIII
M IIIIII II ->2 M UU II
M UUII ->4 M UUIIUUII
M UUIIUUII ->3 M UUIII I
M UUIII I ->2 M UUU I

4
MI -> nicht möglich!

Invariante: Anzahl der I's
-> Vermutung: Die Anzahl der I's ist die ohne Rest durch 3 teilbar
Beobachtung: 
1. Am Anfang ein I (nicht durch 3 teilbar)
2. Mit Regel 4 wird es verdoppelt (auch nicht durch 3 teilbar)
3. Mit Regel 2 wird die Anzahl um 3 verringert, und das Abziehen einer Zahl, die nicht durch 3 teilbar ist, macht es trotzdem nicht teilbar durch 3.
4. Regel 1 ändert die Anzahl der I's nicht.
5. Regel 3 ändert sie auch nicht.
-> Die Anzahl der I's ist nie durch 3 teilbar.

-> Es ist nicht möglich, aus MI ein MU zu machen, da man 3 I's braucht, was aber wegen der Tatsache, dass die Anzahl der I's nie durch 3 teilbar sein kann, kann 4 nie gehen!

Anwendung: Die Compiler validieren z.B. print-Funktionen oder andere Funktionen mit Parametern mithilfe dieser Systeme.
Validierung wichtig, damit es andernsfalls terminieren kann, und nicht extrem lang compiled.

## Mengenoperationen
Teilmenge = Menge, von denen die Mengen darunter Teil dieser Menge sein müssen, d.h. T = N bedeutet dass alle Mengen die das als Teilmenge haben natürliche Zahlen haben

1
a) {1,2,3,4,5,6,7,8,10,12}
b) {2,4,6,8}
c) {1,3,5,7}
d) {9,10,11,12}
e) {1,3,5,7,9,11}

2
a) Alle ungeraden Zahlen, die durch 3 geteilt werden können.
b) Alle geraden Zahlen, die durch 3 geteilt werden können.
c) Alle ungeraden Zahlen, die durch 3 geteilt werden können.
**Visualisierung und die Notationen im Blatt, später nachtragen!**

## Aussagenlogik
Aussagenvariablen werden durch Großbuchstaben repräsentiert
Aussagen sind valide, wenn gültige aussagenlogische Formeln und gültige Operationen vorhanden sind.
### Übung 3.6
Gültig:
1, 2, 4, 7, 8, 9, 11, 13, 14

Nicht gültig:
3, 5, 6, 10, 12

$$
\begin{flalign}
&\text{Warum ist } A \setminus ¬B = A \cap B?\\
&A \setminus B = A \cap ¬B\\
&\text{Also:}\\ 
&A \setminus ¬B =A \cap ¬(¬B) = A \cap B&
\end{flalign}
$$

Vorrang und Assoziativität der Junktoren
- Äußerste Klammern um eine Formel können weggelassen werden
- Gleiche Junktoren werden links-assoziativ gelesen.
A -> B -> C = (A -> B) -> C