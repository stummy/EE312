#include<stdio.h>
#include<string.h>
#include "Poly.h"

int main() {
    Poly p1, p2, p3, p4, p5, p6, p7;

//    p1 = makePoly("3x^2 + 5x + 2");
//    deletePoly(p1);

//    p1 = makePoly("3x^2 + 5x + 2");
//    p2 = makePoly("-2x + 6");
//    deletePoly(p1);
//    deletePoly(p2);



    // ================================== Given Test Cases ============================================
   printf("\n------ Given Tests -------\n");
    // test 1, makePoly and stringPoly
    p1 = makePoly("3x^2 + 5x + 2");
    p2 = makePoly("-2x + 6");
    char *str1 = stringPoly(p1);
    char *str2 = stringPoly(p2);
    if(strcmp(str1, "3x^2 + 5x + 2") == 0 && strcmp(str2, "-2x + 6") == 0)
        printf("Test 1 makePoly and stringPoly: passed\n");
    else
        printf("Test 1 makePoly and stringPoly: failed\n");

    // test 2, polyMult
    Poly ans = polyMult(p1, p2);
    char *str3 = stringPoly(ans);
    if(strcmp(str3, "-6x^3 + 8x^2 + 26x + 12") == 0)
        printf("Test 2 polyMult: passed\n");
    else
        printf("Test 2 polyMult: failed\n");

    deletePoly(p1);
    deletePoly(p2);
    deletePoly(ans);
    free(str1);
    free(str2);
    free(str3);

    // ================================== Tests of Truth and Honor =====================================
    printf("\n------ Testing !!! -------\n");
    // test 1: polyAdd & (makePoly, stringPoly)
    p1 = makePoly("3x^2 + 5x + 2");
    p2 = makePoly("-13x^3 - 2x + 6");
    p3 = makePoly("13x^3 + 2x - 6");
    p4 = makePoly("-123x^14 + 20x^2 - x");

    ans = polyAdd(p2, p3);
    char *str = stringPoly(ans);
    if(strcmp(str, "") == 0)
        printf("Test 1 polyAdd: passed\n");
    else
        printf("Test 1 polyAdd: failed\n");

    ans = polyAdd(p1, ans);
    str = stringPoly(ans);
    if(strcmp(str, "3x^2 + 5x + 2") == 0)
        printf("Test 2 polyAdd: passed\n");
    else
        printf("Test 2 polyAdd: failed\n");

    ans = polyAdd(p4, ans);
    str = stringPoly(ans);
    if(strcmp(str, "-123x^14 + 23x^2 + 4x + 2") == 0)
        printf("Test 3 polyAdd: passed\n");
    else
        printf("Test 3 polyAdd: failed\n");

    deletePoly(p1);
    deletePoly(p2);
    deletePoly(p3);
    deletePoly(p4);
    deletePoly(ans);
    free(str);


    // test 2: polyMult
    p1 = makePoly("3x^2 + 5x + 2");
    p2 = makePoly("-13x^3 - 2x + 6");
    p3 = makePoly("13x^3 + 2x - 6");
    p4 = makePoly("-23x^14 - x");
    p5 = makePoly("");

    ans = polyMult(p5, p5);
    str = stringPoly(ans);
    if(strcmp(str, "") == 0)
        printf("Test 4 polyMult: passed\n");
    else
        printf("Test 4 polyMult: failed\n");

    ans = polyMult(p1, ans);
    str = stringPoly(ans);
    if(strcmp(str, "") == 0)
        printf("Test 5 polyMult: passed\n");
    else
        printf("Test 5 polyMult: failed\n");

    ans = polyMult(p2, p4);
    str = stringPoly(ans);
    if(strcmp(str, "299x^17 + 46x^15 - 138x^14 + 13x^4 + 2x^2 - 6x") == 0)
        printf("Test 6 polyMult: passed\n");
    else
        printf("Test 6 polyMult: failed\n");

    deletePoly(p1);
    deletePoly(p2);
    deletePoly(p3);
    deletePoly(p4);
    deletePoly(p5);
    deletePoly(ans);
    free(str);


    // test 3: realRoots
    p1 = makePoly("-4x^2 + 12x - 9"); // root = 1
    p2 = makePoly("12x^2 + 5x + 2"); // root = 0
    p3 = makePoly("2x^2 - 11x + 5"); // root = 2

    if(realRoots(p1) == 1)
        printf("Test 7 realRoots: passed\n");
    else
        printf("Test 7 realRoots: failed\n");

    if(realRoots(p2) == 0)
        printf("Test 8 realRoots: passed\n");
    else
        printf("Test 8 realRoots: failed\n");

    if(realRoots(p3) == 2)
        printf("Test 9 realRoots: passed\n");
    else
        printf("Test 9 realRoots: failed\n");

    deletePoly(p1);
    deletePoly(p2);
    deletePoly(p3);


    // test 4: polyEqual
    p1 = makePoly("-4x^2 + 12x - 9");
    p2 = makePoly("12x^2 + 5x + 2");
    p3 = makePoly("12x^2 + 5x + 2");
    p4 = makePoly("12x^2 + 5x");

    bool stat = polyEqual(p1, p2);
    if(stat == false)
        printf("Test 10 polyEqual: passed\n");
    else
        printf("Test 10 polyEqual: failed\n");

    stat = polyEqual(p2, p2);
    if(stat == true)
        printf("Test 11 polyEqual: passed\n");
    else
        printf("Test 11 polyEqual: failed\n");

    stat = polyEqual(p4, p3);
    if(stat == false)
        printf("Test 12 polyEqual: passed\n");
    else
        printf("Test 12 polyEqual: failed\n");

    stat = polyEqual(p3, p2);
    if(stat == true)
        printf("Test 13 polyEqual: passed\n");
    else
        printf("Test 13 polyEqual: failed\n");

    deletePoly(p1);
    deletePoly(p2);
    deletePoly(p3);
    deletePoly(p4);

    // test 4: polyEval
    p1 = makePoly("x^5 - 15x^4 + 85x^3 - 225x^2 + 274x - 120");
    p2 = makePoly("x^6 - 21x^5 + 175x^4 - 735x^3 + 1624x^2 - 1764x + 720");
    p3 = makePoly("x^7 - 28x^6 + 322x^5 - 1960x^4 + 6769x^3 - 13132x^2 + 13068x - 5040");

    double sum = polyEval(p1, 3.14);
    if(sum > 0.546334 - 0.00001 && sum < 0.546334 + 0.00001)
        printf("Test 14 polyEval: passed\n");
    else
        printf("Test 14 polyEval: failed\n");

    sum = polyEval(p2, 6.02);
    if(sum > 2.51141 - 0.00001 && sum < 2.51141 + 0.00001)
        printf("Test 15 polyEval: passed\n");
    else
        printf("Test 15 polyEval: failed\n");

    sum = polyEval(p2, -4.0);
    if(sum == 151200)
        printf("Test 16 polyEval: passed\n");
    else
        printf("Test 16 polyEval: failed\n");

    sum = polyEval(p3, -1.01);
    if(sum > -41017.54446 - 0.00001 && sum < -41017.5 + 0.00001)
        printf("Test 17 polyEval: passed\n");
    else
        printf("Test 17 polyEval: failed\n");

    deletePoly(p1);
    deletePoly(p2);
    deletePoly(p3);

}
    