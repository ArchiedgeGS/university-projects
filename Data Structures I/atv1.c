/*
Faça um programa em C que cria uma lista estática encadeada cujos nós têm dois
campos: info e prox (ambos do tipo inteiro). Inicialize propriamente o vetor, criando a
lista de nós livres (apontada por disponivel).
a) Faça uma função para inserir nós numa lista ordenada sem repetição, apontada por
L (indica a posição do primeiro nó). Para inserir nós em L, primeiramente deve-se
obtê-los da lista disponivel.
b) Faça uma função que receba como parâmetros Vi e Vf (números inteiros), sendo Vi
< Vf. A função deverá eliminar da lista os nós cujos valores do campo info estejam
compreendidos entre Vi e Vf (inclusive eles). Assuma que os valores de Vi e Vf estão
contidos em L, e que Vi não é o primeiro nó e Vf não é o último nó da lista. Os nós
eliminados deverão ser inseridos apropriadamente na lista indicada por disponivel.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int info, prox;
} No;

typedef struct {
    No nos[MAX];
    int disponivel;
    int L;
} Lista;

void inicializarLista(Lista* lista) {    
    for(int i = 0; i < MAX - 1; i++) {
        lista->nos[i].prox = i + 1;
    }

    lista->nos[MAX-1].prox = -1;
    lista->disponivel = 0;
    lista->L = -1; 
}

int obterNo(Lista* lista) {
    if(lista->disponivel == -1) {
        return -1;
    }

    int posicao = lista->disponivel;
    lista->disponivel = lista->nos[posicao].prox;
    return posicao;
}

void liberarNo(Lista* lista, int posicao) {
    lista->nos[posicao].prox = lista->disponivel;
    lista->disponivel = posicao;
}

void inserirOrdenado(Lista* lista, int valor) {
    int novoNo = obterNo(lista);
    if(novoNo == -1) {
        printf("ERRO: lista cheia\n");
        return;
    }
    lista->nos[novoNo].info = valor;

    int *posicao = &lista->L;
    while(*posicao != -1 && lista->nos[*posicao].info < valor) {
        posicao = &lista->nos[*posicao].prox;
    }
}