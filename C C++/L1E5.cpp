#include "h.h"

int main () {
    int total=1, raiz, soma=1, impar=1;

    cout<<"Digite um número: ";
    cin>>raiz;

    while (soma<raiz) {
        if (raiz<0) {
        cout<<"Numero invalido, tente novamente";
        }
        else {
            if (raiz==0) {
                cout<<0;
            }
            else {
                impar+=2;
                soma+=impar;
                total+=1;
            }
        }
    }
    cout<<"A raiz superior mais proxima eh: "<<total;

    return 0;
}
