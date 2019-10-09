#include<stdio.h>
#include<string.h>
#include "String.h"

void test1() {
    const char *q = "Hello World";

    String *s = makeString(q);

    printf("%s", s->data);
    printf("\n");

    String *t = utStrdup(s);
    printf("%s", t->data);
    printf("\n");

    utStrfree(t);
    utStrfree(s);
}

void test2() {
    char str1[20] = "hello";
    char str2[20] = " world";
    String *utStr1;
    String *utStr2;

    utStr1 = makeString(str1);
    utStr2 = makeString(str2);

    String *utStr3 = utStrdup(utStr1);
    utStr3 = utStrrealloc(utStr3, 50);
    utStrcat(utStr3, utStr2);

    printf("utStr3: %s\n", utStr3->data);
    printf("\tlength: %u\n", utStr3->length);
    printf("\tcapacity: %u\n", utStr3->capacity);
}

void test3() {
    String *s = makeString("hi");
    s = utStrrealloc(s, 10000);
    fflush(stdout);

    String *ast = makeString("*");

    for(int k = 0; k < 9000; k++) utStrcat(s, ast);
    if(s->data[9000] != '*') printf("Test 3 fails\n");
    else if(strlen(s->data) != 9002) printf("Wrong string length - test 3 fails\n");

    printf("String length: %u\n", s->length);

    utStrfree(s);
}

void test4(){
    String *s= makeString("No Hard Exam Please!");
    printf("Test String: %s\n",s->data);
    int strlength=utStrlen(s);
    printf("Length of the string is: %d\n",strlength);
    printf("Capacity of the string is: %d\n\n",s->capacity);

    String *t=makeString("1234567");
    printf("Test String: %s\n",t->data);
    strlength=utStrlen(t);
    printf("Length of the string is: %d\n",strlength);
    printf("Capacity of the string is: %d\n",t->capacity);
    utStrcpy(t,s);
    printf("New String of First String Copied Into Second String Is: ");
    printf("%s", t->data);//Should now say "No Hard"
    printf("\n");
    utStrfree(s);
    utStrfree(t);
}

void test5(){
    String *s=makeString("Cuphead");
    String *t=makeString(" and Mugman");
    printf("Test String 1: %s\n",s->data);
    printf("Test String 2: %s\n",t->data);
    printf("Length of String 1 is: %d\n",s->length);
    printf("Length of String 2 is: %d\n\n",t->length);
    utStrcat(s,t);//Should not change s. "Cuphead"
    printf("Adding String 2 to String 1 Without Changing Capacity: %s\n",s->data);
    printf("Length of String 1 is: %d\n\n",s->length);
    utStrrealloc(s,11);
    utStrcat(s,t);//Should now say "Cuphead and"
    printf("Adding String 2 to String 1 With Changing Capacity: %s\n",s->data);
    printf("Length of String 1 is: %d\n\n",s->length);
    utStrrealloc(s,22);
    utStrcat(s,t);//Should now say "Cuphead and and Mugman"
    printf("Adding String 2 to String 1 With Changing Capacity: %s\n",s->data);
    printf("Length of String 1 is: %d\n\n",s->length);
    utStrfree(s);
    utStrfree(t);
}

void test6() {
    String *s = makeString("          ");
    printf("Test String 1: %s\n", s->data);
    printf("Length of String 1 is: %d\n", s->length);
    printf("Capacity of String 1 is %d\n\n", s->capacity);
    String *t = makeString("");
    printf("Test String 2: %s\n", t->data);
    printf("Length of String 2 is: %d\n", t->length);
    printf("Capacity of String 2 is %d\n\n", t->capacity);
    utStrrealloc(s, 50);
    utStrcat(s,t);
    printf("Adding String 2 to String 1 is: %s\n", s->data);
    printf("New length is: %d\n\n", s->length);
    String *a = makeString("hi.");
    printf("Test String 3: %s\n", a->data);
    printf("Length of String 3 is: %d\n", a->length);
    printf("Capacity of String 3 is %d\n\n", a->capacity);
    utStrcat(s,a);
    printf("Adding String 3 to String 1 is: %s\n", s->data);
    printf("New length is: %d\n\n", s->length);

    utStrfree(s);
    utStrfree(t);
    utStrfree(a);
}



int main() {
    printf("Test 1: \n");
    test1();
    printf("\n\nTest 2: \n");
    test2();
    printf("\n\nTest 3: \n");
    test3();
    printf("\n\nTest 4: \n");
    test4();
    printf("\n\nTest 5: \n");
    test5();
    printf("\n\nTest 6: \n");
    test6();

}