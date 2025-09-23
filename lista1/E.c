#include<stdio.h>
int main(){
    int n, a, b, c, dista, distb;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &a, &b, &c);
        dista = abs(c - a);
        distb = abs(c - b);
        if (dista < distb){
            printf("Cat A\n");
        } else if (distb < dista){
            printf("Cat B\n");
        } else {
            printf("Mouse C\n");
        }
    }
    return 0;
}