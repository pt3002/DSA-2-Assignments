#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

void init_graph(graph *g,int n){
    g -> A = (edge **) malloc( (sizeof(edge **) * n));
    g -> n = n;
    int i;
    for( i = 0 ; i < n; i++){
        g -> A[i] = NULL;
    }
    return;
}

void linked_graph(int *A, int i, graph *g){

	int j = 0;
	while( j < g -> n){
		edge *back;
		if(A[j]!=0){
			//printf("%d - %d :",j,A[j]);
			edge *new;
			new = (edge *) malloc(sizeof(edge));
			new -> data = j;
			new -> weight = A[j];
			new -> next = NULL;
			if(g -> A[i] == NULL){
				g -> A[i] = new;
				back = new;
			}
			else{
				back -> next = new;
				back = new;
			}
			//printf("%d - %d - %d\n",new -> data, new -> weight, i);
		}
		j += 1;
	}
	return;
}

void traverse(graph g){
	int i;
	for(i = 0; i < g.n; i++){
		edge *temp;
		temp = g.A[i];
		while(temp){
			printf("%d - %d\n", temp -> data, temp -> weight);
			temp = temp -> next;
		}
		printf("\n");
	}
}

void bfs(graph *g, int s){
	printf("\nBFS TRAVERSAL\n");
	queue *Q1;
	Q1 = createQueue();
	int *visited = calloc(g -> n, sizeof(int));
	enqueue(Q1, s);
	visited[s] = 1;
	//printf("%d, ",s);
	edge *temp;
	temp = g -> A[s];

	while(!isEmpty(Q1)){
		int current = dequeue(Q1);
		printf("%d, ",current);
		edge *temp = g -> A[current];
		while(temp){
				int i = temp -> data;
				if(!visited[temp->data]){
					visited[temp->data] = 1;
					enqueue(Q1,temp->data);
				}
			temp = temp -> next;
		}
	}
}

void dfs(graph *g, int s, int *visited){
	edge *temp;
	temp = g -> A[s];
	visited[s] = 1;
	printf("%d, ",s);
	while(temp){
		int adj = temp->data;
		if(visited[temp->data] == 0){
			dfs(g, temp->data,visited);
		}
		temp = temp -> next;
	}
}

void in_out_degree(graph *g){
	int i;
	int check = 0;
	int *A;
	A = (int *)malloc(sizeof(int)*(2*(g ->n)));
	int k = 0;
	for(i = 0; i < g -> n; i++){
		int in = 0;
		int out = 0;
		edge *temp;
                temp = g -> A[i];
                while(temp){
                       out ++;
                       temp = temp -> next;
                }
                int j;
                for(j = 0; j < g -> n; j++){
                      temp = g -> A[j];
                      while(temp){
                           if(temp -> data == i){
                                 in ++;
                           }
                           temp = temp -> next;
                      }
                }
                if(in != out){
                     check = 1;
                }
                
	        A[k] = in;
                k += 1;
                A[k] = out;
                k += 1;
	}
        if(check == 0){
                printf("\nUndirected Graph\n");
                int x;
                for(x = 0; x < g -> n; x++){
                     printf("For vertex %d the degree is %d\n",x,A[2*x];
                }
        }
        else{
               printf("\nDirected Graph\n");
               int x;
               int t = 0;
               for(x = 0; x < (2* g -> n);x+=2){
                   printf("For vertex %d the in degree is %d and out degree is %d\n",t,A[x],A[x+1];
                   t += 1;
               }
        }
}

