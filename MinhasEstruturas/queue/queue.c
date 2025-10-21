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
void enQueue(Queue *q, char* string){
    if (q == NULL) return;
    Node *new = malloc(sizeof(Node));
    new->name = (char*)malloc(100*sizeof(char));    
    strcpy(new->name, string);
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
    char* nome = (char*)malloc(100 * sizeof(char));
    if (isEmpty(q)){
        strcpy(nome, "A fila está vazia.\n");
        return nome;
    }
    Node* temp = q->front;
    strcpy(nome, temp->name);
    q->front = (Node*) q->front->next;
    if (isEmpty(q)){
        q->rear = NULL;
    }
    q->size--;
    free(temp->name);
    free(temp);
    return nome;
}
char* front(Queue *q){
    char* nome = (char*)malloc(100*sizeof(char));
    strcpy(nome, q->front->name);
    return nome;
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