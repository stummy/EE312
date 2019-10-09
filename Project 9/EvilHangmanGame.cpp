#include "EvilHangmanGame.h"
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

// EvilHangmanGame.cpp (or RunEvilHangman.cpp) -- EE 312 Project 9

/* Student information for project:
 *
 * On my honor, Zahra Atzuri, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Zahra Atzuri
 * email address: atzuri@utexas.edu
 * UTEID: zfa84
 * Section 5 digit ID: 11615
 * Number of slip days used on this assignment: 2
 */


/* Project Description: Evil Hangman is a program that cheats at Hangman.
 *      Instead of initially choosing a word from the dictionary that the
 *      player tries to guess, the program has a set of words that it
 *      updates as the user makes guesses.
 */


// ===================== Helper Functions =========================
/* Function: toLowerCase
 * Description: Converts a char from uppercase to lowecase
 * Input: char
 * Output: char
 */
char toLowerCase(char &letter) {
    if(letter >= 'A' && letter <= 'Z')            // compares if A-Z
        letter = letter - 'A' + 'a';              // changes it if lowercase
    return letter;
}

/* Function: generateMap
 * Description: A helper function to loop through the current word bank,
 *      generate the keys for a map, and then insert key/value to map
 * Input: map, set of current word bank, char guessed
 * Output: -
 */
void generateMap(map<string,set<string>> &wordMap, set<string> &currentWords, char guess) {
    string key;

    for(set<string>::iterator itr = currentWords.begin(); itr != currentWords.end(); ++itr) {
        key = *itr;
        for(unsigned int i = 0; i < key.length(); i++) {    // make key
            if (key[i] != guess)
                key[i] = '-';
        }
        wordMap[key].insert(*itr);       // insert(key,itr)
    }
}

/* Function: tieBreakerRightLetters
 * Description: A helper function to break a tie. Checks for a key that has
 *      rightmost guessed letter and it's set becomes current
 *      word bank (if applicable)
 * Input: map, set of current word bank, char guessed
 * Output: -
 */
yvoid tieBreakerRightLetters(map<string,set<string>> &wordMap, set<string> &currentWords, int wordLen) {
    string key;
    map<string,set<string>> temp;
    map<string,set<string>>::iterator k = wordMap.begin();

    for(int j = wordLen-1; j >= 0; --j) {
        while(k != wordMap.end()) {
            key = k->first;
            if(key[j] != '-'){
                temp.insert(make_pair(key,k->second));              // insert to temporary map
                break;
            }
            k++;
        }
        if(temp.size() == 1)
            break;
        else
            k = wordMap.begin();                                    // reset iterator through map
    }
    if(temp.size()!= 1)
        tieBreakerRightLetters(wordMap, currentWords, wordLen);     // repeat if not found
    wordMap.clear();                                                // clear map
    wordMap = temp;                                                 // and add temp
    temp.clear();                                                   // and clear temp
    currentWords = wordMap[key];
}

/* Function: tieBreakerFewestLetters
 * Description: A helper function to break a tie. Checks for a key that has
 *      fewest occurrences of letters in key and it's set becomes current
 *      word bank (if applicable)
 * Input: map, set of current word bank, char guessed
 * Output: -
 */
void tieBreakerFewestLetters(map<string,set<string>> &wordMap, set<string> &currentWords, int wordLen) {
    string keyMin;
    string key;
    int minCount = 0, count = 0;
    map<string,set<string>> temp;

    temp = wordMap;                                     // copy wordMap to temp
    map<string,set<string>>::iterator i = temp.begin();

    minCount = wordLen;                                 // set to max numbers
    while(i != temp.end()) {
        key = i->first;
        for(int j = 0; j < wordLen; ++j) {
            if(key[j] != '-')
                count++;
        }
        // find words with fewest letters
        if(count <= minCount){                          //  if minimum change
            if(minCount != count)                       //  or if it is the same, delete
                temp.erase(keyMin);
            minCount = count;
            keyMin = i->first;
            i++;
        } else {                                        // anything else delete
            i = temp.erase(i);
        }
        count = 0;
    }
    if(temp.size() == 1){                               // there should only be 1 item in map
        wordMap = temp;                                 // copy back
        temp.clear();                                   // delete the temp
        currentWords = wordMap[keyMin];
    } else {
        temp.clear();                                   // delete the temp
        tieBreakerRightLetters(wordMap, currentWords, wordLen);
    }
}

