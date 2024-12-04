**Definitionszeichen:** 
:= oder =:
z.B. n! **!=** 1 \* 2 \* 3 \* ... \* (n - 1) \* n

**Allquantor:** ∀ ("für alle")
z.B. ∀n ∈ ℕ 
-> "Für alle natürlichen Zahlen" oder verbose: "Für alle n, die in den natürlichen Zahlen sind"

**Existenzquantor:** ∃ ("es gibt ein")
z.B. ∃n ∈ ℕ 
-> "Für (mindestens) eine natürliche Zahl" 

**Existenzquantor:** ∃! ("es gibt **genau** ein")
z.B. ∃! ∈ ℕ
-> "Für genau eine natürliche Zahl" 

*Diese Quantoren machen wir in den Vorlesungen oft genug, dass wir es nicht wie Vokabeln auswendig lernen müssen :)*
## Aussagenverknüpfungen:
Mathematische Aussagen sind immer entweder **wahr** oder **falsch**

z.B. A ⋀ B (A **und** B) bzw. A ⋁ B (A **oder** B)

**Negation:** 
¬A (**Nicht** A)

**Implikation:** 
A -> B

**Äquivalenz:**
A <-> B

Alternative Formulierungen:
*A ist äquivalent zu B
A gilt genau dann, wenn B gilt*
## Eindeutigkeitsprobleme:
Mathematische Ausdrücke sollten **eindeutig** sein

z.B. 0.9999... = 1 ist blöd
**Warum aber eigentlich? (fun fact)**
1/9 = 0,11111...
6/9 = 0,66666...
9/9 = 0,99999...

Bei Termen kann es zu Missverständnissen kommen, was auch schlecht ist. 
z.B. bei **1 + 2 + ... + 2³**, was ist gemeint?
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 *oder* 1 + 2 + 4 + 8
-> Summennotation, um Missverständnisse zu vermeiden!

## Summennotation
![[Summennotation04122024.jpg]]

**Immer in aufsteigender Reihe zählen!** 
z.B. 1, 2, 3, ...
**NICHT** 7, 6, 5, ...
-> Wenn m (Startindex) > n (Endindex) gilt, also es versucht wird, absteigend zu zählen, wird die **leere Summe** definiert:
$$
\begin{flalign}
&\sum_{k = m}^{n}a_{k} := 0&\\
\end{flalign}
$$
### Rechenregeln Summennotation
Wenn die Laufindexe der beiden Summen gleich sind, können sie so addiert und subtrahiert werden:
$$
\begin{flalign}
&\sum_{k = 1}^{n}a_{k} \pm \sum_{k = 1}^{n}b_{k} = \sum_{k = 1}^{n} (a_{k} \pm b_{k})&\\
&(a_{1}+a_{2}+\dots+a_{n}) + (b_{1}+b_{2}+\dots+b_{n}) = (a_{1}+b_{1}) + (a_{2}+b_{2})+\dots+(a_{n}+b_{n})&\\ 
\end{flalign}
$$
(Technisch gesehen ist es auch mit verschiedenen Laufindexen zu machen, nur bleiben dann einige Indexe übrig... oder sowas)
#### Ausmultiplizieren und Ausklammern
$$
\begin{flalign}
&c\sum_{k = 1}^{n}a_{k} = \sum_{k = 1}^{n} (c * a_{k})&\\
&c*(a_{1}+a_{2}+\dots+a_{n}) = c * a_{1} + c*a_{2} + \dots + c*a_{n}&\\ 
\end{flalign}
$$
Mehr oder weniger analog zur Integralregel :)
#### Summentrennung

