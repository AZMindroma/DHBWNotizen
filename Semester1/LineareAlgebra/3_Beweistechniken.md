**3 Teile von mathematischen Sätzen:**
1. Voraussetzung
2. Behauptung
3. Beweis
**3 Methoden:**
1. Direkter Beweis
2. Indirekter Beweis
3. Beweis durch vollständige Induktion

Alle 3 kommen in den Klausuren dran, aber Direkte und Indirekte Beweise sind oft **Learning by doing**, während Vollständige Induktion eher separat ist und auch gelernt werden muss.
## 3.1 Direkter Beweis
Beim direkten Beweis kann auch der Voraussetzung V die Behauptung B direkt bewiesen werden.
#### Beispiel direkter Beweis
**Zeigen Sie, dass wenn n eine ungerade Zahl ist, dessen Quadrat ebenfalls gerade ist.**
Voraussetzung V: n ist eine ungerade Zahl
Behauptung B: n² ist ungerade

**Beweis:**
- Da n ungerade ist, gilt n = n = 2k+1 (k ist eine natürliche Zahl)
- Daher gilt: n² = (2k+1)² = 4k² + 4k + 1 = 2 (2k² + 2k) + 1
- Da 2 (2k² + 2k) + 1 eine ungerade Zahl ist, folgt, **dass n² ungerade ist.**
□
## 3.2 Indirekter Beweis
Beim indirekten Beweis (auch **Beweis durch Widerspruch** genannt) wird angenommen, dass die Behauptung B falsch ist. Dann wird ein Widerspruch zur Voraussetzung V hergeleitet oder mit V einen Widerspruch zu einer wahren Aussage herleiten 
-> Die Behauptung kann dann nicht falsch sein und die Behauptung stimmt
#### Beispiele indirekter Beweis
##### Beispiel 1
**Zeigen Sie, dass wenn n eine ungerade Zahl ist, dessen Quadrat ebenfalls gerade ist.**
Voraussetzung V: n ist eine ungerade Zahl
Behauptung B: n² ist ungerade -> Annahme: Behauptung B ist falsch: **n² ist gerade**

**Beweis:**
- Da n² gerade sein soll, ist n² = 2k
- Also ist 2 in der Primfaktorzerlegung von n² 
- Also muss 2 auch in der Primfaktorzerlegung von n sein
- Aber n ist ungerade und wenn eine Zahl die 2 in der Primfaktorzerlegung hat, ist sie gerade
- **Dies ist ein Widerspruch zur Voraussetzung V, deswegen muss n² gerade sein**
□
##### Beispiel 2
**Zeigen Sie, dass x² + 4 keine Nullstellen in ℝ besitzt.**
Voraussetzung V: x² + 4 ist definiert in ℝ
Behauptung B: x² + 4 hat keine Nullstellen in ℝ -> Annahme: Behauptung B ist falsch: **x² + 4 hat Nullstellen in ℝ**

**Beweis:**
- Angenommen, x² + 4 besitzt Nullstellen
- Es muss ein x ∈ ℝ geben, dass x² + 4 = 0 erfüllt
- x² + 4 = 0 <==> x² = -4
- Dies geht nicht, da x² >= 0 für alle x ∈ ℝ
- **Dies ist ein Widerspruch zur Voraussetzung V, deswegen kann x² + 4 keine Nullstellen in ℝ haben**
□

*Evtl mal versuchen, einen Indirekten Beweis mit 2 anstatt von sqrt(2) durchzuführen (keine Aufgabe, von mir selber)
Indirekten Beweis nochmal selber durchführen.*
## 3.3 Vollständige Induktion
### Induktionsaxiom
**Enthält eine Teilmenge A ⊆ ℕ die Zahl 1 und mit jedem k auch k + 1, dann ist A = ℕ.**
-> Basis, um das **Dominoprinzip** für die natürlichen Zahlen anzuwenden.

**Dominoprinzip:** Wenn eine Aussage A(n) für **alle natürlichen Zahlen richtig** sein soll, dann muss man beweisen, dass die Aussage für den **Startwert 1** richtig ist und denn sie für eine **natürliche Zahl k richtig** ist, **auch für k + 1 richtig** ist.
### Vorgehensweise
1. **Induktionsanfang (IA):**
   Prüfe, ob die Aussage für einen **Startwert n₀** gilt
2. **Induktionsschritt (IS):**
   Nehme an, dass die Aussage **für k** gilt, und zeige, dass sie **auch für k + 1** gilt.
3. **Induktionsende (IE):**
   Wenn der Induktionsanfang und Induktionsschritt erfüllt sind, dann **gilt die Aussage A(n)** für jede natürliche Zahl n >= n₀

![[VollstaendigeInduktion.jpg]]