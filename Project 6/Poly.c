#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "Poly.h"

/* Student information for project:
 *
 * On my honor, Zahra Atzuri, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Zahra Atzuri
 * email address: atzuri@utexas.edu
 * UTEID: zfa84
 * Section 5 digit ID: 16185
 * Number of slip days used on this assignment: 2
 */


// ============================ HELPER FUNCTIONS ==========================
/* Function: deleteNode
 * Description: deletes a node based on an input coeff
 *      This segment of code is based off of Dr. Eberlein's lecture
 *      slides (topic9-memory allocation)
 * Input: linked list polynomial, coefficient to be deleted
 * Output: none (output updated polynomial one)
 * Big-O: O(N)
 */
void deleteNode(Poly poly, int coeff){
    struct node *cur = poly->list;
    struct node *prev = NULL;

    // case to delete at head
    if(cur->coeff == coeff){
        poly->list = cur->next;
        free(prev);
        prev = NULL;
        free(cur);
        cur = NULL;
        return;
    }
    // delete other than head
    while(cur != NULL && cur->coeff != coeff){
        if(cur == NULL)
            poly->list = NULL;
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;

    // free nodes and set to null
    free(cur);
    cur = NULL;

}


/* Function: stringHelp
 * Description: helper function for stringPoly (to reduce redundancy)
 * Input: string to add to, coeff, and exp
 * Output: string polynomial
 * Big-O: O(1)
 */
char *stringHelp(char *term, int coeff, int exp){
    if(exp == 1 && coeff != 1)
        sprintf(term, "%dx", coeff);                           // print coeff*x
    else if(exp > 1 && coeff != 1)
        sprintf(term, "%dx^%d", coeff, exp);                   // print coeff*x^exp
    else if(exp == 1 && coeff == 1)
        sprintf(term, "x");                                    // print x
    else if(exp > 1 && coeff == 1)
        sprintf(term, "x^%d", exp);                            // print x^exp
    else if(exp == 0)
        sprintf(term, "%d", coeff);                            // print constant
    return term;
}

/* Function: combineCoeff
 * Description: Helper function for addTerm to combine coefficients when like exp
 * Input: struct node temp, struct node current, and a coeff
 * Output: none (output updated polynomial one)
 * Big-O: O(1)
 */
void combineCoeff(struct node *n, struct node *cur, int coeff){
    cur->coeff += coeff;
    free(n);
    n = NULL;
}


// ============================ POLY FUNCTIONS ==========================

/* Function: makePoly
 * Description: This function takes a string representation src of a
 *      polynomial, and returns a pointer to the linked list representation
 *      of the polynomial. The linked list must contain only terms with
 *      non-zero coefficients, and the nodes for the terms must be listed
 *      in decreasing order of degree. No two nodes can represent terms with
 *      the same power of x.
 * Input: polynomial in string src
 * Output: linked list polynomial p
 * Big-O: O(N^2)
 */
Poly makePoly(char *src) {
    int i = 0, j = 0, k = 0;
    int caratPos = 0, len = 0;
    bool neg = false;
    
    len = strlen(src);
    
    Poly p = malloc(sizeof(struct polyType));
    // check malloc
    if(p == NULL) {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    p->list = NULL;
    
    // zero polynomial
    if(len == 0 || src[0] == '0'){
        p->list = NULL;
        return p;
    }
    
    // create the link list
    for (i = len-1; i >= 0 ; --i) {
        //counts how long the term is b/w operator signs
        if(src[i] != '-' || src[i] != '+' || i != 0)
            j++;
        
        // index hits a -, + or index is 0
        if(src[i] == '-' || src[i] == '+' || i == 0){
            // create and initialize a node
            struct node *n = malloc(sizeof(struct node));
            // check malloc
            if(n == NULL) {
                printf("Error: malloc failed\n");
                exit(EXIT_FAILURE);
            }
            // initialize contents of node
            n->coeff = 0;
            
            int coeffic = 0;
            int expo = 0;
            
            // loops from operation sign (or beginning of str) to another (or end of str) to find contents of a term
            for (k = i; k < i+j; k++) {
                // set indicator if negative
                if(src[k] == '-')
                    neg = true;
                
                // -------------- coefficient --------------
                // if coefficient is 1
                if(src[k] == 'x' && src[k-1] == ' ')
                    coeffic = 1;
                else if((k == 0 && src[i] == 'x') || (k == 0 && src[i] == '-' && src[k+1] == 'x')){
                    // if coefficient is 1 AND negative
                    coeffic = 1;
                    if(src[k] == '-'){
                        coeffic *= -1;
                        neg = false;
                    }
                }
                // concatenate non-one coeff
                if((src[k] >= '0' && src[k] <= '9') && src[k] != 'x') {
                    if(caratPos == 0)
                        coeffic = coeffic*10 + (src[k] - '0');
                }
                // apply negative condition after concatenating the coeff
                if(src[k] == 'x' || k == len-1){
                    if (neg == true){
                        coeffic *= -1;
                        neg = false;
                    }
                }
                
                // -------------- exponent --------------
                // find position of the carat (indicator for ^)
                if(src[k] == '^')
                    caratPos = k;
                // set exp = 0 for constant
                if(k == len-1 && src[k] != 'x' && caratPos == 0){
                    expo = 0;
                }
                // set exp = 1 for 'x' without exponent
                if(src[k] == ' ' && src[k-1] == 'x'){           // this finds 'x' if not last term
                    expo = 1;
                } if (src[k] == 'x' && k == len-1) {            // this finds 'x' if last term
                    expo = 1;
                }
                // find exp > 1 if '^'
                if((src[k] >= '0' && src[k] <= '9') && caratPos != 0){
                    expo = expo * 10 + (src[k] - '0');
                }
            }
            n->coeff = coeffic;
            n->exp = expo;
            
            if(p->list == NULL){
                n->next = NULL;                                // null terminate
                p->list = n;
            } else {
                n->next = p->list;                             // adds to list
                p->list = n;
            }
            
            j = 0; // reset all indicators
        }
        caratPos = 0; // reset all indicators
    }
    return p;
}


/* Function: polyCopy
 * Description: This function creates a copy of the polynomial that src references.
 *      The original polynomial and the copy should not share nodes -
 *      each node in the src polynomial will be duplicated for the copy.
 * Input: linked list polynomial src
 * Output: copied linked list
 * Big-O: O(N)
 */
Poly polyCopy(Poly src) {
    Poly p = malloc(sizeof(Poly));
    // check malloc
    if(p == NULL) {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // check if src null
    if(src == NULL){
        free(p);
        p = NULL;
        // p->list = NULL;
        return p;
    }
    // initialize nodes
    struct node *srcPtr = src->list;  // set ptr to src
    struct node *head = NULL;
    struct node *cur = NULL;

    while(srcPtr != NULL){
        struct node *n = malloc(sizeof(struct node));
        // check malloc
        if(n == NULL) {
            printf("Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        // initialize node
        n->exp = srcPtr->exp;
        n->coeff = srcPtr->coeff;
        n->next = NULL;

        // add nodes to p
        if(head != NULL){                                       // if not the last term
            cur->next = n;
            cur = n;
        } else if(head == NULL){                                // if last term
            head = n;
            p->list = head;
            cur = n;
        }
        srcPtr = srcPtr->next;
    
    }  
    // free node and set to null
    //free(srcPtr);
    //srcPtr = NULL;

    return p;
}


/* Function: polyEval
 * Description: This function returns the polynomial function's value at x = val.
 * Input: linked list polynomial src, input value (in double)
 * Output: result (in double) after computing the polynomial with input value
 * Big-O: O(N)
 */
double polyEval(Poly src, double val) {
    double result = 0;

    // check if src null
    if(src == NULL)
        return result;
    struct node *srcPtr = src->list;

    while(srcPtr != NULL){
        // initialize & declare
        int exp = 0;
        int coeff = 0;
        double term = val;

        exp = srcPtr->exp;
        coeff = srcPtr->coeff;

        if(exp != 0){
            for (int i = 0; i < exp-1; ++i) {
                term *= val;                                        // find x^exponent
            }
            term *= coeff;                                          // multiply by constant
            result += term;                                         // add to sum
        } else {
            // constant
            result += coeff;
        }
        srcPtr = srcPtr->next;
    }
    // free node and set to null
    free(srcPtr);
    srcPtr = NULL;

    return result;
}

/* Function: addTerm
 * Description: This function modifies the poly one by adding the monomial term
 *      with the specified coefficient and exponent. Note that this may require creating a
 *      new node in the polynomial's linked list representation, modifying the fields in an
 *      existing node, or doing nothing (e.g., if the coefficient argument is 0 or the
 *      exponent is negative.) If a high order term is added, the pointer to the list will need to be updated.
 * Input: linked list polynomial one, coefficient and exponent to be added.
 * Output: none (output updated polynomial one)
 * Big-O: O(N)
 */
void addTerm(Poly one, int coeff, int exponent) {
    // checks if coeff not 0 or if exponent not neg
    if(coeff != 0 || exponent > 0){
        struct node *n = malloc(sizeof(struct node));
        // check malloc
        if(n == NULL) {
            printf("Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        // initialize node
        n->coeff = coeff;
        n->exp = exponent;
        n->next = NULL;

        struct node *cur = one->list;  // set pointer to poly

        // case for a zero polynomial or null
        if(one->list == NULL){
            one->list = n;
            free(n);
            n = NULL;
            return;
        }

        // head insertion
        if(exponent >= cur->exp) {
            if (n->exp == one->list->exp){                      // if same exp, combine coeffs
                combineCoeff(n, cur, coeff);
                return;
            } else {
                n->next = one->list;                            // or links node to beginning of list if not
                one->list = n;
                return;
            }
        }
        // somewhere-in-between-head-and-tail insertion
        else {
            while(cur->next != NULL) {
                // compare if exponent is bigger than the next one
                if(exponent >= cur->next->exp){
                    if (exponent == cur->next->exp) {           // if same exp, combine coeffs
                        cur = cur->next;                        //      and also change cur to next term
                        combineCoeff(n, cur, coeff);
                        return;
                    }
                    n->next = cur->next;                        // or links node if not
                    cur->next = n;
                    break;
                }
                cur = cur->next;
            }
        }
        // tail insertion
        if(cur->next == NULL){
            cur->next = n;                                      // set current's last node to n
            n->next = NULL;                                     //      and null terminate n
        }
    }
}


/* Function: polyAdd
 * Description: This function returns the sum of the polynomial arguments.
 *      Neither of the arguments are modified. You will be dynamically creating
 *      a new linked list to hold the result of the operation.
 * Input: linked list polynomials one and two
 * Output: combined polynomial
 * Big-O: O(N^2)
 */
Poly polyAdd(Poly one, Poly two){
    int mark = 0;
    
    Poly twoCopy;
    Poly oneCopy;
    struct node *onePtr;
    struct node *twoPtr;

    // make a copy of one and two if neither null
    if(one->list != NULL)
        oneCopy = polyCopy(one);
    if(two->list != NULL)
        twoCopy = polyCopy(two);
    // if either or both are null
    if(one->list == NULL && two->list != NULL){
        return twoCopy;
    }
    if(two->list == NULL && one->list != NULL){
        return oneCopy;
    }
    if(one->list == NULL && two->list == NULL){
        oneCopy->list = NULL;
        return oneCopy;
    }

    // set pointers to the copied polys
    onePtr = oneCopy->list;
    twoPtr = twoCopy->list;

    while(onePtr->next != NULL && twoPtr->next != NULL){
        // check if both exponents are equal and adds to copyOne
        if(onePtr->exp == twoPtr->exp){
            addTerm(oneCopy, twoPtr->coeff, twoPtr->exp);  // O(N^2)
            onePtr = onePtr->next;
            twoPtr = twoPtr->next;
        } else {
            addTerm(oneCopy, twoPtr->coeff, twoPtr->exp);
            twoPtr = twoPtr->next;
        }
    }

    // if one of the poly's is shorter than the other or if both's next node is null
    if(onePtr->next == NULL || twoPtr->next == NULL){
        // if two's length is shorter than one's
        if(onePtr->next != NULL && twoPtr->next == NULL){
            addTerm(oneCopy, twoPtr->coeff, twoPtr->exp);
            onePtr = onePtr->next;
            mark = -1;                                              //  marker to prevent last condition
        }
        if(twoPtr->next != NULL && onePtr->next == NULL) {
            // if one's length is shorter than two's
            while (twoPtr->next != NULL) {
                addTerm(oneCopy, twoPtr->coeff, twoPtr->exp); // O(N^2)
                twoPtr = twoPtr->next;
                mark = -1;                                          //  marker to prevent last condition
            }
            // adding the last node
            if(twoPtr->next == NULL){
                addTerm(oneCopy, twoPtr->coeff, twoPtr->exp);
                mark = -1;                                          //  marker to prevent last condition
            }
        }
        // if both have reached the end of list
        if(twoPtr->next == NULL && onePtr->next == NULL && mark != -1)
            addTerm(oneCopy, twoPtr->coeff, twoPtr->exp);
    }

    // deletes all zero coefficients
    onePtr = oneCopy->list;
    while(onePtr != NULL){
        if(onePtr->coeff == 0){
            deleteNode(oneCopy, 0); // O(N^2)
            onePtr = oneCopy->list;
        }
        onePtr = onePtr->next;
    }
    if(oneCopy->list->coeff == 0 && oneCopy->list->next == NULL){
        free(oneCopy->list);
	    oneCopy->list = NULL;
    }
    // delete and free stuff
    deletePoly(twoCopy);
    twoCopy = NULL;
    return oneCopy;
}


/* Function: polyMult
 * Description: This function returns the product of the polynomial arguments.
 *      Neither of the arguments are modified. You will be dynamically creating
 *      a new linked list to hold the result of the operation.
 * Input: linked list polynomials one and two
 * Output: combined polynomial
 * Big-O: O(N^2)
 */
Poly polyMult(Poly one, Poly two) {
    Poly twoCopy;
    Poly oneCopy;
    Poly p1 = NULL;
    Poly p2;

    struct node *onePtr = NULL;
    struct node *twoPtr = NULL;
    struct node *p1Ptr = NULL;
    struct node *p2Ptr = NULL;

    if(one->list == NULL || two->list == NULL){
        oneCopy = malloc(sizeof(Poly));
        oneCopy->list = NULL;
        return oneCopy;
    }
    oneCopy = polyCopy(one);
    twoCopy = polyCopy(two);

    // set pointers to the copied polys
    onePtr = oneCopy->list;
    twoPtr = twoCopy->list;

    struct node *head = NULL;
    struct node *cur = NULL; 

    while(onePtr != NULL){
        p2 = malloc(sizeof(Poly));
          while(twoPtr != NULL){
            struct node *n = malloc(sizeof(struct node));
            // check malloc
            if(n == NULL) {
                printf("Error: malloc failed\n");
                exit(EXIT_FAILURE);
            }
            // initialize node
            n->coeff = onePtr->coeff * twoPtr->coeff;
            n->exp = onePtr->exp + twoPtr->exp;
            n->next = NULL;

            // add nodes to p2
            if(head == NULL){                                       // if not the last term
                head = n;
                p2->list = head;
                cur = n;
            } else {                                                // if last term
                cur->next = n;
                cur = n;
            }
            twoPtr = twoPtr->next;
        }
        // reset nodes & pters
        head = NULL;
        twoPtr = twoCopy->list;

        // combine both polys
        if(p1 == NULL)
            p1 = polyCopy(p2);                                      // set p1 as p2
        else{
	    Poly pTemp = p1;
            p1 = polyAdd(p1, p2);
            deletePoly(pTemp);                                   // add p2 to p1
        }
	deletePoly(p2);
        onePtr = onePtr->next;
    }
    // free node and set to null
    deletePoly(twoCopy);
    deletePoly(oneCopy);
    return p1;
}


/* Function: realRoots
 * Description: If the src polynomial is of degree 2 or less, return the number
 *      of distinct real roots of the polynomial. If the polynomial is of degree
 *      3 or higher, return -1. Return -1 if the degree of the polynomial is 0.
 * Input: linked list polynomial src
 * Output: int
 * Big-O: O(N)
 */
int realRoots(Poly src) {
    // initialize
    struct node *n = src->list;
    int a = 0, b = 0, c = 0;
    int discr = 0, root = 0;

    // check if degree >= 3 or 0
    if(n->exp >= 3 || n->exp == 0) return -1;

    else if(n->exp <= 2 && n->exp != 0) {
        while(n->next != NULL){
            if(a == 0) a = n->coeff;                        // set a as first coefficient
            else if(b == 0) b = n->coeff;                   // set b as second coefficient
            n = n->next;
        }
        if(c == 0) c = n->coeff;                            // set c as constant
        discr = (b * b) - (4 * a * c);                      // find discriminant

        // check roots
        if(discr > 0) root = 2;
        if(discr == 0) root = 1;
        if(discr < 0) root = 0;
    }
    // free node and set to null
    n = NULL;

    return root;
}


/* Function: stringPoly
 * Description: This function returns a string representation of the polynomial.
 *      The non-zero terms should be given in order of decreasing exponent, and the ^
 *      symbol should be used to indicate exponentiation. The portion of the string that
 *      represents a term should not contain embedded space, and each + or - (subtraction)
 *      in the polynomial should contain a single blank space before and after it. You may
 *      assume that the string representation of the polynomial is at most 100 characters.
 *      Do not print coefficients equal to 1 except in constant terms. Negative coefficients
 *      should be represented in your string as a subtraction in terms after the high-order term.
 *      E.g., the string should be 3x^2 - 2x, not 3x^2 + -2x.
 * Input: linked list polynomial src
 * Output: string polynomial
 * Big-O: O(N)
 */
char *stringPoly(Poly src){
    int i = 0, check = 0;
    char *string = calloc(101 * sizeof(char), 1);
    char term[101];
    char signedTerm[101];
    struct node *cur = src->list;

    while(cur != NULL) {
        if(string[i] == 0){
            stringHelp(signedTerm, cur->coeff, cur->exp);
        } else {
                if (cur->coeff < 0) {
                    check = cur->coeff * -1;
                    sprintf(signedTerm, " - ");
                    stringHelp(term, check, cur->exp);
                    strcat(signedTerm, term);
                } else {
                    sprintf(signedTerm, " + ");
                    stringHelp(term, cur->coeff, cur->exp);
                    strcat(signedTerm, term);
                }
            }
        strcat(string, signedTerm);
        cur = cur->next;
    }
    return string;
}


/* Function: polyEqual
 * Description: This function returns true if the two polynomials are equal, and false otherwise.
 * Input: linked list polynomials one and two
 * Output: true or false if equal or not
 * Big-O: O(N)
 */
bool polyEqual(Poly one, Poly two) {
    bool eq = false;
    int mark = 0;
    struct node *onePtr = one->list;
    struct node *twoPtr = two->list;
    if(onePtr == NULL || twoPtr == NULL)
        eq = false;

    while(onePtr->next != NULL && twoPtr->next != NULL && mark != -1){
        if(onePtr->coeff != twoPtr->coeff || onePtr->exp != twoPtr->exp){
            eq = false;
            mark = -1;
        }
        onePtr = onePtr->next;
        twoPtr = twoPtr->next;
    }
    if(onePtr->next == NULL && twoPtr->next == NULL)
        eq = true;
    return eq;
}


/* Function: deletePoly
 * Description: Destroy the polynomial and deallocate all memory associated with it.
 * Input: linked list polynomial one
 * Output: none
 * Big-O: O(N)
 */
void deletePoly(Poly one) {
//    while(one->list != NULL){
//        one->list->coeff = 0;
//        deleteNode(one, 0);
//    }
//    one->list = NULL;
//    free(one);

    struct node *cur = one->list;
    struct node *next = NULL;
    while(cur != NULL){
        next = cur->next;
        free(cur);
        cur = next;
    }
    one->list = NULL;
    free(one);
 }
