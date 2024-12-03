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