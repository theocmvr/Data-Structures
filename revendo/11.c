#include<stdio.h>
#include<string.h>
int main(){ 
    int n, num, prod = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        if (num%2 != 0){
            prod *= num;
        }
    }
    printf("%d\n", prod);
    return 0;
}