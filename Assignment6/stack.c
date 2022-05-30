#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init_stack(Stack* *st,int size){
    Stack *t;
    t -> size = size;
    t -> top = -1;
    t -> A = (int *)malloc(t -> size * sizeof(int));
    *st = t;
}

int isFull(Stack *st){
    return st -> top == st -> size - 1;
}

int isEmpty(Stack *st){
    return st -> top == -1;
}

void push(Stack *st, int data){
    if(isFull(st))
        return;
    st -> A[++st->top];
}

int pop(Stack *st){
    if(isEmpty(st)){
        return INT_MIN;
    }
    return st -> A[st -> top--];
}