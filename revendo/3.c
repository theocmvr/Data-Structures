#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int n, aux = 1;
    scanf("%d", &n);
    for (int i = 2; i <= sqrt(n); i++){
        if (n%i == 0){
            aux = 0;
            break;
        }
    }
    if (aux){
        printf("%d eh primo\n", n);
    } else {
        printf("%d nao eh primo\n", n);
    }
    return 0;
}