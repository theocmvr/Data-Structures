#include<stdio.h>
int main(){
    int a = 10;
    int *ptr = &a;
    *ptr = 20;
    printf("%d\n", a);
    return 0;
}