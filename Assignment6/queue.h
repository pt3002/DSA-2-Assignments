#define SIZE 40

typedef struct queue {
  int items[SIZE];
  int front;
  int rear;
}queue;

queue* createQueue();
int isEmpty(struct queue* q);
void enqueue(struct queue* q, int value);
int dequeue(struct queue* q) ;
void printQueue(struct queue* q);