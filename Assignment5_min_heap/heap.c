#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include <limits.h>

void init_heap(heap *h, int s){
    h -> size = s;
    h -> A = (int *)malloc(sizeof(int) * h -> size);
    h -> rear = -1;
    return ;
}

// Max heap
void insert_heap(heap *h, int key){
    //heap full condition
    if(h -> rear == h -> size - 1){
        return ;
    }
    h -> rear += 1;
    h -> A[h -> rear] = key;
    int i = h -> rear;
    int p_i;             // parent of i
    if(h -> rear!=0){
        p_i = (i-1)/2;
        if(h -> A[p_i] <= h -> A[i]){
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
        temp = h -> A[p_i];
        h -> A[p_i] = h -> A[i];
        h -> A[i] = temp;
        i = p_i;
        p_i = (i-1) / 2;
    }
    return;
}

int del_min(heap *h){
    if(h -> rear == -1){
        printf("Heap is empty");
        return INT_MIN;
    }
    int root = h -> A[0];
    h -> A[0] = h -> A[h -> rear];
    h -> rear--;
    heapify_del(h);
    return root;
}

void heapify_del(heap *h){
    int i = 0;
    while(i <= h -> rear){
        int left = 2*i +1;
        int right = 2*i +2;
        if(h -> A[i]<=h -> A[left] && h ->A[i]<=h->A[right]){
            return;
        }
        else if(left <= h -> rear && right <= h -> rear){
            int min;
            int temp;
            if(h -> A[left] < h ->A[right]){
                min = h -> A[left];
                temp = h -> A[i];
                h -> A[i] = min;
                h -> A[left] = temp;
                i = left;
            }
            else{
                min = h -> A[right];
                temp = h -> A[i];
                h -> A[i] = min;
                h -> A[right] = temp;
                i = right;
            } 
        }
        else if(left <= h -> rear){
            int min;
            int temp;
            min = h -> A[left];
            temp = h -> A[i];
            h -> A[i] = min;
            h -> A[left] = temp;
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
        printf("%d\n", h.A[i]);
    }
    return;
}
