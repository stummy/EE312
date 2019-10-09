#include <stdio.h>

// Song.c -- EE 312 Project 2

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Zahra Atzuri, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Zahra Atzuri
 * email address: atzuri@utexas.edu
 * UTEID: zfa84
 * Section 5 digit ID: 16115
 * Number of slip days used on this assignment: 0
 */

/* Function: lastTwoLines
 * Description: prints the last two lines of each verse
 * Input: none
 * Output: last two lines of each verse
 */
void lastTwoLines() {
    printf("I don't know why she swallowed that fly,\n");
    printf("Perhaps she'll die.\n");
}

/* Function: swallowSpider
 * Description: prints the line where she swallows spider & calls lastTwoLines
 * Input: none
 * Output: none
 */
void swallowSpider() {
    printf("She swallowed the spider to catch the fly,\n");
    lastTwoLines();
}

/* Function: swallowBird
 * Description: prints the line where she swallows bird & calls swallowSpider
 * Input: none
 * Output: none
 */
void swallowBird() {
    printf("She swallowed the bird to catch the spider,\n");
    swallowSpider();
}

/* Function: swallowCat
 * Description: prints the line where she swallows cat & calls swallowBird
 * Input: none
 * Output: none
 */
void swallowCat() {
    printf("She swallowed the cat to catch the bird,\n");
    swallowBird();
}

/* Function: swallowDog
 * Description: prints the line where she swallows dog & calls swallowCat
 * Input: none
 * Output: none
 */
void swallowDog() {
    printf("She swallowed the dog to catch the cat,\n");
    swallowCat();
}

/* Function: swallowGoat
 * Description: prints the line where she swallows goat & calls swallowDog
 * Input: none
 * Output: none
 */
void swallowGoat() {
    printf("She swallowed the goat to catch the dog,\n");
    swallowDog();
}

/* Function: swallowCow
 * Description: prints the line where she swallows cow & calls swallowGoat
 * Input: none
 * Output: none
 */
void swallowCow() {
    printf("She swallowed the cow to catch the goat,\n");
    swallowGoat();
}


/* Function: firstVerse
 * Description: prints a statement and calls lastTwoLines
 * Input: none
 * Output: none
 */
void firstVerse() {
    printf("There was an old woman who swallowed a fly.\n");
    lastTwoLines();
}

/* Function: secondVerse
 * Description: prints statements and calls swallowSpider
 * Input: none
 * Output: none
 */
void secondVerse() {
    printf("There was an old woman who swallowed a spider,\n");
    printf("That wriggled and iggled and jiggled inside her.\n");
    swallowSpider();
}

/* Function: thirdVerse
 * Description: prints statements and calls swallowBird
 * Input: none
 * Output: none
 */
void thirdVerse() {
    printf("There was an old woman who swallowed a bird,\n");
    printf("How absurd to swallow a bird.\n");
    swallowBird();
}

/* Function: fourthVerse
 * Description: prints a statements and calls swallowCat
 * Input: none
 * Output: none
 */
void fourthVerse() {
    printf("There was an old woman who swallowed a cat,\n");
    printf("Imagine that to swallow a cat.\n");
    swallowCat();
}

/* Function: fifthVerse
 * Description: prints statements and calls swallowDog
 * Input: none
 * Output: none
 */
void fifthVerse() {
    printf("There was an old woman who swallowed a dog,\n");
    printf("What a hog to swallow a dog.\n");
    swallowDog();
}

/* Function: sixthVerse
 * Description: prints statements and calls swallowGoat
 * Input: none
 * Output: none
 */
void sixthVerse() {
    printf("There was an old woman who swallowed a goat,\n");
    printf("She just opened her throat to swallow a goat.\n");
    swallowGoat();
}

/* Function: seventhVerse
 * Description: prints statements and calls swallowCow
 * Input: none
 * Output: none
 */
void seventhVerse() {
    printf("There was an old woman who swallowed a cow,\n");
    printf("I don't know how she swallowed a cow.\n");
    swallowCow();
}

/* Function: lastVerse
 * Description: prints statements of the last verse
 * Input: none
 * Output: none
 */
void lastVerse() {
    printf("There was an old woman who swallowed a horse,\n");
    printf("She died of course.\n");
}

int main(void) {
    firstVerse();
    printf("\n");
    secondVerse();
    printf("\n");
    thirdVerse();
    printf("\n");
    fourthVerse();
    printf("\n");
    fifthVerse();
    printf("\n");
    sixthVerse();
    printf("\n");
    seventhVerse();
    printf("\n");
    lastVerse();
}

