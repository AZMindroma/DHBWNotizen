add(0,X,X).
add(s(X),Y,s(Z)) :- add(X,Y,Z).

numeral(0).
numeral(s(X)) :- numeral(X).
less(X,s(X)) :- numeral(X).
less(X,s(Y)) :- less(X,Y).
