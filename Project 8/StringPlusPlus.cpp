#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>

#include "StringPlusPlus.h"

// StringPlusPlus.cpp -- EE 312 Project 8

/* Student information for project:
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

/* Project Description: this project introduces the programmer to concepts in C++ by completing the
 *      string functions provided. The program cannot contain any globals or statics and it must
 *      compile and run correctly. Do not add additional #includes, and do not use concepts that we
 *      have not covered in class.
 */

using namespace std;

/* Function: charToString
 * Description: Converts a char value to the string containing the char.
 * Input: char
 * Output: string
 */
string charToString(char c) {
    string str = "";
    str.append(1, c);
    return str;
}


/* Function: boolToString
 * Description: Converts bool b to the corresponding string, "true" or "false"
 * Input: bool
 * Output: string
 */
string boolToString(bool b) {
    if(b)
        return "true";
    else
        return "false";
}


/* Function: endsWith
 * Description: Returns true if s ends with suf, false otherwise.
 * Input: string s and suff
 * Output: bool
 */
bool endsWith(string s, string suf) {
    int sufLen = suf.length();
    int sLen = s.length();

    if(s.substr(sLen-sufLen) == suf)
        return true;
    else
        return false;
}


/* Function: endsWith
 * Description: Returns true if s ends with ch, false otherwise.
 * Input: string s and char ch
 * Output: bool
 */
bool endsWith(string s, char ch) {
    // check for null case
    if(ch == '\0' && s[s.length()] == ch)
        return true;
    if(s[s.length()-1] == ch)
        return true;
    else
        return false;
}


/* Function: startsWith
 * Description: Returns true if s starts with pref, false otherwise.
 * Input: string s and pref
 * Output: bool
 */
bool startsWith(string s, string pref) {
    // check for null case
    if(pref == "" && s.length() != 0)
        return false;
    else if(s.substr(0,pref.length()) == pref)
        return true;
    else
        return false;
}


/* Function: startsWith
 * Description: Returns true if s starts with ch, false otherwise.
 * Input: string s and char ch
 * Output: bool
 */
bool startsWith(string s, char ch) {
    if(s[0] == ch)
        return true;
    return false;
}


/* Function: equalsIgnoreCase
 * Description: Returns true if s1 and s2 are equal if case is ignored, false otherwise.
 * Input: string s1 and s2
 * Output: bool
 */
bool equalsIgnoreCase(string s1, string s2) {
    string s1low = toLowerCase(s1);
    string s2low = toLowerCase(s2);

    // checks if same length first, then compares each character
    if(s1.length() != s2.length())
        return false;
    else {
        for (int i = 0; i < s1.length(); ++i) {
            if (s1low[i] != s2low[i])
                return false;
        }
    }
    return true;
}


/* Function: doubleToString
 * Description: Converts a floating-point number into the corresponding
 *      string form with dig digits after the decimal point.
 * Input: double and digits to show (int)
 * Output: string
 */
string doubleToString(double d, int dig) {
    stringstream stream;
    double num = d;

    // check for null case
    if(d == '\0')
        return "";
    else {
        stream << fixed << setprecision(dig) << num;        // converts number to string
        return stream.str();
    }
}


/* Function: stringToDouble
 * Description: Converts a string into its corresponding double value.
 *      pre: s contains a fixed point representation of a double
 * Input: string
 * Output: double
 */
double stringToDouble(string s) {
    if(s != ""){
        stringstream stream;
        double num;

        stream << s;            // converts string to stream
        stream >> num;          // convert back to a double
        return num;
    } else
        return '\0';
}


/* Function: stringJoin
 * Description: Concatenates the strings in vector (maintaining their order)
 *      into a single string. In the returned string, any two string
 *      elements from the vector are separated by the given delimiter.
 * Input: vector<string>, delimiter (string)
 * Output: string
 */
string stringJoin(const vector<string> & v, string delimiter) {
    string join = "";
    int lenDelim = delimiter.length();

    for(auto i = v.begin(); i != v.end(); i++) {
        join += *i + delimiter;                       // concatenate string
    }
    join.erase(join.length()-lenDelim);               // erase last delimiter b/c end of string
    return join;
}


/* Function: stringSplit
 * Description: Break apart string str into a list of strings separated
 *      by the specified delimiter, and place each of those strings in a
 *      vector. The order of the strings should not change.
 * Input: string, delimiter (string)
 * Output: vector<string>
 */
