#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void init_bst(bst *t){
    *t = NULL;
    return;
}

void insert(bst *t, int d){
    node *nn;
    nn = (node *) malloc(sizeof(node));
    nn -> left = NULL;
    nn -> right = NULL;
    nn -> data = d;
     
    // Tree empty condition
    if(*t == NULL){
        *t = nn;
        return;
    }

    if((*t) -> data > d){
        insert(&((*t) -> left), d);
    }

    if((*t) -> data < d){
        insert(&((*t) -> right), d);
    }

    return;
}

void inorder_traversal(bst t){
    if(!t){
        return;
    }
    inorder_traversal(t -> left);
    printf("%d ",t -> data);
    inorder_traversal(t -> right);
}

void postorder_traversal(bst t){
    if(!t){
        return;
    }
    postorder_traversal(t -> left);
    postorder_traversal(t -> right);
    printf("%d ",t -> data);
}