// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
// This program was written for making a mini Pokédex
//
// Pokémon are fictional creatures from the Pokémon franchise, most
// famously from the Pokémon games. The game revolves around the
// (questionably ethical) capturing of these creatures. Within the fiction
// of this universe, a device called the Pokédex is used to catalogue all 
// the creatures a player finds and captures.
//
// http://pokemon.wikia.com/wiki/Pok%C3%A9dex
//
//
// This program was written by Jay (z5261536)
// on 2019.04.28
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.
// Version 1.1.1: Renamed "pokemon_id" to "id" in change_current_pokemon.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pokedex.h"

struct pokedex {
    struct pokenode *head;
};


struct pokenode {
    struct pokenode *next;
// next evolution of the pokemon
    struct pokenode *evolution; 
    Pokemon pokemon;
// select = 1 means pokenode is currently selected, 0 means not
    int selected;   
// found = 1 means the pokenode is "found", 0 means not
    int found;    
};



static struct pokenode *new_pokenode(Pokemon pokemon);
static void add_to_end(Pokedex pokedex, struct pokenode *node);
static void star(char *pointer);
static void printPoke(struct pokenode *current);
static int match(char pokemon[], char text[]);
static struct pokenode *selected(Pokedex pokedex);


Pokedex new_pokedex(void) {
// ask for new memory
    Pokedex new_pokedex = malloc(sizeof (struct pokedex)); 
// check melloc success
    assert(new_pokedex != NULL); 
    new_pokedex->head = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
// create pokenode for pokemon
    struct pokenode *node = new_pokenode(pokemon); 
// add each new pokenode to the end of pokedex
    add_to_end(pokedex, node); 
}

void detail_pokemon(Pokedex pokedex) {
// pokedex is empty
    if (pokedex->head == NULL) { 
        printf("Pokedex is empty.\n");
        exit(1);
    } else { // currently selected pokenode
        struct pokenode *current = selected(pokedex);
// print the detail of currently selected pokenode         
        printPoke(current);       
    }

}

Pokemon get_current_pokemon(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        printf("No currently selected pokemon.\n");
        exit(1);
    } else { // you have currently selected pokenode
        struct pokenode *current = selected(pokedex); 
// get the currently selected pokemon
        Pokemon curPokemon = current->pokemon; 
        return curPokemon;
    }
}

void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
// currently selected pokemon(pokenode)
        struct pokenode *current = selected(pokedex); 
// make currently selected pokemon found
        current->found = 1;  
    }
}

void print_pokemon(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    while (current != NULL) {
        Pokemon pokemon = current->pokemon;
// If it's not the currently selected pokemon        
        if (current->selected == 0) { 
            if (current->found == 0) { // neither currenly selected nor found
                printf("    #%03d: ", pokemon_id(pokemon));
                star(pokemon_name(pokemon)); // print ******
                printf("\n");
            } else { // not currently selected pokemon but been found
                printf("    #%03d: %s\n", pokemon_id(pokemon), 
                pokemon_name(pokemon));      
            }
        }
        
// If it's currently selected pokemon        
        if (current->selected != 0) { 
            if (current->found == 0) { // currenly selected but not found
                printf("--> #%03d: ", pokemon_id(pokemon));
                star(pokemon_name(pokemon)); // print ******
                printf("\n");
            } else { // currently selected pokemon and been found
                printf("--> #%03d: %s\n", pokemon_id(pokemon), 
                pokemon_name(pokemon));      
            }
   
        
        }     
        current = current->next;
    }    
    
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
// Pokemon is in the Pokedex    
    if (pokedex->head != NULL) { 
// currently selected pokemon(pokenode)
        struct pokenode *current = selected(pokedex); 
        if (current->next != NULL) { 
            current->selected = 0;
            current->next->selected = 1; 
        } 
    
    }
}

void prev_pokemon(Pokedex pokedex) {
// Pokemon in the Pokedex
    if (pokedex->head != NULL) { 
        struct pokenode *previous = pokedex->head;
// currently selected pokemon is not in the first pokenode
// find the previous pokenode
        if (previous->selected != 1) {  
            while (previous->next != NULL) {
                if (previous->next->selected == 1) { // previous pokenode
                    break; 
                }
                previous = previous->next;
            }
            
            previous->selected = 1;
            previous->next->selected = 0; 
        } 
    }                            
}

void change_current_pokemon(Pokedex pokedex, int id) {
    if (pokedex->head != NULL) {
        struct pokenode *newCurrent = pokedex->head;    
// find the new Pokenode you need to change to
        while (newCurrent != NULL) { 
            if (id == pokemon_id(newCurrent->pokemon)) { 
                break;
            }
            newCurrent = newCurrent->next;
        } 

// currently selected pokemon(pokenode)        
        struct pokenode *current = selected(pokedex); 

// change the currently selected Pokenode to the new Pokenode (id:XX)
        if (newCurrent != NULL) { 
            current->selected = 0; 
            newCurrent->selected = 1;
        }    
    }
}

