#include<stdio.h>
struct aluno{
    char nome[50];
    int idade;
    float nota;
};
#define Aluno struct aluno
int main(){
    Aluno a1 = {"Theo", 19, 8.5};
    Aluno *ptr;
    ptr = &a1;
    printf("Nota antes da correcao: %.2f\n", ptr->nota);
    printf("Nota apos a correcao: %.2f\n", (ptr)->nota+1.0);
    return 0;
}