#include "stack.h"
#include <stdlib.h>

stack* create(int s){
    stack* st = (stack *) malloc(sizeof(stack));
    st->top = -1;
    st->size = s;
    st->A = (int *)malloc(sizeof(int)*(st->size));
    return st;
}

void push(stack* st, char operator){
    st->A[++st->top] = operator;
}

char pop(stack* st){
    if (st->top!=-1)
        return st->A[st->top--] ;
    return '$';
}

char peek(stack* st){
    return st->A[st->top];
}

int isEmpty(stack* st){
    return st->top == -1 ;
}