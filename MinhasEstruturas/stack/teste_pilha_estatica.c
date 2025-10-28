#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "pilha_estatica.h"
int main(){
    Stack* s = Pilha();
    for (int i = 0; i < 100; i++){
        s->arr[i] = -1;
    }
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("O tamanho da lista eh de: %d\n", s->size);
    printf("O elemento do topo eh: %d\n", peek(s));
    pop(s);
    pop(s);
    pop(s);
    if (isEmpty) printf("A pilha esta vazia!\n");
    return 0;
}