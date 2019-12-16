#include<iostream>
#include<algorithm>
using namespace std;

struct Pais{
	int ouro;
	int prata;
	int bronze;
	int numero;
};

bool ordenacao(Pais a, Pais b){
	if(a.ouro!=b.ouro){
		return a.ouro>b.ouro;
	}
	else if(a.prata!=b.prata && a.ouro==b.ouro){
		return a.prata>b.prata;
	}
	else if(a.bronze!=b.bronze && a.ouro==b.ouro && a.prata==b.prata){
		return a.bronze>b.bronze;
	}
	else if(a.bronze==b.bronze && a.ouro==b.ouro && a.prata==b.prata){
		return a.numero<b.numero;
	}
}

int main(){
	int paises, modalidades;
	Pais P[100];
	cin>>paises>>modalidades;
	
	for(int i=0; i<paises; i++){
		P[i].numero = i+1;
		P[i].ouro=0;
		P[i].prata=0;
		P[i].bronze=0;
	}
	
	for(int i=0; i<modalidades; i++){
		int o, p, b;
		cin>>o>>p>>b;
		
		P[o-1].ouro++;
		P[p-1].prata++;
		P[b-1].bronze++;
	}

	sort(P, P+paises, ordenacao);
	
	for(int i=0; i<paises; i++){
		cout<<P[i].numero<<" ";
	}
	
	cout<<"\n";
	return 0;
}
