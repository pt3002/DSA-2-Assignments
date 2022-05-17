#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){

    // heap h1;
    // init_heap(&h1,100);
    // insert_heap(&h1,9);
    // insert_heap(&h1,10);
    // insert_heap(&h1,12);
    // insert_heap(&h1,14);
    // insert_heap(&h1,16);
    // insert_heap(&h1,17);
    // insert_heap(&h1,18);
    // insert_heap(&h1,25);
    // insert_heap(&h1,29);
    // insert_heap(&h1,8);
    // traverse(h1);
    

    heap h1; 
    FILE *fptr;
    
    int *final;

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
    int filelines = 0;
    while (fscanf(fptr, "%d", &num) == 1){
    	filelines++;
        A[i] = num;
        i+=1;
    }
    final = (int *) malloc(sizeof(int)*filelines);
    fclose(fptr);

    init_heap(&h1, 100);

    printf("\n");
    for(int i=0; i<100; i++){
        insert_heap(&h1, A[i]);
    }
    i = 0;
    int k = h1.rear;
    while(i<=k){
        int a = del_min(&h1);
        final[i] = a;
        i++;
    }
    
    int j = 99;
    while(j>=0){
    	printf("%d\n",final[j]);
    	j --;
    }
    
    return 0;
}
