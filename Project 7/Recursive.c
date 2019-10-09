#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>  // strlen only!!

// Recursive.c -- EE 312 Project 7

/* Student information for project:
 *
 * On my honor, Zahra Atzuri, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Zahra Atzuri
 * email address: atzuri@utexas.edu
 * UTEID: zfa84
 * Section 5 digit ID: 16115
 * Number of slip days used on this assignment: 1
 */

/* Project Description: The purpose of this assignment is to practice writing
 *      recursive algorithms and implementing them in C. You will implement
 *      recursive solutions to the problems described below.
 *      You must write recursive functions to receive credit.
 */


// ============================ HELPER FUNCTIONS ==========================
/* Function: paliByIndex
 * Description: finds palindrome by traversing through the string by incrementing
 *      first index & decrementing last index and comparing letters at each index.
 *      Basically checks for palindrome without altering string.
 * Input: string, first index, last index
 * Output: true or false if palindrome
 */
bool paliByIndex(char *s, int st, int en){
    // true if indexes are the same (base case)
    if(st == en)
        return true;
    // false if encountered different letters
    if(s[st] != s[en])
        return false;

   // change indexes
    st++;
    en--;

    return paliByIndex(s, st, en);                    // recurse
}

/* Function: doubChecker
 * Description: finds if next element is double of the current one
 * Input: int array, length of array, index, count of doubles
 * Output: count of doubles
 */
int doubChecker(int arr[], int N, int i, int count){
    // last index
    if(i == N-2){
        // increment count if necessary & return
        if(2*arr[i] == arr[N-1])
            count++;
        return count;
    }
    // increment count
    if(2*arr[i] == arr[i+1])
        count++;
    i++; // increment index

    return doubChecker(arr, N, i, count);             // recurse
}

// ============================ MAIN FUNCTIONS ==========================
/* Function: getBinary
 * Description: A recursive function that returns the base 2 representation of int n.
 *       Assume that n is non-negative.
 * Input: an integer in base 10 (decimal)
 * Output: an integer in base 2 (binary)
 */
int getBinary(int n) {
    // base case
    if(n/2 == 0)
        return n%2;
    else
        return n%2 + 10*getBinary(n/2);            // concatenate
}


/* Function: isPalindrome
 * Description: A recursive function that returns true if str is a palindrome, and
 *      false otherwise.
 * Input: a string
 * Output: true or false if the string is palindrome or not
 */
bool isPalindrome(char *s) {
    // initialize
    int start = 0;
    int end = strlen(s)-1;

    return paliByIndex(s, start, end);            // recursion in the helper function
}
//bool isPalindrome(char *s) {
//    if(strlen(s) == 1 || strlen(s) == 0)
//        return true;
//    if(s[0] != s[strlen(s)-1])
//        return false;
//    s[strlen(s)-1] = '\0';
//    for (int i = 0, j = 1; j < strlen(s); ++i, ++j) {
//        s[i] = s[j];
//    }
//    s[strlen(s)-1] = '\0';
//    return isPalindrome(s);
//}

/* Function: nextisDouble
 * Description: Returns the number of elements in data that are directly followed
 *      by double that element. (Write a helper function that is passed an index into the array.)
 * Input: an array of ints and length N
 * Output: number of doubles in array
 */
int nextIsDouble(int data[], int N){
    // initialize
    int count = 0;
    int i = 0;
    
    // check for null
    if(N == 0)
        return 0;
    
    return doubChecker(data, N, i, count);        // recursion in the helper function
}

/* Function: canFlowOff
 * Description: drop of water can move to one of the four adjacent cells
 *      (above, below, left and right of the current cell) if the elevation
 *      of the adjacent cell is less than the elevation of the current cell.
 *      Water in any cell on the edge of the map can flow off the map.
 * Input: an array of ints and length N
 * Output: number of doubles in array
 */
bool canFlowOff(int M, int N, int map[M][N], int row, int col){
    // base case
    if(row == 0 || row == M-1 || col == 0 || col == M-1)
        return true;

    // check north
    if(map[row][col] > map[row-1][col]){
        row--;
        if(canFlowOff(M, N, map, row, col)) return true;
        row++;
    }
    // check south
    if(map[row][col] > map[row+1][col]){
        row++;
        if(canFlowOff(M, N, map, row, col)) return true;
        row--;
    }
    // check west
    if(map[row][col] > map[row][col-1]){
        col--;
        if(canFlowOff(M, N, map, row, col)) return true;
        col++;
    }
    // check east
    if(map[row][col] > map[row][col+1]){
        col++;
        if(canFlowOff(M, N, map, row, col)) return true;
        col--;
    }
    return false;
}
