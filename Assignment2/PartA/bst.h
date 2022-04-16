#include <stdio.h>

typedef struct node{
    int *A;
    int n;
    int MIN;
}node;

typedef node* bst;

void init_bst( bst *t1);

void insert_bst( bst *t, int data );

void inorder(bst t);
void inorder_helper( bst t, int index);

void postorder(bst t);
void postorder_helper( bst t, int index );

void preorder(bst t);
void preorder_helper( bst t, int index );

void isComplete( bst t );
