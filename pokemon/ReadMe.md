# Pokédex and Pokémon
What is a Pokémon? What is a Pokédex?
Hello there! Welcome to the world of Pokémon! My name is Oak! People call me the Pokémon Prof! This world is inhabited by creatures called Pokémon! For some people, Pokémon are pets. Others use them for fights. Myself ... I study Pokémon as a profession. — Professor Oak

Pokémon are fictional creatures from the Pokémon franchise, most famously from the Pokémon games. The game revolves around the (questionably ethical) capturing of these creatures. Within the fiction of this universe, a device called the Pokédex is used to catalogue all the creatures a player finds and captures.
```

===========================[ Pokédex ]==========================
            Welcome to the Pokédex!  How can I help?
================================================================
Enter command: ?
  a [pokemon_id] [name] [height] [weight] [type1] [type2]
    Add a Pokemon to the Pokedex
  p
    Print all of the Pokemon in the Pokedex (in the order they were added)
  d
    Display details of the currently selected Pokemon
  >
    Move the cursor to the next Pokemon in the Pokedex
  <
    Move the cursor to the previous Pokemon in the Pokedex
  m [pokemon_id]
    Move the cursor to the Pokemon with the specified pokemon_id
  r
    Remove the current Pokemon from the Pokedex
  x [seed] [factor] [how_many]
    Go exploring for Pokemon
  f
    Set the current Pokemon to be found
  c
    Print out the count of Pokemon who have been found
  t
    Print out the total count of Pokemon in the Pokedex
  e [pokemon_A] [pokemon_B]
    Add an evolution from Pokemon A to Pokemon B
  s
    Show evolutions of the currently selected Pokemon
  q
    Quit
  ?
    Show help
Enter command: a 1 Bulbasaur 0.7 6.9 poison grass
Added Bulbasaur to the Pokedex!
```

# Stage 1: Adding and Printing
```
$ dcc -o pokedex main.c pokedex.c pokemon.c
$ ./pokedex
===========================[ Pokédex ]==========================
            Welcome to the Pokédex!  How can I help?
================================================================
Enter command: a 1 Bulbasaur 0.7 6.9 poison grass
exiting because you have not implemented the add_pokemon function in pokedex.c


// Add a new Pokemon to the Pokedex.
// Note: just adding the Pokemon to the Pokedex does not mean it has
// been 'found'.
//
// The new Pokemon should be added to the end of the Pokedex (i.e.
// directly after the Pokemon that was added when add_pokemon was last
// called).
//
// When the first Pokemon is added to the Pokédex, the currently
// selected Pokemon becomes this Pokemon.
//
// The currently selected Pokemon remains the first Pokemon that was
// inserted into the Pokedex, until the `change_current_pokemon`,
// `next_pokemon`, or `prev_pokemon` functions are called.
//
// If there is already a Pokemon in the Pokedex with the same pokemon_id
// as this Pokemon, the function should print an appropriate error
// message and exit the program.
//
// Pokedex Order:
// --------------
// The Pokemon in the Pokedex are stored in the order in which they were
// added, i.e. the first Pokemon in the Pokedex will be the first
// Pokemon that was added, the second Pokemon in the Pokedex will be the
// second Pokemon that was added etc, and the last Pokemon in the
// Pokedex will be the Pokemon that was added most recently.
//
// For example, if Pikachu (#025) was added into an empty Pokedex, the
// Pokedex would now contain Pikachu at the start of the list, and
// Pikachu would be the currently selected Pokemon.
//
// [Start of Pokedex]
// #025: Pikachu <-- currently selected Pokemon
// [End of Pokedex]
//
// If Squirtle (#007) was then added, it would be the second Pokemon in
// the Pokedex, after Pikachu. The currently selected Pokemon would
// remain Pikachu.
//
// [Start of Pokedex]
// #025: Pikachu <-- currently selected Pokemon
// #003: Squirtle
// [End of Pokedex]
//
// If Diglett (#050) was then added, it would be the third Pokemon in the
// Pokedex, after Squirtle.
//
// [Start of Pokedex]
// #025: Pikachu <-- currently selected Pokemon
// #003: Squirtle
// #050: Diglett
// [End of Pokedex]
void add_pokemon(Pokedex pokedex, Pokemon pokemon);
```




https://cgi.cse.unsw.edu.au/~cs1511/19T1/assignments/ass2/index.html
