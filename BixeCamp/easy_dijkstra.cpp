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

#define MAXN 10010

vector<pii> adj[MAXN];
int processado[MAXN], dist[MAXN];

void bfs(int S){
	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, S));

	while(true){
		int davez = -1;

		while(!fila.empty()){
			int atual = fila.top().second;
			if(!processado[atual]){
				davez = atual;
				fila.pop();
				processado[davez] = 1;
				break;
			}
			else fila.pop();
		}

		if(davez == -1) break;

		fr(i, adj[davez].size()){
			int v = adj[davez][i].first;
			int e = adj[davez][i].second;

			if(!processado[v]){
				dist[v] = dist[davez] + e;
				fila.push(mp(dist[v], v));
			}
		}
	}
}

int v, k;

int main(){
	int tests;
	cin >> tests;


	cin >> v >> k;

	while(tests--){
		frr(i, v) adj[i].clear();
		mem(processado, 0);
		mem(dist, -1);

		fr(i, k){
			int a, b, c;

			cin >> a >>  b >> c;

			adj[a].pb(mp(b, c));
			adj[b].pb(mp(a, c));
		}

		int A, B;
		cin >> A >> B;
		dist[A] = 0;

		bfs(A);

		if(dist[B] != -1) cout << dist[B] << endl;
		else cout << "NO" << endl;
		
		cin >> v >> k;
	}

	return 0;
}