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
void merge(int* arr, int l, int m, int r){
    int i = l, j = m+1, k = 0;
    int auxarr[r-l+1];
    while(i <= m && j <= r){
        if (arr[i] > arr[j]) auxarr[k] = arr[j++];
        else auxarr[k] = arr[i++];
        k++;
    }
    while(i <= m) auxarr[k++] = arr[i++];
    while(j <= r) auxarr[k++] = arr[j++];
    for (i = l, k = 0; i <= r; i++, k++) arr[i] = auxarr[k];
}
void mergesort(int* arr, int l, int r){
    if (l < r){
        int m = l+((r-l)/2);
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}