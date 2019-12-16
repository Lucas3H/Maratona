#include<bits/stdc++.h>

using namespace std;

int main(){
	// É uma estrutura de dados que armazena os elementos em uma determinada ordem:
	priority_queue<int> pq;

	pq.push(0);
	pq.push(-1);
	pq.push(9);
	pq.push(0);
	pq.push(7);
	pq.push(10);

	// Por padrao, a fila esta em ordem decrescente.
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << endl;

	// Para deixar em crescente, tem que mudar a declaracao:
	
	priority_queue<int, vector<int>, greater<int>> pq0;

	pq0.push(0);
	pq0.push(-1);
	pq0.push(9);
	pq0.push(0);
	pq0.push(7);
	pq0.push(10);

	while(!pq0.empty()){
		cout << pq0.top() << " ";
		pq0.pop();
	}	
	
	cout << endl;

	// Tem as funcoes top(), pop(), swap(), empty(), size() que são identicas às de uma queue.
}
