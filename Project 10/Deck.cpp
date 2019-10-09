#include<cstdlib>
#include<time.h>

#include "Deck.h"

// EE 312 Project 10 -- The Game of War

/* Student information for project:
 *
 * On my honor, Zahra Atzuri, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Zahra Atzuri
 * email address: atzuri@utexas.edu
 * UTEID: zfa84
 * Section 5 digit ID: 11615
 * Number of slip days used on this assignment
 */

/* Project Description: This is a program that plays the card game "War".
 *  "The deck is divided evenly among the players, giving each a down stack.
 *  In unison, each player reveals the top card of their deck – this is a
 *  'War' – and the player with the higher card takes both of the cards
 *  played and moves them to their stack." - Wikipedia
 */

/* Function: Deck
 * Description: constructor for Deck
 * Input: -
 * Output: -
 */
Deck::Deck() {
    for (int i = 0; i < 4; ++i) {           // loop for suits
        for (int j = 1; j < 14; ++j) {      // loop for value
            myDeck.push_back(Card(i,j));
        }
    }
    top = 0;
    deckSize = myDeck.size();
}

/* Function: shuffle
 * Description: shuffles Deck
 * Input: -
 * Output: -
 */
void Deck::shuffle() {
    srand(time(NULL));
    int index1, index2;
    for (int i = 0; i < SHUFFLE; ++i) {
        // pick index1
        index1 = rand() % deckSize;
        Card c1 = myDeck.at(index1);
        // pick index2
        index2 = rand() % deckSize;
        // make sure that index1 is not the same as index2
        while(index1 == index2)
            index2 = rand() % deckSize;
        Card c2 = myDeck.at(index2);

        Card tmp = c1;
        myDeck.at(index1) = c2;
        myDeck.at(index2) = tmp;
    }
}

/* Function: dealCard
 * Description: deal a card and update deck
 * Input: -
 * Output: Card&
 */
Card& Deck::dealCard() {
    int temp = top;
    top++;
    deckSize--;
    return myDeck.at(temp);
}

/* Function: getTop
 * Description: accessor function for top
 * Input: -
 * Output: int
 */
int Deck::getTop() {
    return top;
}

/* Function: getDeckSize
 * Description: accessor function for deckSize
 * Input: -
 * Output: int
 */
int Deck::getDeckSize() {
    return deckSize;
}

/* Function: toString
 * Description: returns string of the Deck
 * Input: -
 * Output: string
 */
string Deck::toString() {
    string out = "";
    for (vector<Card>::iterator itr = myDeck.begin(); itr != myDeck.end(); itr++){
        out += (*itr).toString() + "\n";
    }
    return out;
}

    
	    
