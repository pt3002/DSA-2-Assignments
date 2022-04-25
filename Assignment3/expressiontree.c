#include <stdio.h>
#include <stdlib.h>
#include "expressiontree.h"
#include "postfix.h"
#include "etstack.h"
#include <string.h>

void init_tree(et *t, char *exp){
    *t = NULL;
    int i;
    etstack* ets = etscreateStack(strlen(exp));
    for(i=0; i<strlen(exp); i++){
        if(isOperand(exp[i])){
            node *nn;
            nn = (node *)malloc(sizeof(node));
            nn -> o = exp[i];
            nn -> left = NULL;
            nn -> right = NULL;
            etspush(ets,nn);
        }
        else{
            node *nright;
            nright = (node *)malloc(sizeof(node));
            node *nleft;
            nleft = (node *)malloc(sizeof(node));
            nright = etspop(ets);
            nleft = etspop(ets);
            node *nn;
            nn = (node *)malloc(sizeof(node));
            nn -> left = nleft;
            nn -> right = nright;
            nn -> o = exp[i];
            etspush(ets,nn);
        }
    }
    *t = etspop(ets);
    return;
}

void validation_leaves(et t, int *leaves, int *index){
    if(t==NULL){
        return;
    }
    if(t->left == NULL && t->right == NULL){
        if(!isOperand(t->o)){
            leaves[*index] = 0;
            *index+=1;
        }
        else{
            leaves[*index] = 1;
            *index+=1;
        }
        
    }
    validation_leaves(t->left, leaves, index);
    validation_leaves(t->right, leaves, index);
}

void validation_nodes(et t, int *nodes, int *k){
    if(t==NULL){
        return;
    }
    if(t->left != NULL || t->right != NULL){
        if(isOperand(t->o)){
            nodes[*k] = 0;
            *k+=1;
        }
        else{
            nodes[*k] = 1;
            *k+=1;
        }
        
    }
    validation_nodes(t->left, nodes, k);
    validation_nodes(t->right, nodes, k);
}

void inorder(et t){
    if(t==NULL){
        return;
    }
    inorder(t->left);
    printf("%c ",t->o);
    inorder(t->right);
}

void compute(et t){
    if(t==NULL){
        return;
    }
    if(t->left && t->right && (t->left->left==NULL && t->left->right==NULL) && (t->right->left==NULL && t->right->right==NULL)){
        int a = '9' - t->left->o;
        int b = '9' - t->right->o;
        if(t->o=='+'){
            int c = a+b;
            t->o= '0' + c;
        }
        if(t->o=='-'){
            int c = a-b;
            t->o= '0' + c;
        }
        if(t->o=='*'){
            int c = a*b;
            t->o= '0' + c;
        }
        if(t->o=='/'){
            int c = a/b;
            t->o= '0' + c;
        }
        t->left == NULL;
        t->right == NULL;
    }
    compute(t->left);
    compute(t->right);
}