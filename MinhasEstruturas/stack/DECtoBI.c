#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
int main(){
    int n, size = 1;
    scanf("%d", &n);
    Stack* s = createStack();
    while (n/2 != 0){
        push(s, n%2);
        n /= 2;
        if(n/2 == 0) push(s, 1);
        size++;
    }
    while(size--) pop(s);
    printf("\n");
}