vector<string> stringSplit(string str, string delim) {
    string copy = str;
    string temp;
    vector<string> v;
    int indexDelim = 0;   // index of 1st occurrence of delimeter in stirng

    while(indexDelim != -1){
        indexDelim = copy.find(delim);                  // finds delim
        temp = copy.substr(0, indexDelim);              // temporary substring
        v.push_back(temp);                              // adds substring to vector
        copy.erase(0, indexDelim + delim.length());     // erase that part of the string
    }
    return v;
}


/* Function: toLowerCase
 * Description: Return a lower case version of string s.
 * Input: string
 * Output: string
 */
string toLowerCase(string s) {
    string copy = s;

    for (int i = 0; i < s.length(); ++i) {
        if(s[i] >= 'A' && s[i] <= 'Z')          // compares if A-Z
            copy[i] = s[i] - 'A' + 'a';         // changes it if lowercase
    }
    return copy;
}


/* Function: toUpperCase
 * Description: Return an upper case version of string s.
 * Input: string
 * Output: string
 */
string toUpperCase(string s) {
    string copy = s;

    for (int i = 0; i < s.length(); ++i) {
        if(s[i] >= 'a' && s[i] <= 'z')          // compares if a-z
            copy[i] = s[i] - 'a' + 'A';         // changes it if uppercase
    }
    return copy;
}


/* Function: stringReplace
 * Description: Return a new string which is orig with all occurrences of old replaced with repl.
 * Input: strings: orignial, old (old word to replace), repl (new word to replace)
 * Output: string
 */
string stringReplace(string orig, string old, string repl) {
    string copy = orig;
    int index = 0;

    index = copy.find(old, index);                  // set  original index
    while(index != -1){
        copy.replace(index, old.length(), repl);
        index += repl.length();                     // increment index by length of new word
        index = copy.find(old, index);              // change index again
    }
    return copy;
}


/* Function: trim
 * Description: Returns a new string which is s with all leading and trailing whitespace removed.
 * Input: string
 * Output: string
 */
string trim(string s) {
    string copy = s;
    int countSpace = 0, i = 0;

    // leading whitespace
    while(copy[i] == ' ' || copy[i] == '\n' || copy[i] == '\t'){
        countSpace++;
        i++;
    }
    copy.erase(0,countSpace);

    // trailing whitespace
    countSpace = 0;
    i = copy.length()-1;
    if(i == -1)
        return copy;       // case if string is null
    else {
        while(copy[i] == ' ' || copy[i] == '\n' || copy[i] == '\t'){
            countSpace++;
            i--;
        }
        copy.erase(i+1, countSpace+1);
        return copy;
    }
}


/* Function: pigLatinfy
 * Description: Return a new string that contains s translated into pig latin.
 *      The string may contain blank spaces and (possibly one) punctuation symbol
 *      at the end of words. There will not be punctuation embedded in words,
 *      and there will not be digits.
 * Input: string
 * Output: string
 */
string pigLatinfy(string s) {
    //initializers
    stringstream stream;
    string pigL = "";
    string word;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    stream << s;
    while(stream >> word) {
        // initializers
        int len = 0;
        int endIndex = word.length()-1;
        int origWordLen = word.length();
        int notLetter = 0;

        //find if word has any punctuation at the end
        while(!(word[endIndex] >= 'A' && word[endIndex] <= 'Z') && !(word[endIndex] >= 'a' && word[endIndex] <= 'z')){
            notLetter++;
            endIndex--;
        }
        // check first letter for vowel (yay)
        for (int i = 0; i < 10; ++i) {
            if(word[0] == vowels[i]){
                word += "yay";
                break;
            }
        }
        // check letters that are consonants until a vowel is found (ay)
        for (int j = 1; j < word.length() && word.length() == origWordLen; ++j) {
            for (int i = 0; i < 10; ++i) {
                if(word[j] == vowels[i]) {
                    string temp = word.substr(0, len+1) + "ay";
                    word.insert(endIndex+1, temp);
                    word.erase(0, len+1);
                    break;
                }
            }
            len++;
        }
        pigL += word + " ";         // concatenate to output string
    }
    pigL.erase(pigL.length()-1);    // erase the last element
    return pigL;
}