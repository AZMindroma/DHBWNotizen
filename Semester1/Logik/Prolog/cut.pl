numberinlist(X,Y) :- member(X,Y), number(X).

filter([],[]).
filter([H,T],T2) :- number(H), !, filter(T,T2).
filter([H,T],[H,T2]) :- filter(T,T2).
