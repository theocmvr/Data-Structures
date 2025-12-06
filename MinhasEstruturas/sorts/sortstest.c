#include "sorts.h"
int main(){
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, n-1);
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
    return 0;
}