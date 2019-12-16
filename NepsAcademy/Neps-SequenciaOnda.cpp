#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int cres[100010], decres[100010], onda[100010], n;

void lis(){
	vector<int> pilha;

	pilha.pb(onda[0]);
	cres[0] = pilha.size();

	for(int i = 1; i < n; i++){
		int ini = 0, fim = pilha.size() - 1, meio, j = 0;

		meio = (ini + fim)/2;

		while(ini <= fim && j < 30){
			if(pilha[meio] < onda[i]) ini = meio + 1;
			else fim = meio;

			meio = (ini + fim)/2;
			j++;
		}

		if(ini == pilha.size()){
			pilha.pb(onda[i]);
			cres[i] = pilha.size();
		}
		else{
			pilha[ini] = onda[i];
			cres[i] = ini + 1;
		}
	}
}

void lds(){
	vector<int> pilha;

	pilha.pb(onda[n-1]);
	decres[n-1] = pilha.size();

	for(int i = n-2; i >= 0; i--){
		int ini = 0, fim = pilha.size() - 1, meio, j = 0;

		meio = (ini + fim)/2;

		while(ini <= fim && j < 30){
			if(pilha[meio] < onda[i]) ini = meio + 1;
			else fim = meio;

			meio = (ini + fim)/2;
			j++;
		}

		if(ini == pilha.size()){
			pilha.pb(onda[i]);
			decres[i] = pilha.size();
		}
		else{
			pilha[ini] = onda[i];
			decres[i] = ini + 1;
		}
	}
}

int main(){
	cin >> n;

	for(int i = 0; i < n; i++) cin >> onda[i];

	lis();
	lds();

	int max = 0;

	for(int i = 0; i < n; i++){
		if(min(cres[i], decres[i]) > max) max = min(cres[i], decres[i]);
	}

	cout << 2*max - 1 << endl;

	return 0;
}