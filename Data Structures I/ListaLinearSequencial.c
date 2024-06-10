#include <stdio.h>

#define MAX 50

typedef struct  {
    int chave;
    // conteúdo
} No;

typedef struct {
    NO Nos[MAX];
    int nroElem;
} Lista;

void inicializarLista(Lista* l) {
    l->nroElem = 0;
}