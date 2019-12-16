#include <iostream>
using namespace std;

int main(){
	int casos_teste, linhas, colunas;
	
	cin >> casos_teste;
	
	for(int i=0; i < casos_teste; i++){
		char m[51][51];
		cin >> linhas >> colunas;
		
		int uns = 0;
		
		for(int j=0; j < linhas; j++){
			for(int k=0; k < colunas; k++) {
				cin >> m[j][k];
				
				if(m[j][k] == '1') uns++;
			}
		}
		
		if(uns < 2*linhas + 2*colunas - 4) cout << -1 << endl;
		
		else
		{
			int resp = 0;
			for(int j = 1; j < colunas - 1; j++){
				if(m[0][j] == '1') resp++;
				if(m[linhas-1][j] == '1') resp++; 
			}
			
			for(int j = 1; j < linhas - 1; j++){
				if(m[j][0] == '1') resp++;
				if(m[j][colunas-1] == '1') resp++;
			}
			
			if(m[0][0] == '1') resp++;
			if(m[0][colunas-1] == '1') resp++;
			if(m[linhas-1][0] == '1') resp++;
			if(m[linhas-1][colunas-1] == '1') resp++;
			
			cout<< 2*linhas + 2*colunas - 4 - resp << endl;
		}
	}
	
	return 0;
}
