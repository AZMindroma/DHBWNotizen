## Größtenteils analog zu [[Logik/Mengenlehre]]

## Darstellung von Mengen
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
-> Erweiterung Zahlenbereich 

N Teilmenge von Z Teilmenge von Z Teilmenge von Q Teilmenge von R Teilmenge von C

Unterschiedliche Klammerschreibweisen sind OK, aber ich sollte mich zu der in der Präsentation angewöhnen.

Potenzmengen aufschreiben! Ist ein neues Ding.

Leere Menge und Menge X selbst sind triviale Teilmengen.
In der Potenzmenge muss die Menge X selbst dabei sein.

|N| ist unendlich.
|{N}| ist 1, da N ein Element ist, nicht die Menge.

### Mengenoperationen
Analog zur Logik.

Disjunkte Mengen, wenn A geschnitten (und) B = Leere Menge ist.
z.B. A = {1,2,3} B = {4,5,6}
Dann ist die Vereinigung dann mit einem Punkt (kein Fehler in der Folie):
A V(mit Punkt) B = {1,2,3,4,5,6}
(auch nicht schlimm, wenn es fehlt)

Kartesische Produkt (A x B)
A = {1; 3}
B = {2; 4; 7}
A x B = {(1;2); (1;4); (1;7);
		(3,2); (3;4); (3;7)}

Mächtigkeit oder: A und B, aber da gibt es die Schnittmenge, was abgezogen werden muss!

### Binäre Relation
~ -> Steht in Relation zu
Aber auch eine Menge!
(Analog zu Proportionalität in Physik)

Beispiel mithilfe der selben Menge oben: A ~ B <-> x+y ist gerade 
~ = {(1;7);(3;7)}

A = {1; 2}
Reflexiv, da hier z.B. 1+1 = 2 = gerade ist und 2+2 = 4 = gerade ist.
Transitiv: Kleiner als Relation.

Wenn alle 3 in der Folie genannten Relationstypen zustimmen, wird sie Äquivalenzrelation genannt.

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