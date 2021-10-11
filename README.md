# COMP1511-19T1

Hey everyone,
I'm Jay and currently doing my CompSci/Commerce degree in UNSW. 
It's my first summer holiday in uni and kinda boring, so I decide to upload my comp labs/ assignments/ notes to github
not only help the new students get some ideas from my codes
but also help myself doing some reivision for my whole 2019 computer science studies.


# COCO CARD GAME
The Rules of Coco
Coco is an unusual card game invented by the great mathematician John von Neumann.

Cards
Coco is played with a deck of 40 cards.

The cards are numbered 10 to 49.

No two cards have the same number.

The 11 cards with prime numbers ([11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]) have special significance. The card numbered 42, usually called the The Douglas, also has special significance. This is described below.

Game Play
Coco is played by four players sitting around a circular table. These players are numbered clockwise: 0, 1, 2 and 3. The deck is divided randomly among the 4 players. So each player starts with a hand of 10 cards.

Stage 1: Discarding
In the first stage of play, each player selects three cards from their hand to be passed to the player on their left (clockwise). They, of course, then receive three cards from the player on their right. So player 0 passes to player 1, player 1 to player 2, player 2 to player 3 and player 3 to player 0.

The four players simultaneously select the three cards to be passed on. Each player must pass on 3 cards, before receiving the three cards from the player on their right. Hence, you must select the three cards you will pass to the player on your left before you know which three cards you have been given by the player on your right.

Stage 2: Playing Cards
The second stage of play consists of a series of 10 rounds. The goal of the game is to avoid penalty points during these ten rounds.

A round begins with a designated player selecting a card from their hand and playing it. Then proceeding clockwise, the other players, in turn, each select a card from their hand and play it.

Hence for the first round, each player will have ten cards in their hand to select from, for the second round they will have nine cards in their hand and so on. For the tenth and last round, each player will have only one card and hence, no choice in the card they play.

Playing a Card
The first card played in a round is important. It determines the cards following players are allowed to play.

If the first card played has a prime number the subsequent players must play a prime-numbered card, if they have one.

If the first card played has a prime number and a player does not have any card with a prime number, they are allowed to play any card in their hand.

If the first card played does not have a prime number, then subsequent players must play a card with a number which is cocomposite (defined below) with the first card, if they have one.

If the first card played does not have a prime number and a player does not have any card which is cocomposite with the first card played, they are allowed to play any card in their hand.

Cocomposite Definition
Two numbers x and y are cocomposite if they have a common factor other than 1, x and y.

For example: 14 and 49 are cocomposite because 7 is a factor of both.

For example: 15 and 45 are cocomposite because 3 & 5 are common factors.

For example: 25 and 49 are not cocomposite because they have no common factor other than 1.

For example: 3 and 9 are not cocomposite because they have no common factor other than 1 and 3.

Winning a Round
If the first card played has a prime number the round is won by the person who plays the card with the largest prime number.

If the first card played does not have a prime number the round is won by the person who plays the card with the largest number which is cocomposite with the first card played.

Player 0 plays the first card of the first round. Subsequently the winner of each round plays the first card of the next round.

If, for example, player 2 won the last round, then player 2 would play the first card of the next round and then players 3, 0 and 1 would play in that order.

Hint: winning rounds is not the aim of Coco. Sometimes winning a round is bad - see below..

Restriction: Playing A Prime-Numbered Card as the First Card
One restriction to the above rules is that a player is not allowed to play a prime-numbered card as the first card in a round unless a prime-numbered card has been played in one of the previous rounds or they have only prime-numbered cards in their hand.

In other words, if no prime-numbered cards have been previously played, a prime-numbered card cannot be played as the first card of a round unless the player has no choice.

This restriction does not apply to playing a prime-numbered card as the second, third or fourth card in a round.

In other words, if a non-prime card is played as the first card and a player does not have a cocomposite numbered card in their hand, they may play a prime numbered card.

There is no restriction on when The Douglas (42) can be played as the first card.

Penalty Points
The aim of Coco is to avoid penalty points. A player scores penalty points if certain cards occur in rounds they have won. Each prime-numbered card is worth one penalty point and The Douglas (the card numbered 42) is worth 7 penalty points.

Hence, generally players try to avoid winning rounds which contain prime-numbered cards and they particularly try to avoid winning rounds which contain The Douglas (42).

If a round doesn't contain a prime-numbered card or The Douglas (42) it doesn't affect the score.

When all 10 rounds are played the penalty points are calculated for each player. The winner of the game is the player with the fewest penalty points.

If a player attempts to play an illegal card they receive five penalty points. The referee will instead select a legal card from their hand at random. The same applies to discards.

https://cgi.cse.unsw.edu.au/~cs1511/19T1/assignments/ass1/index.html

# Pokédex and Pokémon
What is a Pokémon? What is a Pokédex?
Hello there! Welcome to the world of Pokémon! My name is Oak! People call me the Pokémon Prof! This world is inhabited by creatures called Pokémon! For some people, Pokémon are pets. Others use them for fights. Myself ... I study Pokémon as a profession. — Professor Oak

Pokémon are fictional creatures from the Pokémon franchise, most famously from the Pokémon games. The game revolves around the (questionably ethical) capturing of these creatures. Within the fiction of this universe, a device called the Pokédex is used to catalogue all the creatures a player finds and captures.

