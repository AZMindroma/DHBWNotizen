**Eigenschaften**
Aussagenvariablen werden durch Großbuchstaben repräsentiert
Aussagen sind valide, wenn gültige aussagenlogische Formeln und gültige Operationen vorhanden sind.
### Übung 3.6
Gültig:
1, 2, 4, 7, 8, 9, 11, 13, 14

Nicht gültig:
3, 5, 6, 10, 12

Vorrang und Assoziativität der Junktoren
- Äußerste Klammern um eine Formel können weggelassen werden
- Gleiche Junktoren werden links-assoziativ gelesen.
A -> B -> C = (A -> B) -> C

**Priorität der Junktoren:**
¬ (Negation) 
⋀ (Konjunktion)
⋁ (Disjunktion)
-> (Implikation)
<-> (Äquivalenz)
### Übung 3.8
1. A ⋀ B ⋁ (C ⋀ D -> A ⋁ C)
2. (A ⋀ (B ⋁ C) ⋀ D -> A) ⋁ C
3. A ⋀ (B ⋁ C ⋀ (D -> A ⋁ C))

## Semantik
Bedeutung von Ausdrücken

Voraussetzung: Ausdruck ist syntaktisch richtig
Linguistik: Was ein Satz bedeutet
Logik: Ob ein Satz wahr oder falsch ist
#### Interpretation
Zuweisung von 1 oder 0 zu Aussagenvariablen (Funktion)

Die in der Vorlesung beinhalteten Wahrheitstabellen können bei Phi mit A und B ersetzt werden, und sind mehrdimensional, aber trotzdem normale Wahrheitstabellen

Implikation: Aus A muss B folgen
0 -> 1: "Ist mir egal"-Fall

### Übung 3.13
1
Richtig: I = {A ↦ 0, B ↦ 1, C ↦ 0}
Falsch: I = {A ↦ 1 B ↦ 1 C ↦ 0}

Alternative korrekte Form: 
$$
A^I = 1, B^I = 1, C^I = 1 \ \ \ \ \ \ \varphi^I 1 \land 1 \to 1 = 1
$$
2
Richtig: I = {A ↦ 0 B ↦ 1 C ↦ 1}
Falsch: I = {A ↦ 1 B ↦ 0 C ↦ 1}

3
Richtig: I = {A ↦ 1 B ↦ 1}
Falsch: Nicht möglich

### Tautologie
Formel, die in jeder Interpretation wahr ist.
### Modell
Eine Interpretation ist ein Modell für eine Formel, wenn sie 1 ist
I = {A -> 1, B -> 0} ist ein Modell für A v B, aber nicht für A ^ B

Eine Formel ist erfüllbar, wenn sie ein Modell hat, sonst unerfülbar.
Tautologien sind gültig
(Bild aus Heft einfügen)
### Logische Implikation
Wenn links wahr ist, muss rechts wahr sein
Wenn links falsch ist, ist es egal
### Logische Äquivalenz
Wenn jede Interpretation beiden Formeln denselben Wahrheitwert zuordner
Beide müssen gleich sein.
### Rechenregeln
(Rechenregeln aufschreiben insbesondere Distributivgesetze und De Morgan)
## Schlussfolgerungsverfahren
**Äquivalenzumformungen** (Reduction ad Absurdum)
Vom Blatt einfügen :)
**Wahrheitstabellen**
### Resolutionsprinzip
Erfüllbarkeitstest für Formel phi
Dieser Test entscheidet auch die Gültigkeit, (logische) Implikation
Wenn man einen Widerspruch erzeugen kann, ist die Formel unerfüllbar
Wenn man alle möglichen Kombinationen durchprobiert und trotzdem keinen Widerspruch findet, ist die Formel erfüllbar.
- Betrachte phi als Konjunktion von Disjunktionen von Literalen
  -> Und-Verknüpfungen von Oder-Verknüpfungen
Es wird eine Resolvente C3 erstellt, die durch die Vereinigung von 2 Elternklauseln C1 und C2 entsteht.
#### Literale
Literale sind Aussagenvariablen, die man anstatt von phi nutzen kann
### Klausel
Klauseln sind Disjunkionen (Oder-Verknüpfungen), geschrieben als Mengen.
Dies ist möglich, da Disjunktionen kommutativ sind und deren doppelten Vorkommen nichts verändert.

Beispiel 3.44 für den Beweis mit Induktion
Beim Beispiel ist S nicht erfüllbar, weil nicht A1 falsch sein muss, um wahr zu sein, und A2 auch falsch sein muss, aber dann ist A1, A2 nie wahr, also kann es nicht wahr sein.

-> Beispiel ist nur eine Formalisierung von dieser Beschreibung.

Jeder Weg beim Resolutionsprinzip führt zum Ende, da es eine endliche Eingabe gibt, und man eventuell ein Ende findet. Entweder findet man einen Widerspruch oder man findet ihn nicht.
-> Es gibt keine falschen Wege, aber es kann unterschiedlich lang dauern.

### Übersetzung natürlicher Sprache in Aussagenlogik
nichtR und E -> M (R - Reise, E - Eingeladen, M - Meeting)

Implizieren die Prämissen 1-5 die Konklusion 6?
1 und 2 und 3 und 4 und 5 |= 6?
Umgekehrt: Implizieren die Prämissen 1-5 die Konklusion NICHT 6?
1 und 2 und 3 und 4 und 5 |= NICHT 6? <- Sehr wichtig!


Beim Resolutionsverfahren lieber mit Klauseln mit nur 1 Literal anfangen, da es einfacher ist, dort Widersprüche zu finden.

