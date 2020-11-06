#include<bits/stdc++.h>

using namespace std;

int main(){

	deque<int> d;

	d.push_front(1);
	d.push_front(2);
	d.push_back(3);
	d.pop_front();
	d.pop_back();

	cout << d[0] << d[1] << d[2] << endl;

	stack<int> st;	// top() eh o ultimo	
	queue<int> fl; // top() eh o primeiro

	// priority_queue

	// Do maior para o menor
	priority_queue<int> pq1 

	// Do menor para o maior;
	priority_queue<int, vector<int>, greater<int>> pq2;

	// Iteradores:  eh tipo uma abstracao de um ponteiro
	// jeito mais certo , mas mais longom é 
	auto it = v.end();

	cout << *it;

	it += 2;

	cout << *it << endl;

	// set

	set<int> s;

	s.insert(1);
	s.insert(2);
	s.insert(1);

	auto it = s.begin();

	while(it != s.end()){
		cout << *it << endl;
		it++;
	}

	// remover
	s.erase(5);
	s.erase(s.begin());

	//Passar por todos os elementos de set:
	for(auto x : s){
		cout << *x << endl;
	}

	// Achar um elemento:
	cout << s.count(3) << "\n";

	// Retornar o iterador do elemento, se  tiver:
	cout << s.find(3) << "\n";

	// Achar o primeiro elemento maior ou igual que:
	it = s.lower_bound(5);

	// Achar o primeiro elemento estritamente maior que:
	it = s.upper_bound(5);

	// Da para fazer um multi-set (que pode ter elementos repetidos)
	multiset<int> ms;

	// map -> associa chave ao valor:

	map<int, string> m;

	m[3] = 'oie';
	m[1] = 'tchau';
	m[3] = '123';

	// achar um elemento:
	auto it1 = m.find(8);
	cout << (*it1).first << " " << (*it1).second << endl;
	// tem as funcoes lower_bound, upper_bound, count e etc;

	// tuple
	tuple<int, int, string, double> t(1, 2, "oi", 3.14);

	cout << get<2>(t1) << endl;

	int a, b;
	string s;
	double d;

	tie(a, b, s, d) = t1;
	tie(a, b, s, ignore) = t2;

	// sort decrescente;
	sort(v.rbegin(), v.rend());

	// Achar o maior elemento:
	auto it = max_element(v.begin(), v.end());

	// Busca binaria usando lower bound usa somente vector e deque

	// Eliminar os elementos de um vector:
	vector<int> v = {1, 2, 3, 4};
	v.erase(v.begin()+1, v.begin()+3);

	for(int x : v) cout << x << endl;



	// Unique
	vector<int> u = {1, 2, 3 ,4, 1, 2};

	sort(u.begin(), u.end());

	auto it2 = unique(u.begin(), u.end()); // retorna o iterador para o primeiro elemento que nao eh unico

	for(int x : u) cout << x << endl;
	u.erase(it2, u.end());



	// Permutacoes de um vetor;
	// Essa funcao muda os elementos de v:

	vector<int> h = {4, 1, 2, 3, 8};

	next_permutation(begin(v), end(v));

	for(int x : v) cout << x << " ";
	cout << "\n";
}
