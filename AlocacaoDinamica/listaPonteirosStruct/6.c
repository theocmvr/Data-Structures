#include<stdio.h>
struct aluno{
    char nome[50];
    int idade;
    float nota;
};
#define Aluno struct aluno
void corretor(Aluno *ptr){
    ptr->nota *= 1.1;
    return;
}
int main(){
    Aluno a1 = {"Theo", 18, 9.0};
    Aluno *ptr = &a1;
    corretor(ptr);
    printf("%.2f\n", ptr->nota);
    return 0;
}