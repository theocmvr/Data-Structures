#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* next;
    int data;
    int index;
} Node;

typedef struct{
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enQueue(Queue* q, int key, int idx){
    Node* new = malloc(sizeof(Node));
    new->data = key;
    new->next = NULL;
    new->index = idx;
    if (q->tail == NULL && q->head == NULL){
        q->head = q->tail = new;
    } else {
        q->tail->next = new;
        q->tail = new;
    }
}

Node* deQueue(Queue *q){
    if (q->head == NULL) return NULL;
    Node* temp = q->head;
    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;
    temp->next = NULL;
    return temp;
}

int hasHigherPriority(Queue* q, int value) {
    for (Node* current = q->head; current != NULL; current = current->next)
        if (current->data > value)
            return 1;
    return 0;
}

void freeQueue(Queue* q) {
    while (q->head != NULL) {
        Node* temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    free(q);
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        Queue* q = createQueue();
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++){
            int k;
            scanf("%d", &k);
            enQueue(q, k, i);
        }
        int printed = 0;
        while (q->head != NULL){
            Node* front = deQueue(q);
            if (hasHigherPriority(q, front->data)){
                enQueue(q, front->data, front->index);
                free(front);
            } else {
                printed++;
                if (front->index == m){
                    printf("%d\n", printed);
                    free(front);
                    break;
                }
                free(front);
            }
        }
        freeQueue(q);
    }
    return 0;
}