#include<bits/stdc++.h>

#define MAXN 1000010

using namespace std;

#define ll long long

ll n, m, S;
pair<ll, ll> s[MAXN];
ll r[MAXN];
int ini, fim, meio, achei;

int main(){
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		cin >> S;
		s[i] = make_pair(S, i);
	}

	sort(s, s + n);

	vector<int> aux;
	fr(i, n) aux.push_back(s[i]);

	for(int i = 0; i < m; i++) cin >> r[i];

	vector<ll> pilha;

	for(int i = 0; i < m; i++){

		vector<pair<int, int>>::iterator it = lower_bound(aux.begin(), aux.end(), r[i]);

		if((*it) == r[i]){

			ll k = s[meio].second;

			if(pilha.size() == 0){
				pilha.push_back(k);
				continue;
			}
		
			vector<ll>::iterator it0 = lower_bound(pilha.begin(), pilha.end(), k);

			if(it0 == pilha.end()) pilha.push_back(k);
			else (*it0) = k;
		}
	}

	cout << pilha.size() << endl;

	return 0;
}