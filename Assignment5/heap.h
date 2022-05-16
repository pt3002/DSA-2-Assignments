#include <stdlib.h>

typedef struct heap{
    int *A;
    int size;
    int rear;
}heap;

void init_heap(heap *h, int s);
void insert_heap(heap *h, int key);
void heapify(heap *h);
int del_max(heap *h);
void traverse(heap h);
void heapify_del(heap *h);