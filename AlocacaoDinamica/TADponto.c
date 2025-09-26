    #include <stdio.h>
    #include <math.h>
    #include "TADponto.h"
    void imprime_ponto(Ponto ponto) {
        printf("(%.2lf, %.2lf)\n", ponto.x, ponto.y);
    }

    int get_quadrante_ponto(Ponto x) {
        if (x.x > 0 && x.y > 0) return 1;
        if (x.x < 0 && x.y > 0) return 2;
        if (x.x < 0 && x.y < 0) return 3;
        if (x.x > 0 && x.y < 0) return 4;
        return 0;
    }

    float distancia_entre_pontos(Ponto a, Ponto b) {
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }
    Ponto *criar_ponto(float x, float y){
        Ponto *p1 = (Ponto*) malloc(sizeof(Ponto));
        printf("Cordenada X:");
        scanf("%f", &x);
        printf("\n");
        printf("Cordenada Y:");
        scanf("%f", &y);
        p1->x = x;
        p1->y = y;
        return p1;
    }
    void libera_ponto(Ponto *ponto){
        free(ponto);
    }