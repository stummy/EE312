#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Recursive.h"


void doBinaryTests();
void doPalindromeTests();
void doNextIsDoubleTests();
void doCanFlowOffTests();
void doOneFlowOffTest(int M, int N, int arr[M][N], int, int, bool, int);

int main() {
    doBinaryTests();
    doPalindromeTests();
    doNextIsDoubleTests();
    doCanFlowOffTests();
}

void doCanFlowOffTests() {
    int testNum = 1;
    int world[][6] = {{5, 5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5, 5},
                      {5, 5, 4, 4, 5, 5},
                      {5, 5, 3, 3, 5, 5},
                      {5, 5, 2, 2, 5, 5},
                      {5, 5, 5, 1, 5, 5},
                      {5, 5, -2, 5, 5, 5}};

    int why[][6] =   {{8, 8, 8, 8, 8, 8},
                      {8, 5, 6, 7, 6, 8},
                      {8, 4, 8, 8, 7, 8},
                      {8, 3, 8, 8, 6, 8},
                      {1, 2, 8, 8, 5, 8},
                      {8, 8, 8, 8, 8, 8}};

    int why1[][6] =   {{8, 8, 8, 8, 8, 8},
                       {8, 5, 6, 7, 6, 8},
                       {8, 4, 8, 8, 7, 8},
                       {8, 3, 8, 8, 6, 8},
                       {2, 2, 8, 8, 5, 8},
                       {8, 8, 8, 8, 8, 8}};


    int worldd[][6] = {{5, 5, 5, 5, 5, 5},
                       {5, 5, 5, 5, 5, 5},
                       {5, 5, 5, 5, 5, 5},
                       {5, 5, 4, 4, 5, 5},
                       {5, 5, 3, 3, 5, 5},
                       {5, 5, 2, 2, 5, 5},
                       {5, 5, 5, 1, 5, 5},
                       {5, 5, 5, 5, 5, 5}};

    int test[][7] =  {{10, 10, 10, 10, 10, 10, 10},
                      {10, 10, 10,  7, 10, 10, 10},
                      {10,  6,  7,  8,  7,  6, 10},
                      {10, 10, 10,  9, 10,  5, 10},
                      { 7,  8,  9, 10,  9,  4, 10},
                      {10,  3,  4,  9,  2,  3, 10},
                      {10,  10, 5,  8,  1,  2, 10},
                      {10,   5, 6,  7, 10, 10, 10},
                      {10, 10, 10, 10, 10, 10, 10}};

    int testd[][7] =  {{10, 10, 10, 10, 10, 10, 10},
                       {10, 10, 10,  7, 10, 10, 10},
                       {10,  6,  7,  8,  7,  6, 10},
                       {10, 10, 10,  9, 10,  5, 10},
                       {10,  8,  9, 10,  9,  4, 10},
                       {10,  3,  4,  9,  2,  3, 10},
                       {10,  10, 5,  8,  1,  2, 10},
                       {10,   5, 6,  7, 10, 10, 10},
                       {10, 10, 10, 10, 10, 10, 10}};

    doOneFlowOffTest(8, 6, world, 3, 3, false, testNum++);
    doOneFlowOffTest(8, 6, world, 6, 2, true, testNum++);

    doOneFlowOffTest(8, 6, worldd, 6, 2, false, testNum++);

    doOneFlowOffTest(9, 7, test, 4, 3, true, testNum++);
    doOneFlowOffTest(9, 7, test, 1, 5, false, testNum++);

    doOneFlowOffTest(9, 7, testd, 4, 3, false, testNum++);

    doOneFlowOffTest(6, 6, why, 2, 3, true, testNum++);

    doOneFlowOffTest(6, 6, why1, 2, 3, false, testNum++);
    printf("\n");
}

void doOneFlowOffTest(int M, int N, int world[M][N], int r, int c, bool expected, int testNum) {
    printf("Can Flow Off Map Test Number %d\n", testNum);
    bool actual = canFlowOff(M, N, world, r, c);
    printf("Start location = %d, %d\n", r, c);
    printf("Expected result = %d, actual result = %d\n", expected, actual);
    if(expected == actual)
        printf("Passed Test %d can flow off map\n", testNum);
    else
        printf("FAILED test %d can flow off map\n", testNum);
    printf("\n");
}

