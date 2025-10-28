#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next; // aponta para cima (próximo em direção ao top)
    struct Node* prev; // aponta para baixo (próximo em direção ao rear)
    char letra;
} Node;

typedef struct {
    Node* top;
    Node* rear;
} Stack;

Stack* createStack() {
    Stack* s = malloc(sizeof(Stack));
    if (s == NULL) return NULL;
    s->top = NULL;
    s->rear = NULL;
    return s;
}

void push(Stack* s, char item) {
    Node* new = malloc(sizeof(Node));
    if (!new) return;
    new->letra = item;

    // new será o novo top: não há ninguém acima dele
    new->next = NULL;

    // abaixo dele fica o antigo top (pode ser NULL se estiver vazio)
    new->prev = s->top;

    if (s->top != NULL) {
        // antigo top passa a apontar pra cima (para o novo top)
        s->top->next = new;
    }
    s->top = new;

    // se estava vazio, rear também aponta para o novo nó
    if (s->rear == NULL) {
        s->rear = new;
    }
}

void pop(Stack* s) {
    if (s->top == NULL) return; // pilha vazia

    Node* temp = s->top;
    // novo topo é o que estava abaixo
    s->top = temp->prev;

    if (s->top != NULL) {
        // novo topo não tem ninguém acima
        s->top->next = NULL;
    } else {
        // pilha ficou vazia
        s->rear = NULL;
    }

    free(temp);
}

void printStack(Stack* s) {
    // imprime do rear até o top seguindo 'next'
    Node* curr = s->rear;
    while (curr != NULL) {
        printf("%c", curr->letra);
        curr = curr->next;
    }
    printf("\n");
}

/* Função auxiliar para limpar toda a pilha (opcional) */
void clearStack(Stack* s) {
    while (s->top != NULL) pop(s);
}
