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

#define MAXN 500010

int processado[MAXN], componente[MAXN], qtd[MAXN];
vector<int> adj[MAXN];

void dfs(int x, int c){
	processado[x] = 1;
	componente[x] = c;
	fr(i, adj[x].size()){
		int e = adj[x][i];

		if(!processado[e]){
			dfs(e, c);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int k;
		cin >> k;

		int ant, atu;
		if(k > 0) cin >> ant;

		fr(i, k - 1){
			cin >> atu;
			adj[ant].pb(atu);
			adj[atu].pb(ant);
			ant = atu;
		}
	}

	int r = 0;
	frr(i, n){
		if(!processado[i]){
			dfs(i, r);
			r++;
		}
	}

	mem(qtd, 0);
	frr(i, n){
		//cout << componente[i] << " ";

		qtd[componente[i]]++;
	}

	frr(i, n){
		cout << qtd[componente[i]] << " ";
	}

	cout << endl;
}