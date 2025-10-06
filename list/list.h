#ifndef LISTA_H
#define LISTA_H
typedef struct {
    int dado;
    struct Node *next;
} Node;
typedef struct{
    Node *begin;
    int size;
} List;
List* createList();
void add(List *l, int item);
int removeItem(List *l, int item);
int isEmpty(List *l);
void printList(List *l);
int freeList(List *l);
#endif