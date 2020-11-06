#include<bits/stdc++.h>

using namespace std;

int main(){
	int A, B;
	cin >> A >> B;

	set<int> a, b;
	for(int i = 0; i < A; i++){
		int x;
		cin >> x;
		a.insert(x);
	}

	for(int i = 0; i < B; i++){
		int x;
		cin >> x;
		b.insert(x);
	}

	int iguais = 0;
	for (set<int>::iterator it=a.begin(); it!=a.end(); ++it){
		if(b.find(*it) != b.end()) iguais++;
	} 

	cout << min(a.size(), b.size()) - iguais << endl;

	return 0;
}