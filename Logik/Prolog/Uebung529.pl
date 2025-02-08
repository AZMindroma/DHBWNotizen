house_elf(dobby).
witch(hermione).
witch('McGonagall').
wizard(ron).
magic(X):- house_elf(X).
magic(X):- wizard(X).
magic(X):- witch(X).



