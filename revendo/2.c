#include<stdio.h>
#include<string.h>
int main(){
    int num, countpos = 0, countneg = 0;
    for (int i = 0; i < 10; i++){
        scanf("%d", &num);
        if (num > 0){
            countpos++;
        } else {
            countneg++;
        }
    }
    printf("%d positivos e %d negativos\n", countpos, countneg);
    return 0;
}