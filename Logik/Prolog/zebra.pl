street(S) :-
    S = [H1,H2,H3],
    member([red,_,_],S),
    member([green,_,_],S),
    member([blue,_,_],S),
    member([_,english,_],S),
    member([_,japanese,_],S),
    member([_,spanish,_],S),
    member([_,_,snail],S),
    member([_,_,jaguar],S),
    member([_,_,zebra],S),

    member([red,english,_],S),
    member([_,spanish,jaguar],S).
