#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    int top = 0;
    int* stack = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        int type, a;
        scanf("%d", &type);
        if (type == 1){
            scanf("%d", &a);
            stack[++top] = a;
        } else if (type == 2){
            if(top != -1)  top--;
        } else {
            if (top == -1) printf("Empty!\n");
            else printf("%d\n", stack[top]);
        }
    }
    free(stack);
    return 0;
}