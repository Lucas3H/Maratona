#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
	int linhas, colunas; 
	long long resp = 0;
	int m[51][51];
	
	cin >> linhas >> colunas;
	
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++) cin >> m[i][j];
	}
	
	for(int i=0; i<linhas; i++){
		int branco = 0, preto = 0;
		
		for(int j=0; j<colunas; j++){
			if(m[i][j] == 0) branco++;
			else preto++;
		}
		resp+=pow(2, branco) + pow(2, preto) - 2;
	}
	
	for(int i=0; i<colunas; i++){
		int branco = 0, preto = 0;
		
		for(int j=0; j<linhas; j++){
			if(m[j][i] == 0) branco++;
			else preto++;
		}
		
		resp+=pow(2, branco) + pow(2, preto) - 2;
	}
	
	cout << resp - linhas*colunas << endl;
	return 0;
}
