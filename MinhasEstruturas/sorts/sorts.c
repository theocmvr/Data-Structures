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
    int i, j, k;
    int n1 = m-l+1, n2 = r-m;
    int larr[n1], rarr[n2];
    for (i = 0; i < n1; i++) larr[i] = arr[l+i];
    for (j = 0; j < n2; j++) rarr[j] = arr[r+j+1];
    i = j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (larr[i] <= rarr[j]){
            arr[k] = larr[i];
            i++;
        } else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}
void mergesort(int* arr, int l, int r){
    if (l < r){
        int m = l+((r-l)/2);
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}