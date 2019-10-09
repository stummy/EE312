#include<iostream>

#include "Deck.h"
#include "Hand.h"

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


using namespace std;

int main() {
    Deck deck;
    Hand playerOne;
    Hand playerTwo;
    vector<Card> playerOnePot;
    vector<Card> playerTwoPot;
    bool warBool = false;
    int warCount = 0;
    int rounds = 0;

    //shuffle the deck first
    deck.shuffle();

    // distribute the cards
    int deckSize = deck.getDeckSize();
    for (int i = 0; i < deckSize; i++) {
        // deal playerOne
        if(i % 2 == 0) {
            playerOne.addCard(deck.dealCard());
        }
        // deal playerTwo
        else {
            playerTwo.addCard(deck.dealCard());
        }
    }
    cout << "Hand of Player 1:" << endl;
    cout << playerOne.toString() << endl;

    cout << "Hand of Player 2:" << endl;
    cout << playerTwo.toString() << endl;

    /* ~~~~~PLAY WAR!~~~~~ */
    while(!playerOne.isEmpty() && !playerTwo.isEmpty() && rounds < 5000) {
        // if a war, add face down to winning pot
        if(warBool== true){
            Card faceDownOne = playerOne.getNext();
            Card faceDownTwo = playerTwo.getNext();
            playerOnePot.push_back(faceDownOne);
            playerTwoPot.push_back(faceDownTwo);

        }
        // face up cards, add to winning pot
        Card cardOne;
        Card cardTwo;
        try {
            cardOne = playerOne.getNext();          // check for cardOne
        } catch (const char* s) {
            break;
        }
        try {
            cardTwo = playerTwo.getNext();          // check for cardTwo
        } catch (const char* s) {
            break;
        }
        playerOnePot.push_back(cardOne);
        playerTwoPot.push_back(cardTwo);

        int cardOneVal = cardOne.getValue();
        int cardTwoVal = cardTwo.getValue();

        // check for aces
        if(cardOneVal == 1)
            cardOneVal = 14;
        if(cardTwoVal == 1)
            cardTwoVal = 14;

        //if player 1 wins, give winning pot to player 1
        if(cardOneVal > cardTwoVal){
            // add player 1's pot first, then player 2's
            for (vector<Card>::iterator itr = playerOnePot.end()-1; itr >= playerOnePot.begin(); itr--){
                playerOne.addCard(*itr);
            }
            for (vector<Card>::iterator itr = playerTwoPot.end()-1; itr >= playerTwoPot.begin(); itr--){
                playerOne.addCard(*itr);
            }
            playerOnePot.clear();
            playerTwoPot.clear();
            warBool = false;
            rounds++;
        }
        //else if player 2 wins, give winning pot to player 2
        else if(cardOneVal < cardTwoVal){
            // add player 2's pot first, then player 1's
            for (vector<Card>::iterator itr = playerTwoPot.end()-1; itr >= playerTwoPot.begin(); itr--){
                playerTwo.addCard(*itr);
            }
            for (vector<Card>::iterator itr = playerOnePot.end()-1; itr >= playerOnePot.begin(); itr--){
                playerTwo.addCard(*itr);
            }
            playerOnePot.clear();
            playerTwoPot.clear();
            warBool = false;
            rounds++;
        }
        //else WAR!!!
        else if(cardOneVal == cardTwoVal){
            if(!warBool)
                warCount++;
            warBool = true;
        }
    }

    //if player 1 empty, player 2 won
   if(playerOne.isEmpty()) {
        cout << "Player 1 lost after " << rounds << " rounds. "<< endl;
        cout << "There were " << warCount << " wars. "<< endl;
    }
    //if player 2 empty, player 1 won
    if(playerTwo.isEmpty()) {
        cout << "Player 2 lost after " << rounds << " rounds. "<< endl;
        cout << "There were " << warCount << " wars. "<< endl;
    }
    //if rounds 5000+, tie
    if(rounds >= 5000) {
        cout << "The game was a draw after 5000 rounds." << endl;
        cout << "There were " << warCount << " wars. "<< endl;
    }

}
