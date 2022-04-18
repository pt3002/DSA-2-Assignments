#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int* sort(int *postorder, int inorderSize){
    int i, key, j;
    for (i = 1; i < inorderSize; i++) {
        key = postorder[i];
        j = i - 1;
        while (j >= 0 && postorder[j] > key) {
            postorder[j + 1] = postorder[j];
            j = j - 1;
        }
        postorder[j + 1] = key;
    }
    return postorder;
}