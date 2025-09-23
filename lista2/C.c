         #include<stdio.h>
        int solve(int n){
            if (n == 0){
                return 1;
            } else if (n%2 != 0){
                return (4 + solve(n-1));
            } else {
                return (3 + solve(n/2));
            }
        }
        int main(){
            int n;
            scanf("%d", &n);
            while (n--){
                int num;
                scanf("%d", &num);
                printf("%d\n", solve(num));
            }
            return 0;
        }