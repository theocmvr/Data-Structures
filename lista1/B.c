#include<stdio.h>
int main(){
    int n, num, arr[201];
    double pos, neg, zero;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++){
        if (arr[i] > 0){
            pos++;
        } else if (arr[i] < 0){
            neg++;
        } else {
            zero++;
        }
    }
    printf("%.6lf\n%.6lf\n%.6lf\n", pos/n, neg/n, zero/n);
    return 0;
}