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

/* Function: Hand
 * Description: default constructor for Hand
 * Input: -
 * Output: -
 */
Hand::Hand() {
    size = 0;
    top = 0;
}

/* Function: getSize
 * Description: accessor function for size
 * Input: -
 * Output: int
 */
int Hand::getSize() {
    return size;
}

/* Function: toString
 * Description: returns string of cards in Hand
 * Input: -
 * Output: int
 */
string Hand::toString(){
    string out = "";
    for (vector<Card>::iterator itr = myHand.begin(); itr != myHand.end(); itr++) {
        out += (*itr).toString() + "\n";
    }
    return out;
}

/* Function: getTop
 * Description: accessor function for top
 * Input: -
 * Output: int
 */
int Hand::getTop() {
    return top;
}

/* Function: isEmpty
 * Description: checks if empty
 * Input: -
 * Output: bool
 */
bool Hand::isEmpty() {
    return size == 0;
}

/* Function: addCard
 * Description: adds a card to the Hand and update
 * Input: -
 * Output: -
 */
void Hand::addCard(Card& c) {
    myHand.push_back(c);
    size++;
}

/* Function: getNext
 * Description: removes and returns the top card from the Hand
 *      this method throws a string (a char array) if the Hand is empty.
 * Input: -
 * Output: Card&
 */
Card& Hand::getNext() {
    if(size == 0){
        char s[] = "Hand is empty!";
        throw s; // throws const char*
    }

    else {
        Card& temp = myHand.at(top);
        size--;
        top++;
        return temp;
    }
}


