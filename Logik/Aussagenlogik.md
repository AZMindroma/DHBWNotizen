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

Tautologien sind gültig