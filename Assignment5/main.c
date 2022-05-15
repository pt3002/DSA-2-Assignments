#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){

    FILE *fn;
    int num,n,range;

    printf("Enter number of positive integer:");
    scanf("%d",&n);
    printf("Enter max integer:");
    scanf("%d",&range);

    fn=fopen("number.txt","w");
    for (int i=0;i<n;++i) {
        num=(rand()%range)+1;
        fprintf(fn,"%d\n",num);
    }
    fclose(fn);
    return 0;
}