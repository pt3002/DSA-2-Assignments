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
        int x =0;
        char *a;
        a = (char *)malloc(sizeof(char)*20);
        while(isOperand(exp[i])){
            a[x] = exp[i];
            i++;
            x++;
        }
        if(x>0){
            node *nn;
            nn = (node *)malloc(sizeof(node));
            nn -> o = (char *)malloc(sizeof(char)*x);
            memcpy(nn->o,a,x+1);
            nn -> left = NULL;
            nn -> right = NULL;
            etspush(ets,nn);
        }
        else if(exp[i]!=' '){
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
            a[0] = exp[i];
            nn -> o = (char *)malloc(sizeof(char));
            memcpy(nn->o,a,strlen(a)+1);
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
        if(!isOperand(t->o[0])){
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
        if(isOperand(t->o[0])){
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
    printf("%s ",t->o);
    inorder(t->right);
}

void compute(et *t){
    if(*t==NULL){
        return;
    }
    if((*t)->left && (*t)->right && ((*t)->left->left==NULL && (*t)->left->right==NULL) && ((*t)->right->left==NULL && (*t)->right->right==NULL)){
        int a = atoi((*t)->left->o);
        int b = atoi((*t)->right->o);
        int c;
        if((*t)->o[0]=='+'){
            c = a+b;
        }
        if((*t)->o[0]=='-'){
            c = a-b;
        }
        if((*t)->o[0]=='*'){
            c = a*b;
        }
        if((*t)->o[0]=='/'){
            c = a/b;
        }
        (*t) -> left = NULL;
        (*t) -> right = NULL;
        (*t) -> o = (char *)malloc(sizeof(char)*2);
        (*t) -> o[0] = '0' + c%10;
        c = c - c%10;
        c = c/10;
        if(c){
            (*t) -> o[1] = '0'+c%10;
        }
        int j = 0;
        printf("\n");
        return;
    }
    compute(&((*t)->left));
    compute(&((*t)->right));
}