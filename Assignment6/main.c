#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <string.h>
#include "queue.h"

void printarray(int *A, int n){
	int i;
	for(i = 0; i < n ;i++){
		printf("%d - ",A[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
    FILE *fptr;
    int *A;
    char *s;
    s = (char *) malloc(sizeof(char)*100);
    memcpy(s,argv[1],sizeof(argv[1]));
    fptr = fopen(s, "r");
    if (fptr == NULL) {
        printf("No such file.");
        return 0;
    }
    int n;
    char line[500];
    int i = 0;
    graph g;
    while(fgets(line, sizeof(line), fptr)){
        
        if(i == 0){
            init_graph(&g, atoi(line));
            n = atoi(line);
            //printf("%d--\n",n);
            i+=1;
        }
        else{
        int *A;
		A = (int *)malloc(sizeof(int) * n);
		int j = 0;
		int start = 0;
		while(j < strlen(line)){
			char p[10];
			int x = 0;
			while(line[j] != ' ' && line[j+1] != '\0' && line[j+1]!=EOF){
				p[x] = line[j];
				j+=1;
			}
			A[start] = atoi(p);
			start+=1;
			j+=1;
		}
		//printarray(A,n);
		linked_graph(A,i-1,&g);
        //printf("%d\n",i);
		i+=1;
        }
        
    }
    traverse(g);
    bfs(&g,0);
    printf("\nDFS TRAVERSAL\n");
    int *visited = calloc(g.n, sizeof(int));
    dfs(&g,0,visited);
    return 0;
}
