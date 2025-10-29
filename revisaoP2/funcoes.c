// estruturas.c
#include <stdio.h>
#include <stdlib.h>

//
// ============================================================
// 1. Singly Linked List (Lista Encadeada Simples)
// ============================================================
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

List* createList() {
    List* l = malloc(sizeof(List));
    l->head = NULL;
    return l;
}

void insertFront(List* l, int val) {
    Node* new = malloc(sizeof(Node));
    new->data = val;
    new->next = l->head;
    l->head = new;
}

void insertBack(List* l, int val) {
    Node* new = malloc(sizeof(Node));
    new->data = val;
    new->next = NULL;
    if (!l->head) l->head = new;
    else {
        Node* temp = l->head;
        while (temp->next) temp = temp->next;
        temp->next = new;
    }
}

void deleteValue(List* l, int val) {
    Node *temp = l->head, *prev = NULL;
    while (temp && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    if (!prev) l->head = temp->next;
    else prev->next = temp->next;
    free(temp);
}

void printList(List* l) {
    for (Node* t = l->head; t; t = t->next)
        printf("%d ", t->data);
    printf("\n");
}

//
// ============================================================
// 2. Doubly Linked List (Lista Duplamente Encadeada)
// ============================================================
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct {
    DNode* head;
    DNode* tail;
} DList;

DList* createDList() {
    DList* l = malloc(sizeof(DList));
    l->head = l->tail = NULL;
    return l;
}

void insertFrontD(DList* l, int val) {
    DNode* new = malloc(sizeof(DNode));
    new->data = val;
    new->prev = NULL;
    new->next = l->head;
    if (l->head) l->head->prev = new;
    else l->tail = new;
    l->head = new;
}

void insertBackD(DList* l, int val) {
    DNode* new = malloc(sizeof(DNode));
    new->data = val;
    new->next = NULL;
    new->prev = l->tail;
    if (l->tail) l->tail->next = new;
    else l->head = new;
    l->tail = new;
}

void deleteValueD(DList* l, int val) {
    DNode* t = l->head;
    while (t && t->data != val) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else l->head = t->next;
    if (t->next) t->next->prev = t->prev;
    else l->tail = t->prev;
    free(t);
}

void printD(DList* l) {
    for (DNode* t = l->head; t; t = t->next)
        printf("%d ", t->data);
    printf("\n");
}

//
// ============================================================
// 3. Circular Linked List (Lista Encadeada Circular)
// ============================================================
typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

typedef struct {
    CNode* tail;
} CList;

CList* createCList() {
    CList* l = malloc(sizeof(CList));
    l->tail = NULL;
    return l;
}

void insertCircular(CList* l, int val) {
    CNode* new = malloc(sizeof(CNode));
    new->data = val;
    if (!l->tail) {
        l->tail = new;
        new->next = new;
    } else {
        new->next = l->tail->next;
        l->tail->next = new;
        l->tail = new;
    }
}

void deleteCircular(CList* l, int val) {
    if (!l->tail) return;
    CNode *curr = l->tail->next, *prev = l->tail;
    do {
        if (curr->data == val) {
            if (curr == l->tail && curr->next == l->tail) l->tail = NULL;
            else {
                prev->next = curr->next;
                if (curr == l->tail) l->tail = prev;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != l->tail->next);
}

void printC(CList* l) {
    if (!l->tail) return;
    CNode* t = l->tail->next;
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != l->tail->next);
    printf("\n");
}

//
// ============================================================
// 4. Stack (Pilha)
// ============================================================
typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

typedef struct {
    SNode* top;
} Stack;

Stack* createStack() {
    Stack* s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int val) {
    SNode* new = malloc(sizeof(SNode));
    new->data = val;
    new->next = s->top;
    s->top = new;
}

void pop(Stack* s) {
    if (!s->top) return;
    SNode* temp = s->top;
    s->top = s->top->next;
    free(temp);
}

int peek(Stack* s) {
    return s->top ? s->top->data : -1;
}

void printStack(Stack* s) {
    for (SNode* t = s->top; t; t = t->next)
        printf("%d ", t->data);
    printf("\n");
}

//
// ============================================================
// 5. Queue (Fila)
// ============================================================
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

typedef struct {
    QNode *head, *tail;
} Queue;

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    return q;
}

void enqueue(Queue* q, int val) {
    QNode* new = malloc(sizeof(QNode));
    new->data = val;
    new->next = NULL;
    if (!q->tail) q->head = q->tail = new;
    else {
        q->tail->next = new;
        q->tail = new;
    }
}

void dequeue(Queue* q) {
    if (!q->head) return;
    QNode* temp = q->head;
    q->head = q->head->next;
    if (!q->head) q->tail = NULL;
    free(temp);
}

void printQueue(Queue* q) {
    for (QNode* t = q->head; t; t = t->next)
        printf("%d ", t->data);
    printf("\n");
}

//
// ============================================================
// 6. Priority Queue (Fila de Prioridade)
// ============================================================
typedef struct PQNode {
    int data;
    int priority;
    struct PQNode* next;
} PQNode;

typedef struct {
    PQNode* head;
} PQueue;

PQueue* createPQueue() {
    PQueue* q = malloc(sizeof(PQueue));
    q->head = NULL;
    return q;
}

void enqueuePriority(PQueue* q, int val, int p) {
    PQNode* new = malloc(sizeof(PQNode));
    new->data = val;
    new->priority = p;
    if (!q->head || p > q->head->priority) {
        new->next = q->head;
        q->head = new;
    } else {
        PQNode* t = q->head;
        while (t->next && t->next->priority >= p) t = t->next;
        new->next = t->next;
        t->next = new;
    }
}

void dequeuePriority(PQueue* q) {
    if (!q->head) return;
    PQNode* temp = q->head;
    q->head = q->head->next;
    free(temp);
}

void printPQueue(PQueue* q) {
    for (PQNode* t = q->head; t; t = t->next)
        printf("(%d, p=%d) ", t->data, t->priority);
    printf("\n");
}

//
// ============================================================
// 7. Circular Queue (Fila Circular com Array)
// ============================================================
#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear, size;
} CQueue;

CQueue* createCQueue() {
    CQueue* q = malloc(sizeof(CQueue));
    q->front = q->rear = q->size = 0;
    return q;
}

int isFull(CQueue* q) { return q->size == MAX; }
int isEmpty(CQueue* q) { return q->size == 0; }

void enqueueC(CQueue* q, int val) {
    if (isFull(q)) return;
    q->arr[q->rear] = val;
    q->rear = (q->rear + 1) % MAX;
    q->size++;
}

void dequeueC(CQueue* q) {
    if (isEmpty(q)) return;
    q->front = (q->front + 1) % MAX;
    q->size--;
}

void printCQueue(CQueue* q) {
    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % MAX;
        printf("%d ", q->arr[idx]);
    }
    printf("\n");
}
