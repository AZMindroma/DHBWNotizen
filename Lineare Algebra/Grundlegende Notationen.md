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
\sum_{k = m}^{n}a_{k} := 0
\end{flalign}
$$
### Rechenregeln Summennotation
Wenn die Laufindexe der beiden Summen gleich sind, können sie so addiert und subtrahiert werden:
$$
\begin{gather*}
\sum_{k = 1}^{n}a_{k} \pm \sum_{k = 1}^{n}b_{k} = \sum_{k = 1}^{n} (a_{k} \pm b_{k})\\
(a_{1}+a_{2}+\dots+a_{n}) + (b_{1}+b_{2}+\dots+b_{n}) = (a_{1}+b_{1}) + (a_{2}+b_{2})+\dots+(a_{n}+b_{n})
\end{gather*}

$$
(Technisch gesehen ist es auch mit verschiedenen Laufindexen zu machen, nur bleiben dann einige Indexe übrig... oder sowas)
#### Ausmultiplizieren und Ausklammern
$$
\begin{gather*}
c\sum_{k = 1}^{n}a_{k} = \sum_{k = 1}^{n} (c * a_{k}) \\
c*(a_{1}+a_{2}+\dots+a_{n}) = c * a_{1} + c*a_{2} + \dots + c*a_{n} 
\end{gather*}
$$
Mehr oder weniger analog zur Integralregel :)
#### Summentrennung
$$
\sum_{k=1}^{n}a_{k} = \sum_{k=1}^{l}a_{k} + \sum_{k=l+1}^{n}a_{k}
$$
Hier ist l ein **Index** zwischen k und n. z.B.
1 2 3 4 5 6 7 8 9 
k              l        n
**Also wird von 1 bis 5 (k zu l) und dann von 6 zu 9 (l + 1 zu n) gezählt. Logisch, oder?**
#### Indexverschiebung
$$
\sum_{k = m}^{n}a_{k} = \sum_{k = m - l}^{n - l} a_{k+l}
$$
Man kann erkennen, dass der Start- und Index um l subtrahiert werden, während bei der Funktion der Index um l addiert wird. Dies wird später noch präziser veranschaulicht.
#### Summe von Produkten ≠ Produkte von Summen!!!
$$
\sum_{k = m}^{n} (a_{k} * b_{k}) ≠ \left(\sum_{k = m}^{n} (a_{k})\right) * \left(\sum_{k = m}^{n} (b_{k})\right)
$$
### Beispiele
$$
\begin{flalign}
& \sum_{k = 3}^{27} = 3 + 4 + 5 + \dots + 27 &\\
& \left( \frac{4}{7} \right)^2 + \left( \frac{5}{7} \right)^2 + \left( \frac{6}{7} \right)^2 + \dots + \left( \frac{n}{7} \right)^2 = \sum_{j=4}^{n} \left( \frac{j}{7} \right)^2 = \left( \frac{1}{7} \right)^2 \sum_{j=4}^{n} j^2 &\\ 
\end{flalign}
$$
Am Ende wird ausmultipliziert :)

Sei x eine reelle Zahl. Die sogenannte **geometrische Summe** ist
$$
\begin{flalign}
&1 + x + x^2 + x^3 + x^4 + \dots + x^n = \sum_{k=0}^{n}x^k&\\
\end{flalign}
$$
**Indexverschiebung**
$$
\begin{flalign}
& (4 + 5 + 6 + \dots + n) + (5^4 + 6^5 + 7^6 + \dots + (n+1)^n) &\\
& = \sum_{k = 4}^{n}k + \sum_{k = 5}^{n+1}k^{k-1} &\\
& \text{Indexverschiebung an der rechten Summe, um beide auf k=4 zu bringen:} &\\
& = \sum_{k = 4}^{n}k + \sum_{k = 5-1}^{(n+1)-1}(k+1)^{(k+1)-1} &\\
& = \sum_{k = 4}^{n}k + \sum_{k = 4}^{n}(k+1)^{k} &\\
& \text{Zusammenfassen mit Rechenregeln:} &\\
& = \sum_{k = 4}^{n}(k+(k+1)^k)
\end{flalign}
$$
## Produktnotation
![[Produktnotation04122024.jpg]]
Ebenfalls darf hier nur aufgezählt, nicht heruntergezählt werden. 
Falls m > n ist, wird das **leere Produkt** so definiert:
$$
\prod_{k=m}^{n}a_{k} := 1
$$
### Rechenregeln Summennotation
#### Produkt von Produkten
$$
\prod_{k = m}^{n}a_{k} * \prod_{k = m}^{n}b_{k} = \prod_{k = m}^{n} (a_{k} * b_{k})
$$
#### Ausklammern
$$
\prod_{k = 1}^{n}c*a_{k} = c^n\prod_{k = 1}^{n} a_{k}
$$
"c wird n mal nach vorne geschoben" (?)
#### Quotient von Produkten
$$
\frac{\prod_{k = m}^{n}a_{k}}{\prod_{k = m}^{n}b_{k}}   = \prod_{k = m}^{n} \frac{a_{k}}{b_{k}}
$$
#### Indexverschiebung
$$
\prod_{k = m}^{n}a_{k} = \prod_{k = m - l}^{n - l} a_{k+l} 
$$

**Beispiele von der Folie weil ich faul bin:**
![[page_24.png]]
