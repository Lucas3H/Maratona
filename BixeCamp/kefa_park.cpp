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

int n, m;
int cat[MAXN], processado[MAXN];
vector<int> adj[MAXN];
int resp = 0;	

void dfs(int v, int gatos){
	processado[v] = 1;
	
	if(cat[v] == 0) gatos = 0;
	else gatos++;

	if(gatos > m) return;

	if(adj[v].size() == 1 && v != 1) resp++;


	fr(i, adj[v].size()){
		int e = adj[v][i];

		if(processado[e] == -1){
			dfs(e, gatos);
		}
	}
}

int main(){
	cin >> n >> m;

	frr(i, n) cin >> cat[i];

	fr(i, n-1){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	mem(processado, -1);

	dfs(1, 0);

	cout << resp << endl;
}
