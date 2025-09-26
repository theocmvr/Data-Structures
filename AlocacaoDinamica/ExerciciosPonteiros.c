#include<stdio.h>
int aumentanota(float *(ptr), int idx, float aumento){
    float nota;
    nota = *(ptr+idx-1) + aumento;
    if (nota > 10){
        printf("O aluno %d nao pode ter a nota ajustada\n", idx);
        return 1;
    }
    printf("O aluno %d tera a nota aumentada para %.2f.\n", idx, nota);
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    float arr[20];
    float soma = 0;
    float *ptr;
    ptr = arr;
    for (int i = 0; i < n; i++){
        printf("Nota do aluno %d: ", i+1);
        scanf("%f", (ptr+i));
        soma += *(ptr+i);
        printf("\n");
    }
    ptr = arr;
    int idx;
    float aumento;
    printf("Media inicial: %.2f\n", soma/n);
    printf("Que aluno deseja aumentar a nota? E quanto? ");
    scanf("%d %f", &idx, &aumento);
    if (aumentanota(ptr, idx, aumento) == 0){
        printf("A nova media eh: %.2f\n", (soma+aumento)/n);
    } else {
        printf("A media final eh igual a media inicial (%.2f)\n", soma/n);
    }
    return 0;
}