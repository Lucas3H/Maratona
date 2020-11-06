#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	int t, n, m, q;
	int ini, fim;
	
	cin >> t;
	while(t--){

		cin >> n >> m >> q;

		vector<pii> V;

		fr(i, n){
			cin >> ini >> fim;
			V.pb(mp(ini, fim));
		}

		sort(V.begin(), V.end());

		vector<pair<int, pii>> v;
		
		v.pb(mp(V[0].first-1, mp(1, V[0].first - 1)));
		
		for(int i = 1; i < n; i++){
			v.pb(mp(V[i].first - V[i-1].second - 1, mp(V[i-1].second + 1, V[i].first - 1)));
		}

		v.pb(mp(m - V[n-1].second, mp(V[n-1].second + 1, m)));

		stack<pair<int, pii>> a;

		fr(i, v.size()){
			while(a.size() > 0 && a.top().first <= v[i].first) a.pop();
			a.push(v[i]);
		}

		vector<pair<int, pii>> bb;

		while(a.size() > 0){
			bb.pb(a.top());
			a.pop();
		}

		fr(i, q){
			int tam;
			cin >> tam;

			int meio;
			ini = 0;
			fim = bb.size()-1;

			if(bb[fim].first < tam) cout << -1 << " " << -1 << endl;
 
			else {
				while(ini <= fim){
					meio = (ini+fim)/2;

					if(bb[meio].first == tam) break;
					else if(bb[meio].first > tam) fim = meio - 1;
					else ini = meio + 1;
				}

				cout << bb[meio].second.second - tam + 1 << ' ' << bb[meio].second.second << endl;		
			}
		}
	} 
3
	return 0;
}