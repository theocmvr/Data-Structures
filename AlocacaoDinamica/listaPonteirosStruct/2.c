#include<stdio.h>
int main(){
    int arr[5];
    int *ptr;
    ptr = arr;
    for (int i = 0; i < 5; i++){
        scanf("%d", (ptr+i));
        printf("%p ", *(ptr+i));
    }
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("%d ", 2*(*(ptr+i)));
    }
    printf("\n");
    return 0;
}