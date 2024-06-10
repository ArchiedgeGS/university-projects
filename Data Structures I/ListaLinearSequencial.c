#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef struct  {
    int chave;
    // conteúdo
} No;

typedef struct {
    No Nos[MAX];
    int numElem;
} Lista;

void inicializarLista(Lista* l) {
    l->numElem = 0;
}

int tamanhoLista(Lista* l) {
    return l->numElem;
}

void exibirLista(Lista* l) {
    printf("Lista: \" ");

    for(int i = 0; i< l->numElem; i++) {
        printf("%i ", l->Nos[i].chave);
    }

    printf("\"\n");
}

int buscaSequencial(Lista* l, int ch) {
    int i = 0;
    while(i < l->numElem) {
        if(ch == l->Nos[i].chave) {
            return i;
        }
        else {
            i++;
        }
    }
    return -1;
}

bool inserirElemLista(Lista* l, No no, int n) {
    if(l->numElem == MAX || n < 0 || n > l->numElem) {
        return false;
    }

    for(int i = l->numElem; i > n; i--) {
        l->Nos[i] = l->Nos[i-1];
    }

    l->Nos[n] = no;
    l->numElem++;
    return true;
}

bool excluirElemLista(int ch, Lista* l) {
    int posicao;
    posicao = buscaSequencial(l, ch);
    if(posicao == -1) {
        return false;
    }

    for(int i = posicao; i< l->numElem-1; i++) {
        l->Nos[i] = l->Nos[i+1];
    }

    l->numElem--;
    return true;
}

void reinicializarLista(Lista* l) {
    l->numElem = 0;
}



int main() {
     Lista lista;
    inicializarLista(&lista);

    int opcao, chave, posicao;
    No no;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Excluir elemento\n");
        printf("3. Exibir lista\n");
        printf("4. Tamanho da lista\n");
        printf("5. Buscar elemento\n");
        printf("6. Reinicializar lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a chave do elemento a ser inserido: ");
                scanf("%d", &no.chave);
                printf("Digite a posicao para inserir o elemento (0 a %d): ", tamanhoLista(&lista));
                scanf("%d", &posicao);
                if (inserirElemLista(&lista, no, posicao)) {
                    printf("Elemento inserido com sucesso!\n");
                } else {
                    printf("Erro ao inserir o elemento. Verifique se a posicao e valida ou se a lista esta cheia.\n");
                }
                break;
            case 2:
                printf("Digite a chave do elemento a ser excluido: ");
                scanf("%d", &chave);
                if (excluirElemLista(chave, &lista)) {
                    printf("Elemento excluido com sucesso!\n");
                } else {
                    printf("Erro ao excluir o elemento. Verifique se a chave existe na lista.\n");
                }
                break;
            case 3:
                exibirLista(&lista);
                break;
            case 4:
                printf("Tamanho da lista: %d\n", tamanhoLista(&lista));
                break;
            case 5:
                printf("Digite a chave do elemento a ser buscado: ");
                scanf("%d", &chave);
                posicao = buscaSequencial(&lista, chave);
                if (posicao != -1) {
                    printf("Elemento encontrado na posicao: %d\n", posicao);
                } else {
                    printf("Elemento nao encontrado.\n");
                }
                break;
            case 6:
                reinicializarLista(&lista);
                printf("Lista reinicializada com sucesso!\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}