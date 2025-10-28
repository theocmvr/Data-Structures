#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef STACK_H
#define STACK_H
typedef struct Node{
    struct Node* next;
    int element;
} Node;
typedef struct{
    Node* top;
    int size;
} Stack;
Stack* createStack();
void push(Stack* s, int item);
void pop(Stack* s);
int peek(Stack* s);
bool isEmpty(Stack* s);
int size(Stack* s);
#endif