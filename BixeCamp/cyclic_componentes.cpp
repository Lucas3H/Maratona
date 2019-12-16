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

#define MAXN 200010

int n, m;
int componente[MAXN];
vector<int> adj[MAXN];

int dfs(int v, int ok){
	if(adj[v].size() != 2) ok = 0;

	fr(i, adj[v].size()){
		int e = adj[v][i];

		if(componente[e] == -1){
			componente[e] = componente[v];
		
			ok *= dfs(e, ok);
		}
	}

	return ok;
}

int main(){
	cin >> n >> m;

	fr(i, m){
		int v1, v2;
		cin >> v1>> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	mem(componente, -1);
	
	int resp = 0;

	frr(i, n){
		if(componente[i] == -1){
			componente[i] = i;
			if(dfs(i, 1)) resp++; 
		}
	}

	cout <<resp << endl;
}
