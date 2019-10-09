#include "EvilHangmanGame.h"
#include <iostream>
#include <sstream>
#include <set>
#include <string>

using namespace std;

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
/* Function: toLowerCaseDispl
 * Description: Converts a char from uppercase to lowecase
 * Input: char
 * Output: char
 */
char toLowerCaseDispl(char &letter) {
    if(letter >= 'A' && letter <= 'Z')          // compares if A-Z
        letter = letter - 'A' + 'a';            // changes it if lowercase
    return letter;
} // end of toLowerCase

int strToInt(char *s) {
    if(s != NULL){
        stringstream stream;
        int num;
        stream << s;            // converts string to stream
        stream >> num;          // convert back to a double
        return num;
    } else
        return '\0';
}

/* Function: printPrompt
 * Description: Prompt to display to user
 * Input: number of guesses, word bank of letters guessed, word being guessd, char guessed
 * Output: -
 */
void printPrompt(int guessNum, set<char> letterBank, string display, char &guess) {
    string line;
    cout << "You have " << guessNum << " guesses left" << endl;
    cout << "Letters guesed: ";
    for(set<char>::iterator it = letterBank.begin(); it != letterBank.end(); it++)
        cout << *it << ' ';
    cout << endl;
    cout << "Word: " << display << endl;
    cout << "Enter guess: ";
    getline (cin, line);

    //check if not just one letter
    if(line.length() != 1)
        guess = '!';        // change guess to invalid char
    else
        guess = line[0];

}

/* Function: printEnd
 * Description: Display the final result of game (win or lose)
 * Input: bool, final word
 * Output: -
 */
void printEnd(bool win, string actualWord) {
    if(win == true)
        cout << "You win!" << endl;
    else
        cout << "You lose!" << endl;
    cout << "The word was: " << actualWord << endl;
}


// ===================== Main =========================
int main(int argc, char* argv[]) {
    EvilHangmanGame game;
    set<char> letterBank;       // characters that the user has guessed
    string display = "";        // string with word to display
    string actualWord = "";
    int len = 0, guessNum = 0;
    bool win = false;

    // check arguments
    if(argc != 4){
        cout << "Incorrect number of arguments. Please try again." << endl;
    }

    else {
        // convert argv's to ints
        len = strToInt(argv[2]);
        guessNum = strToInt(argv[3]);

        // read file and make set of words based on wordLen
        game.startGame(argv[1], len);

        // set display with -'s
        for (int l = 0; l < len; ++l) {
            display.append("-");
        }

        // make a guess
        while(guessNum > 0){
            bool invalid = false, guessRight = false;
            int countLettersInWord = 0;
            set<string> curWords;      // current word bank, i.e., active word list
            string temp;
            char guess;

            printPrompt(guessNum, letterBank, display, guess);

            // check if input is already guessed letter or invalid input
            try {
                guess = toLowerCaseDispl(guess);
                curWords = game.makeGuess(guess);
            } catch(char guess) {
                if((guess >= 'A' && guess <= 'Z') || (guess >= 'a' && guess <= 'z'))
                    cout << "You have already guessed that letter, try again" << endl;
                else
                    cout << "Invalid input, try again" << endl;
                invalid = true;
            }

            if(invalid == false) {
                // get the first word of current word bank and find pattern to display
                set<string>::iterator it = curWords.begin();
                temp = *it;
                for (int j = 0; j < len; ++j) {
                    if(temp[j] == guess){
                        display[j] = guess;                   // replace '-'s in display with guessed letter
                        countLettersInWord++;                 // counts how many letters are in the word
                        guessRight = true;                    // user guessed the right letter
                    }
                }
                letterBank.insert(guess);      // add guessed letter to set

                // checks if guesss is right or wrong
                if(guessRight == true){
                    if(countLettersInWord == 1)
                        cout << "Yes, there is " << countLettersInWord << " " << guess << endl;
                    else
                        cout << "Yes, there are " << countLettersInWord << " " << guess << "'s" << endl;
                } else {
                    cout << "Sorry, there are no "<< guess << "'s" << endl;
                    guessNum--;
                }
                if(guessNum == 0)
                    actualWord = *it;          // displays the final word
            }
            cout << endl;

            // check for win or lose by going through display
            unsigned int lenCount = 0;
            for (unsigned int i = 0; i < display.length(); ++i) {
                if(display[i] != '-')
                    lenCount++;
            }
            // if player wins: guesses to 0
            if(lenCount == display.length()) {
                guessNum = 0;
                actualWord = display;
                win = true;
            }
        }

        // print out "win" or "lose"
        printEnd(win, actualWord);
    }
}

