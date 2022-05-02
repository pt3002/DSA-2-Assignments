#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

int main(){
    avl t1;

    //Initialize avl tree
    initAVL(&t1);

    //Add new node
    insertNode(&t1, 7);
    insertNode(&t1, 20);
    insertNode(&t1, 5);
    insertNode(&t1, 15);
    insertNode(&t1, 10);
    insertNode(&t1, 4);
    insertNode(&t1, 33);
    insertNode(&t1, 2);
    inorder(t1);
    return 0;
}