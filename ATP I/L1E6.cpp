#include "h.h"

int main () {
    int a,b,c,d,e,f,g,h,i,x,y,dv1,dv2,p1,p3;

    cout<<"Digite seu CPF completo separando os numeros por espaco: ";
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>x>>y;

    p1= a*10 + b*9 + c*8 + d*7 + e*6 + f*5 + g*4 + h*3 + i*2;
    cout<<"\nA soma do passo 1 eh: "<<p1;

    if(p1%11<2) {
        dv1=0;
    }
    else {
        dv1=11-p1%11;
    }
    cout<<"\nO primeiro digito de validacao eh: "<<dv1;

    p3= a*11 + b*10 + c*9 + d*8 + e*7 + f*6 + g*5 + h*4 + i*3 + dv1*2;
    cout<<"\nA soma do passo 3 eh: "<<p3;

     if(p3%11<2) {
        dv2=0;
    }
    else {
        dv2=11-p3%11;
    }
    cout<<"\nO segundo digito de validacao eh: "<<dv2;

    if (dv1==x && dv2==y) {
        cout<<"\nValidade: S";
    }
    else {
        cout<<"\nValidade: N";
    }

    return 0;
}