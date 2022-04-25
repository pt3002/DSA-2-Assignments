#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "postfix.h"
#include "expressiontree.h"
#include <string.h>

int main(){
    char exp[] = "((1+2)*(3-(8/4)))";
    printf("Postfix expression\n");
    infixToPostfix(exp);
    printf("\n");
    et t1;
    init_tree(&t1, exp);

    //Validating that all nodes except leaves are operands
    int *leaves;
    leaves = (int *)malloc(sizeof(strlen(exp)));
    int index = 0;
    validation_leaves(t1, leaves, &index);
    int i;
    int valid = 1;
    for(i=0; i<index; i++){
        if(leaves[i]==0){
            valid = 0;
            printf("Invalid infix expression");
            break;
        }
    }

    //Validating that all nodes except leaves are operators
    int *nodes;
    nodes = (int *)malloc(sizeof(strlen(exp)));
    int k = 0;
    validation_nodes(t1, nodes, &k);
    int node_valid = 1;
    for(i=0; i<k; i++){
        if(nodes[i]==0){
            node_valid = 0;
            printf("Invalid infix expression");
            break;
        }
    }

    //If both conditions are valid
    if(valid==1 && node_valid==1){
        printf("\n");
        printf("Inorder traversal of expression tree - \n");
        inorder(t1);
        printf("\n\n");
        printf("Computation - ");
        while(t1->left!=NULL && t1->right!=NULL){
            compute(&t1);
            inorder(t1);
        }
        printf("\n\n");
        printf("Final Answer - \n");
        inorder(t1);
        printf("\n");
    }


    return 0;
}
