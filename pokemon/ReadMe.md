# Pokédex and Pokémon
What is a Pokémon? What is a Pokédex?
Hello there! Welcome to the world of Pokémon! My name is Oak! People call me the Pokémon Prof! This world is inhabited by creatures called Pokémon! For some people, Pokémon are pets. Others use them for fights. Myself ... I study Pokémon as a profession. — Professor Oak

Pokémon are fictional creatures from the Pokémon franchise, most famously from the Pokémon games. The game revolves around the (questionably ethical) capturing of these creatures. Within the fiction of this universe, a device called the Pokédex is used to catalogue all the creatures a player finds and captures.

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


# Stage 1: Adding and Printing
```
$ dcc -o pokedex main.c pokedex.c pokemon.c
$ ./pokedex
===========================[ Pokédex ]==========================
            Welcome to the Pokédex!  How can I help?
================================================================
Enter command: a 1 Bulbasaur 0.7 6.9 poison grass
exiting because you have not implemented the add_pokemon function in pokedex.c
```




https://cgi.cse.unsw.edu.au/~cs1511/19T1/assignments/ass2/index.html
