#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char nome[51];
    char sobrenome[51];
    int alt;
    int pes;
} Candidatos;

void height(Candidatos* arr, int x){
    for(int i = 0; i < x-1; i++){
        for (int j = i+1; j < x; j++){
            if (arr[i].alt > arr[j].alt){
                Candidatos aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void weight(Candidatos* arr, int x){
    for(int i = 0; i < x-1; i++){
        for (int j = i+1; j < x; j++){
            if(arr[i].alt == arr[j].alt){
                if (arr[i].pes > arr[j].pes && arr[i].pes != 75 && arr[j].pes != 75){
                    Candidatos aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                }
            }
        }
    }
}

void surname(Candidatos* arr, int x){
    for(int i = 0; i < x-1; i++){
        for (int j = i+1; j < x; j++){
            if(arr[i].alt == arr[j].alt){
                if (arr[i].pes == arr[j].pes){
                    if (strcmp(arr[i].sobrenome, arr[j].sobrenome) > 0){
                        Candidatos aux = arr[i];
                        arr[i] = arr[j];
                        arr[j] = aux;
                    }
                }
            }
        }
    }
}

void name(Candidatos* arr, int x){
    for(int i = 0; i < x-1; i++){
        for (int j = i+1; j < x; j++){
            if(arr[i].alt == arr[j].alt){
                if (arr[i].pes == arr[j].pes){
                    if (strcmp(arr[i].sobrenome, arr[j].sobrenome) == 0){
                        if (strcmp(arr[i].nome, arr[j].nome) > 0){
                            Candidatos aux = arr[i];
                            arr[i] = arr[j];
                            arr[j] = aux;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int n;
    Candidatos arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        char nome[51];
        char sobrenome[51];
        int altura, peso;
        scanf("%s %s %d %d", nome, sobrenome, &altura, &peso);
        strcpy(arr[i].nome, nome);
        strcpy(arr[i].sobrenome, sobrenome);
        arr[i].alt = abs(180 - altura);
        arr[i].pes = peso;
    }
    height(arr, n);
    weight(arr, n);
    surname(arr, n);
    name(arr, n);
    for (int i = 0; i < n; i++){
        printf("%s, %s", arr[i].sobrenome, arr[i].nome);
        if (i != n-1) printf("\n");
    }
    return 0;
}
