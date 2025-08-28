#include<stdio.h>
#include<string.h>
int main(){
    int n, resto, soma = 0;
    scanf("%d", &n);
    while(n > 0){
        soma += n%10;
        n /= 10;
    }
    printf("%d\n", soma);
    return 0;
}