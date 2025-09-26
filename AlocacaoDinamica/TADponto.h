#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float x;
    float y;
} Ponto;

void imprime_ponto(Ponto x); 
int get_quadrante_ponto(Ponto x);
double distancia_entre_pontos(Ponto a, Ponto b);
Ponto *criar_ponto(float x, float y);
void libera_ponto(Ponto *ponto);
#endif
