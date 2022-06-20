#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

typedef struct Stack{
    node* *A;
    int size;
    int top;
}stack;

typedef node *bst;

void init_bst(bst *t);
void insert(bst *t, int key);

void init_bst(bst *t){
    *t = NULL;
    return;
}

void insert(bst *t, int key){
    node *new;
    new = (node *) malloc(sizeof(node));
    new -> data = key;
    new -> left = NULL;
    new -> right = NULL;
    if(*t==NULL){
        *t = new;
        return;
    }
    if((*t)->data > key){
        insert(&((*t)->left),key);
    }
    else{
        insert(&((*t)->right),key);
    }
    return;
}

void init_stack(stack *s, int size){
    s -> A = (node **)malloc(sizeof(node*)*size);
    s -> size = size;
    s -> top = -1;
    return;
}

void push(stack *s, node* n){
    s -> top ++;
    s -> A[s -> top] = n;
    return;
}

node* pop(stack *s){
    return s -> A[s->top--];
}

int main(){
    bst t;
    stack s1;
    init_stack(&s1,100);
    stack s2;
    init_stack(&s2,100);
    init_bst(t);
    return 0;
}
