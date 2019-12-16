#include <bits/stdc++.h>

using namespace std;

int main(){
	int m;
	long long a[100010], b[100010];
	
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> a[i];
		b[m-1-i] = a[i];
	} 
	
	int e[100010], s[100010];
	
	vector<long long> pilha1;
	
	for(int i = 0; i < m; i++){
		
		vector<long long>::iterator it = lower_bound(pilha1.begin(), pilha1.end(), a[i]);
		
		if(it == pilha1.end()) pilha1.push_back(a[i]);
		else *it = a[i];
		
		e[i] = pilha1.size();
	}
	
	vector<long long> pilha2;
	
	for(int i = 0; i < m; i++){
		
		vector<long long>::iterator it = lower_bound(pilha2.begin(), pilha2.end(), b[i]);
		
		if(it == pilha1.end()) pilha1.push_back(b[i]);
		else *it = b[i];
		
		s[m-1-i] = pilha2.size();
	}
	
	int maior = 0;
	
	for(int i = 0; i < m; i++){
		if(min(e[i], s[i]) > maior) maior = min(e[i], s[i]);
	}
	
	cout << 2*maior + 1 << endl;
	
	return 0;
}
