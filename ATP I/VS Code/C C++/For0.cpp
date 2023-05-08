#include <iostream>
using namespace std;

int main() {
	int x,n,k;
	cout<<"Insira o numero de termos do conjunto: ";
	cin>>k;
	int a[k];
	cout<<"\n";
	
		for(n=0;n<k;n+=1) {
			cout<<"Insira o #"<<n+1<<" termo da lista: ";
			cin>>a[n];
		}
		
		cout<<"\n";
		cout<<"Insira o elemento a ser testado: ";
		cin>>x;
		cout<<"\n";
		
		for(n=0;n<k;n+=1) {
			if(x==a[n]) {
				cout<<"O elemento pertence ao conjunto";
				break;
			}
			else {
				if(n==k-1) {
				cout<<"O elemento nao pertence ao conjunto";
				}
			}
		}
	return 0;
}
