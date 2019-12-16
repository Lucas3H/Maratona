#include <iostream>
using namespace std;

int linhas[1000], colunas[1000], m[1000][1000];
int n;

int main(){	
	cin >> n;
	
	for(int i=0; i < n; i++){
		linhas[i] = 0;
		for(int j=0; j < n; j++){
			cin >> m[i][j];
			linhas[i]+=m[i][j];
		}
	}
	
	for(int i=0; i < n; i++){
		colunas[i] = 0;
		for(int j=0; j < n; j++){
			colunas[i]+=m[j][i];
		}
	}
	
	int max = 0;
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			if(max < linhas[i]+colunas[j]-2*m[i][j]) {
				max = linhas[i]+colunas[j]-2*m[i][j];
			}
		}
	}
	
	cout << max << endl;
	
	return 0;
}
