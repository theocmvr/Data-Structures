#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

Stack* createStack(){
    Stack* s = malloc(sizeof(Stack));
    if (s == NULL) return s;
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack* s, int item){
    Node* new = malloc(sizeof(Node));
    new->element = item;
    new->next = s->top;
    s->top = new;
    s->size++;
}

void pop(Stack* s){
    Node* temp = s->top;
    printf("%d", temp->element);
    s->top = temp->next;
    s->size--;
    free(temp);
}

int peek(Stack* s){
    return s->top->element;
}

bool isEmpty(Stack* s){
    if (s == NULL || s->top == NULL) return true;
    else return false;
}

int size(Stack* s){
    return s->size;
}