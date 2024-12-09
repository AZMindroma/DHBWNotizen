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

Es gilt:
$$
ℕ ⊂ ℤ ⊂ ℚ ⊂ ℝ ⊂ ℂ
$$
### Intervallschreibweise
**\[ \]** - Beinhaltet diesen Wert
**( )** - Beinhaltet diesen Wert nicht
Es wird auch alternativ zum Nichtbeinhalten eines Wertes **\] \[** verwendet 
(Das Verwenden davon ist erlaubt, aber ich sollte mich zu der in der Präsentation angewöhnen)
### Potenzmengen
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
|A̅| = |X| - |A| 

Die Mächtigkeit vom Komplement von A (was einfach alles ist, das nicht A ist) ist die Mächtigkeit der Grundmenge X abzezogen von der Mächtigkeit von A, was dann alles außer die Elemente von A beinhaltet.
### (B gehört nicht zur Grundmenge, oder? Also geht das nur, wenn es A und die Schnittmenge gibt?)

|A x B| = |A| \* |B|
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

### Binäre Relation
~ -> Steht in Relation zu
Aber gleichzeitig steht dieses Symbol auch für die Menge, die für eine bestimmte Relation gilt!

Beispiel mithilfe der selben Menge oben: 
**A ~ B <-> x+y ist gerade** (~ ist hier die Relation zwischen A und B)
**~ = {(1;7);(3;7)}** (~ ist hier die Menge, für welche die Relation zutrifft.)
### Äquivalenzrelation
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

Bei Aufgabe 10 wäre x ~ y wäre z z.B. x Stuttgart y Berlin und z München, dass man auch über München von Stuttgart nach München gehen kann.

Reflexiv: Für jedes Element mit sich selber prüfen
Symmetrisch: Ob von x, y auch y, x folt
Transitiv: Wenn x,y und x,z ist, auch x(in der Folie nachlesen!)

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

### Äquivalentklasse
Aufteilung einer Menge in verschiedene Klassen
z.B. Menge ist Z
x ~ y <-> "x und y haben denselben Rest bei Division durch 2"
Z wid aufgeteilt in die geraden Zahlen 2Z und 2Z+1
Repräsentant für 2Z ist z.B. 14, 2Z+1 ist z.B. 17

Partitionierung, es überlappen sich die Äquivalenzklassen NICHT.

S.60 bedeutung: x - y ist durch 3 teilbar
Restklassen: Sie haben den gleichen Rest bei Division (hier durch 3)

### Abbildungen
Mehr oder weniger Funktionen (Zuweisung EINES Wertes zu einem anderen Wert)
Von 2 verschiedenen Mengen, Menge A ist Definitionsbereich und Menge B ist Zielbereich
Wertebereich muss aber nicht dem Bild entsprechen, da nicht alles im Wertebereich im Bild sein muss!
Eingabewert a ist das Urbild von b unter f

Künftig immer Definitionsbereich und Zielbereich aufschreiben bei einer Funktion!

injektiv, wenn ALLES aus A auf genau EINS (und auch ALLES in B) auf B zeigt.
surjektiv, wenn 

injektiv: Jedes b in B wird höchstens 1x getroffen
jedes b in B besitzt mindestens 1 Urbild
surjektiv: Jedes b in B wird mindestens 1x
jedes b in B besitzt höchstens 1 Urbild

bijektiv: injektiv und surjektiv zusammen.
bijekiv: Es müssen genauso viele Elemente im Definitionsbereich wie im Zielbereich sein (|A| = |B|)

Das Angeben vom Definitions- und Wertebereich ist deswegen wichtig, um zu sehen, was auf die Funktion gilt.


...

Bijektivität nötig, um Funktion wie in S.67 beschrieben wird umzukehren!!

S.69 wichtig!

Kapitel II in den Übungen durchmachen ;)