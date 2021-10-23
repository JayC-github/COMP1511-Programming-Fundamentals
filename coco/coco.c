// Assignment 1 19T1 COMP1511 Coco
//
// This program was written for playing the card game Coco.
// Coco is an unusual card game invented by 
// the great mathematician John von Neumann.
// https://en.wikipedia.org/wiki/John_von_Neumann
// 
// This progarm has three stages:
// Print your player name;
// Select the cards to discard;
// Select which card to play;
// 
// Strategy for discarding card: Always discard the three largest card.
// Strategy for playing card: Avoid being winner (playing the largest    
// card) in each round unless your card is not counted in this round.
//
// This program was written by Jay (z5261536)
// on 2019.04.01
//

#include <stdio.h>
#include <assert.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3
#define N_CARDS_RECEIVED      3 // IF YOU NEED MORE #defines ADD THEM HERE

#define CARD_MIN             10
#define CARD_MAX             49



void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);
int check_prime(int num); // ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
int check_compo(int num1, int num2);


// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {

    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME

    printf("Jayjayjay\n");

}

void choose_discards() {

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    int i; // counter to read the cards of your hand.
    int array[N_CARDS_INITIAL_HAND]; // collect all cards of your hand. 
    int j; // counter to print out the 3 discarded card.
    i = 0;
    while (i < N_CARDS_INITIAL_HAND) {
        scanf("%d", &array[i]);    
        i++;
    }
    
    j = 7; // Discard the largest 3 cards in my hand,array[7]..aray[9].
    while (j < N_CARDS_INITIAL_HAND) {
        printf("%d ", array[j]);    
        j++;
    }
    
}

void choose_card_to_play(void) {
    
    // ADD CODE TO READ THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
    int i; //counter for all the while loops
    int cards_in_hand, played_cards, table_position;
    // card_in_hand = NUMBER OF CARDS IN YOUR HAND 
    // played_cards = NUMBER OF CARDS PLAYED THIS ROUND
    // table_position = TABLE POSITION              
                                          
    scanf("%d %d %d", &cards_in_hand, &played_cards, &table_position);
    
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    
    int hCard[cards_in_hand]; // collect the cards of my Hand.(h)
    if (cards_in_hand > 0) {
        i = 0;
        while (i < cards_in_hand) {
            scanf("%d", &hCard[i]);
            i++;
        }
    }
    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int pCard[4];// Array for the cards previously Played this round.(p)
    if (played_cards > 0) {
        i = 0;
        while (i < played_cards) {
            scanf("%d", &pCard[i]);
            i++;
        }
    }
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int gCard[N_CARDS] = {0};// cards played in the history of the Game(g)
    if (cards_in_hand < 10) { 
        i = 0;
        while (i < (10-cards_in_hand)*4) { 
            scanf("%d", &gCard[i]);
            i++;
        }
    }
    
    int discarded[N_CARDS_DISCARDED]; // Array for the 3 discarded cards. 
    i = 0;
    while (i < N_CARDS_DISCARDED) {
        scanf("%d", &discarded[i]);
        i++;
    }
    
    int received[N_CARDS_RECEIVED]; // Array for the 3 received cards.
    i = 0;
    while (i < N_CARDS_RECEIVED) {
        scanf("%d", &received[i]);
        i++;
    }
    
 
// Collect the prime number and non-prime number cards into 3 diffenrent new arrays.
    int prime[10] = {0};
    int non_prime[10] = {0}; // Their size always less or equal to 10
    int cocom[10] = {0};
    
    int primeNum = 0; // counter for collect the prime numbers
    int nonPrime = 0; // counter for collect the non-prime numbers.
    int cocomNum = 0; // counter for collect the cocomposite numbers.
// Collect the prime number card    
    if (cards_in_hand > 0) {
        i = 0; // counter for checking number is prime or not
        while (i < cards_in_hand) {
            if (check_prime(hCard[i]) == 0) { // 0 means you have prime card
                prime[primeNum] = hCard[i];
                primeNum ++;        
            } else {                        
// Then collect non-prime number card also include cocomposite number card.
                non_prime[nonPrime] = hCard[i]; 
                nonPrime ++;
                if (played_cards > 0 && check_compo(pCard[0], hCard[i]) == 0) {
                    cocom[cocomNum] = hCard[i];
                    cocomNum ++;
                }
            }        
            i++;
        }
    }

// Check if there has a prime-numbered card been played in previous Game round or not.    
    int pnCard = 0; // pnCard = 0 means no prime-numbered card played
                    // pnCard not equal 0 means it has prime card played.
    if (cards_in_hand < 10) {
        i = 0;
        while (i < (10-cards_in_hand)*4) { // size always less than 40         
            if (check_prime(gCard[i]) == 0) { // prime card played in previous Game.
                pnCard++;                          
            }        
            i++;
        }        
    }
    
    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    
// Firstly check if you play the first card in a round or not

// This part is for when you are the first player in a round.    
    
    if (played_cards == 0) { // You playing the first card in a round. 
// Check if there has a prime-numbered card been played in previous Game round or not.
        if (pnCard != 0) { // It has prime card been played.                                  
            printf("%d\n", hCard[0]); // You can play any card
                                      // play the smallest card in your hand.   
                                                // or
        } else {                      // no prime number card played yet.
                                      // check if you have non-prime card or not.                           
            if (nonPrime != 0) {      // you have non-prime number.
                printf("%d\n", non_prime[0]); // play the smallest non-prime card.
            
            } else {                 // you don't have non-prime number card.
                printf("%d\n", hCard[0]); // play the smallest card in your hand.
            }    
        }
    }

// This part is for when you are not the first player in a round.    
    if (played_cards != 0) { // You playing not-first in a round.
// Check if the first played card was prime or not.        
// Yes,the first card was prime.        
        if (check_prime(pCard[0]) == 0) { 
// Check if you have a prime card or not.
            if (primeNum != 0) { // primeNum is not equal 0, you have prime card.
                printf("%d\n", prime[0]); // Then print the smallest prime card.    
            } else {                      // You don't have any prime card.
                printf("%d\n", hCard[cards_in_hand - 1]); // play the largest
                                                          // card in your hand.   
            }                             // do not count in this round anyways
        
        } else {                             
// No,the first card was not prime.
// Check if you have a cocomposite card.            
            if (cocomNum != 0) {  // you have cocomposite card
                printf("%d\n", cocom[0]); // play the smallest cocomposite card.           
            } else {                      // No cocomposite card.
                printf("%d\n", hCard[cards_in_hand - 1]); // play the largest
                                                          // card in your hand.    
            }                             // do not count in this round anyways 
        }
    }
}
// ADD YOUR FUNCTIONS HERE
// The function to check the prime number.(0 prime, 1 not)
int check_prime(int num) {  
    int i = 2;
    while (i < num) {
        if (num%i == 0) {
            return 1;// 1 means it's non-prime number
        }
        i++;
    }                
    return 0;// 0 means it's prime number
}

// The function to check the cocomposite number (0 cocomposite, 1 not)
int check_compo(int num1, int num2) {
    int i = 2;        
    while (i < 49) {  // factor can't be greater than 49.
        if (num1%i == 0 && num2%i == 0 && 
            num1 != i && num2 !=i) {
            return 0; // 0 means these two numbers are cocomposite.     
        }
        i++;    
    }
    return 1; // 1 means these two numbers are not cocomposite.        
}
