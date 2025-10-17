#ifndef STACK_H
#define STACK_H
typedef struct {
    int element;
    struct Node *next;
} Node;
typedef struct{
    Node *top;
    int size;
} Stack;
Stack* creatStack();
int push(Stack *s, int item);
int pop(Stack *s)
#endif