#include<stdlib.h>

//Structure for stack
struct Stack
{
    int size;
    int top;
    struct node* *array;
};


//Stack functions
struct Stack* createStack(int size);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, node* node);
node* pop(struct Stack* stack);
node* peek(struct Stack* stack);