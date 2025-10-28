#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "pilha_estatica.h"

Stack* Pilha(){
    Stack* s = malloc(sizeof(Stack));
    s->arr = malloc(100*sizeof(int));
    s->size = 0;
    s->top = 0;
    return s;
}

void push(Stack* s, int item){
    s->arr[s->top+1] = item;
    s->top++;
    s->size++;
}

void pop(Stack* s){
    int temp = s->arr[s->top];
    printf("Esse numero foi poppado: %d\n", temp);
    s->arr[s->top] = -1;
    s->top--;
    s->size--;
}

int peek(Stack* s){
    return s->arr[s->top];
}

bool isEmpty(Stack* s){
    return (s->size > 0);
}

int size(Stack* s){
    return s->size;
}