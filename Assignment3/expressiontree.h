#include <stdlib.h>

typedef struct node{
    char *o;
    struct node *left;
    struct node *right;
}node;

typedef node *et;

void init_tree(et *t, char *exp);

void inorder(et t);

void validation_leaves(et t, int *leaves, int *index);

void validation_nodes(et t, int *nodes, int *k);

void compute(et *t);
