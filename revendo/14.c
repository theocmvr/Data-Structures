#include<stdio.h>
#include<string.h>
int main(){
    int num, countquatro = 0, countseis = 0;
    for (int i = 0; i < 20; i++){
        scanf("%d", &num);
        if (num%4 == 0){
            countquatro++;
        }
        if (num%6 == 0){
            countseis++;
        }
    }
    printf("%d %d\n", countquatro, countseis);
    return 0;
}