#include "String.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *  EE312 Assignment 5.
 *  On my honor, Zahra Atzuri, this programming assignment is my own work.
 *
 *  A program to print out a Rocketship in ASCII art form.
 *
 *  Name: Zahra Atzuri
 *  email address: atzuri@utexas.edu
 *  UTEID: zfa84
 *  Section 5 digit ID: 16115
 *  Number of slip days used on this assignment: 0
 *. Total number of slip days used this semester: 0
 */

unsigned int sLen(const char *src);

/* Function: sLen
 * Description: This function finds the length of string (an array of chars)
 * Input: pointer to string (array of char)
 * Output: int length of string (array of char)
 */
unsigned int sLen(const char *src) {
    int len = 0;
    while (src[len] != '\0') {
        len++;
    }
    return len;
}

/* Function: makeString
 * Description: This function creates a copy of the String
 *      argument s. The returned pointer is to a copy of s. After this function is
 *      called, modifying the original string should not change the duplicate,
 *      and vice versa.
 * Input: original string s
 * Output: copied string s
 */
String *makeString(const char *src) {
    int i = 0;

    struct String *s = malloc(sizeof(struct String));   // allocate space
    int len = sLen(src);                                // find length of str (arr of char)

    char *copy = malloc((len+1) * sizeof(char));             // allocate space for array

    for (i = 0; i < len; ++i) {
        copy[i] = src[i];
    }
    copy[i] = '\0'; // null terminate

    // set the stuff in the struct
    s->data = copy;
    s->length = len;
    s->capacity = len;

    return s;
}

/* Function: utStrdup
 * Description: This function creates a copy of the String
 *      argument s. The returned pointer is to a copy of s. After this function is
 *      called, modifying the original string should not change the duplicate,
 *      and vice versa.
 * Input: original string s
 * Output: copied string s
 */
String *utStrdup(String *s) {
    struct String *new = malloc(sizeof(struct String));     // allocate space for struct
    char *copyS = malloc(((s->length)+1) * sizeof(char));    // allocate space for array

    for (int i = 0; i <= s->length; ++i) {
        copyS[i] = s->data[i];
    }

    // set the stuff in the struct
    new->data = copyS;
    new->length = s->length;
    new->capacity = s->capacity;
    return new;
}

/* Function: utStfree
 * Description: Free the memory for this String
 * Input: string s
 * Output: none
 */
void utStrfree(String *s) {
    free(s->data); // must free the memory pointer in array & set to null
    s->data = NULL;
    free(s); // free memory in string struct
    s = NULL;
}

/* Function: utStrlen
 * Description: For String s, return the length of the string stored
 *      in the data field of s. The length is stored as a field in the struct.
 *      Note that you are not allowed to use any functions from string.h for this project.
 * Input: string s
 * Output: length of s
 */
unsigned int utStrlen(String *s){
    int len = 0;
    while (s->data[len] != '\0') {
        len++;
    }
    return len;
}

/* Function: utStrcpy
 * Description: Replace the characters in dst with the characters from src.
 *      Do not overflow the capacity of the String dst. If the String src is longer than
 *      the capacity for dst, copy only as many characters as will fit (that is, copy
 *      capacity characters.) Update the length of dst. Return a pointer to dst.
 * Input: original string src and copy string dst
 * Output: copy string dst
 */
String *utStrcpy(String *dst, String *src) {
    unsigned int len = 0;

    // must take into account whether to use capacity or length as condition in for loop
    if (dst->capacity <= src->length) {
        len = dst->capacity;
    } else {
        len = src->length;
    }

    for (int i = 0; i < len; ++i) {
        dst->data[i] = src->data[i];
    }
    dst->length = utStrlen(dst);
    return dst;
}

/* Function: utStrcat
 * Description: Append suffix to dst, but do not exceed the capacity of dst.
 * Input: two strings dst and suffix
 * Output: concatenated string in dst
 */
String *utStrcat(String *dst, String *suffix) {
    int i = 0;
    int j = 0;

    // for loop under condition that its less than capacity and ends when reach end of suffix
    for (i = dst->length, j = 0; i < dst->capacity && suffix->data[j] != '\0'; ++i, ++j) {
        dst->data[i] = suffix->data[j]; // concatenate suffix to dst
    }
    dst->data[i] = '\0'; // null terminate
    dst->length = utStrlen(dst);

    return dst;
}

/* Function: utStrrealoc
 * Description: If the current capacity is equal to or larger than newCapacity,
 *      do nothing and return s. If the current capacity is smaller than newCapacity,
 *      return a pointer to a String that has the specified newCapacity.
 *      You should only need to allocate new memory for the data field.
 * Input: string s and a new capacity
 * Output: new string s
 */
String *utStrrealloc(String *s, unsigned int newCapacity) {
    int i = 0;
    if (s->capacity < newCapacity) {
        char *new = malloc((newCapacity+1) * sizeof(char)); // must manually malloc array
        for (i = 0; i < s->length ; ++i) {
            new[i] = s->data[i];
        }
        new[i] = '\0';

        free(s->data); // must free data
        s->data = new; // reallocate
        s->capacity = newCapacity; // and changes new capacity
    }
    return s;
}
