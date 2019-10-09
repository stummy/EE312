#ifndef _Poly_h
#define _Poly_h 1

#include<stdbool.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

struct polyType {
    struct node *list;  // Pointer to first node (for high-order term)
};
typedef struct polyType *Poly;

Poly makePoly(char *);
Poly polyCopy(Poly);
double polyEval(Poly, double);
Poly polyAdd(Poly, Poly);
Poly polyMult(Poly, Poly);
void addTerm(Poly, int, int);
int realRoots(Poly);
char *stringPoly(Poly);
bool polyEqual(Poly, Poly);
void deletePoly(Poly);

//helper functions

#endif
