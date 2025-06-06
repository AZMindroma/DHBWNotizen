## Größtenteils analog zu [[Logik/Mengenlehre|Logik->Mengenlehre]], aber hat (Stand jetzt) mehr Inhalt

## 2.1 Darstellung von Mengen
Mengennamen (M) sind in der Regel in **Großbuchstaben** geschrieben:
**M** = {A, %, 1, Ü, a, T, l}
Eine Menge kann mehr oder weniger alles enthalten, sogar andere Mengen in der Menge!

**Bestimmt**: Ein Element x gehört entweder zu einer Menge oder nicht
**Wohlunterschieden**: Jedes Element ist nur einmal in der Menge, die Elemente in der Menge sind also unterscheidbar.

**Nicht wohlunterschieden:** {1,2,2,3}
**Wohlunterschieden:** {1,2,3}

Die Reihenfolge ist in der Notation der Menge egal:
{1,2,3} = {3,2,1}

**Zum Merken :)**
Runde Klammern -> Reihenfolge **wichtig**!
Geschweifte Klammern -> Reihenfolge **egal**!
### Darstellungsweisen
Menge in **aufzählender** Darstellung:
M1 := {a1, a2, ... an}

Menge in **beschreibender** Darstellung:
M2 := {x ∈ X | x besitzt die Eigenschaften E1, E2, ..., Em}

*Die Beschreibung sind je Situation anders praktisch*

hier ist X eine Übermenge / größere Menge (größer als M2)

*Übung: Formulieren sie Q in Symbolschreibweise.*
#### Zu Teilmengen
Warum auch immer ist eine Teilmenge, wenn sie keine Teilmenge ist, nur eine Teilmenge, und nicht gleich...? Wegen präventiven Gründen.

...so wie 3 < 4 = 3 <= 4
(die Relation der Zahlen muss noch untersucht werden, deswegen wird nicht gesagt, dass keine echte Teilmenge bedeutet, dass die beiden Mengen gleich sind.)
### Lösungsmenge: 
**Zusammenfassung aller Elemente, die die Gleichung erfüllen.**

Für **x ∈ ℕ** keine Lösung für x + 1 = 0, also L = ∅ 
-> Erweiterung des Zahlenbereichs nötig, damit die Gleichung gelöst werden kann (Zu ℤ)

