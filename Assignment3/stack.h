#include <stdlib.h>

typedef struct stack{
    int top;
    int size;
    int *A;
}stack;

stack* create(int s);

void push(stack* st, char operator);

char pop(stack* st);

char peek(stack* st);

int isEmpty(stack* st);