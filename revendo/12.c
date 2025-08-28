#include<stdio.h>
#include<string.h>
int main(){
    char *n;
    scanf("%s", n);
    for (int i = strlen(n) - 1; i >= 0; i--){
        printf("%c", n[i]);
    }
    printf("\n");
    return 0;
}