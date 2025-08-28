#include<stdio.h>
#include<string.h>
int main(){
    int arr[10], aux ;
    for (int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 9; i++){
        if (arr[i] > arr[i + 1]){
            aux = 0;
            break;
        }
    }
    for (int i = 0; i < 9; i++){
        if (arr[i] < arr[i + 1]){
            aux = 1;
            break;
        }
    }    
    return 0;
}