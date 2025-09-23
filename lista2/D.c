#include<stdio.h>
int n, m, k;
int matrix[100][100];
int dp[100][100];
int solve(int i, int j){
    if (dp[i][j]){
        return matrix[i][j];
    }
    dp[i][j] = 1;
    if (i == 0 && j ==0){
        return matrix[i][j] = m;
    } 
    if (i > j){
        return matrix[i][j] = solve(i-1, j) - 1;
    } else if (i < j){
        return matrix[i][j] = solve(i, j-1) - 1;
    } else {
        return matrix[i][j] = solve(i-1, j-1) + k; 
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", solve(i, j));
        }
        printf("\n");
    }
    return 0;
}