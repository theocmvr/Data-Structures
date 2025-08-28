#include<stdio.h>
#include<string.h>
int main(){
    int n, num, soma = 0;
    for (int i = 0; i < 10; i++){
        scanf("%d", &num);
        if (num > 0){
            soma += num;
        }
    }
    printf("%d\n", soma);
    return 0;
}