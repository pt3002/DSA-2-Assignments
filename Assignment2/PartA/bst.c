#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#define minimum -1

// Init BST function
void init_bst( bst *t1) {

    bst t;
    t = (bst) malloc(sizeof(node));
    t -> n = 100;
    t -> MIN = minimum;
    t -> A = (int *) malloc( t -> n * sizeof(int) );

    // Making all array elements min
    int i;
    for( i = 0; i < t-> n; i ++){
        t -> A [i] = t -> MIN;
    }

    *t1 = t;
    return;
    
}

// Non recursuve insert function
void insert_bst( bst *t, int data ){

    // Tree empty condition then inserting root at index 0
    if( (*t) -> A [0] == minimum ){
        (*t) -> A[0] = data;
        return;
    }

    int i = 0;

    while(( i < (*t) -> n ) && ( (*t) -> A[i] != minimum)){

        if( (*t) -> A[i] == data ){
            return;
        }

        // Node to be inserted on left
        else if( (*t) -> A[i] > data ){
            i = 2*i + 1;
        }

        // Node to be inserted on right
        else{
            i = 2*i + 2;
        }
    }

    (*t) -> A[i] = data;
    return; 

}

// Recursive inorder traversal
void inorder(bst t){

    printf("Inorder traversal is - \n");

    inorder_helper(t, 0);

    printf("\n");

}

// Recursive postorder traversal
void postorder(bst t){

    printf("Postorder traversal is - \n");

    postorder_helper(t, 0);

    printf("\n");

}

// Recursive preorder traversal
void preorder(bst t){

    printf("Preorder traversal is - \n");

    preorder_helper(t, 0);

    printf("\n");

}

// To check if the binary search tree is complete
void isComplete( bst t ){

    int i = 0;
    
    while( i < t -> n){

        if( t -> A[i] == t -> MIN ){
            int j = i;
            while( j < t -> n){
                if( t -> A[j] != t -> MIN){
                    printf("This is not a complete binary search tree \n");
                    return;
                    
                }
                j ++;
            }
        }

        i ++;
    }

    printf("This is a complete binary search tree \n");
    return;

}
