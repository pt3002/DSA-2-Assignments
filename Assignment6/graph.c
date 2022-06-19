#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"
#include "limits.h"
#define INFINITY 9999

void init_graph(graph *g,int n){
    g -> A = (node **) malloc( (sizeof(node **) * n));
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
		node *back;
		if(A[j]!=0){
			//printf("%d - %d :",j,A[j]);
			node *new;
			new = (node *) malloc(sizeof(node));
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
		node *temp;
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
	node *temp;
	temp = g -> A[s];

	while(!isEmpty(Q1)){
		int current = dequeue(Q1);
		printf("%d, ",current);
		node *temp = g -> A[current];
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
	node *temp;
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
		node *temp;
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
                     printf("For vertex %d the degree is %d\n",x,A[2*x]);
                }
        }
        else{
               printf("\nDirected Graph\n");
               int x;
               int t = 0;
               for(x = 0; x < (2* g -> n);x+=2){
                   printf("For vertex %d the in degree is %d and out degree is %d\n",t,A[x],A[x+1]);
                   t += 1;
               }
        }
}

void prims(graph *g, int s){
	int no_of_edges = 0;
	int * selected;
	selected = (int *) malloc(sizeof(int)*(g -> n));

	int i;
	for(i = 0; i<g -> n; i++){
		selected[i] = 0;
	}

	selected[s] = 1;

	int total_dist = 0;

	while(no_of_edges < g -> n -1){
		int min_edge = INT_MAX;
		int start = 0;
		int end = 0;
		int dist = 0;

		for(i = 0; i < g-> n ; i++){
			node *temp;
			if(selected[i]){
				temp  = g ->A[i];
				while(temp){
					if(!selected[temp -> data]){
						if(min_edge > temp -> weight){
							start = i;
							end = temp -> data;
							dist = temp ->weight;
						}
					}
					temp  = temp -> next;
				}
			}
		}
		
		printf("From : %d - To : %d - Distance : %d\n",start, end, dist);
		selected[end] = 1;
		no_of_edges ++;
	}
	return;
}

void Dijkstra(graph *g, int s){
	int cost[g->n][g->n];
	int dist[g->n];
	int pred[g->n];
	int visited[g->n];
	int count, mindistance, nextnode, i, j;

	//Creating cost matrix
	for(i= 0 ; i<g->n; i++){
		node *temp;
		temp = g -> A[i];
		for(j = 0 ;j < g ->n; j++){
			if(temp && temp->data==j){
				cost[i][j] = temp -> weight;
				temp = temp -> next;
			}
			else{
				cost[i][j] = INFINITY;
			}
		}
	}

	// for(i = 0; i< g->n; i++){
	// 	for(j = 0; j < g->n ; j++){
	// 		printf("%d-",cost[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for(i = 0; i < g->n; i++){
		dist[i] = cost[s][i];
		pred[i]  = s;
		visited[i] = 0;
	}

	dist[s] = 0;
	visited[s] = 1;
	count = 1;

	while(count < g->n - 1){
		mindistance = INFINITY;
		for(i = 0; i < g->n; i++){
			if(dist[i] < mindistance && !visited[i]){
				mindistance = dist[i];
				nextnode = i;
			}
		}

		visited[nextnode] = 1;
		for(i = 0; i < g->n;i++){
			if(!visited[i]){
				if(mindistance+cost[nextnode][i] < dist[i]){
					dist[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
			}
		}

		count++;
	}

	//Printing the distance
	for(i = 0; i<g->n; i++){
		if(i != s){
			printf("\nDistance from source to destination %d : %d",i,dist[i]);
		}
	}
}

