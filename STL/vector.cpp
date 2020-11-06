#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v;
	for(int i = 0; i < 4; i++) v.push_back(2*i);

	v.push_back(10);
	v.push_back(-1);
	v.push_back(12);
	v.push_back(0);

	// Printar mais rapidamente os elementos de v:
	for(auto x : v) cout << x << " ";

	cout << endl;

	//Sort decrescente:
	sort(v.rbegin(), v.rend());

	for(auto x : v) cout << x << " ";
	cout << endl;

	// Maior elemento em um intervalo:
	
	auto it = max_element(v.begin(), v.end());
	cout << *it << endl;


	// Proxima permutacao de um elemento em sua ordem lexicografica:
	cout << "Permutacao:" << endl;
	vector<int> h = {4, 1, 2, 3, 8};

	next_permutation(h.begin(), h.end());

	for(int x : h) cout << x << " ";
	cout << "\n";

	// Unique
	cout << "Unique:\n"; 
	vector<int> u = {1, 2, 3 ,4, 1, 2};

	sort(u.begin(), u.end());

	auto it2 = unique(u.begin(), u.end()); // retorna o iterador para o primeiro elemento que nao eh unico

	for(int x : u) cout << x << " ";
	cout << endl;
	u.erase(it2, u.end());

	for(int x : u) cout << x << " ";
	cout << endl;
}