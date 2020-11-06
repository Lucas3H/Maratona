#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 200010

vector<pii> adj[MAXN];
int cor[MAXN];
pii edges[MAXN];
int deu = 1;

void dfs(int v, int color){
	cor[v] = (color+1)%2;

	fr(i, adj[v].size()){
		int u = adj[v][i].first;

		if(cor[u] == cor[v]) deu = 0;

		if(cor[u] == -1){
			dfs(u, cor[v]);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	fr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		edges[i] = mp(v1, v2);

		adj[v1].pb(mp(v2, 0));
		adj[v2].pb(mp(v1, 1));
	}

	mem(cor, -1);

	dfs(1, 0);

	if(deu){
		cout << "YES" << endl;
		
		fr(i, m){
			int v1 = edges[i].first, v2 = edges[i].second;

			if(cor[v1] == 0) cout << 1;
			else cout << 0;
		}

		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}
}