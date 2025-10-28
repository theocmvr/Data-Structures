#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    struct Node* next;
    struct Node* prev;
    int num;
} Node;
typedef struct{
    Node* head;
    Node* tail;
} List;
List* createList(){
    List* l = malloc(sizeof(List));
    if (l == NULL) return l;
    l->head = NULL;
    l->tail = NULL;
    return l;
}
void I(List* l, int num){
    Node* new = malloc(sizeof(Node));
    new->num = num;
    new->prev = NULL;
    if (l->head == NULL){
        new->next = NULL;
        l->head = l->tail = new;
    } else {
        new->next = l->head;
        new->next->prev = new;
        l->head = new;
    }
}   
void D(List* l){
    Node* temp = l->head;
    printf("%d\n", temp->num);
    l->head = temp->next;
    if (l->head == NULL){
        l->tail = NULL;
    } else {
        l->head->prev = NULL;
    }
    free(temp);
}
void F(List* l, int num){
    Node* new = malloc(sizeof(Node));
    new->num = num;
    new->next = NULL;
    if (l->head == NULL){
        new->prev = NULL;
        l->head = l->tail = new;
    } else {
        new->prev = l->tail;
        new->prev->next = new;
        l->tail = new;
    }
}
void P(List* l){
    Node* temp = l->tail;
    printf("%d\n", temp->num);
    l->tail = temp->prev;
    if (l->tail == NULL) {
        l->head = NULL;
    } else {
        l->tail->next = NULL;
    }
    free(temp);
}

void printList(List* l){
    Node* current = l->head;
    while(current != NULL){
        printf("%d\n", current->num);
        current = current->next;
    }
}
void freeList(List* l){
    Node* temp = l->head;
    while (temp != NULL){
        Node* aux = temp;
        temp = aux->next;
        free(aux);
    }
    free(l);
}
int main(){
    char c;
    List* l = createList();
    scanf("%c", &c);
    while(c != 'X'){
        if (c == 'I'){
            int a;
            scanf("%d", &a);
            I(l, a);
        } else if (c == 'F'){
            int a;
            scanf("%d", &a);
            F(l, a);
        } else if (c == 'D'){
            D(l);
        } else {
            P(l);
        }
        scanf(" %c", &c);
    }
    printf("\n");
    printList(l);
    freeList(l);
    return 0;
}