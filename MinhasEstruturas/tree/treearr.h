#ifndef TREEARR_H
#define TREEARR_H
#include<stdio.h>
#include<stdlib.h>
extern int tree[1001];
void criaTree();
int cria_no(int data); 
int insere(int idx, int data);
void ordem(int idx);
void pre_ordem(int idx);
void pos_ordem(int idx);
int remover(int idx, int data);
int idxmin(int idx);
int DFS(int idx, int data);
int BFS(int idx, int data);
#endif
