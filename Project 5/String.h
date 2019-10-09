#ifndef _String_h
#define _String_h 1

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

// define Struct String
typedef
struct String {
    unsigned int capacity;
    unsigned int length;
    char *data;
} String;


String *makeString(const char *src);
String *utStrdup(String *s);
void utStrfree(String *s);
unsigned int utStrlen(String *s);
String *utStrcpy(String *dst, String *src);
String *utStrcat(String *dst, String *suffix);
String *utStrrealloc(String *s, unsigned int newCapacity);
void printut(String *s); // print string

#endif /* _String_h */
