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

#define MAXN 101

int n, arestas;

int dist[MAXN];
vector<pii> adj[MAXN];
int maior = 0, resp = 100000;
void bfs(int v){
	pq<pii, vector<pii>, greater<pii>> fila;

	fila.push(mp(0, v));

	while(true){

		if(fila.empty()) break;

		int D = fila.top().first;
		int davez = fila.top().second;
		fila.pop();

		if(dist[davez] != -1) continue;
		dist[davez] = D;
		maior = D;

		fr(i, adj[davez].size()){
			int e = adj[davez][i].second, u = adj[davez][i].first;

			if(dist[u] == -1){
				fila.push(mp(dist[davez] + e, u));
			}
		}
	}
}

int main(){
	cin >> n >> arestas;

	fr(i, arestas){
		int u, v, e;
		cin >> u >> v >> e;

		adj[u].pb(mp(v, e));
		adj[v].pb(mp(u, e));
	}

	fr(i, n){
		mem(dist, -1);
		bfs(i);
		
		if(maior < resp) {
			resp = maior;
		}
	}

	cout << resp << endl;

}