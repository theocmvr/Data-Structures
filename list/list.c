#include<stdio.h>
#include<stdlib.h>
#include<list.h>
List* createList(){
    List *l = malloc(sizeof(List));
    if (l == NULL) return NULL;
    l->size = 0;
    l->begin = NULL;
    return l;
}
void add(List *l, int item){
    if (l == NULL) return;
    Node *new = malloc(sizeof(Node));
    new->dado = item;
    new->next = (Node*) l->begin;
    l->begin = new;
    l->size++;
}
int removeItem(List *l, int item){
    if (isEmpty(l)) return 0;
    Node *current = l->begin;
    Node *past = NULL;
    while(current != NULL && current->dado != item){
        past = current;
        current = (Node*) current->next;
    }
    if (current == NULL) return 0;
    if (past == NULL) l->begin = (Node*)current->next;
    else past->next = current->next;
    free(current);
    return 1;
}
int isEmpty(List *l){
    if (l == NULL) return 1;
    if (l->size == 0) return 1;
    return 0;
}
void printList(List *l){
    if (isEmpty(l)){
        printf("Lista Vazia\n");
        return;
    }
    Node *aux = l->begin;
    printf("Lista: [");
    while (aux != NULL){
        printf(" %d ", aux->dado);
        aux = (Node*) aux->next;
    }
    printf("]\n");
}
int freeList(List *l){
    if (l == NULL) return 0;
    Node *aux = l->begin;
    int count = 0;
    while (aux != NULL){
        Node *temp = aux;
        aux = (Node*) aux->next;
        free(temp);
        count++;
    }
    free(l);
    return count;
}