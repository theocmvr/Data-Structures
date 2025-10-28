#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"queue.h"
int main(){
    srand(time(NULL));
    Queue* q = createQueue();
    enQueue(q, "Theo");
    enQueue(q, "Guissis");
    enQueue(q, "Eduardo");
    enQueue(q, "Yuzo");
    enQueue(q, "Pp");
    while(q->size > 1){
        int steps = rand()%10 + 1;
        for (int i = 0; i < steps; i++){
            char* nome = deQueue(q);
            enQueue(q, nome);
            free(nome);
        }
        char* queimado = deQueue(q);
        printf("%s foi queimado!\n", queimado);
        free(queimado);
    }
    char* winner = deQueue(q);
    printf("\nO vencedor eh o: %s!\n", winner);
    free(winner);
    freeQueue(q);
    return 0;
}