#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "stack.h"

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (node**) malloc(stack->size * sizeof(node*));
    return stack;
}

int isFull(struct Stack* stack)
{ return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{ return stack->top == -1; }
 
void push(struct Stack* stack, node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
 
node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}