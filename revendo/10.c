#include<stdio.h>
#include<string.h>
int main(){
    int n, num, maior = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        if (num > maior){
            maior = num;
        }
    }
    printf("%d\n", maior);
    return 0;
}