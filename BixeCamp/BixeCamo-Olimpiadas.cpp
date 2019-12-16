#include<iostream>
#include<algorithm>

using namespace std;

struct Pais{
	int ouro=0;
	int prata=0;
	int bronze=0;
	int numero;
};

bool ordenacao(Pais A, Pais B){
	if(A.ouro!=B.ouro) return A.ouro > B.ouro;
	else if(A.prata!=B.prata) return A.prata > B.prata;
	else if(A.bronze!=B.bronze) return A.bronze > B.bronze;
	else return A.numero < B.numero;
}

int main(){
	int paises, modalidades;
	cin >> paises >> modalidades;
	
	Pais p[101];
	for(int i=0; i<paises; i++){
		p[i].numero=i+1;
	}
	
	for(int i=0; i<modalidades; i++){
		int o, pr, b;
		
		cin >> o >> pr >> b;
		
		p[o-1].ouro++;
		p[pr-1].prata++;
		p[b-1].bronze++;
	}
	
	sort(p, p+paises, ordenacao);
	
	for(int i=0; i<paises; i++) cout << p[i].numero << " ";
	
	return 0; 
}
