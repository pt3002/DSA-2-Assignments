#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){

    heap h1; 
    FILE *fptr;

    int *A;
    A = (int *)malloc(sizeof(int) * 100);

    char *s;
    s = (char *) malloc(sizeof(char)*100);
    printf("Enter filename - ");
    scanf("%s", s);

    fptr = fopen(s, "r");
    if (fptr == NULL) {
        printf("no such file.");
        return 0;
    }

    int num;
    int i = 0;
    while (fscanf(fptr, "%d", &num) == 1){
        A[i] = num;
        i+=1;
    }
    fclose(fptr);

    init_heap(&h1, 100);

    printf("\n");
    for(int i=0; i<100; i++){
        insert_heap(&h1, A[i]);
    }
    i = 0;
    int k = h1.rear;
    while(i<=k){
        int a = del_max(&h1);
        printf("%d - %d \n ",i+1,a);
        i++;
    }
    return 0;
}