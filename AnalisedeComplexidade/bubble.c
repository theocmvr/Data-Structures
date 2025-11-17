#include<stdio.h>
int main(){
    int n, op = 0;
    int arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n-1; i++){
        for(int j =i+1; j < n; j++){
            op++;
            if (arr[i] > arr[j]){
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if (i != n-1)printf(" ");
    }
    printf("\n%d\n", op);
    return 0;
}