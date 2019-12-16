#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n, topo[1000], pilhas = 0;
vector<int> a;

int lis(vector<int> &v){
	
	vector<int> pilha;
	
	for(int i=0; i < v.size(); i++){
		
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
		
		if(it == pilha.end()) pilha.pb(v[i]);
		
		else *it = v[i];
		
	}

	return pilha.size();
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.pb(x);
	}
	
	cout << lis(a) << endl;
}
