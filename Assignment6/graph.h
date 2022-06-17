#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int weight;
    struct node *next;
}node;

typedef struct graph{
    node **A;
    int n;
}graph;

void init_graph(graph *g,int n);
void linked_graph(int *A, int i, graph *g);
void traverse(graph g);
void bfs(graph *g, int s);
void dfs(graph *g, int s, int *visited);
void prims(graph *g, int s);