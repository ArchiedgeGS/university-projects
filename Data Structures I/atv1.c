    /*
    Faça um programa em C que cria uma lista estática encadeada cujos nós têm dois
    campos: info e proximo (ambos do tipo inteiro). Inicialize propriamente o vetor, criando a
    lista de nós livres (apontada por dispo).

    a) Faça uma função para inserir nós numa lista ordenada sem repetição, apontada por
    L (indica a posição do primeiro nó). Para inserir nós em L, primeiramente deve-se
    obtê-los da lista dispo.

    b) Faça uma função que receba como parâmetros Vi e Vf (números inteiros), sendo Vi
    < Vf. A função deverá eliminar da lista os nós cujos valores do campo info estejam
    compreendidos entre Vi e Vf (inclusive eles). Assuma que os valores de Vi e Vf estão
    contidos em L, e que Vi não é o primeiro nó e Vf não é o último nó da lista. Os nós
    eliminados deverão ser inseridos apropriadamente na lista indicada por dispo.
    */

    #include <stdio.h>

    #define MAX 100

    typedef struct {
        int info;
        int proximo;
    } No;

    No lista[MAX];
    int dispo = 0;
    int L = -1; // Indica o primeiro nó da lista



    void inicializar() {
        int i;
        for(i = 0; i < MAX - 1; i++) {
            lista[i].proximo = i + 1;
        }
        lista[MAX - 1].proximo = -1;  // -1 indica fim da lista
    }



    void inserir(int valor) {
        int anterior = -1;
        int atual = L;

        while(atual != -1 && lista[atual].info < valor) {
            anterior = atual;
            atual = lista[atual].proximo;
        }

        if(dispo != -1) {
            int novo = dispo;
            dispo = lista[dispo].proximo;
            lista[novo].info = valor;

            if(anterior == -1) {
                lista[novo].proximo = L;
                L = novo;
            } else {
                lista[novo].proximo = lista[anterior].proximo;
                lista[anterior].proximo = novo;
            }
        } else {
            printf("Lista cheia\n");
        }
    }



    void eliminar(int Vi, int Vf) {
        int anterior = L;
        int atual = lista[L].proximo;

        while(atual != -1 && lista[atual].info <= Vf) {
            if(lista[atual].info >= Vi) {
                // Remover nó da lista e inserir na lista dispo
                if(atual == L) {
                    L = lista[atual].proximo;
                } else {
                    lista[anterior].proximo = lista[atual].proximo;
                }
                
                int temp = dispo;
                dispo = atual;
                lista[dispo].proximo = temp;

                atual = lista[anterior].proximo;
            } else {
                anterior = atual;
                atual = lista[atual].proximo;
            }
        }
    }



    int main() {
        inicializar();
        
        int opcao, valor, Vi, Vf;

        do {
            printf("\nMenu:\n");
            printf("1. Inserir numero\n");
            printf("2. Eliminar numeros entre Vi e Vf\n");
            printf("3. Exibir lista\n");
            printf("0. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                    printf("Digite o numero para inserir: ");
                    scanf("%d", &valor);
                    inserir(valor);
                    break;
                case 2:
                    printf("Digite Vi e Vf (Vi < Vf): ");
                    scanf("%d %d", &Vi, &Vf);
                    eliminar(Vi, Vf);
                    break;
                case 3:
                    printf("Lista: ");
                    int atual = L;
                    while(atual != -1) {
                        printf("%d ", lista[atual].info);
                        atual = lista[atual].proximo;
                    }
                    printf("\n");
                    break;
                case 0:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida\n");
            }

        } while(opcao != 0);

        return 0;
    }