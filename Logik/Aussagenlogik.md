**Eigenschaften von Aussagenvariablen**
- Aussagenvariablen werden durch Großbuchstaben repräsentiert (A, B, X, Y)
- Sie drücken Aussagen aus, die wahr oder falsch sein können.
## 3.1 Syntax
- Vergleichbar mit der Linguistik in der Sprache; Das Erzeugen von Sätzen aus Wörtern
- Bei Logik: Regeln zum Erzeugen von Formeln aus vorgegebenen Symbolen
- Aussagen sind gültig, wenn gültige aussagenlogische Formeln und gültige Operationen vorhanden sind.
### Aussagenlogische Formeln
Wenn V eine Menge von Aussagenvariablen ist...
- Ist jedes X∈V eine aussagenlogische Formel
- W und F sind aussagenlogische Formeln
- Wenn φ und ψ aussagenlogische Formeln sind, gelten auch folgende Formeln:

- (¬φ) (Negation (NICHT/NOT))
- (φ ⋀ ψ) (Konjunktion (UND/AND))
- (φ ⋁ ψ) (Disjunktion (ODER/OR))
- (φ -> ψ) (Implikation)
- (φ <-> ψ) (Äquivalenz)
#### Übung 3.6
Gültig:
1, 2, 4, 7, 8, 9, 11, 13, 14

Nicht gültig:
3, 5, 6, 10, 12
### Vorrang und Assoziativität der Junktoren
Um Klammern zu sparen, gilt folgendes:
- Äußerste Klammern um eine Formel können weggelassen werden
- Gleiche Junktoren werden links-assoziativ gelesen. z.B. A -> B -> C = (A -> B) -> C 

**Priorität der Junktoren (von oben nach unten):**
¬ (Negation) 
⋀ (Konjunktion)
⋁ (Disjunktion)
-> (Implikation)
<-> (Äquivalenz)

Implikation: Aus A muss B folgen
0 -> 1 oder 0 -> 0: "Ist mir egal"-Fall (es ist egal, was danach kommt)
#### Übung 3.8
1. A ⋀ B ⋁ (C ⋀ D -> A ⋁ C)
2. (A ⋀ (B ⋁ C) ⋀ D -> A) ⋁ C
3. A ⋀ (B ⋁ C ⋀ (D -> A ⋁ C))
## 3.2 Semantik
**Bedeutung von Ausdrücken**

- **Voraussetzung:** Ausdruck ist syntaktisch richtig
- **In der Linguistik:** Was ein Begriff oder Satz bedeutet
- **Logik (also hier):** Ob ein Satz wahr oder falsch ist

- **Zuweisung** von 1 oder 0 zu Aussagenvariablen 
- Dies sorgt dafür, dass eine Formel **wahr** oder **falsch** ist.
### Interpretation
Eine Interpretation **Funktion I : V -> 𝔹** mit:
- Einer Menge von Aussagenvariablen V
- Der Boole'schen Menge 𝔹 = {0, 1}
z.B. 
**I = {A ↦ 0, B ↦ 1} 
<=> I(A) = 0 und I(B) = 1
<=> Aⁱ = 0 und Bⁱ = 1**
#### Übung 3.13
1)
Richtig: I = {A ↦ 0, B ↦ 1, C ↦ 0}
Falsch: I = {A ↦ 1, B ↦ 1, C ↦ 0}

Alternative korrekte Form: 
$$
A^I = 1, B^I = 1, C^I = 1 \ \ \ \ \ \ \varphi^I 1 \land 1 \to 1 = 1
$$
2)
Richtig: I = {A ↦ 0, B ↦ 1, C ↦ 1}
Falsch: I = {A ↦ 1, B ↦ 0, C ↦ 1}

3)
Richtig: I = {A ↦ 1, B ↦ 1}
Falsch: Nicht möglich, da es eine **Tautologie** ist.
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
#### Nachteile von der Resolution
Es sagt nur, dass eine Lösung existiert oder nicht, aber gibt die Lösung selber nicht aus!
-> Anderer Ansatz: Tableau-Verfahren
### Tableau-Verfahren
Tableau - Tabelle
Jede Spalte n steht für eine Interpretation
Jede Zeile einer Spalte enthält eine Formel, die die Interpretation erfüllen muss

Hier ist die **Negations-Normalform** besser:
Da gibt es nur Und und Oder und Negationen nur vor Aussagenvariablen.

Warum funktioniert es?
Wenn es eine Clash-freie Spalte gibt, ist für keine Variable X und NichtX vorhanden
Eine Clash-freie Spalte ist vorhanden, wenn phi erfüllbar ist.

Teilformeln: Alle Teile, von denen eine Formel entsteht.
Terminierung des Tableau-Algorithmus:
Für JEDE Formel phi nach endlich vielen Schritten
-> Warum? Da es nur endlich viele Teilformeln von nnf(phi) gibt

don't care-nichtdeterministisch:
- jede Auswahl führt zur Lösung
don't know-nichtdeterministisch:
- Alles muss getestet werden

-> Ein Modell aus einer nicht-clashender Spalte wird gelesen, indem man von unten nach oben liest (z.B. wenn da A ist, ist A = 1 und wenn NICHTB ist, ist B 0)