void remove_pokemon(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    struct pokenode *previous = pokedex->head;
    if (current != NULL) {
// only one pokemon in the pokedex
        if (current->next == NULL) { 
            destroy_pokemon(current->pokemon); // remove everything
            free(current);
            pokedex->head = NULL; 
        } else { 
// more than one pokemon in the pokedex
            while (current->selected != 1) { // currently selected pokenode
                previous = current;
                current = current->next; // find previous pokenode
            }
// current is not the end of the pokedex            
            if (current->next != NULL) { 
                current->next->selected = 1;
// first pokenode is currently selected 
                if (current == pokedex->head) { 
// link the pokedex head to the next pokenode of current pokenode
                    pokedex->head = current->next; 
                } else {
                    previous->next = current->next;
                }
                destroy_pokemon(current->pokemon);                
                free(current); 
            } else { 
// current is the end of the pokedex
// previous pokenode is now selected
                previous->selected = 1; 
                previous->next = NULL;
                destroy_pokemon(current->pokemon);
                free(current);  
            }
        } 
    }
}

// destroy all pokenodes in this pokedex
void destroy_pokedex(Pokedex pokedex) { 
    struct pokenode *current = pokedex->head;
    struct pokenode *temp;   
    while (current != NULL) {
        temp = current;
        current = current->next;
        destroy_pokemon(temp->pokemon);
        free(temp);
    }                              
                                    
    free(pokedex);
}
////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    srand(seed); 
    // counter check if there is a pokemon in pokedex fit the condition
    // encounter for how_many pokemon we need to explore
    // exploPoke is the radom number (pokemon id)     
    int counter, encounter, exploPoke;
    struct pokenode *current = pokedex->head;
    counter = 0;
    while (current != NULL) {
// if there is a pokemon's id in the pokedex between 0 to (factor - 1)
        if (pokemon_id(current->pokemon) <= factor - 1) {
            counter++;   
        }
        current = current->next;
    }  

// not possible to explore any Pokemon    
    if (counter == 0) { 
        printf("Factor is too small to explore any Pokemon");
        exit(1);
    }                                    
// create a random number between 0 to factor-1 to represent the pokemon id 
    exploPoke = rand() % factor; 
    encounter = 0;                
    while (encounter < how_many) {
        struct pokenode *check = pokedex->head;
        while (check != NULL) {
            if (pokemon_id(check->pokemon) == exploPoke) {
                check->found = 1;
            }
            check = check->next;
        }
        exploPoke = rand() % factor;
        encounter++;
    }

}    

// counter the number of pokemon that already been found    
int count_found_pokemon(Pokedex pokedex) { 
    struct pokenode *current = pokedex->head;
    int counter = 0;
    while (current != NULL) {
        if (current->found == 1) {
            counter++;
        }
        current = current->next;
    }
    return counter;
}

// count the total number of pokemon in the pokedex
int count_total_pokemon(Pokedex pokedex) { 
    struct pokenode *current = pokedex->head;
    int counter = 0;
    while (current != NULL) {
        counter++;
        current = current->next;
    }
    
    return counter;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
// pointer for checking each pokemon id in the pokedex
    struct pokenode *check = pokedex->head; 
// the original Pokemon
    struct pokenode *from = pokedex->head; 
// the evolution Pokemon
    struct pokenode *to = pokedex->head; 
    int check_from = 0; 
    int check_to = 0;
    while (check != NULL) {
        if (pokemon_id(check->pokemon) == from_id) {
            check_from = 1;
        }
        if (pokemon_id(check->pokemon) == to_id) {
            check_to = 1;
        }
        check = check->next;    
    }
// you must have different from_id and to_id    
    if (from_id == to_id || check_from == 0 || check_to == 0) {
        printf("Evolution fail.\n");
        exit(1);
    }
    
    while (from != NULL && pokemon_id(from->pokemon) != from_id) { 
// get the pokenode of the original Pokemon
        from = from->next; 
    }
    
    while (to != NULL && pokemon_id(to->pokemon) != to_id) {
// get the pokenode of evolution type Pokemon
        to = to->next; 
    }
// original Pokemon->evolution ---------> evolution type Pokemon    
    from->evolution = to; 
}

