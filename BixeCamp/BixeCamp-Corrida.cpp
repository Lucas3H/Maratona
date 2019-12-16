#include <iostream>
#include <algorithm>
using namespace std;

struct Carros{
	int numero;
	int tempo;
};

bool ordenacao(Carros A, Carros B){
	return A.tempo < B.tempo;
}

int main(){
	int voltas, carros;
	cin >> carros >> voltas;
	
	Carros carro[110];
	for(int i=0; i<carros; i++){
		carro[i].numero = i+1;
		carro[i].tempo = 0;
	}
	
	for(int i=0; i < carros; i++){
		for(int j=0; j < voltas; j++){
			int t;
			cin >> t;
			carro[i].tempo+=t;
		}
	}
	
	sort(carro, carro+carros, ordenacao);
	
	cout << carro[0].numero << "\n" << carro[1].numero << "\n" << carro[2].numero << endl;
	
	return 0;
}
