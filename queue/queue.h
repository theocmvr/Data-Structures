#ifndef QUEUE_H
#define QUEUE_H
typedef struct Node{
    char *name;
    struct Node *next;
} Node;
typedef struct Queue{
    Node *front;
    Node *rear;
    int size;
} Queue;
Queue *createQueue();
void enQueue(Queue *q, char *string);
char *deQueue(Queue *q);
int isEmpty(Queue *q);
char* front(Queue *q);
int size(Queue *q);
int freeQueue(Queue *q);
#endif