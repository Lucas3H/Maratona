#include<bits/stdc++.h>

using namespace std;

int main(){
	//Deque é uma generalizacao de stack e queue. posso tanto adicionar elementos no comeco como no fim.
	//
	deque<int> d;

	d.push_front(2);
	d.push_front(1);
	d.push_back(3);
	d.push_back(4);
	d.push_front(0);
	d.push_back(5);
	d.push_back(6);
	d.pop_front();
	d.pop_back();

	cout << d[0] << " " << d[1] << " " << d[2] << endl;
	cout << d.front() << " " << d.back() << endl;


	// Funcao insert:
	// Considere que terá dois parametros: a posicao e o valor inserido.
	auto it = d.begin() + 2;

	d.insert(it, 10); // 

	cout << d[2] << endl; // printa 10

	//Funcao erase:
	//Posso apagar tanto um elmento:
	
	d.erase(d.begin() + 2);

	cout << d[2] << endl;

	//Como um intervalo de elementos:
	
	d.erase(d.begin(), d.begin()+2);

	cout << d[0] << " " << d[1] << " " << d[2] << endl;

	//Funcao swap:
	//Troca dois deques:
	
	deque<int> d1, d2;

	for(int i = 0; i < 4; i++) d1.push_back(i);
	for(int i = 4; i < 10; i++) d2.push_front(i);

	d1.swap(d2);

	for(auto it = d1.begin(); it != d1.end(); it++){
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}