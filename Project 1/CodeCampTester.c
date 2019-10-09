#include<stdio.h>
#include<stdbool.h>
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int, int);
int reverseInt(int); 

// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Zahra Atzuri
 * email address: atzuri@utexas.edu
 * UTEID: zfa84
 * Section 5 digit ID: 16115
 * Number of slip days used on this assignment: 0
 */

int main() {

    // test 1, hamming distance
    int h1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int h2[] = {2, 4, 3, 8, 10, -13, 14, 13, 18, -20};
    int expected = 4;
    int actual = hammingDistance(h1, h2, 10);
    printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 1, hamming distance\n\n");
    else printf("**** FAILED **** test 1, hamming distance\n\n");

    // test 2, hamming distance
    int h3[34] = {1, 2, 3, 4, 5, 6, 7};
    int h4[34] = {0, 0, 0, 0, 0, 0, 0};
    expected = 7;
    actual = hammingDistance(h3, h4, 34);
    printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 2, hamming distance\n\n");
    else printf("**** FAILED **** test 2, hamming distance\n\n");

    //// test 3, hamming distance
    int h5[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 25};
    int h6[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 25};
    expected = 0;
    actual = hammingDistance(h5, h6, 10);
    printf("Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 3, hamming distance\n\n");
    else printf("**** FAILED **** test 3, hamming distance\n\n");


    // test 4, last digit
    int n1 = 4;
    int n2 = 624;
    expected = true;
    actual = lastDigit(n1, n2);
    printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 4, last digit\n\n");
    else printf("**** FAILED **** test 4, last digit\n\n");

    // test 5, last digit
    n1 = 12122221;
    n2 = -3115;
    expected = false;
    actual = lastDigit(n1, n2);

    printf("Test 5 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 5, last digit\n\n");
    else printf("**** FAILED **** test 5, last digit\n\n");

    // test 6, last digit
    n1 = -2338;
    n2 = -34232058;
    expected = true;
    actual = lastDigit(n1, n2);
    printf("Test 6 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 6, last digit\n\n");
    else printf("**** FAILED **** test 6, last digit\n\n");


    // test 7, sum of multiples of 3 or 5
    expected = 233168;
    actual = sum3or5Multiples();
    printf("Test 7 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 7, sum of multiples of 3 or 5\n\n");
    else printf("**** FAILED **** test 7, sum of multiples of 3 or 5\n\n");


    // test 8, reverse int
    n1 = 314159;
    expected = 951413;
    actual = reverseInt(n1);
    printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 8, reverse int\n\n");
    else printf("**** FAILED **** test 8, reverse int\n\n");

    // test 9, reverse int
    n1 = -800;
    expected = -8;
    actual = reverseInt(n1);
    printf("Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 9, reverse int\n\n");
    else printf("**** FAILED **** test 9, reverse int\n\n");

    // test 10, reverse int
    n1 = 2147483647; // INT_MAX
    expected = 0;
    actual = reverseInt(n1);
    printf("Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 10, reverse int\n\n");
    else printf("**** FAILED **** test 10, reverse int\n\n");

    // test 11, reverse int
    n1 = 2147483641;
    expected = 1463847412;
    actual = reverseInt(n1);
    printf("Test 11 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 11, reverse int\n\n");
    else printf("**** FAILED **** test 11, reverse int\n\n");

    // test 12, reverse int
    n1 = -2147483648; // INT_MIN
    expected = 0;
    actual = reverseInt(n1);
    printf("Test 12 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 12, reverse int\n");
    else printf("**** FAILED **** test 12, reverse int\n");
}

