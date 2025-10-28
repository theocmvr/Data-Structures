#ifndef PILHA_H
#define PILHA_H
typedef struct Stack{
    int* arr;
    int size;
    int top;
} Stack;
Stack* Pilha();
void push(Stack* s, int item);
void pop(Stack* s);
int peek(Stack* s);
bool isEmpty(Stack* s);
int size(Stack* s);
#endif