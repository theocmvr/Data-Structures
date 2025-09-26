#include<stdio.h>
struct aluno{
    char nome[50];
    int idade;
    float nota;
};
#define Aluno struct aluno
void idade(Aluno *ptr[]){
    for (int i = 0; i < 5; i++){
        if ((*(ptr+i))->idade >= 18){
            printf("%s eh maior de idade\n", (*(ptr+i))->nome);
        }
    }
}
int main(){
    Aluno a1[5] = {
        {"Theo", 19, 9.0},
        {"Guissis", 18, 9.5},
        {"Pepe", 19, 10.0},
        {"Eduardo", 18, 5.0},
        {"Yuzo", 18, 9.75},
    };
    Aluno *ptr[5];
    for (int i = 0; i < 5; i++){
        *(ptr+i) = (a1+i);
    }
    idade(ptr);
    return 0;
}