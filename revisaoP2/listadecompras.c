#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    struct Node* next;
    float price;
    char comida[21];
} Node;
typedef struct{
    Node* head;
    float total;
    int size;
} List;
List* createList(){
    List* l = malloc(sizeof(List));
    if (l == NULL) return l;
    l->head = NULL;
    l->size = 0;
    l->total = 0.00;
    return l;
}
void add(List* l, char nome[21], float preco){
    if (l == NULL) return;
    Node* new = malloc(sizeof(Node));
    strcpy(new->comida, nome);
    new->price = preco;
    new->next = l->head;
    l->head = new;
    l->size++;
    l->total+= preco;
}
void del(List *l, char nome[21]){
    if (l == NULL) return;
    Node* current = l->head;
    Node* past = NULL;
    while (current != NULL && strcmp(current->comida, nome) != 0){
        past = current;
        current = current->next;
    }
    if (current == NULL) return;
    if (past == NULL) l->head = l->head->next;
    else past->next = current->next;
    l->size--;
    l->total -= current->price;
    free(current);
}
void printList(List* l){
    Node* current = l->head;
    while(current != NULL){
        printf("%s %.2f\n", current->comida, current->price);
        current = current->next;
    }
    printf("----------------------\n");
    printf("%d item(ns): R$ %.2f\n", l->size, l->total);
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
    char s[21];
    List* l = createList();
    scanf("%s", s);
    while(strcmp(s, "fim") != 0){
        if (s[0] != '-'){
            float preco;
            scanf("%f", &preco);
            add(l, s, preco);
        } else {
            char apagar[21];
            scanf("%s", apagar);
            del(l, apagar);
        }
        scanf("%s", s);
    }
    printList(l);
    freeList(l);
    return 0;
}