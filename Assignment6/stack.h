typedef struct Stack{
    int top;
    int size;
    int *A;
}Stack;

void init_stack(Stack* *st,int size);
int isFull(Stack *st);
int isEmpty(Stack *st);
void push(Stack *st, int data);
int pop(Stack *st);