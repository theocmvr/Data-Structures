#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"
int main(){
    Stack* s = createStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("O tamanho da Stack eh de: %d elementos.\n", size(s));
    while (!isEmpty(s)){
        printf("Topo atual: %d\n", peek(s));
        pop(s);
    }
    printf("A Stack eta vazia!\n");
}