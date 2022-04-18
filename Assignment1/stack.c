#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "stack.h"

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (Treenode**) malloc(stack->size * sizeof(Treenode*));
    return stack;
}

int isFull(struct Stack* stack)
{ return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{ return stack->top == -1; }
 
void push(struct Stack* stack, Treenode* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
Treenode* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
 
Treenode* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}