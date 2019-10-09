#include <stdio.h>

/*
 *  EE312 Assignment 3.
 *  On my honor, Zahra Atzuri, this programming assignment is my own work.
 *
 *  A program to print out a Rocketship in ASCII art form.
 *
 *  Name: Zahra Atzuri
 *  email address: atzuri@utexas.edu
 *  UTEID: zfa84
 *  Section 5 digit ID: 16115
 *  Number of slip days used on this assignment:
 *. Total number of slip days used this semester:
 */


const int SIZE = 3; // declares a constant for size of rocket

/* Function: cone
 * Description: prints out the top of the rocket and its fire
 * Input: none
 * Output: none (just printf statements)
 */
void cone() {
    for (int i = 0; i < (2*SIZE)-1; i++) {
        for (int j = 0; j < (2*SIZE)-i-1; ++j) {
            printf(" ");
        }
        for (int k = 0; k < i+1; ++k) {
            printf("/");
        }
        printf("**");

        for (int m = 0; m < i+1; ++m) {
            printf("\\");
        }
        printf("\n");
    }

} // end of cone

/* Function: trianglesUp
* Description: prints out the upper body of the rocket with triangles facing up
* Input: none
* Output: none (just printf statements)
*/
void trianglesUp() {
    // this prints out the upper half
    for (int a = 0; a < SIZE; ++a) {
        printf("|");

        // this is the left side
        for (int c = 0; c < (SIZE-a)-1; ++c) {
            printf(".");
        }
        for (int d = 0; d < (a+1); ++d) {
            printf("/\\");
        }
        for (int e = 0; e < (SIZE-a)-1; ++e) {
            printf("..");
        }
        for (int l = 0; l < (a+1); ++l) {
            printf("/\\");
        }
        for (int i = 0; i < (SIZE-a)-1; ++i) {
            printf(".");
        }

        printf("|\n");
    }
} // end of trianglesUp

/* Function: trianglesDown
 * Description: prints out the lower body of the rocket facing down
 * Input: none
 * Output: none (just printf statements)
 */
void trianglesDown() {
    // this prints out the upper half
    for (int a = 0; a < SIZE; ++a) {
        printf("|");

        for (int d = 0; d < a; ++d) {
            printf(".");
        }
        for (int c = 0; c < (SIZE-a); ++c) {
            printf("\\/");
        }
        for (int d = 0; d < a; ++d) {
            printf("..");
        }
        for (int e = 0; e < (SIZE-a); ++e) {
            printf("\\/");
        }
        for (int d = 0; d < a; ++d) {
            printf(".");
        }

        printf("|\n");
    }
} // end of trianglesDown

/* Function: border
 * Description: prints out the border of the body
 * Input: none
 * Output: none (just printf statements)
 */
void border() {

    printf("+");
    for (int i = 0; i < (2*SIZE); ++i) {
        printf("=*");
    }
    printf("+\n");
} // end of border

/* Function: body
 * Description: uses functions to build the main body of the rocket
 * Input: none
 * Output: none (just printf statements)
 */
void body() {
    border();
    trianglesUp();
    trianglesDown();
    border();
    trianglesDown();
    trianglesUp();
    border();
} // end of body

int main() {
    int n = 7;
    cone(); // top/cone of rocket
    body();
    cone(); // rocket fire
} // end of main
