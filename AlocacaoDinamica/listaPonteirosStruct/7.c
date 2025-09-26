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
void sort(Aluno *ptr[]){
    for (int i = 0; i < 4; i++){
        for (int j = i+1; j < 5; j++){
            Aluno *aux;
            if ((*(ptr+i))->nota < (*(ptr+j))->nota){
                aux = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = aux;
            }
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
    sort(ptr);
    for(int i = 0; i < 5; i++){
        printf("\n%d -> %s, %d anos, %.2f pontos", i+1, (*(ptr+i))->nome, (*(ptr+i))->idade, (*(ptr+i))->nota);
        if (i < 4){
            printf(";");
        }
        printf("\n");
        printf("\n-----------------------------------\n");
    }
    return 0;
}