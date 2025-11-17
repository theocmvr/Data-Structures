#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void namesort(char arr[500][101], int x){
    for(int i = 0; i < x-1; i++){
        for (int j = i+1; j < x; j++){
            if (strcmp(arr[i], arr[j]) < 0){
                char aux[101];
                strcpy(aux, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], aux);
            }
        }
    }
}
int main(){
    int n;
    char SS[500][101], MS[500][101], MM[500][101], MI[500][101], II[500][101], SR[500][101];
    scanf("%d", &n);
    getchar();
    int cSS = 0, cMS = 0, cMM = 0, cMI = 0, cII = 0, cSR = 0;
    for(int i = 0; i < n; i++){
        char nota[3];
        char nome[101];
        scanf("%s %[^\n]", nota, nome);
        if (strcmp(nota, "SS") == 0) strcpy(SS[cSS++], nome);
        if (strcmp(nota, "MS") == 0) strcpy(MS[cMS++], nome);
        if (strcmp(nota, "MM") == 0) strcpy(MM[cMM++], nome);
        if (strcmp(nota, "MI") == 0) strcpy(MI[cMI++], nome);
        if (strcmp(nota, "II") == 0) strcpy(II[cII++], nome);
        if (strcmp(nota, "SR") == 0) strcpy(SR[cSR++], nome);
    }
    namesort(SS, cSS);
    namesort(MS, cMS);
    namesort(MM, cMM);
    namesort(MI, cMI);
    namesort(II, cII);
    namesort(SR, cSR);
    for(int i = cSS-1; i >= 0; i--){
        printf("SS %s\n", SS[i]);
    }
    for(int i = cMS-1; i >= 0; i--){
        printf("MS %s\n", MS[i]);
    }
    for(int i = cMM-1; i >= 0; i--){
        printf("MM %s\n", MM[i]);
    }
    for(int i = cMI-1; i >= 0; i--){
        printf("MI %s\n", MI[i]);
    }
    for(int i = cII-1; i >= 0; i--){
        printf("II %s\n", II[i]);
    }
    for(int i = cSR-1; i >= 0; i--){
        printf("SR %s\n", SR[i]);
    }
    return 0;
}