// Assignment 2 19T1 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Jay (z5261536)
// on 2019.04.29
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Added pointer check for the provided tests.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"


// Sample data on Bulbasaur, the Pokemon with pokemon_id 1. 
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE

// Sample data on Pikachu, the Pokemon with pokemon_id 25.
#define PIKACHU_ID 25
#define PIKACHU_NAME "Pikachu"
#define PIKACHU_HEIGHT 6.0
#define PIKACHU_WEIGHT 6.0
#define PIKACHU_FIRST_TYPE ELECTRIC_TYPE
#define PIKACHU_SECOND_TYPE NONE_TYPE

static void test_detial_pokemon(void); 
static void test_get_current_pokemon(void); // (used)
static void test_remove_pokemon(void); // (checked)
static void test_prev_pokemon(void); // (checked)
static void test_find_current_pokemon(void); // (uesed)
static int is_same_pokedex(Pokedex first, Pokedex second); // (used)
static void test_change_current_pokemon(void); // (checked)
static void test_evolution(void); // (checked)

// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void); // (checked)
static void test_add_pokemon(void); // (checked)
static void test_get_found_pokemon(void); // (checked)
static void test_next_pokemon(void); // (checked)

// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static Pokemon create_pikachu(void);
static int is_same_pokemon(Pokemon first, Pokemon second);
static int is_copied_pokemon(Pokemon first, Pokemon second);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_prev_pokemon();
    test_get_found_pokemon();
    test_find_current_pokemon();
    test_change_current_pokemon();
    test_remove_pokemon();
    test_evolution();
    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - adding additional Pokemon other than just Bulbasaur, (Y)
//   - checking whether the currently selected Pokemon is correctly set, (Y)
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added, 
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    
    printf("    ... Creating Pikachu\n"); // additional pokemon
    Pokemon pikachu = create_pikachu();
    
    printf("    ... Adding Pikachu to the Pokedex\n");
    add_pokemon(pokedex, pikachu);
    
    // check the current selected pokemon
    printf("       --> Checking that the current Pokemon is Bulbasaur\n"); 
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("       --> Checking the correct Pokemon were added\n");
    assert(count_total_pokemon(pokedex) == 2); // count_total_pokemon works
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex, (Y)
//   - calling the next_pokemon function when there is no "next" Pokemon,(Y)
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("    ... Creating Pikachu\n"); // additional pokemon
    Pokemon pikachu = create_pikachu();
    
    printf("    ... Adding Pikachu to the Pokedex\n");
    add_pokemon(pokedex, pikachu);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    // additional moving
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Pikachu\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), pikachu));
    
    // there is no "next" pokemon
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is still Pikachu\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), pikachu));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}

// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex, (Y)
//   - calling the get_found_pokemon function on a Pokedex where none of 
//     the Pokemon have been found, (Y)
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex), (Y)
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly, 
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Checking found Pokemon when Pokedex is empty\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex); 
    
    printf("       --> Checking no Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 0);
    assert(count_found_pokemon(found_pokedex) == 0);
    
    printf("    ... Creating Bulbasaur,Ivysaur and Pikachu\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon pikachu = create_pikachu();

    printf("    ... Adding Bulbasaur, Pikachu and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur); // id:001
    add_pokemon(pokedex, pikachu); // id:025
    add_pokemon(pokedex, ivysaur); // id:002

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Checking when none of the pokemon have been found\n");
    found_pokedex = get_found_pokemon(pokedex); 
    
    printf("       --> Checking no Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 0);
    assert(count_found_pokemon(found_pokedex) == 0);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Getting all found Pokemon\n");
    found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were found\n");
    assert(count_total_pokemon(found_pokedex) == 1);
    assert(count_found_pokemon(found_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));
    
    printf("    ... Moving to the next pokemon Pikachu\n");
    next_pokemon(pokedex);
    
    printf("    ... Setting pikachu to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Getting all found Pokemon\n");
    found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 2);
    assert(count_found_pokemon(found_pokedex) == 2);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(found_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Write your own Pokedex tests here!

// `test_prev_pokemon` checks whether the prev_pokemon function works
// correctly.
//
// It does this by creating three Pokemon: Bulbasaur and Ivysaur and Pikachu 
// (using the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.

// Then checks that calling the prev_pokemon function changes the currently
// selected Pokemon from Ivysaur to Bulbasaur.
// 
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex, (Y)
//   - calling the prev_pokemon function when there is no "previous" Pokemon,(Y)
//   - ... and more!
static void test_prev_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("    ... Creating Pikachu\n");
    Pokemon pikachu = create_pikachu();
    
    printf("    ... Adding Pikachu to the Pokedex\n");
    add_pokemon(pokedex, pikachu);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    // there is no "previous" pokemon
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is still Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed prev_pokemon tests!\n");
}



// `test_find_current_pokemon` checks whether the find_current_pokemon
// function works correctly.
//
// It does this by creating three Pokemon: Bulbasaur and Ivysaur and Pikachu
// (using the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// find_current_pokemon function make the currently selected Pokemon been found.

static void test_find_current_pokemon(void) {
    printf("\n>> Testing find_current_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur and Pikachu\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon pikachu = create_pikachu();
    
    printf("    ... Adding Bulbasaur and Ivysaur and Pikachu to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, pikachu);

    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur ));
    
    printf("       --> Finding the current Pokemon Bulbasaur\n");
    find_current_pokemon(pokedex);
    
    
    printf("       --> Checking that the current Pokemon Bulbasaur is found\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);
    assert(count_found_pokemon(found_pokedex) == 1);

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("       --> Finding the current Pokemon Ivysaur\n");
    find_current_pokemon(pokedex);
    
    printf("       --> Checking that both Ivysaur and Bulbasaur are found\n");
    found_pokedex = get_found_pokemon(pokedex);
    assert(count_found_pokemon(found_pokedex) == 2);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed remove_pokemon tests!\n");
}




// `test_change_current_pokemon` checks whether the change_current_pokemon
// function works correctly.
//
// It does this by creating three Pokemon: Bulbasaur and Ivysaur and Pikachu
// (using the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// change_current_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//

static void test_change_current_pokemon(void) {
    printf("\n>> Testing change_current_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur and Pikachu\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon pikachu = create_pikachu();
    
    printf("    ... Adding Bulbasaur and Ivysaur and Pikachu to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, pikachu);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    // Pikachu's id is 25
    printf("    ... Changing the current Pokemon to Pikachu\n");
    change_current_pokemon(pokedex, 25);
    
    printf("       --> Checking that the current Pokemon is Pikachu\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), pikachu));
       
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed change_current_pokemon tests!\n");
}


// `test_remove_pokemon` checks whether the remove_pokemon
// function works correctly.
//
// It does this by creating three Pokemon: Bulbasaur and Ivysaur and Pikachu
// (using the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// remove_pokemon function removes the currently selected Pokemon.
// 

static void test_remove_pokemon(void) {
    printf("\n>> Testing remove_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur and Pikachu\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon pikachu = create_pikachu();
    
    printf("    ... Adding Bulbasaur and Ivysaur and Pikachu to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, pikachu);

    // remove the none-last pokenode
    printf("    ... Removing the currently selected Pokedex\n");
    remove_pokemon(pokedex); 
    
    // three Pokemons remove one, only left two
    printf("       --> Checking the correct Pokemon were removed\n");
    assert(count_total_pokemon(pokedex) == 2);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Pikachu\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), pikachu));
    
    // remove the last pokenode
    printf("    ... Removing the currently selected Pokedex\n");
    remove_pokemon(pokedex); 
    
    // two Pokemons remove one, only left one
    printf("       --> Checking the correct Pokemon were removed\n");
    assert(count_total_pokemon(pokedex) == 1);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed remove_pokemon tests!\n");
}


// `test_evolution` checks whether the add_pokemon_evolution and 
// get_next_evolution function works correctly.
//
// It does this by creating three Pokemon: Bulbasaur and Ivysaur and Pikachu
// (using the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then calling the add_pokemon_evolution 
// function for evoluting the Bulbasaur to Pikachu.
// 
// Then calling the function again for makeing Pikachu envolve to Ivysaur.
// The correct result will be
// #001 Bulbasaur --> #025 Pikchu --> #002 Ivysaur

// Then calling get_next_evolution function to check everything work correctly.
 
static void test_add_pokemon_evolution(void);
// void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id);
static void test_get_next_evolution (void);
// int get_next_evolution(Pokedex pokedex);



static void test_evolution(void) {
    printf("\n>> Testing add_pokemon_evolution and get_next_evolution function\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur and Pikachu\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon pikachu = create_pikachu();
    
    printf("    ... Adding Bulbasaur and Ivysaur and Pikachu to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, pikachu);

    // Bulbasaur id:001  Pikachu id:025
    printf("    ... Evoluting the Pokemon Bulbasaur to Pikachu\n");
    add_pokemon_evolution(pokedex, 1, 25);
    

    // Pikachu id:025  Ivysaur id:002
    printf("    ... Evoluting the Pokemon Pikachu to Ivysaur\n");
    add_pokemon_evolution(pokedex, 25, 2);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur \n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Getting the next evolution of the pokemon\n");
    int id = get_next_evolution(pokedex);
    
    printf("       --> Checking that the next evolution is Pikachu\n");
    assert(id == pokemon_id(pikachu));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed test_evolution tests!\n");
}



////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to compare whether two Pokemon are the same.
// This checks that the two pointers contain the same address, i.e.
// they are both pointing to the same pokemon struct in memory.
//
// Pokemon ivysaur = new_pokemon(0, 'ivysaur', 1.0, 13.0, GRASS_TYPE, POISON_TYPE)
// Pokemon also_ivysaur = ivysaur
// is_same_pokemon(ivysaur, also_ivysaur) == TRUE
static int is_same_pokemon(Pokemon first, Pokemon second) {
    return first == second;
}

// Helper function to compare whether one Pokemon is a *copy* of
// another, based on whether their attributes match (e.g. pokemon_id,
// height, weight, etc).
// 
// It also checks that the pointers do *not* match -- i.e. that the
// pointers aren't both pointing to the same pokemon struct in memory.
// If the pointers both contain the same address, then the second
// Pokemon is not a *copy* of the first Pokemon.
// 
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int is_copied_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (first != second)
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}


// Helper function to create Pikachu for testing purposes.
static Pokemon create_pikachu(void) {
    Pokemon pokemon = new_pokemon(
            PIKACHU_ID, PIKACHU_NAME,
            PIKACHU_HEIGHT, PIKACHU_WEIGHT,
            PIKACHU_FIRST_TYPE,
            PIKACHU_SECOND_TYPE
    );
    return pokemon;
}

