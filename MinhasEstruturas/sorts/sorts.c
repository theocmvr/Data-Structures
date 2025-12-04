#include "sorts.h"
void bubble(int* arr){
    for (int i = 0; i < (int)sizeof(arr) -1; i++){
        for (int j = 0; j < (int)sizeof(arr) - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}
void merge(int* arr, int left, int mid, int right){
    int i, j, k;
    int n1 = , n2;
}