#include<stdio.h>
int main(){
    int dias1, dias2, horas1, horas2, minutos1, minutos2, segundos1, segundos2, dias, horas, minutos, segundos, total;
    scanf("%d %d:%d:%d", &dias1, &horas1, &minutos1, &segundos1);
    scanf("%d %d:%d:%d", &dias2, &horas2, &minutos2, &segundos2);
    if (dias1 > dias2){
        printf("Data invalida!\n");
        return 0;
    } else if (dias1 == dias2 && horas1 > horas2){
        printf("Data invalida!\n");
        return 0;   
    } else if (dias1 == dias2 && horas1 == horas2 && minutos1 > minutos2){
        printf("Data invalida!\n");
        return 0;
    } else if (dias1 == dias2 && horas1 == horas2 && minutos1 == minutos2 && segundos1 >= segundos2){
        printf("Data invalida!\n");
        return 0;
    }
    dias1 *= 3600*24;
    dias2 *= 3600*24;
    horas1 *= 3600;
    horas2 *= 3600;
    minutos1 *= 60;
    minutos2 *= 60;
    total = (dias2+horas2+minutos2+segundos2) - (dias1+horas1+minutos1+segundos1);
    dias = total/(3600*24);
    horas = (total%(3600*24))/3600;
    minutos = ((total%(3600*24))%3600)/60;
    segundos = ((total%(3600*24))%3600)%60;
    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", dias, horas, minutos, segundos);
    return 0;
}