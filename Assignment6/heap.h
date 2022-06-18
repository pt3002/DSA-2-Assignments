#include <stdlib.h>
typdef struct pair{
  int distance;
  int node;
}pair;


typedef struct heap{
    pair *A;
    int size;
    int rear;
}heap;

void init_heap(heap *h, int s);
void insert_heap(heap *h, int key);
void heapify(heap *h);
int del_min(heap *h);
void traverse(heap h);
void heapify_del(heap *h);
