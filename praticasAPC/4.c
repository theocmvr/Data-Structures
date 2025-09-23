#include<stdio.h>
#include<math.h>
int main(){
    int n;
    double coelhox, coelhoy, raposax, raposay;
    scanf("%d %lf %lf %lf %lf", &n, &coelhox, &coelhoy, &raposax, &raposay );
    for (int i = 0; i < n; i++){
        double buracox, buracoy;
        double distanciacoelho, distanciaraposa;
        scanf("%lf %lf", &buracox, &buracoy);
        distanciacoelho = sqrt((buracox-coelhox)*(buracox-coelhox) + (buracoy-coelhoy)*(buracoy-coelhoy));
        distanciaraposa = sqrt((buracox-raposax)*(buracox-raposax) + (buracoy-raposay)*(buracoy-raposay));
        if (distanciaraposa/2 > distanciacoelho){
            printf("O coelho pode escapar pelo buraco (%.3lf,%.3lf).\n", buracox, buracoy);
            return 0;
        }
    }
    printf("O coelho nao pode escapar.\n");
    return 0;
}