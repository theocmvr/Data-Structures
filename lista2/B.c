#include<stdio.h>
long long solve(int n, int a, int b, int c){
    if (n == 1){
        return a;
    }
    if (n == 2){
        return b;
    }
    if (n == 3){
        return c;
    }
    return solve(n-1, a, b, c) + solve(n-2, a, b, c) + solve(n-3, a, b, c);
}
int main(){
    int n, a, b, c;
    scanf("%d\n%d %d %d", &n, &a, &b, &c);
    printf("%lld\n", solve(n, a, b, c));
    return 0;
}