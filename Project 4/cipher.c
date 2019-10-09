#include <stdio.h>
#include <string.h>

/*
 *  EE312 Assignment 4.
 *  On my honor, Zahra Atzuri, this programming assignment is my own work.
 *
 *  A program to encrypt and decript a given string.
 *
 *  Name: Zahra Atzuri
 *  email address: atzuri@utexas.edu
 *  UTEID: zfa84
 *  Section 5 digit ID: 16115
 *  Number of slip days used on this assignment: 0
 *. Total number of slip days used this semester: 0
 */

const int MAX_ROWS = 6; // declares a constant for the max number of rows

/* Function: checkLen
 * Description: increases the length of string to where its divisible by MAX_ROWS
 * Input: string length and number of row
 * Output: the new length divisible by MAX_ROWS
 */
int checkLen(int len, int row) {
    int newLen = 0;
    newLen = len; // a local variable copy of strlen

    while (newLen % row != 0) { // checks if the length is divisible by MAX_ROWS
        newLen++;
    }
    return newLen;
} // end of checkLen

/* Function: encryptStr
 * Description: encrypts a string
 * Input: the original string (in char array), decrypted string (in char array), row number, and strlen of original string
 * Output: encrypted string
 */
char *encryptStr(char str1[], char str2[], int row, int len) {
    int k = 0;
    int col = 0;
    col = strlen(str1)/row;
    for (int j = 0; j < row; ++j) {             // check through row first
        for (int i = 0; i < col; ++i) {         // then check through each column
            str2[k] = str1[j + i * row];
            k++;
        }
    }
    str2[k] = '\0'; // null terminate
    return str2;
} // end of encryptStr

/* Function: decryptStr
 * Description: decrypts a string
 * Input: the original string (char array), decrypted string (in char array), row number, and strlen of original string
 * Output: decrypted string
 */
char *decryptStr(char str1[], char str2[], int row, int len) {
    int k = 0;
    int col = 0;
    col = strlen(str1)/row;
    for (int i = 0; i < col; ++i) {             // check through column first
        for (int j = 0; j < row; ++j) {         // then check through each row
            str2[k] = str1[i + j * col];
            k++;
        }
    }
    str2[k] = '\0'; // null terminate
    return str2;
} // end of decryptStr

/* Function: removeX
 * Description: removes the padded 'X' in an encrypted string
 * Input: encrypted string
 * Output: encrypted string without the padding
 */
char *removeX(char str[]){
    int i,j = 0;
    char *p = str; // create new array for string without padding
    for (i = 0, j = 0; i < strlen(str); ++i, ++j) {
        if(str[i] != 'X'){
            p[j] = str[i];  // copies content of original string to new string
        } else {
            j--;
        }
    }
    p[j]='\0';
    return p;
} // end of removeX

/* Function: padStr
 * Description: adds padding ('X') to a string
 * Input: the original string (in char array), padded string (in char array), and strlen of padded string
 * Output: padded string
 */
char *padStr(char str1[], char str2[], int len2) {
    strcpy(str2, str1); // copys str1 to str2
    int len1 = strlen(str1);

    // adds padding after string copied
    while (len1 < len2) {
        str2[len1] = 'X';
        len1++;
    }
    str2[len1] = '\0';
    return str2;
} // end of padStr

/* Function: encryptNoPad
 * Description: encrypts a string without padding ('X')
 * Input: the original string (in char array), and strlen of original string
 * Output: encrypted string without padding
 */
void encryptNoPad(char str[], int len) {
    int newLen;

    for (int row = 2; row <= MAX_ROWS; ++row) {
        newLen = checkLen(len, row); // get new length based on row
        char newStr[newLen]; // new string with new length
        char encrStr[newLen]; // encrypted string

        padStr(str, newStr, newLen);
        printf("Encrypted with %i rows: ", row);
        encryptStr(newStr, encrStr, row, newLen);
        printf("%s\n", removeX(encrStr));

    }
} // end of encryptNoPad

/* Function: encryptPad
 * Description: encrypts a string with padding ('X')
 * Input: the original string (in char array), and strlen of original string
 * Output: encrypted string with padding
 */
void encryptPad(char str[], int len) {
    int newLen; // a local variable copy of len

    for (int row = 2; row <= MAX_ROWS; ++row) {
        newLen = checkLen(len, row); // get new length based on row
        char newStr[newLen]; // new string with new length
        char encrStr[newLen]; // encrypted string

        printf("Clear text padded for %i rows: ", row);
        printf("%s\n", padStr(str, newStr, newLen));
        printf("Encrypted with %i rows: ", row);
        printf("%s\n\n", encryptStr(newStr, encrStr, row, newLen));
    }
} // end of encryptPad

/* Function: decryptPad
 * Description: decrypts a string with padding ('X')
 * Input: the original string (in char array), and strlen of original string
 * Output: decrypted string with padding
 */
void decryptPad(char str[], int len) {
    int newLen; // a local variable copy of len

    for (int row = 2; row <= MAX_ROWS; ++row) {
        newLen = checkLen(len, row); // get new length based on row
        char newStr[newLen]; // new string with new length
        char decrStr[newLen]; // decrypted string

        printf("Encrypted text padded for %i rows: ", row);
        printf("%s\n", padStr(str, newStr, newLen));
        printf("Decrypted with %i rows: ", row);
        printf("%s\n\n", decryptStr(newStr, decrStr, row, newLen));
    }
} // end of decryptPad

int main() {
    char strToEncr[20] = {};
    char strToDecr[20] = {};
    printf("This program demonstrates a transposition cipher.\n"
    "A cipher is an algorithm to encrypt or decrypt a message.\n\n");
    printf("This program will demonstrate encrypting a message with\n"
    "a columnar transposition cipher both with and without\n"
    "padding characters. The program will then decrypt a message\n"
    "assuming it was encrypted with a columnar transposition cipher\n"
    "with padding.\n\n\n");

    printf("A demonstration of encrypting with a columnar transposition cipher:\n\n");
    printf("Enter the message to encrypt: "); // Hook_'em_Horns!!!
    scanf("%s", strToEncr);
    printf("\n");

    int lenE = strlen(strToEncr); // get the length of encrypting string

    printf("Message encrypted with columnar transposition cipher and no padding.\n");
    encryptNoPad(strToEncr, lenE);

    printf("\nMessage encrypted with columnar transposition cipher and padding.\n\n");
    encryptPad(strToEncr, lenE);
    printf("\n");

    printf("A demonstration of decrypting with a columnar transposition cipher.\n"
    "If the length of the message is not a multiple of the number of rows\n"
    "it will be padded which may throw off the decryption.\n\n");

    printf("Enter the message to decrypt: "); // H__n!o'HsXoeo!Xkmr!X
    scanf("%s", strToDecr);
    printf("\n");

    int lenD = strlen(strToDecr); // get the length of decrypting string

    printf("Message decrypted with a columnar transposition cipher:\n\n");
    decryptPad(strToDecr, lenD);
    printf("\n");
}