#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
int main(){
    char *nome = malloc(100*sizeof(char));
    Queue *q = createQueue();
    scanf("%s", nome);
    enQueue(q, nome);
    return 0;
}