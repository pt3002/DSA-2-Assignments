#include <stdlib.h>

typedef struct node{
    char o;
    struct node *left;
    struct node *right;
}node;

typedef node *et;

void init_tree(et *t, char *exp);