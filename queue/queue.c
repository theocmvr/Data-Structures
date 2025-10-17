#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"queue.h"
Queue *createQueue(){
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) return NULL;
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}
int isEmpty(Queue *q){
    return (q->front == NULL);
}
void enQueue(Queue *q, char *string){
    if (q == NULL) return;
    Node *new = malloc(sizeof(Node));
    strcpy(string, new->name);
    new->next = NULL;
    if (isEmpty(q)){
        q->front = q->rear = new;
    } else {
        q->rear->next = (Node* ) new;
        q->rear = new;
    }
    q->size++;
    printf("O(A) %s entrou fila.\n", string);
}
char* deQueue(Queue *q){
    if (isEmpty(q)){
        return "A fila está vazia.\n";
    }
    Node* temp = q->front;
    char *nome = temp->name;
    q->front = (Node*) q->front->next;
    if (isEmpty(q)){
        q->rear = NULL;
    }
    free(temp);
    return nome;
}
char* front(Queue *q){
    return q->front->name;
}
int size(Queue *q){
    return q->size;
}
int freeQueue(Queue *q){
    while(!isEmpty(q)){
        deQueue(q);
    }
    free(q);
    return 0;
}