void show_evolutions(Pokedex pokedex) {
// currently selected pokenode (Pokemon)
    struct pokenode *current = selected(pokedex); 

    Pokemon pokemon = current->pokemon; 
// first type and second type of the currently selected pokemon (origin)    
    int first_type = pokemon_first_type(pokemon);
    int second_type = pokemon_second_type(pokemon);
// pokemon is not found    
    if (current->found == 0) { 
        printf("#%03d ???? [????]", pokemon_id(pokemon));
    } else { 
// pokemon is found
        printf("#%03d %s ", pokemon_id(pokemon), pokemon_name(pokemon));
// pokemon only have one type
        if (second_type == 0) { 
            printf("[%s]", pokemon_type_to_string(first_type));
        } else {
// pokemon have double type 
            printf("[%s, %s]", pokemon_type_to_string(first_type), 
            pokemon_type_to_string(second_type));
        }
    }
 
    while (current->evolution != NULL) {
        current = current->evolution;
        pokemon = current->pokemon;
        first_type = pokemon_first_type(pokemon);
        second_type = pokemon_second_type(pokemon);
        
        printf(" --> ");
// pokemon is not found        
        if (current->found == 0) { 
            printf("#%03d ???? [????]", pokemon_id(pokemon));
        } else { 
// pokemon is found
            printf("#%03d %s ", pokemon_id(pokemon), pokemon_name(pokemon));
// pokemon only have one type
            if (second_type == 0) { 
                printf("[%s]", pokemon_type_to_string(first_type));
            } else {
// pokemon have double type                
                printf("[%s, %s]", pokemon_type_to_string(first_type), 
                pokemon_type_to_string(second_type));
            }
        } 
    }
    
    printf("\n");
}

