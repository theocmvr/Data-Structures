#include<stdio.h>
struct aluno{
    char nome[50];
    int idade;
    float nota;
};
#define Aluno struct aluno
int main(){
    Aluno a1[3];
    Aluno *ptr = a1;
    for (int i = 0; i < 3; i++){
        printf("Me diga o nome, a idade e a nota do aluno %d\n", i+1);
        scanf("%s %d %f", (ptr+i)->nome, &(ptr+i)->idade, &(ptr+i)->nota);
    }
    for (int i = 0; i < 3; i++){
        if ((ptr+i)->nota > 7.0){
            printf("O aluno %s de %d anos passou\n", (ptr+i)->nome, (ptr+i)->idade);
        } else {
            printf("O aluno %s de %d anos nao passou\n", (ptr+i)->nome, (ptr+i)->idade);
        }
    }
    return 0;
}