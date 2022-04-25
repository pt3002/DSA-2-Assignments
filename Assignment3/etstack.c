#include<stdio.h>
#include<stdlib.h>
#include "expressiontree.h"
#include "etstack.h"

etstack* etscreateStack(int size)
{
    etstack* stack = (etstack*) malloc(sizeof(etstack));
    stack->size = size;
    stack->top = -1;
    stack->A = (node**) malloc(stack->size * sizeof(node*));
    return stack;
}

int etsisFull(etstack* stack)
{ return stack->top - 1 == stack->size; }
 
int etsisEmpty(etstack* stack)
{ return stack->top == -1; }
 
void etspush(etstack* stack, node* node)
{
    if (etsisFull(stack))
        return;
    stack->A[++stack->top] = node;
}
 
node* etspop(etstack* stack)
{
    if (etsisEmpty(stack))
        return NULL;
    return stack->A[stack->top--];
}
 
node* etspeek(etstack* stack)
{
    if (etsisEmpty(stack))
        return NULL;
    return stack->A[stack->top];
}