/* Function: tieBreakerNoLetters
 * Description: A helper function to break a tie. Checks for a key that only
 *      has -'s and it's set becomes current word bank (if applicable)
 * Input: map, set of current word bank, char guessed
 * Output: -
 */
void tieBreakerNoLetters(map<string,set<string>> &wordMap, set<string> &currentWords, int wordLen) {
    string keyMax;
    string key;
    bool isLetter = false;
    map<string,set<string>> temp;

    temp = wordMap;                                    // copy wordMap to temp
    map<string,set<string>>::iterator i = temp.begin();

    while(i != temp.end()) {
        key = i->first;
        for(int j = 0; j < wordLen; ++j) {
            if(key[j] != '-')
                isLetter = true;                        // checks for string of just -'s
        }
        if(isLetter == true){
            i = temp.erase(i);
        } else {
            keyMax = key;
            i++;
        }
    }

    if(temp.size() == 1){
        wordMap = temp;                                 // copy back to wordMap
        temp.clear();                                   // delete the temp
        currentWords = wordMap[keyMax];
    } else {
        temp.clear();                                   // delete the temp
        tieBreakerFewestLetters(wordMap, currentWords, wordLen);
    }
}

/* Function: maxWordsinSet
 * Description: A helper function to find the set with the most words (if applicable)
 * Input: map, set of current word bank, char guessed
 * Output: -
 */
void maxWordsinSet(map<string,set<string>> &wordMap, set<string> &currentWords, int wordLen) {
    string keyMax; string key;
    int maxCount = -1, count = 0;
    map<string,set<string>>::iterator i = wordMap.begin();

    while(i != wordMap.end()) {
        key = i->first;
        // find the size of the set
        for(set<string>::iterator j = (i->second).begin(); j != (i->second).end(); j++)
            count++;
        // find set with max values
        if(count >= maxCount){
            if(maxCount != count)
                wordMap.erase(keyMax);                      // erase if not > maxCount
            maxCount = count;
            keyMax = i->first;
            i++;
        } else {
            i = wordMap.erase(i);                           // count < maxCount
        }
        count = 0;
    }
    if(wordMap.size() == 1)
        currentWords = wordMap[keyMax];
    else
        tieBreakerNoLetters(wordMap, currentWords, wordLen);
}


// ===================== Hangman Functions =========================
/* Description: Constructor for EvilHangmanGame */
EvilHangmanGame::EvilHangmanGame() {
    currentWordsLength = 0;
}

/* Function: startGame
 * Description: This function creates the initial word families based
 *      on the word length and the input file.
 * Input: string, int
 * Output: -
 */
void EvilHangmanGame::startGame(string dictionaryFile, int wordLength) {
    ifstream in;
    string word;
    currentWordsLength = wordLength;

    // check for min word length
    if(currentWordsLength <= 1){
        throw "ERROR: word length is too small!"; // throw error
        in.close();
    }

    in.open(dictionaryFile);
    while(getline(in, word)) {
        // check for '\r'
        if(word[word.length()-1] == '\r')
            word = word.erase(word.length()-1,1);
        if(word.length() == currentWordsLength)
            currentWords.insert(word);
    }

    // check for max word length (if set is empty)
    if(currentWords.empty() == true){
        throw "ERROR: word length is too large!"; // throw error
        in.close();
    } else {
        in.close();
    }
}

/* Function: makeGuess
 * Description: Takes the user's guess. If the character has been guessed
 *      before, a char is thrown. Otherwise, the guess is inserted into
 *      instance field guesses. Based on the guess, currentWords is updated.
 * Input:  char guessed
 * Output: current word bank
 */
set<string> EvilHangmanGame::makeGuess(char guess) {
    map<string,set<string>> wordMap;

    // check for invalid input OR repeated guess
    if((guess >= 'A' && guess <= 'Z') || (guess >= 'a' && guess <= 'z'))
        guess = toLowerCase(guess);     // change to lowercase if uppercase
    else if(guess == '\n' || guess == '\t' || guess == '\r')
        throw guess;
    else
        throw guess;        // invalid input
    for(set<char>::iterator it = guesses.begin(); it != guesses.end(); it++) {
        if(*it == guess)
            throw guess;    // repeated guess
    }
    guesses.insert(guess);  // add letter to letters guessed

    generateMap(wordMap, currentWords, guess);   // make map
    maxWordsinSet(wordMap, currentWords, currentWordsLength);

    return currentWords;
}
