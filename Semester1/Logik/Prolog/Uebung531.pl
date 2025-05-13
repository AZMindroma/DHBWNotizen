word(astante, a,s,t,a,n,t,e).
word(astoria, a,s,t,o,r,i,a).
word(baratto, b,a,r,a,t,t,o).
word(cobalto, c,o,b,a,l,t,o).
word(pistola, p,i,s,t,o,l,a).
word(statale, s,t,a,t,a,l,e).

crossword(V1,V2,V3,H1,H2,H3) :-
    word(V1,_,X,_,_,_,_,_), word(H1,_,X,_,_,_,_,_),
    word(V1,_,_,_,Y,_,_,_), word(H2,_,Y,_,_,_,_,_),
    word(V1,_,_,_,_,_,Z,_), word(H3,_,Z,_,_,_,_,_),

    word(V2,_,A,_,_,_,_,_), word(H1,_,_,_,A,_,_,_),
    word(V2,_,_,_,B,_,_,_), word(H2,_,_,_,B,_,_,_),
    word(V2,_,_,_,_,_,C,_), word(H3,_,_,_,C,_,_,_),

    word(V3,_,D,_,_,_,_,_), word(H1,_,_,_,_,_,D,_),
    word(V3,_,_,_,E,_,_,_), word(H2,_,_,_,_,_,E,_),
    word(V3,_,_,_,_,_,F,_), word(H3,_,_,_,_,_,F,_),

    V1 \= V2, V1 \= V3, V1 \= H1, V1 \= H2, V1 \= H3,
    V2 \= V3, V2 \= H1, V2 \= H2, V2 \= H3,
    V3 \= H1, V3 \= H2, V3 \= H3,
    H1 \= H2, H1 \= H3,
    H2 \= H3.
