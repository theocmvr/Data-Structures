#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    scanf("%d", &n);
    int stack[10001] = {-1};
    int tipo, ordem, k, topo = 0;
    int push[10001] = {-1};
    int pop[10001] = {-1};
    for (int i = 0; i < n; i++){
        scanf("%d %d", &ordem, &tipo);
        if (tipo == 1){
            scanf("%d", &k);
            push[ordem] = k;
        } else {
            pop[ordem] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        printf(" Pushaa essa valor: %d\n", push[i]);
        if(push[i] != -1){
            stack[i] = push[i];
            topo = i;
            printf("%d\n", stack[topo]);
            continue;
        }
        if(pop[i] != -1){
            stack[topo] = -1;
            topo--;
            printf("%d\n", stack[topo]);
        }
    }
    return 0;
}