#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){

    bst t1;
    init_bst( &t1 );

    insert_bst( &t1, 10);
    insert_bst( &t1, 15);
    insert_bst( &t1, 5);
    insert_bst( &t1, 1);

    inorder(t1);

    postorder(t1);

    preorder(t1);

    isComplete(t1);

    // To see the array 
    int i;
    for( i = 0; i < t1 -> n; i ++){
        printf(" %d - %d \n", t1 -> A[i], i);
    }

    return 0;
}