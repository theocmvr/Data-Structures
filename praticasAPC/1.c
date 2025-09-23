#include<stdio.h>
int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y){
        printf("%d\n%d\ndiferentes\n", x, y);
    } else if (x < y){
        printf("%d\n%d\ndiferentes\n", y, x);
    } else {
        printf("%d\n%d\niguais\n", x, y);
    }
    return 0;
}