Es gilt die (echte) Inklusionskette:
$$
ℕ ⊂ ℤ ⊂ ℚ ⊂ ℝ ⊂ ℂ
$$
### Intervallschreibweise
**\[ \]** - Beinhaltet diesen Wert
**( )** - Beinhaltet diesen Wert nicht
Es wird auch alternativ zum Nichtbeinhalten eines Wertes **\] \[** verwendet 
(Das Verwenden davon ist erlaubt, aber ich sollte mich zu der in der Präsentation angewöhnen)
### Potenzmengen
*Bei Stochastik wird es wahrscheinlich nötig sein*

Eine Potenzmenge P(X) ist die Menge aller Teilmengen von X. 
Verwirrend. Deswegen hier ein Beispiel:

X = {1, 5, 7}
P(X) = {∅, {1}, {5}, {7}, {1, 5}, {1, 7}, {5, 7}, {1, 5, 7}}

Die leere Menge und Menge X selbst sind **triviale Teilmengen**.
In der Potenzmenge muss die Menge X **selbst** dabei sein.
### Mächtigkeit (erklärt in [[Logik/Mengenlehre#Definition 2.2 (Mächtigkeit)|Logik->Mengenlehre->Definition 2.2 (Mächtigkeit)]])
*Einige zusätzliche Funfacts:*
**|ℕ|** ist unendlich. (Alle natürlichen Zahlen)
**|{ℕ}|** ist 1, da ℕ ein Element in einer Menge ist, nicht die Menge!

|A ⋃ B| = |A| + |B| - |(A ⋂ B)|
Um die Mächtigkeit der Menge A ⋃ B zu bekommen, kann man die Mächtigkeiten von A und B addieren, muss dann aber die Mächtigkeit der Schnittmenge abziehen, da es sonst 2x gezählt wird. 
|A̅| = |X| - |A| (hier ist A und X vorhanden, kein B)

*Die Mächtigkeit vom Komplement von A (was einfach alles ist, das nicht A ist) ist die Mächtigkeit der Grundmenge X abzezogen von der Mächtigkeit von A, was dann alles außer die Elemente von A beinhaltet.*

|A x B| = |A| \* |B|

anzählbar unendlich < überabzählbar unendlich
ℕ, ℤ, ℚ < ℝ, ℂ

---
## 2.2 Mengenoperationen
Analog zu [[Logik/Mengenlehre#Mengenoperationen|Logik->Mengenlehre->Mengenoperationen]]

**Zusätzlich:**
Man nennt Mengen **disjunkte Mengen**, wenn **A ⋂ B = ∅** ist.
z.B. 
A = {1,2,3} und B = {4,5,6}
A ⋂ B = {1, 2, 3} ⋂ {4, 5, 6} = ∅

**Wenn** eine Menge disjunkt ist, dann ist die Vereinigung dann mit einem Punkt:
$$
\begin{flalign}
A \dot{\cup}B = \{1, 2, 3, 4, 5, 6\}
\end{flalign}
$$
### Kartesisches Produkt (A x B)
Das Produkt ist durch die **2-Tupel** (a, b) mit a ∈ A und b ∈ B gegeben:
$$
A \times B = \{(a,b)|a \in A \wedge b \in B \}
$$
z.B.
A = {1; 3}
B = {2; 4; 7}
A x B =   {(1;2); (1;4); (1;7);
        (3,2); (3;4); (3;7)}

---
## 2.3 Binäre Relationen
~ -> Steht in Relation zu
Aber gleichzeitig steht dieses Symbol auch für die Menge, die für eine bestimmte Relation gilt!

Beispiel mithilfe der selben Menge oben: 
**A ~ B <-> x+y ist gerade** (~ ist hier die Relation zwischen A und B)
**~ = {(1;7);(3;7)}** (~ ist hier die Menge, für welche die Relation zutrifft.)
### Äquivalenzrelationen
Wir schauen uns folgende Menge an:
**A = {1; 2}**
A x A = {(1, 1); (1, 2); (2, 1); (2, 2)}
~ = {(1, 1); (2, 2)}

Für die Relation ~ (hier **x + y ist gerade**) in A x A gilt:

**Reflexiv: x ~ x für alle x∈A** 
für x = 1: 1 + 1 ist 2 -> gerade
für x = 2: 2 + 2 ist 4 -> gerade
-> Die Relation ist reflexiv.

**Symmetrisch: x ~ y -> y ~ x**
**Wenn x + y gerade ist, ist auch y + x gerade.**
Für (1, 1): 
x + y = 1 + 1 -> gerade
y + x = 1 + 1 -> gerade
Für (2, 2):
x + y = 2 + 2 -> gerade
y + x = 2 + 2 -> gerade
-> Die Relation ist symmetrisch.

**Transitiv: x ~ y ⋀ y ~ z -> x ~ z**
**Wenn x + y gerade ist UND y und z gerade ist, ist x und z auch gerade.**
Für (1, 1):
x + y = 1 + 1 -> gerade
y + z = 1 + (2n+1) -> gerade
x + z = 1 + (2n+1) -> auch gerade
*2n+1 steht für eine ungerade Zahl. 1 + eine beliebige ungerade Zahl ergibt eine gerade Zahl.*

Für (2, 2):
x + y = 2 + 2 -> gerade
y + z = 2 + (2n) -> gerade
x + z = 2 + (2n) -> auch gerade
*2n steht für eine gerade Zahl. 2 + eine beliebige gerade Zahl ergibt eine gerade Zahl.*

-> Die Relation ist transitiv.

**Wenn alle 3 Relationstypen für eine Relation zustimmen (die Relation ist reflexiv, symmetrisch und transitiv), wird sie Äquivalenzrelation genannt.
-> Diese Relation ist eine Äquivalenzrelation.**

**Oft gibt es in Klausuren Fehler, da man versucht, etwas zu beweisen mithilfe von Tests mit 2, 3 Werten. Aber man muss es allgemein, also für alle Werte beweisen.**
### Mögliche Hilfen, um es klarer zu machen.
![[Aufgabe10Aufgabenkatalog.png]]
**Beispiel für Transitivität:**
Wenn **Stadt x** Stuttgart ist und **Stadt y** Berlin ist, dann kann **Stadt z** z.B. München sein.
**Wenn man also von Stuttgart nach München und von München nach Berlin fahren kann, kann man auch von Stuttgart nach Berlin fahren.**
#### Paar weitere Beispiele
x ~ y <-> x = y
x = x und y = y -> Reflexiv!
Wenn x = y, dann auch y = x -> Transitiv!
Wenn x = y und y = z, dann auch x = z -> Transitiv!

x ~ y <-> x <= y
x <= x und y <= y -> Reflexiv!
Wenn x <= y, dann auch y <= x -> Falsch! Nicht transitiv!
Wenn x <= y und y <= z, dann auch auch x <= z -> Transitiv!

x ~ y <-> x >= y
x >= x und y >= y -> Reflexiv!
Wenn x >= y, dann auch y >= x -> Falsch! Nicht transitiv!
Wenn x >= y und y >= z, dann auch auch x >= z -> Transitiv!

### Äquivalenzklassen
**Aufteilung einer Menge in verschiedene Äquivalenzklassen mithilfe von Äquivalenzrelationen**
Alle Elemente in einer Äquivalenzrelation sind **gleichberechtigt**, und sind Repräsentanten von der Äquivalenzklasse.

z.B. 
Menge ist ℤ (Ganze Zahlen)
x ~ y <-> "x und y haben denselben Rest bei Division durch 2"
ℤ wird aufgeteilt (**disjunkt**) in die beiden Äquivalenzklassen der geraden Zahlen 2ℤ bzw. der ungeraden Zahlen 2ℤ+1
**Repräsentant** für 2ℤ ist z.B. 14, **Repräsentant** 2ℤ+1 ist z.B. 17

Jedes Element liegt in genau einer Äquivalenzklasse, d.h. durch die Äquivalenzrelation wird die Menge **partitioniert.**

---
## 2.4 Abbildungen
*Mehr oder weniger Funktionen (Zuweisung eines Wertes zu einem anderen Wert)*

Bei den Mengen A und B, die nicht leer sind, ist eine Abbildung f von A nach B eine Vorschrift
**f: A -> B, a ↦ b = f(a)**
<u>die jedem a ∈ A *genau* ein Element aus B zuordnet.</u>

**Informationen:**
- b = f(a) wird **Funktionswert** oder **Bild** von a unter f genannt.
- Die Menge A wird **Definitionsbereich** genannt und die Menge B wird **Zielbereich** genannt
- Der Eingabewert a nennt man das **Urbild** von b unter f

Wertebereich muss aber nicht dem Bild entsprechen, da nicht alles im Wertebereich im Bild sein muss!

Künftig immer Definitionsbereich und Zielbereich aufschreiben bei einer Funktion! Ist wichtig.
### Definitionen
Eine Abbildung f von einer Menge A nach B kann folgende Eigenschaften haben:
#### Injektivität
Jedes b in B wird höchstens 1x getroffen (kann also entweder nicht oder getroffen werden, aber nicht 2x)
d.h. jedes b in B besitzt mindestens 1 Urbild (mindestens einen a aus A oder mehrere)
#### Surjektivität
Jedes b in B wird mindestens 1x getroffen (muss also getroffen werden, aber kann auch mehr als einmal getroffen werden)
d.h. jedes b in B besitzt höchstens 1 Urbild (kein a aus A oder eins)
#### Bijektivität
Wenn die Abbildung injektiv **UND** surjektiv ist, ist die Abbildung auch bijektiv.

**Merkmal:** 
Es müssen genauso viele Elemente im Definitionsbereich wie im Zielbereich sein (|A| = |B|)
Bei Bijektivität kann man die Funktion umkehren.
#### Überblick:
![[InjektivSurjektivBijektiv.png]]
Quelle: https://docs.lucanoahcaprez.ch/books/semester-1/page/funktionen
### Komposition von Abbildungen (auch Verkettung genannt)
Wenn es zwei Abbildungen (mit 3 Mengen A, B und C) gibt, die so definiert sind:
**f: A -> B und g: B -> C**
Dann ist deren Komposition von f mit g, geschrieben **g ◦ f** ("g nach f") definiert durch:
**g ◦ f: A -> C, a ↦ (g ◦ f)(a) := g(f(a))**

Beispiel aus der Schule mit klassischen Funktionen
f(x) = x²
g(x) = 2x + 1

(g ◦ f)(x) = 2 \* f(x) + 1 = 2x²+1
*(g ◦ f)(0) = 2 \* 0² + 1 = 1*

![[Komposition.jpg]]
### Umkehrabbildungen
Wenn f: X -> Y eine **bijektive Abbildung** ist, gibt es genau eine Abbildung von Y nach X, die Umkehrabbildung von f genannt wird und mit f⁻¹ bezeichnet wird. Es gilt:

**(f⁻¹ ◦ f)(x) = x für alle x ∈ X
(f ◦ f⁻¹)(y) = y für alle x ∈ Y**
*d.h. f⁻¹(f(x)) und f(f⁻¹(y))*
-> Die Umkehrfunktion "hebt" den Effekt von der Funktion auf, und die Funktion "hebt" den Effekt von der Umkehrfunktion auf.

Wenn f: X -> Y und g: Y -> Z **bijektive Abbildungen** sind, gilt:

$$
\begin{gather*}
f(^{-1})^{-1}(x) = f(x) \text{ Für alle x ∈ X} \\
\text{(d.h. Die Umkehrfunktion einer Umkehrfunktion ist die Funktion selber)} \\
\\
(g ◦ f) : X\to Z \text{ ist auch bijektiv und es gilt für alle z ∈ Z} \\
(g ◦ f)^{-1} : Z \to X, z ↦ (g ◦ f)^{-1}(z) = f^{-1}(g^{-1}(z)) 
\end{gather*}
$$