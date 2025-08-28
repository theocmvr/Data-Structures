#include<stdio.h>
#include<string.h>
int main(){
    long long n, fib[92];
    scanf("%lld", &n);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i < n; i++){
        printf("%lld\n", fib[i]);
    }    
    return 0;
}