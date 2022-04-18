#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <string.h>

int main(){
    int i;
    int postorderSize;
    int *postorder;
    printf("Enter size of postorder Array - ");
    scanf("%d", &postorderSize);
    printf("Enter the postorder array - ");
    postorder = (int *) malloc(postorderSize * sizeof(int));

    // Taking input the postorder array
    for(i=0; i < postorderSize; i++){
        scanf("%d", &postorder[i]);
    }
        
    // Sorting postorder array to get the inorder array
    int *inorder;
    int inorderSize = postorderSize;
    int *p;
    p = (int *)malloc(postorderSize * sizeof(int));
    int j;
    for(j = 0; j < postorderSize; j ++){
        p [j] = postorder [j];
    }
    inorder = sort(p, inorderSize);

    printf("Inorder array after sorting the postoder array - ");

    for(i=0; i < inorderSize; i++){
        printf("%d ",inorder[i]);
    }

    printf("\n");

    // Initialising the tree
    bst t1;
    init_bst(&t1);
    buildTree(&t1, inorder, postorder, inorderSize, &postorderSize);

    printf("\n");

    printf("Inorder Traversal of constructed tree - \n");
    inorder_traversal(t1);

    printf("\n");

    printf("Post order Traversal of constructed tree is - \n");
    postorder_traversal(t1);

    printf("\n");
}