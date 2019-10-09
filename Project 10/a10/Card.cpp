#include<cstdlib>
#include<time.h>
#include "Card.h"

using namespace std;

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

/* Function: Card
 * Description: default constructor function
 * Input: -
 * Output: -
 */
Card::Card(){
    srand(time(NULL));
    suit = rand() % 4;
    value = rand() % 13 + 1;
}

/* Function: Card
 * Description: constructor function
 * Input: suit and value
 * Output: -
 */
Card::Card(int suit, int value){
    this->suit = suit;
    this->value = value;
}

/* Function: getValue
 * Description: accessor function for card's value
 * Input: -
 * Output: int
 */
int Card::getValue(){
    return value;
}

/* Function: getSuit
 * Description: accessor function for card's suit
 * Input: -
 * Output: int
 */
int Card::getSuit(){
    return suit;
}

/* Function: getSuitAsString
 * Description: returns card's suit as string
 * Input: -
 * Output: string
 */
string Card::getSuitAsString() const{
    string suitStr = "";
    if(suit == 0)
        suitStr = "Clubs";
    else if(suit == 1)
        suitStr = "Diamonds";
    else if(suit == 2)
        suitStr = "Hearts";
    else if(suit == 3)
        suitStr = "Spades";
    return suitStr;
    
}

/* Function: getValueAsString
 * Description: returns card's value as string
 * Input: -
 * Output: string
 */
string Card::getValueAsString() const{
    string valStr = "";
    if(value >= 2 && value <= 10){
        if(value == 10)
            valStr += "10";
        else
            valStr += value + '0';
    }
    else if(value == 11)
        valStr = "Jack";
    else if(value == 12)
        valStr = "Queen";
    else if(value == 13)
        valStr = "King";
    else if(value == 1)
        valStr = "Ace";
    return valStr;
}

/* Function: toString
 * Description: returns card's suit and value as string
 * Input: -
 * Output: string
 */
string Card::toString() const{
    string toStr = "";
    toStr += getSuitAsString() + " of " + getValueAsString();
    return toStr;
}

/* Function: samesSuit
 * Description: returns T/F if suits are same
 * Input: Card
 * Output: bool
 */
bool Card::sameSuit(Card& other) {
    if(suit == other.getSuit())
        return true;
    else
        return false;
}

/* Function: samesSuit
 * Description: returns T/F if value are same
 * Input: Card
 * Output: bool
 */
bool Card::sameValue(Card& other) {
    if(value == other.getValue())
        return true;
    else
        return false;
}

/* Function: overloaded operator ==
 * Description: returns T/F if cards are same
 * Input: two Cards
 * Output: bool
 */
bool operator ==(Card& c1, Card& c2){
    if(c1.getSuit() == c2.getSuit() && c1.getValue() == c2.getValue())
        return true;
    else
        return false;
}

/* Function: overloaded <<
 * Description: returns output of Card
 * Input: ostream, Card
 * Output: ostream
 */
ostream& operator <<(ostream& output, const Card& c){
    output << c.toString();
    return output;
}


