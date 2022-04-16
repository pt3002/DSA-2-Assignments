#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#define minimum -1

void inorder_helper( bst t, int index){

    // Checking if tree is empty
    if( t -> A[index] == minimum){
        return;
    }

    inorder_helper( t, 2*index + 1 );
    printf("%d \n", t -> A[index]);
    inorder_helper( t, 2*index + 2 );
}

void postorder_helper( bst t, int index ){

    // Checking if tree is empty
    if( t -> A[index] == minimum){
        return;
    }

    postorder_helper( t, 2*index + 1 );
    postorder_helper( t, 2*index + 2 );
    printf("%d \n", t -> A[index]);

}

void preorder_helper( bst t, int index ){

    // Checking if tree is empty
    if( t -> A[index] == minimum){
        return;
    }

    printf("%d \n", t -> A[index]);
    preorder_helper( t, 2*index + 1 );
    preorder_helper( t, 2*index + 2 );

}