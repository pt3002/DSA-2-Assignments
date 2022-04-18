#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <string.h>

void buildTree(bst *t, int *inorder, int *postorder, int inorderSize, int* postorderSize){

        if(inorder==NULL){
            return;
        }

        // Popping the root from postorder array
        int val = postorder[*postorderSize-1];
        *postorderSize = *postorderSize - 1;
        // printf("-----------%d-----------------\n",val);
        insert(t, val);

        // Reducing size of postorder array after popping

        // Finding the index of root in inorder array
        int m;
        for(m = 0; m < inorderSize; m++){
            if(inorder[m]==val){
                break;
            }
        }

        int x = inorderSize - m - 1;

        int *leftHalf;
        leftHalf = NULL;

        if(m > 0){
                // splitting inorder array
                // for left part inorder[:m] - size = m
                leftHalf = malloc(m * sizeof(int));
                memcpy(leftHalf, inorder, (m) * sizeof(int));
        }

        int *rightHalf;
        rightHalf = NULL;

        if(x > 0){
                // for right part inorder[m+1:] - size = inorderSize - m -1
                rightHalf = malloc(x * sizeof(int));
                memcpy(rightHalf, inorder + m + 1, x * sizeof(int));

        }
        
        // printf("Left----------\n");
        // int i;
        // for(i=0; i<m; i++){
        //     printf("%d ",leftHalf[i]);
        // }
        // printf("\n");

        // printf("Right---------\n");
        // for(i=0; i<x; i++){
        //     printf("%d ",rightHalf[i]);
        // }
        // printf("\n");

        //root.right
        buildTree(&((*t) -> right),rightHalf,postorder,x,postorderSize);

        //root.left
        buildTree(&((*t) -> left), leftHalf,postorder, m, postorderSize);

        return;

        



}