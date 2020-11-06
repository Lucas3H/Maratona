#include <bits/stdc++.h>

using namespace std;

int main(){
	string linha;
	int linhas;
	queue<char> chaves;

	cin >> linhas;

	int balanceado = 1;
	for(int i = 0; i <= linhas; i++){
		getline(cin, linha);

		for(int j = 0; j < linha.size(); j++){
			if(linha[j] == '{') chaves.push('{');
			else if(linha[j] == '}' && !chaves.empty()) chaves.pop();
			else if(linha[j] == '}' && chaves.empty()){
				balanceado = 0;
				break;
			}
		}
	}

	if(!chaves.empty()) balanceado = 0;

	if(balanceado) cout << "S" << endl;
	else cout << "N" << endl;

	return 0;
}