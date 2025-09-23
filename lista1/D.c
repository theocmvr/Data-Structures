#include<stdio.h>
int main(){
    int S, T, A, B, m, n, maca, laranja, apples = 0, oranges = 0;
    scanf("%d %d", &S, &T);
    scanf("%d %d", &A, &B);
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++){
        scanf("%d", &maca);
        if (A + maca >= S && A + maca <= T){
            apples++;
        }
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &laranja);
        if (B + laranja <= T && B + laranja >= S){
            oranges++;
        }
    }
    printf("%d\n%d\n", apples, oranges);
    return 0;
}