#include<stdio.h>
int main(){
    int n, soma = 0, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        soma += num;
    } 
    printf("%d\n", soma);
    return 0;
}