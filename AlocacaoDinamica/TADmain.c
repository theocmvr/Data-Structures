#include "TADponto.h"

int main() {
    Ponto *p1 = criar_ponto(0, 0);
    Ponto *p2 = criar_ponto(0, 0);
    imprime_ponto(*p1);
    imprime_ponto(*p2);
    get_quadrante_ponto(*p1);
    get_quadrante_ponto(*p2);
    printf("Distancia entre os pontos: %f\n", distancia_entre_pontos(*p1, *p2));
    libera_ponto(p1);
    libera_ponto(p2);
    return 0;
}
