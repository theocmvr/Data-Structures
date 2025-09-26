#include<stdio.h>
struct aluno{
    char *nome;
    int idade;
    float nota;
};
#define Aluno struct aluno
int main(){
    Aluno a1 = {"Theo", 19, 9.65};
    Aluno *ptr;
    ptr = &a1;
    printf("%s\n", ptr->nome);
    printf("%d\n", ptr->idade);
    printf("%.2f\n", ptr->nota);
    return 0;
}