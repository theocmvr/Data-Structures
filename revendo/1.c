#include<stdio.h>
#include<string.h>
int main(){
    int n, soma = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        if (i%2 == 0){
            soma += i;
        }
    }
    printf("%d\n", soma);
    return 0;
}