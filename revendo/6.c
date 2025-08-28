#include<stdio.h>
#include<string.h>
int main(){
    int n, cubo, quad;
    scanf("%d", &n);
    quad = n*n;
    cubo = n*n*n;
    printf("%d e %d\n", quad, cubo);
    return 0;
}