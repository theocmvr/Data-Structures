#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    srand(time(NULL));
    int n = rand()%100 + 1;
    int num;
    while(1){
        scanf("%d", &num);
        if (num == n){
            printf("Acertou!\n");
            break;
        }
        if (num > n){
            printf("Menor\n");
        } else {
            printf("Maior\n");
        }
    }
    return 0;
}