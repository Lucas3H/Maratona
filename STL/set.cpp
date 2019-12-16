#include<bits/stdc++.h>

using namespace std;

int main(){
	//Set não possui elementos repetidos, que nem conjunto na matematica.

	// Tem as funcoes empty(), size(), insert(), erase(), swap() como visto anteriormente

	set<int> s;

	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(2);

	// Passar por todos os elementos de um conjunto;
	auto it = s.begin();
	cout << "Printar os elementos de s:\n";
	while(it != s.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// Outro jeito:
	cout << "Outro jeito de printar os elementos de s:\n";	
	for(auto x : s) cout << x << " ";
	cout << endl;

	// Remover um elemento:
	s.erase(s.begin());
	s.erase(4);

	cout << "s após a deleção do primeiro elemento e o elemento 4:\n";
	for(auto x : s) cout << x << " ";
	cout << endl;

	for(int i = 0; i < 10; i++) s.insert(i);

	cout << "s agora:\n";
	for(auto x : s) cout << x << " ";
	cout << endl;

	// Achar um elemento:
	cout << "O elemento 3 está no conjunto?: "<< int(s.count(3)) << "\n";
	cout << "O elemento 11 está no conjunto?: "<< int(s.count(11)) << "\n";

	// Retornar o iterador do elemento, se tiver:
	cout << "A posicao do elmento 3 é(se não tiver é s.end()): " << *s.find(3) << "\n";
	cout << "A posicao do elmento 11 é(se não tiver é s.end()): " << *s.find(11) << "\n";

	// Achar o primeiro elemento maior ou igual que:
	it = s.lower_bound(5);
	cout << "O primeiro elemento maior ou igual a 5 é " << *it << endl;

	// Achar o primeiro elemento estritamente maior que:
	it = s.upper_bound(5);
	cout << "O primeiro elemento maior que 5 é " << *it << endl;


	// Da para fazer um multi-set (que pode ter elementos repetidos)
	multiset<int> ms;

	for(int i = 0; i < 4; i++) ms.insert(i);
	for(int i = 0; i < 4; i++) ms.insert(i);

	cout << "multiset\n";
	it = ms.begin();
	while(it != ms.end()){
		cout << *it << " ";
		it++;
	}

	cout << endl;

	return 0;
}
