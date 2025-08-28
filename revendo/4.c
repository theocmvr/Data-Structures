#include<stdio.h>
#include<string.h>
int main(){
    int maior, menor, num[5];
    for (int i = 0; i < 5; i++){
        scanf("%d", &num[i]);
    }
    maior = num[0];
    menor = num[0];
    for (int i = 1; i < 5; i++){
        if (num[i] > maior){
            maior = num[i];
        }
        if (num[i] < menor){
            menor = num[i];
        }
    }
    printf("%d eh o maior e %d eh o menor\n", maior, menor);
    return 0;
}