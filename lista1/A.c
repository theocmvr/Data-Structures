#include<stdio.h>
int main(){
    int horas, minutos, segundos;
    char AP, M;
    scanf("%d:%d:%d%c%c", &horas, &minutos, &segundos, &AP, &M);
    if (AP == 'A'){
        if (horas == 12){
            horas = 0;
        }
        printf("%02d:%02d:%02d\n", horas, minutos, segundos);
    } else {
        if (horas == 12){
            horas = 12;
        } else {
            horas += 12;
        }
        printf("%02d:%02d:%02d\n", horas, minutos, segundos);
    }
    return 0;
}   