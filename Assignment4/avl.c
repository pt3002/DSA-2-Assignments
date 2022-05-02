#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

void initAVL(avl *t){
    *t = NULL;
    return;
}



int height(avl t){
    if(t==NULL){
        return 0;
    }
    int l = height( t->left );
    int r = height( t-> right);
    if(l>r){
        return 1+l;
    }
    return 1+r;
}

void insertNode(avl *t, int data){
    node *nn;
    nn = (node *) malloc(sizeof(node));
    nn -> left = NULL;
    nn -> right = NULL;
    nn -> data = data;
    nn -> parent = NULL;
    nn -> bf = 0;
     
    // Tree empty condition
    if(*t == NULL){
        *t = nn;
        return;
    }

    if((*t) -> data > data){
        insertNode(&((*t) -> left), data);
        (*t) -> left -> parent = *t;
        (*t) -> bf = height((*t) -> left) - height((*t) -> right);
    }

    if((*t) -> data < data){
        insertNode(&((*t) -> right), data);
        (*t) -> right -> parent = *t;
        (*t) -> bf = height((*t) -> left) - height((*t) -> right);
    }
    return;
}

void inorder(avl t){
    if(!t){
        return;
    }
    inorder(t -> left);
    if(t->parent){
        printf("%d - %d - %d\n", t->data, t->parent->data, t->bf);
    }
    else{
        printf("%d - %d\n", t->data, t->bf);
    }
    inorder(t -> right);
}