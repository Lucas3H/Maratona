#include<bits/stdc++.h>

using namespace std;

int lis(string s){ 

	vector<int> pilha;
	pilha.push_back(s[0]);

	for(int i=1; i < s.size(); i++){
		
		int ini = 0, fim = pilha.size() - 1, meio, j = 0;

		meio = (ini + fim)/2;

		while(ini <= fim && j < 60) {

			if(pilha[meio] <= int(s[i])) ini = meio + 1;
			else fim = meio;

			meio = (ini+fim)/2;

			j++;
		}

		if(ini == pilha.size()) pilha.push_back(int(s[i]));
		else pilha[ini] = int(s[i]);	
	}

	return pilha.size();
}

int main(){
	string S;
	
	cin >> S;
	
	cout << lis(S) << endl;
}
