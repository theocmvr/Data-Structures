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
void sort(Curso *ptr){
    Aluno *ptrAluno;
    ptrAluno = (ptr)->a1;
    float maior = 0;
    Aluno *melhor;
    for (int i = 0; i < 3; i++){
        if ((ptrAluno+i)->nota > maior){
            maior = (ptrAluno+i)->nota;
            melhor = ptrAluno;
        }
    }
    printf("O aluno %s, de %d anos, é o aluno com a maior nota do curso (%.2f).\n", (melhor)->nome, (melhor)->idade, (melhor)->nota);
    return;
}
int main(){
    Curso c1 = {{{"Theo", 19, 4.25}, {"Eduardo", 18, 4.00}, {"Yuzo", 18, 3.93}}, "Engenharia de Computacao"};
    Curso *ptr;
    ptr = &c1;
    sort(ptr);
    return 0;
}