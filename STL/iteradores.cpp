#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v;

	for(int i = 0; i < 10; i++) v.push_back(i);

	// Iteradores:  eh tipo uma abstracao de um ponteiro.
	 
	//Não é o melhor jeito para se declarar o iterador, mas é mais curto:
	auto it = v.begin();

	while(it < v.end()){
		cout << *it << " ";
		it += 2;
	}

	return 0;
}