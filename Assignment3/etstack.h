typedef struct etstack{
    int top;
    int size;
    node* *A;
}etstack;

etstack* etscreateStack(int size);

int etsisFull(etstack* stack);

int etsisEmpty(etstack* stack);

void etspush(etstack* stack, node* node);

node* etspop(etstack* stack);

node* etspeek(etstack* stack);