#include <bits/stdc++.h>

using namespace std;

vector<int> e[505];

int idade[505];

int busca(int n){
	int min = 1010;
	
	for(int i = 0; i < e[n].size(); i++){
		if(idade[e[n][i]] < min) min = idade[e[n][i]];
	}
	
	return min;
}

int main(){
	int empregados, relacoes, instrucoes;
	
	cin >> empregados >> relacoes >> instrucoes;
	
	idade[0] = 1000;
	for(int i = 1; i <= empregados; i++){
		cin >> idade[i];
		e[i].push_back(0);	
	}
	
	for(int i = 1; i <= relacoes; i++){
		int a, b;
		cin >> a >> b;
		e[b].push_back(a);
		
		for(int j = 0; j < e[a].size(); j++){
			e[b].push_back(e[a][j]);
		}	
	}
	
	for(int i = 0; i < instrucoes; i++){
		char x;
		cin >> x;
		
		if(x == 'T'){
			int a, b;
			cin >> a >> b;
			
			swap(e[a], e[b]);
		}
		
		else{
			int a;
			cin >> a;
			
			cout << busca(a) << endl;
		}
	}
	
	return 0;
}
