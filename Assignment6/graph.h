#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
    int data;
    int weight;
    struct edge *next;
}edge;

typedef struct graph{
    edge **A;
    int n;
}graph;

void init_graph(graph *g,int n);
void linked_graph(int *A, int i, graph *g);
void traverse(graph g);
void bfs(graph *g, int s);
void dfs(graph *g, int s, int *visited);