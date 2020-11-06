#include<bits/stdc++.h>

using namespace std;

int main(){
	// Estrutura de dados que associa chave a valor.
	map<int, string> m;

	// Colocar um elemento no map:
	m[1] = "olaaa";
	m[10] = "xau";
	m[100] = "naooo";

	// achar um elemento:
	auto it = m.find(10);
	cout << (*it).first << " " << (*it).second << endl;

	// tem as funcoes lower_bound, upper_bound, count, find e etc;

}