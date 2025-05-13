m([],L,L).
m(L,[],L).
m([HA|TA],[HB|TB],[HA|TC]) :- HA >= HB, m(TA,TB,TC).
m([HA|TA],[HB|TB],[HB|TC]) :- HB > HA, m(TA,TB,TC).
