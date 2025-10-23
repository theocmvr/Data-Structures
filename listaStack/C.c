#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    struct Node* next;
    int num;
} Node;
typedef struct Stack{
    struct Node* top;
    int size;
} Stack;
Stack* createStack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) return s;
    s->top = NULL;
    s->size = 0;
    return s;
}
void push(Stack* s, int x){
    if (s == NULL) return;
    Node* new = malloc(sizeof(Node));
    new->num = x;
    new->next = s->top;
    s->top = new;
    s->size++;
}
int pop(Stack* s){
    if (s->top == NULL || s == NULL) return -1;
    Node* temp = s->top;
    int value = temp->num;
    s->top = temp->next;
    s->size--;
    free(temp);
    return value;
}
void freeStack(Stack* s) {
    while (s->top != NULL)
        pop(s);
    free(s);
}
int main(){
    char string[21];
    fgets(string, 21, stdin);
    Stack* s = createStack();
    int val = 0;
    int count = 1;
    int a, b;
    for(int i = 0; i < string[i] != '\0' && string[i] != '\n'; i++){
        if (string[i] != '*' && string[i] != '+'){
            push(s, string[i] - '0');
        } else {
            a = pop(s);
            b = pop(s);
            if (string[i] == '*') push(s, a*b);
            else push(s, a+b);
        }
    }
    printf("%d\n", pop(s));
    freeStack(s);
    return 0;
}