#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>

#include "StringPlusPlus.h"

/* Student information for project:
 *
 * On my honor, Zahra Atzuri, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Zahra Atzuri
 * email address: atzuri@utexas.edu
 * UTEID: zfa84
 * Section 5 digit ID: 16115
 * Number of slip days used on this assignment.
 */


//ENDS WITH TEST 5
int main() {
    ///////////DON'T FORGET TO CONSIDER EMPTY INPUTS/////////////////////
    //string charToString
    //TEST CASE 1
    char a = 'a';
    string first = charToString(a);
    if(first == "a")
        printf("Test 1 charToString(char) : passed\n");
    else
        printf("Test 1 charToString(char) : FAILED\n");
    //TEST CASE 2
    a = 'A';
    first = charToString(a);
    if(first == "A")
        printf("Test 2 charToString(char) : passed\n");
    else
        printf("Test 2 charToString(char) : FAILED\n");
    //TEST CASE 3
    a = 'b';
    first = charToString(a);
    if(first == "b")
        printf("Test 3 charToString(char) : passed\n");
    else
        printf("Test 3 charToString(char) : FAILED\n");
    printf("\n\n");

    //string boolToString
    //TEST CASE 1
    bool stat = true;
    string c = boolToString(stat);
    if(c == "true")
        printf("Test 1 boolToString(string,string) : passed\n");
    else
        printf("Test 1 boolToString(string,string) : FAILED\n");
    //TEST CASE 2
    stat = false;
    c = boolToString(stat);
    if(c == "false")
        printf("Test 2 boolToString(string,string) : passed\n");
    else
        printf("Test 2 boolToString(string,string) : FAILED\n");
    printf("\n\n");

/********************************************************************************************************/
///////////////*************************bool endsWith(string, string)************************/////////////
/********************************************************************************************************/
    //TEST CASE 1(True)
    string large = "The corner of my memory";
    string small = "memory";
    bool mem = endsWith(large,small);
    if(mem==1) {
        printf("Test 1 endsWith(string,string) : passed\n");
    }
    else{
        printf("Test 1 endsWith(string,string) : FAILED\n");
    }
    //TEST CASE 2(False)
    large = "The corner of my memory";
    small = "corner";
    mem = endsWith(large,small);
    if(mem==0) {
        printf("Test 2 endsWith(string,string) : passed\n");
    }
    else{
        printf("Test 2 endsWith(string,string) : FAILED\n");
    }
    //TEST CASE 3(True)
    large = "Time travel to 2006";
    small = "2006";
    mem = endsWith(large,small);
    if(mem==1) {
        printf("Test 3 endsWith(string,string) : passed\n");
    }
    else{
        printf("Test 3 endsWith(string,string) : FAILED\n");
    }
    //TEST CASE 4(False)
    large = "Time travel to 2006";
    small ="2007";
    mem = endsWith(large,small);
    if(mem==0) {
        printf("Test 4 endsWith(string,string) : passed\n");
    }
    else{
        printf("Test 4 endsWith(string,string) : FAILED\n");
    }
    /////////////TEST CASE 5
    large = "A girl as small as a violet";
    small= "";
    mem = endsWith(large,small);
    if(mem==1) {
        printf("Test 5 endsWith(string,string) : passed\n");
    }
    else{
        printf("Test 5 endsWith(string,string) : FAILED\n");
    }
    printf("\n\n");

/********************************************************************************************************/
///////////////*************************bool endsWith(string, char)************************///////////////
/********************************************************************************************************/
    //TEST CASE 1
    large = "The corner of my memory";
    char s = 'y';
    mem = endsWith(large,s);
    if(mem==1) {
        printf("Test 1 endsWith(string,char) : passed\n");
    }
    else{
        printf("Test 1 endsWith(string,char) : FAILED\n");
    }
    //TEST CASE 2(False)
    large = "The corner of my memory";
    s = 'c';
    mem = endsWith(large,s);
    if(mem==0) {
        printf("Test 2 endsWith(string,char) : passed\n");
    }
    else{
        printf("Test 2 endsWith(string,char) : FAILED\n");
    }
    //TEST CASE 3(True)
    large = "Time travel to 2006";
    s = '6';
    mem = endsWith(large,s);
    if(mem==1) {
        printf("Test 3 endsWith(string,char) : passed\n");
    }
    else{
        printf("Test 3 endsWith(string,char) : FAILED\n");
    }
    //TEST CASE 4(False)
    large = "Time travel to 2006";
    s ='7';
    mem = endsWith(large,s);
    if(mem==0) {
        printf("Test 4 endsWith(string,char) : passed\n");
    }
    else{
        printf("Test 4 endsWith(string,char) : FAILED\n");
    }
    /////////////TEST CASE 5
    large = "A girl as small as a violet";
    s = '\0';
    mem = endsWith(large,s);
    if(mem==1) {
        printf("Test 5 endsWith(string,char) : passed\n");
    }
    else{
        printf("Test 5 endsWith(string,char) : FAILED\n");
    }
    printf("\n\n");

/********************************************************************************************************/
///////////////*************************bool startsWith(string, string)************************/////////////
/********************************************************************************************************/
    //TEST CASE 1(True)
    large = "The corner of my memory";
    small = "The";
    mem = startsWith(large,small);
    if(mem==1) {
        printf("Test 1 startsWith(string,string) : passed\n");
    }
    else{
        printf("Test 1 startsWith(string,string) : FAILED\n");
    }
    //TEST CASE 2(False)
    large = "Mass is not proportional to volume";
    small = "proportional";
    mem = startsWith(large,small);
    if(mem==0) {
        printf("Test 2 startsWith(string,string) : passed\n");
    }
    else{
        printf("Test 2 startsWith(string,string) : FAILED\n");
    }
    //TEST CASE 3(True)
    large = "Time travel to 2006";
    small = "Time";
    mem = startsWith(large,small);
    if(mem==1) {
        printf("Test 3 startsWith(string,string) : passed\n");
    }
    else{
        printf("Test 3 startsWith(string,string) : FAILED\n");
    }
    //TEST CASE 4(False)
    large = "Time travel to 2006";
    small ="time";
    mem = startsWith(large,small);
    if(mem==0) {
        printf("Test 4 startsWith(string,string) : passed\n");
    }
    else{
        printf("Test 4 startsWith(string,string) : FAILED\n");
    }
    /////////////TEST CASE 5 (False)
    large = "A girl as small as a violet";
    small= "";
    mem = startsWith(large,small);
    if(mem==0) {
        printf("Test 5 startsWith(string,string) : passed\n");
    }
    else{
        printf("Test 5 startsWith(string,string) : FAILED\n");
    }
    printf("\n\n");
/********************************************************************************************************/
///////////////*************************bool startsWith(string, char)************************/////////////
/********************************************************************************************************/
    //TEST CASE 1
    large = "The corner of my memory";
    s = 'T';
    mem = startsWith(large,s);
    if(mem==1) {
        printf("Test 1 startsWith(string,char) : passed\n");
    }
    else{
        printf("Test 1 startsWith(string,char) : FAILED\n");
    }
    //TEST CASE 2(False)
    large = "The corner of my memory";
    s = 't';
    mem = startsWith(large,s);
    if(mem==0) {
        printf("Test 2 startsWith(string,char) : passed\n");
    }
    else{
        printf("Test 2 startsWith(string,char) : FAILED\n");
    }
    //TEST CASE 3(True)
    large = "Mass is not proportional to volume";
    s = 'M';
    mem = startsWith(large,s);
    if(mem==1) {
        printf("Test 3 startsWith(string,char) : passed\n");
    }
    else{
        printf("Test 3 startsWith(string,char) : FAILED\n");
    }
    //TEST CASE 4(False)
    large = "Time travel to 2006";
    s ='7';
    mem = startsWith(large,s);
    if(mem==0) {
        printf("Test 4 startsWith(string,char) : passed\n");
    }
    else{
        printf("Test 4 startsWith(string,char) : FAILED\n");
    }
    /////////////TEST CASE 5(False??)
    large = "A girl as small as a violet";
    s = '\0';
    mem = startsWith(large,s);
    if(mem==0) {
        printf("Test 5 startsWith(string,char) : passed\n");
    }
    else{
        printf("Test 5 startsWith(string,char) : FAILED\n");
    }
    //TEST CASE 6
    large = "";
    s = '\0';
    mem = startsWith(large,s);
    if(mem==1) {
        printf("Test 6 startsWith(string,char) : passed\n");
    }
    else{
        printf("Test 6 startsWith(string,char) : FAILED\n");
    }
    printf("\n\n");
/********************************************************************************************************/
///////////////********************bool equalsIgnoreCase(string, string)*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1(True)
    large = "Mass is not proportional to volume";
    small = "mASS IS noT pRopORtiOnaL to VoLUmE";
    mem = equalsIgnoreCase(large,small);
    if(mem==1) {
        printf("Test 1 equalsIgnoreCase(string,string) : passed\n");
    }
    else{
        printf("Test 1 equalsIgnoreCase(string,string) : FAILED\n");
    }
    //TEST CASE 2(False)
    large = "Mass is not proportional to volume";
    small = "mASS IS noT pRopORtiOnaL";
    mem = equalsIgnoreCase(large,small);
    if(mem==0) {
        printf("Test 2 equalsIgnoreCase(string,string) : passed\n");
    }
    else{
        printf("Test 2 equalsIgnoreCase(string,string) : FAILED\n");
    }
    //TEST CASE 3(True)
    large = "A GIRL AS small as a VioLet";
    small = "a girl as small as a violet";
    mem = equalsIgnoreCase(large,small);
    if(mem==1) {
        printf("Test 3 equalsIgnoreCase(string,string) : passed\n");
    }
    else{
        printf("Test 3 equalsIgnoreCase(string,string) : FAILED\n");
    }
    //TEST CASE 4(False)
    large = "A girl who moves like a flower petal";
    small ="";
    mem = equalsIgnoreCase(large,small);
    if(mem==0) {
        printf("Test 4 equalsIgnoreCase(string,string) : passed\n");
    }
    else{
        printf("Test 4 equalsIgnoreCase(string,string) : FAILED\n");
    }
    //TEST CASE 5 (True)
    large = "";
    small= "";
    mem = equalsIgnoreCase(large,small);
    if(mem==1) {
        printf("Test 5 equalsIgnoreCase(string,string) : passed\n");
    }
    else{
        printf("Test 5 equalsIgnoreCase(string,string) : FAILED\n");
    }
    printf("\n\n");

/********************************************************************************************************/
///////////////********************string doubleToString(double, int)*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1(True)
    double dope = 8.2567;
    string hope = doubleToString(dope,4);
    string test = "8.2567";
    if(test==hope){
        printf("Test 1 doubleToString(double, int) : passed\n");
    }
    else{
        printf("Test 1 doubleToString(double, int) : FAILED\n");
    }
    //TEST CASE 2
    dope = 54678.432167;
    hope = doubleToString(dope,6);
    test = "54678.432167";
    if(test==hope){
        printf("Test 2 doubleToString(double, int) : passed\n");
    }
    else{
        printf("Test 2 doubleToString(double, int) : FAILED\n");
    }
    //TEST CASE 3
    dope = 1.0;
    hope = doubleToString(dope,1);
    test = "1.0";
    if(test==hope){
        printf("Test 3 doubleToString(double, int) : passed\n");
    }
    else{
        printf("Test 3 doubleToString(double, int) : FAILED\n");
    }
    //TEST CASE 4
   dope = '\0';
   hope = doubleToString(dope,'\0');
   test = "";
   if(test==hope){
       printf("Test 3 doubleToString(double, int) : passed\n");
   }
   else{
       printf("Test 3 doubleToString(double, int) : FAILED\n");
   }

    printf("\n\n");
/********************************************************************************************************/
///////////////********************double stringToDouble(string);*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1(True)
    string test1 = "8.2567";
    double num = 8.2567;
    double dub = stringToDouble(test1);
    if(dub==num){
        printf("Test 1 stringToDouble(string s) : passed\n");
    }
    else{
        printf("Test 1 stringToDouble(string s) : FAILED\n");
    }
    //TEST CASE 2
    test1 = "54678.432167";
    num = 54678.432167;
    dub = stringToDouble(test1);
    if(dub==num){
        printf("Test 2 stringToDouble(string s) : passed\n");
    }
    else{
        printf("Test 2 stringToDouble(string s) : FAILED\n");
    }
    //TEST CASE 3
    test1 = "1.0";
    num = 1.0;
    dub = stringToDouble(test1);
    if(dub==num){
        printf("Test 3 stringToDouble(string s) : passed\n");
    }
    else{
        printf("Test 3 stringToDouble(string s) : FAILED\n");
    }
    //TEST CASE 4
    test1 = "";
    num = '\0';
    dub = stringToDouble(test1);
    if(dub==num){
        printf("Test 4 stringToDouble(string s) : passed\n");
    }
    else{
        printf("Test 4 stringToDouble(string s) : FAILED\n");
    }
    printf("\n\n");
/********************************************************************************************************/
///////////////********************string toLowerCase(string);*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1(True)
    string upper = "THE LEGEND OF THE BLUE SEA";
    string low = toLowerCase(upper);
    string lower = "the legend of the blue sea";
    if(low==lower){
        printf("Test 1 string toLowerCase(string) : passed\n");
    }
    else{
        printf("Test 1 string toLowerCase(string) : FAILED\n");
    }
    //TEST CASE 2(True)
    upper = "bit BY BIT by BiT By bIT";
    low = toLowerCase(upper);
    lower = "bit by bit by bit by bit";
    if(low==lower){
        printf("Test 2 string toLowerCase(string) : passed\n");
    }
    else{
        printf("Test 2 string toLowerCase(string) : FAILED\n");
    }
    //TEST CASE 3(True)
    upper = "how2can$i%say";
    low = toLowerCase(upper);
    lower = "how2can$i%say";
    if(low==lower){
        printf("Test 3 string toLowerCase(string) : passed\n");
    }
    else{
        printf("Test 3 string toLowerCase(string) : FAILED\n");
    }
    //TEST CASE 4(True)
    upper = "H";
    low = toLowerCase(upper);
    lower = "h";
    if(low==lower){
        printf("Test 4 string toLowerCase(string) : passed\n");
    }
    else{
        printf("Test 4 string toLowerCase(string) : FAILED\n");
    }
    //TEST CASE 5(True)
    upper = "";
    low = toLowerCase(upper);
    lower = "";
    if(low==lower){
        printf("Test 5 string toLowerCase(string) : passed\n");
    }
    else{
        printf("Test 5 string toLowerCase(string) : FAILED\n");
    }
    printf("\n\n");

/********************************************************************************************************/
///////////////********************string toUpperCase(string)*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1(True)
    string rip = "the legend of the blue sea";
    string up = toUpperCase(rip);
    string upa = "THE LEGEND OF THE BLUE SEA";
    if(up==upa){
        printf("Test 1 string toUpperCase(string) : passed\n");
    }
    else{
        printf("Test 1 string toUpperCase(string) : FAILED\n");
    }
    //TEST CASE 2(True)
    rip = "doN't wAnNa CrY";
    up = toUpperCase(rip);
    upa = "DON'T WANNA CRY";
    if(up==upa){
        printf("Test 2 string toUpperCase(string) : passed\n");
    }
    else{
        printf("Test 2 string toUpperCase(string) : FAILED\n");
    }
    //TEST CASE 3(True)
    rip = "you3tOOk5A9left6ofF";
    up = toUpperCase(rip);
    upa = "YOU3TOOK5A9LEFT6OFF";
    if(up==upa){
        printf("Test 3 string toUpperCase(string) : passed\n");
    }
    else{
        printf("Test 3 string toUpperCase(string) : FAILED\n");
    }
    //TEST CASE 4(True)
    rip = "lastlaugh LANEEEEE$$$$$#####";
    up = toUpperCase(rip);
    upa = "LASTLAUGH LANEEEEE$$$$$#####";
    if(up==upa){
        printf("Test 4 string toUpperCase(string) : passed\n");
    }
    else{
        printf("Test 4 string toUpperCase(string) : FAILED\n");
    }
    //TEST CASE 5(True)
    rip = "";
    up = toUpperCase(rip);
    upa = "";
    if(up==upa){
        printf("Test 5 string toUpperCase(string) : passed\n");
    }
    else{
        printf("Test 5 string toUpperCase(string) : FAILED\n");
    }
    printf("\n\n");


/********************************************************************************************************/
///////////////********************string trim(string)*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1
    string cry = "       I cry\n  ";
    string crying = trim(cry);
    string truly = "I cry";
    if(truly==crying){
        printf("Test 1 string trim(string) : passed\n");
    }
    else{
        printf("Test 1 string trim(string) : FAILED\n");
    }
    //TEST CASE 2
    cry = "         I hate me now    \t    \n      ";
    crying = trim(cry);
    truly = "I hate me now";
    if(truly==crying){
        printf("Test 2 string trim(string) : passed\n");
    }
    else{
        printf("Test 2 string trim(string) : FAILED\n");
    }
    //TEST CASE 3
    cry = "                             ";
    crying = trim(cry);
    truly = "";
    if(truly==crying){
        printf("Test 3 string trim(string) : passed\n");
    }
    else{
        printf("Test 3 string trim(string) : FAILED\n");
    }
    //TEST CASE 4
    cry = "";
    crying = trim(cry);
    truly = "";
    if(truly==crying){
        printf("Test 4 string trim(string) : passed\n");
    }
    else{
        printf("Test 4 string trim(string) : FAILED\n");
    }
    //TEST CASE 5
    cry = "        I SMILEEEEEEE  ! ! ! !      ";
    crying = trim(cry);
    truly = "I SMILEEEEEEE  ! ! ! !";
    if(truly==crying){
        printf("Test 5 string trim(string) : passed\n");
    }
    else{
        printf("Test 5 string trim(string) : FAILED\n");
    }
    printf("\n\n");

    /////*****FIX THIS ONE******//////
/********************************************************************************************************/
///////////////********************string stringReplace(string, string, string)*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1
    string day6 = "I hate me now";
    string old = " ";
    string cool = "hate";
    string day62 = stringReplace(day6,old,cool);
    if(day62=="Ihatehatehatemehatenow"){
        printf("Test 1 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 1 string stringReplace(string, string, string) : FAILED\n");
    }
    //TEST CASE 2
    day6 = "hate hate hate Day6";
    old = "hate";
    cool = "yes";
    day62 = stringReplace(day6,old,cool);
    if(day62=="yes yes yes Day6"){
        printf("Test 2 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 2 string stringReplace(string, string, string) : FAILED\n");
    }
    //TEST CASE 3
    //same
    day6 = "hate hate hate Day6";
    old = "hate";
    cool = "love";
    day62 = stringReplace(day6,old,cool);
    if(day62=="love love love Day6"){
        printf("Test 3 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 3 string stringReplace(string, string, string) : FAILED\n");
    }
    //TEST CASE 4
    day6 = "darnheckdarnyoutoheckingheck";
    old = "heck";
    cool = "frick";
    day62 = stringReplace(day6,old,cool);
    if(day62=="darnfrickdarnyoutofrickingfrick"){
        printf("Test 4 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 4 string stringReplace(string, string, string) : FAILED\n");
    }
    //TEST CASE 5
    day6 = "darnheckdarnyoutoheckingheck";
    old = "heck";
    cool = "bla";
    day62 = stringReplace(day6,old,cool);
    if(day62=="darnbladarnyoutoblaingbla"){
        printf("Test 5 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 5 string stringReplace(string, string, string) : FAILED\n");
    }
    //TEST CASE 6
    //same
    day6 = "darnheckdarnyoutoheckingheck";
    old = "heck";
    cool = "ripp";
    day62 = stringReplace(day6,old,cool);
    if(day62=="darnrippdarnyoutorippingripp"){
        printf("Test 6 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 6 string stringReplace(string, string, string) : FAILED\n");
    }
    //TEST CASE 7
    day6 = "oooooops oooooops";
    old = "oo";
    cool = "o";
    day62 = stringReplace(day6,old,cool);
    if(day62=="ooops ooops"){
        printf("Test 7 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 7 string stringReplace(string, string, string) : FAILED\n");
    }
    //TEST CASE 8
    day6 = "oooooops oooooops";
    old = "oo";
    cool = "aa";
    day62 = stringReplace(day6,old,cool);
    if(day62=="aaaaaaps aaaaaaps"){
        printf("Test 8 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 8 string stringReplace(string, string, string) : FAILED\n");
    }

    //TEST 9
    day6 = "oooooops oooooops";
    old = "oo";
    cool = "eee";
    day62 = stringReplace(day6,old,cool);
    if(day62=="eeeeeeeeeps eeeeeeeeeps"){
        printf("Test 9 string stringReplace(string, string, string) : passed\n");
    }
    else{
        printf("Test 9 string stringReplace(string, string, string) : FAILED\n");
    }
    printf("\n\n");

/********************************************************************************************************/
///////////////********************string pigLatinfy(string)*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1
    string help= "Help! I need somebody. Help!";
    string thelp = "elpHay! Iyay eednay omebodysay. elpHay!";
    string actual = pigLatinfy(help);
    if(actual==thelp){
        printf("Test 1 string pigLatinfy(string) : passed\n");
    }
    else {
        printf("Test 1 string pigLatinfy(string) : FAILED\n");
    }
    //TEST CASE 2
    help= "shutup baby cheer up bbbebbbeee";
    thelp= "utupshay abybay eerchay upyay ebbbeeebbbay";
    actual= pigLatinfy(help);
    if(actual==thelp){
        printf("Test 2 string pigLatinfy(string) : passed\n");
    }
    else{
        printf("Test 2 string pigLatinfy(string) : FAILED\n");
    }
    //TEST CASE 3
    help= "its time to ddddddddDDDDDDDDDDDDDDddDdDdDuel!!!!!!!!!!";
    thelp= "itsyay imetay otay uelddddddddDDDDDDDDDDDDDDddDdDdDay!!!!!!!!!!";
    actual= pigLatinfy(help);
    if(actual==thelp){
        printf("Test 3 string pigLatinfy(string) : passed\n");
    }
    else{
        printf("Test 3 string pigLatinfy(string) : FAILED\n");
    }
    printf("\n\n");

/********************************************************************************************************/
///////////////********************string stringJoin(string)*********************/////////////
/********************************************************************************************************/
    //TEST CASE 1
    vector<string> v = {"Hi", "hello", "Day6", "I", "Smile"};
    string join = "Hi, hello, Day6, I, Smile";
    string act = stringJoin(v, ", ");
    if(act==join){
        printf("Test 1 string stringJoin(string) : passed\n");
    }
    else {
        printf("Test 1 string stringJoin(string) : FAILED\n");
    }
    printf("\n\n");

    //TEST CASE 1
    string toSplit = "Hi///Hello///Day6///I///Smile";
    vector<string> afk = stringSplit(toSplit, "///");
    vector<string> actt = {"Hi", "Hello", "Day6", "I", "Smile"};
    if(actt==afk){
        printf("Test 1 string stringSplit(string) : passed\n");
    }
    else {
        printf("Test 1 string stringSplit(string) : FAILED\n");
    }
    printf("\n\n");

}