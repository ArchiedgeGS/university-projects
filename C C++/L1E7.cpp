#include "h.h"

int main () {
    int x,y,n;

    cout<<"Digite o limite inferior e o superior separados por espaco: ";
    cin>>x>>y;

    if (x<y) {
        if (x%2==0) {
            n=x+1;
        }
        else {
            n=x;
        }

        while (n<=y) {
            cout<<n<<" ";
            n+=2;
        }
    }
    else {
        cout<<"Erro: o segundo numero deve ser maior do que o primeiro!";
    }
    return 0;
}