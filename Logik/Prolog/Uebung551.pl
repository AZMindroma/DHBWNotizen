add(0,X,X).
add(s(X),Y,s(Z)) :- add(X,Y,Z).

less(0,X).
less(s(X),s(Y)) :- less(X,Y).
