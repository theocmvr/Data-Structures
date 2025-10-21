#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
int main(){
    Queue *q = createQueue();
    int n;
    printf("Bem vindo a loja de filas. Qual tamanho de fila voce deseja? ");
    scanf("%d", &n);
    printf("Perfeito! Isso custara %d reais. Me diga o nome dos integrantes que voce deseja colocar em sua fila personalizada:\n", 15*n);
    for(int i = 0; i < n; i++){
        char* nome = (char*)malloc(100*sizeof(char));
        getchar();
        scanf("%s", nome);
        enQueue(q, nome);
    }
    int tamanho = size(q);
    printf("Tem %d pessoas na fila.\n", tamanho);
    printf("Esse eh o primeiro da fila: %s\n", front(q));
    while (!isEmpty(q)){
        char* nome = deQueue(q);
        printf("Esse saiu agora: %s\n", nome);
        free(nome);
        if(isEmpty(q)) break;
        printf("Esse eh o novo primeito da fila: %s\n", front(q));
        tamanho = size(q);
        printf("Agora tem %d pessoas na fila.\n", tamanho);
    }
    printf("A fila esvaziou-se!\n");
    freeQueue(q);
    return 0;
}