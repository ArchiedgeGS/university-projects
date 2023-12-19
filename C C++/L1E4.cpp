#include "h.h"

int main() {
    int n1, n2, t;
    t = 0;
    cout << "Digite dois numeros para multiplicar: ";
    cin >> n1 >> n2;
    
    if (n1==0 || n2==0)
        t=0;
    else
        while (n1 > 0) {
            if (n1 % 2 != 0) {
                t += n2;
            }
            n1 = n1 / 2;
            n2 = n2 * 2;
        }
        cout << "Resultado: " << t;

    return 0;
}