#include <iostream>

#define MAXN 1000000001

using namespace std;

int numero_de_faixas, numero_de_ogros;
int faixa[100010], ogro[100010], premiacao[100010];


int prem(int forca){
	int ini = 0, fim = numero_de_faixas, meio;
	
	while(ini < fim){
		meio = (ini + fim)/2;
		
		if(forca >= faixa[meio] && forca <faixa[meio+1]) return premiacao[meio];
		
		if(forca < faixa[meio]) fim = meio;
		
		if(forca >= faixa[meio + 1]) ini = meio + 1;
	}
}

int main(){
		
	cin >> numero_de_faixas >> numero_de_ogros;
	
	faixa[0] = 0;
	faixa[numero_de_faixas] = MAXN;
	
	for(int i = 1; i < numero_de_faixas; i++) cin >> faixa[i];
	
	for(int i = 0; i < numero_de_faixas; i++) cin >> premiacao[i];
	
	for(int i = 0; i < numero_de_ogros; i++) cin >> ogro[i];
	
	for(int i = 0; i < numero_de_ogros; i++) cout << prem(ogro[i]) << " ";
	
	cout << endl;
	
	return 0;
}
