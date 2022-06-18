#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include <limits.h>

void init_heap(heap *h, int s){
    h -> size = s;
    h -> A = (pair *)malloc(sizeof(pair) * h -> size);
    h -> rear = -1;
    return ;
}

// Min heap
void insert_heap(heap *h, int distance, int node){
    //heap full condition
    if(h -> rear == h -> size - 1){
        return ;
    }
    h -> rear += 1;
    h -> A->distance[h -> rear] = distance;
    h -> A->node[h->rear] = node;
    int i = h -> rear;
    int p_i;             // parent of i
    if(h -> rear!=0){
        p_i = (i-1)/2;
        if(h -> A->distance[p_i] <= h -> A->distance[i]){
            return;
        }
        heapify(h);
    }
    return;
}

void heapify(heap *h){
    int i = h -> rear;
    int p_i = (i-1)/2;
    int temp;
    while(p_i >=0 && h -> A[p_i] > h -> A[i]){
        tempDistance = h -> A->distance[p_i];
        tempNode= h->A->node[p_i];
        h -> A->distance[p_i] = h -> A->distance[i];
        h -> A->node[p_i] = h -> A->node[i];
        h -> A->distance[i] = tempDistance;
        h -> A->node[i] = tempNode;
        i = p_i;
        p_i = (i-1) / 2;
    }
    return;
}

pair* del_min(heap *h){
    if(h -> rear == -1){
        printf("Heap is empty");
        return INT_MIN;
    }
    pair* root=(pair*)malloc(sizeof(pair));
    root->distance = h -> A->distance[0];
    root->node = h -> A->node[0];
    h -> A->distance[0] = h -> A->distance[h -> rear];
    h -> A->node[0] = h -> A->node[h -> rear];
    h -> rear--;
    heapify_del(h);
    return root;
}

void heapify_del(heap *h){
    int i = 0;
    while(i <= h -> rear){
        int left = 2*i +1;
        int right = 2*i +2;
        if(h -> A->distance[i]<=h -> A->disatnce[left] && h ->A->distance[i]<=h->A->distance[right]){
            return;
        }
        else if(left <= h -> rear && right <= h -> rear){
            int minDistance;
            int minNode;
            int tempDistance;
            int tempNode;
            if(h -> A->distance[left] < h ->A->distance[right]){
                minDistance = h -> A->distance[left];
                minNode = h -> A->node[left];
                tempDistance = h -> A->distance[i];
                tempNode = h -> A->node[i];
                h -> A->distance[i] = minDistance;
                h -> A->node[i] = minNode;
                h -> A->distance[left] = tempDistance;
                h -> A->node[left] = tempNode;
                i = left;
            }
            else{
                minDistance = h -> A[right];
                minNode = h -> A[right];
                tempDistance = h -> A[i];
                tempNode = h -> A[i];
                h -> A->distance[i] = minDistance;
                h -> A->node[i] = minNode;
                h -> A->distance[right] = tempDistance;
                h -> A->node[right] = tempNode;
                i = right;
            } 
        }
        else if(left <= h -> rear){
            int minDistance;
            int minNode;
            int tempDistance;
            int tempNode;
            minDistance = h -> A->distance[left];
            minNode = h -> A->node[left];
            tempDistance = h -> A->distance[i];
            tempNode = h -> A->node[i];
            h -> A->distance[i] = minDistance;
            h -> A->node[i] = minNode;
            h -> A->distance[left] = tempDistance;
            h -> A->node[left] = tempNode;
            i = left;
        }
        else{
            return;
        }
    }
    return;
}

void traverse(heap h){
    for(int i = 0; i <= h.rear; i++){
        printf("Node: %d\t Distance: %d\n", h.A->distance[i],h.A->node[i]);
    }
    return;
}
