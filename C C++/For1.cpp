#include <iostream>
using namespace std;
//faltou a intersecção e a união dos conjuntos
int main() {
	int n,k1,k2;
	cout<<"Insira o numero de termos do conjunto A: ";
	cin>>k1;
	cout<<"Insira o numero de termos do conjunto B: ";
	cin>>k2;
	int a[k1],b[k2];
	cout<<"\n";
	
	for(n=0;n<k1;n+=1) {
		cout<<"Insira o #"<<n+1<<" termo do conjunto A: ";
		cin>>a[n];
		}
	cout<<"\n";
	for(n=0;n<k2;n+=1) {
		cout<<"Insira o #"<<n+1<<" termo do conjunto B: ";
		cin>>b[n];
		}
	
	cout<<"\nO conjunto A: ( ";
	for(n=0;n<k1;n+=1) {
		cout<<a[n]<<" ";
	}
	cout<<")";
	
	cout<<"\nO conjunto B: ( ";
	for(n=0;n<k2;n+=1) {
		cout<<b[n]<<" ";
	}
	cout<<")";
	
	//continuar aqui
	
	return 0;
}
