#include<stdio.h>
struct aluno{
    char nome[50];
    int idade;
    float nota;
};
#define Aluno struct aluno
struct curso{
    Aluno a1[3];
    char nomedocurso[50];
};
#define Curso struct curso
int main(){
    Curso c1 = {{{"Theo", 19, 4.25}, {"Eduardo", 18, 4.00}, {"Yuzo", 18, 3.93}}, "Engenharia de Computacao"};
    Curso *ptr;
    ptr = &c1;
    printf("Esses sao os principais alunos do curso de %s:\n", (ptr)->nomedocurso);
    Aluno *ptrAlunos;
    ptrAlunos = (ptr)->a1;
    for (int i = 0; i < 3; i++){
        printf("\n%s, de %d anos e ira de %.2f", (ptrAlunos+i)->nome, (ptrAlunos+i)->idade, (ptrAlunos+i)->nota);
        if (i < 2){
            printf(";\n");
        } else {
            printf(".\n");
        }
        printf("\n-------------------------------------\n");
    }
    return 0;
}