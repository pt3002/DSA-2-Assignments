#include<stdlib.h>

//Structure for stack
struct Stack
{
    int size;
    int top;
    struct Treenode* *array;
};


//Stack functions
struct Stack* createStack(int size);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, Treenode* node);
Treenode* pop(struct Stack* stack);
Treenode* peek(struct Stack* stack);