void doNextIsDoubleTests(){
    int numsForDouble[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    int actual = nextIsDouble(numsForDouble, 9);
    int expected = 8;
    if(actual == expected)
        printf("Test 1 passed, next is double\n");
    else
        printf("Test 1 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    int nums[] = {1, 3, 4, 2, 32, 8, 128, -5, 6};
    actual = nextIsDouble(nums, 9);
    expected = 0;
    if(actual == expected)
        printf("Test 2 passed, next is double\n");
    else
        printf("Test 2 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    int nums2[] = {1, 0, 0, -5, -10, 32, 64, 128, 2, 9, 18};
    actual = nextIsDouble(nums2, 11);
    expected = 5;
    if(actual == expected)
        printf("Test 3 passed, next is double\n");
    else
        printf("Test 3 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    int nums3[] = {0, 0, -2, -4, 25, 50, 50, 100, 2, 4, 18};
    actual = nextIsDouble(nums3, 11);
    expected = 5;
    if(actual == expected)
        printf("Test 4 passed, next is double\n");
    else
        printf("Test 4 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    int nums4[] = {1, 3, 6, 2, 2, 0, 0, 1, 2};
    actual = nextIsDouble(nums4, 9);
    expected = 3;
    if(actual == expected)
        printf("Test 5 passed, next is double\n");
    else
        printf("Test 5 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    int nums5[] = {};
    actual = nextIsDouble(nums5, 0);
    expected = 0;
    if(actual == expected)
        printf("Test 6 passed, next is double\n");
    else
        printf("Test 6 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    printf("\n");
}

void doBinaryTests(){
    int n =13;
    int actual = getBinary(n);
    int expected = 1101;
    if(actual == expected)
        printf("Test 1 passed, get binary\n");
    else
        printf("Test 1 failed, get binary. expected = %d, actual = %d\n", expected, actual);

    actual = getBinary(0);
    expected = 0;
    if(actual == expected)
        printf("Test 2 passed, get binary\n");
    else
        printf("Test 2 failed, get binary. expected = %d, actual = %d\n", expected, actual);

    actual = getBinary(35);
    expected = 100011;
    if(actual == expected)
        printf("Test 3 passed, get binary\n");
    else
        printf("Test 3 failed, get binary. expected = %d, actual = %d\n", expected, actual);

    actual = getBinary(1023);
    expected = 1111111111;
    if(actual == expected)
        printf("Test 4 passed, get binary\n");
    else
        printf("Test 4 failed, get binary. expected = %d, actual = %d\n", expected, actual);

    actual = getBinary(789);
    expected = 1100010101;
    if(actual == expected)
        printf("Test 5 passed, get binary\n");
    else
        printf("Test 5 failed, get binary. expected = %d, actual = %d\n", expected, actual);

    printf("\n");
}

void doPalindromeTests() {
    char s[] = "race ecar";
    bool expected = true;
    bool actual = isPalindrome(s);
    if(actual == expected)
        printf("Test 1 passed, is palindrome\n");
    else
        printf("Test 1 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char t[] = " ";
    expected = true;
    actual = isPalindrome(t);
    if(actual == expected)
        printf("Test 2 passed, is palindrome\n");
    else
        printf("Test 2 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char r[] = "oro";
    expected = true;
    actual = isPalindrome(r);
    if(actual == expected)
        printf("Test 3 passed, is palindrome\n");
    else
        printf("Test 3 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char u[] = "civic";
    expected = true;
    actual = isPalindrome(u);
    if(actual == expected)
        printf("Test 4 passed, is palindrome\n");
    else
        printf("Test 4 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char v[] = "deleveled";
    expected = true;
    actual = isPalindrome(v);
    if(actual == expected)
        printf("Test 5 passed, is palindrome\n");
    else
        printf("Test 5 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char x[] = "red der";
    expected = true;
    actual = isPalindrome(x);
    if(actual == expected)
        printf("Test 6 passed, is palindrome\n");
    else
        printf("Test 6 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char w[] = "Radar";
    expected = false;
    actual = isPalindrome(w);
    if(actual == expected)
        printf("Test 7 passed, is palindrome\n");
    else
        printf("Test 7 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char y[] = "race car";
    expected = false;
    actual = isPalindrome(y);
    if(actual == expected)
        printf("Test 8 passed, is palindrome\n");
    else
        printf("Test 8 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    printf("\n");
}