// next evolution type of the pokemon 
int get_next_evolution(Pokedex pokedex) { 
// pokedex is empty
    if (pokedex->head == NULL) { 
        printf("Pokedex is empty.\n");
        exit(1);
    } else {  
// currently selected pokenode(Pokemon)
        struct pokenode *current = selected(pokedex); 
        if (current->evolution != NULL) {
            int id = pokemon_id(current->evolution->pokemon);
            return id;
        } else {
            return DOES_NOT_EVOLVE;
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
// create a new pokedex for the specific type
    Pokedex typePokedex = new_pokedex(); 
    struct pokenode *current = pokedex->head;
    Pokemon pokemon; // = current->pokemon;
    int first_type; // = pokemon_first_type(pokemon);
    int second_type; // = pokemon_second_type(pokemon);
    Pokemon copyPokemon;
    if (type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE) {
        printf("Wrong type!"); // It's wrong type
        exit(1);
    } else {
        while (current != NULL) {
            if (current->found == 1) {
                pokemon = current->pokemon;
                first_type = pokemon_first_type(pokemon);
                second_type = pokemon_second_type(pokemon);
                
                if (first_type == type || second_type == type) {        
                    copyPokemon = clone_pokemon(pokemon);              
                    struct pokenode *node = new_pokenode(copyPokemon);
// set all correct pokemon been found then and add to the new pokedex
                    node->found = 1; 
                    add_to_end(typePokedex, node); 
                }        
            }
            current = current->next;
        }
    }
    return typePokedex;
}

Pokedex get_found_pokemon(Pokedex pokedex) {
// new pokedex for found pokenode
    Pokedex foundPokedex = new_pokedex();  
    Pokemon copyPokemon; 
    Pokemon pokemon;
    struct pokenode *current = pokedex->head; 
    while (current != NULL) {
 // pokenode is found
        if (current->found == 1) {
            pokemon = current->pokemon;
            copyPokemon = clone_pokemon(pokemon);              
            struct pokenode *node = new_pokenode(copyPokemon);
// set all correct pokemon been found then and add to the new pokedex
            node->found = 1; 
            add_to_end(foundPokedex, node); 
        }
        current = current->next;
    }
    
    struct pokenode *previous = foundPokedex->head;
    while (previous != NULL) {
        
        current = previous->next;
// like a bubble sort to make pokemon id in ascending order in the new pokedex
        while (current != NULL) {  
            if (current->found == 1) {
                if (pokemon_id(previous->pokemon) > pokemon_id(current->pokemon)) {
                    Pokemon temp = previous->pokemon;    
                    previous->pokemon = current->pokemon;
                    current->pokemon = temp;  
                }
            }
            current = current->next;
        }
            
        previous = previous->next;
    }
   
    return foundPokedex;
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {
// create new pokedex for searching pokenode
    Pokedex searchPokedex = new_pokedex();          
    Pokemon copyPokemon; 
    Pokemon pokemon;
    struct pokenode *current = pokedex->head;
    while (current != NULL) {
        if (current->found == 1) {
            pokemon = current->pokemon; 
            if (match(pokemon_name(pokemon), text) == 1) {
                copyPokemon = clone_pokemon(pokemon);              
                struct pokenode *node = new_pokenode(copyPokemon);
// change all the new pokenode been found
                node->found = 1; 
                add_to_end(searchPokedex, node); 
            }
        }
        current = current->next;
    }
    return searchPokedex;
}

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.


// Create a new pokenode and add pokemon to that pokenode.
static struct pokenode *new_pokenode(Pokemon pokemon) {
    struct pokenode *node = malloc(sizeof (struct pokenode));
// check malloc creat new memory
    assert(node != NULL); 
    node->pokemon = pokemon;
    node->next = NULL;
    node->evolution = NULL;
// set initial state of pokemon not found 
    node->found = 0; 
    return node; 
}

// add new pokenode to the end of the pokedex
static void add_to_end(Pokedex pokedex, struct pokenode *node) {
    if (pokedex->head == NULL) {
// selected = 1 means it's the first add node
        node->selected = 1;  
        pokedex->head = node;
    } else {
        struct pokenode *current = pokedex->head;
        while (current->next != NULL) { // stop at the last pokenode
            
            if (pokemon_id(node->pokemon) == pokemon_id(current->pokemon)) {
                printf("Same pokemon,error.\n");
                exit(1);
            }
            current = current->next;
        }
        
        if (current->next == NULL) { // curret is now the last pokenode
            if (pokemon_id(node->pokemon) == pokemon_id(current->pokemon)) {
                printf("Same pokemon,error.\n");
                exit(1);
            }            
        }
// selected = 0 means it's not the first add node.                       
        node->selected = 0; 
// add the pokenode to the end of the pokedex   
        current->next = node; 
    }
}

// print the star with numbers equal the length of the pokemon name
static void star(char *p) {
    int i = 0;
    while (p[i] != '\0') {
        printf("*");
        i++;
    }
}

// print the detial information of the pokemon
static void printPoke(struct pokenode *current) { // details for pokemon 
    Pokemon pokemon = current->pokemon;
    int first_type = pokemon_first_type(pokemon);
    int second_type = pokemon_second_type(pokemon);
    
    if (current != NULL) {
// pokemon is not found
        if (current->found == 0) { 
            printf("Id: %03d \n", pokemon_id(pokemon));
            printf("Name: ");
// print the "*"  
            star(pokemon_name(pokemon));
            printf("\n");
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");
        } else { 
// pokemon is found
            printf("Id: %03d \n", pokemon_id(pokemon));        
            printf("Name: %s\n", pokemon_name(pokemon));
            printf("Height: %.1lfm\n", pokemon_height(pokemon));  
            printf("Weight: %.1lfkg\n", pokemon_weight(pokemon));
            printf("Type: %s", pokemon_type_to_string(first_type)); 
            
            if (second_type != 0) {
                printf(" %s", pokemon_type_to_string(second_type));    
            }    
            printf("\n");  
        }
    } 
}

// function for seach pokemon
// return 1 means text and name match and return 0 means not match 
static int match(char pokemon[], char text[]) { 
// create character array for input text
    char input[1000]; 
    int i = 0; // counter
// length of the input text
    int inputlength = 0; 
// use character array to collect the input text
    while (text[i] != '\0') { 
        input[i] = text[i]; 
        inputlength++;
        i++;
    }
    
// change all the capital letter to lower case
    i = 0;
    while (i < inputlength) { 
        if ('A' <= input[i] && input[i] <= 'Z') {
            input[i] = input[i] - 'A' + 'a';
        }
        i++;
    }

// character array for pokemon name    
    char pokename[1000]; 
// length of the pokemon name
    int namLength = 0;   
    i = 0;
    while (pokemon[i] != '\0') {
        pokename[i] = pokemon[i];
        namLength++;
        i++;
    }
    
// change the pokename to lower case
    i = 0;
    while (i < namLength) { 
        if ('A' <= pokename[i] && pokename[i] <= 'Z') {
            pokename[i] = pokename[i] - 'A' + 'a';       
        }    
        i++;
    }
    
// pokemon name character position
    int pokem = 0; 
// input text character position
    int subword = 0; 
    while (pokem != namLength && subword != inputlength) {
// character match, both move to next character and check if match or not
        if (pokename[pokem] == input[subword]) {
            pokem++;        
            subword++;
// not match, text postion return to 0 and start to check again
        } else if (subword == 0) {
            pokem++;       
            subword = 0;  
        } else {
            subword = 0;
        }
         
    }
// input text and pokemon name match    
    if (subword == inputlength) {
        return 1;
// input text and pokemon name is not match
    } else { 
        return 0;
    }  

}

// function for currenly selected pokenode
static struct pokenode *selected(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    while (current != NULL) {
// find the currently selected pokenode
        if (current->selected == 1) { 
            break; // break the while loop
        }
        current = current->next;
    }
        
    return current;
}
