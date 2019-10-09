#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

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



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/
int hammingDistance(int aList[], int bList[], int len) {
    int ham = 0;

    for (int i = 0; i < len; ++i) {
        if (aList[i] != bList[i]) {     // checks if value of aList an bList at x index is not equal
            ham++;
        }
    }

    return ham;
}

/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if x and y have the same last digit, false otherwise.
*/
bool lastDigit(int x, int y) {

    // checks if x is negative and then converts to positive
    if (x < 0) {
        x = abs(x);
    }

    // checks if y is negative and then converts to positive
    if (y < 0) {
        y = abs(y);
    }

    // check for last digit
    if ((x % 10) == (y % 10)) {
        return true;
    }
    else {
        return false;
    }

}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/
int sum3or5Multiples() {
    int x = 0;
    int sum = 0;

    while (x < 1000) {
        if (x % 3 == 0 || x % 5 == 0) {         // check if multiple of 3 and/or 5
            sum += x;
        }
        x++;
    }
    return sum;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return x with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int x) {
    bool neg = 0;
    int last = 0;
    long out = 0;

    // checks if number is negative first
    if (x < 0) {
        neg = true;
        x *= -1; // make positive
    }

    // reverse the number
    while (x != 0){
        last = x % 10;
        out = out*10 + last;

        // check if output in range of int
        if (out > INT_MAX || out < INT_MIN){
            return 0;
        }

        x /= 10;
    }

    // output becomes negative if input was negative
    if (neg == true) {
        out *= -1;
    }

    return (int)out;

}

  

