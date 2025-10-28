#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    struct Node* next;
    struct Node* prev;
    int data;
} Node;
typedef struct List{
    struct Node* head;
    struct Node* rear;
} List;
List* createList(){
    List *l = malloc(sizeof(List));\
    if (l == NULL) return l;
    l->head = NULL;
    l->rear = NULL;
    return l;
}
void insert(List* l, int x){
    if (l == NULL) return;
    Node* new = malloc(sizeof(Node));
    new->data = x;
    new->next = l->head;
    new->prev = NULL;
    if (l->head != NULL) l->head->prev = new;
    else l->rear = new;
    l->head = new;
}
void delete(List* l, int x){
    if (l == NULL) return;
    Node* current = l->head;

    while (current != NULL && current->data != x)
        current = current->next;

    if (current == NULL) return;

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        l->head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;
    else
        l->rear = current->prev;
    free(current);
}
void deleteFirst(List* l) {
    if (l == NULL || l->head == NULL) return;
    Node* temp = l->head;
    l->head = temp->next;
    if (l->head != NULL) l->head->prev = NULL;
    else l->rear = NULL;
    free(temp);
}
void deleteLast(List* l){
    if (l == NULL || l->rear == NULL) return;
    Node* temp = l->rear;
    l->rear = temp->prev;
    if(l->rear != NULL)l->rear->next = NULL;
    else l->head = NULL; 
    free(temp);
}
void printList(List* l){
    Node* temp = l->head;
    while(temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}
void freeList(List *l){
    if (l == NULL) return;
    Node *aux = l->head;
    while (aux != NULL){
        Node *temp = aux;
        aux = (Node*) aux->next;
        free(temp);
    }
    free(l);
}
int main(){
    int n;
    scanf("%d", &n);
    List* l = createList();
    while (n--){
        char op[11];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0){
            int x;
            scanf("%d", &x);
            insert(l, x);
        }
        if (strcmp(op, "delete") == 0){
            int x;
            scanf("%d", &x);
            delete(l, x);
        }
        if (strcmp(op, "deleteFirst") == 0){
            deleteFirst(l);
        }
        if (strcmp(op, "deleteLast") == 0){
            deleteLast(l);
        }
        //printList(l);
    }
    printList(l);
    freeList(l);
    return 0;
}