twice([],[]).
twice([Z|T],[Z,Z|U]) :- twice(T,U).
