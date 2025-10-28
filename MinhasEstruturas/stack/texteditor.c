#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* next;
    struct Node* prev;
    char letra;
} Node;
typedef struct{
    Node* top;
    Node* rear;
} Stack;

Stack* createStack(){
    Stack* s = malloc(sizeof(Stack));
    if (s == NULL) return s;
    s->top = NULL;
    s->rear = NULL;
    return s;
}

void push(Stack* s, char item){
    Node* new = malloc(sizeof(Node));
    new->letra = item;
    new->next = NULL;
    new->prev == NULL;
    if (s->top == NULL){
        s->top = new;
        s->rear = new;
    } else {
        new->next = s->top;
        new->next->prev = new;
        s->top = new;        
    }
}

void pop(Stack* s){
    if (s == NULL) return;
    Node* temp = s->top;
    s->top = temp->next;
    if (s->top != NULL) s->top->prev = NULL;
    else s->rear = NULL;
    free(temp);
}
void printStack(Stack* s){
    Node* curr = s->rear;
    while(curr != NULL){
        printf("%c", curr->letra);
        curr = curr->prev;
    }
}
int main(){
    char c;
    Stack* s = createStack();
    while(scanf("%c", &c) != EOF){
        if (c == '\n') continue;
        if (c == '#') {
            pop(s);
            printf("Texto atual: ");
            printStack(s);
        } else if (c == '@'){
            while(s->top != NULL) pop(s);
            printf("Texto atual: \n");
        } else {
            push(s, c);
        }
    }
    return 0;
}