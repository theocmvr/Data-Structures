#include<stdio.h>
long long dp[37];
long long solve(int n){
    if (dp[n] > -1){
        return dp[n];
    }
    if (n < 0){
        return 0;
    }
    if (n == 0){
        return 1;
    }
    dp[n] = (solve(n-1) + solve(n-2) + solve(n-3))%10000000007;
    return dp[n];
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 37; i++){
        dp[i] = -1;
    }
    int num;
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        printf("%lld\n", solve(num));
    }
    return 0;
}