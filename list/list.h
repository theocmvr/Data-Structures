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
// void push(int arr[100], int i){
//     scanf("%d", &arr[i]);
// }
// for (int i = 0; i < n; i++){
//     void push(arr[i], i);
// }
// void pop(int arr[100], int i){
//     printf("%d", arr[i]);
//     arr[i] = -1;
// }
// for (int i = n-1; i >= 0; i++){
//     pop(arr[i]. i);
// }
#endif