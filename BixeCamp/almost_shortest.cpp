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

#define MAXN 510

vector<pii> adj[2][MAXN];
int proibida[MAXN][MAXN], processado[2][MAXN], dist[2][MAXN];

void bfs(int V, int id){
	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, V));

	while(true){
		int davez = -1;

		while(!fila.empty()){
			int atual = fila.top().second;

			if(!processado[id][atual]){
				davez = atual;

				processado[id][atual] = 1;
				dist[id][atual] = fila.top().first;

				fila.pop();

				break;
			}

			fila.pop();
		}

		if(davez == -1) break;

		fr(i, adj[id][davez].size()){
			int v = adj[id][davez][i].first, e = adj[id][davez][i].second;

			if(!processado[id][v] && !proibida[v][davez]){
				fila.push(mp(dist[id][davez] + e, v));
			}
		}
	}
}

int main(){
	int n, m;

	cin >> n >> m;

	while(n != 0 || m != 0){
		fr(i, n){
			adj[0][i].clear();
			adj[1][i].clear();
		}

		mem(processado, 0);
		mem(dist, -1);
		mem(proibida, 0);

		int ini, fim;
		cin >> ini >> fim;

		fr(i, m){
			int v1, v2, e;
			cin >> v1 >> v2 >> e;

			adj[0][v1].pb(mp(v2, e));
			adj[1][v2].pb(mp(v1, e));
		}

		dist[0][ini] = 0;
		dist[1][fim] = 0;

		bfs(ini, 0);
		bfs(fim, 1);

		int D = dist[0][fim];

		fr(i, n){
			fr(j, adj[0][i].size()){
				int vizinho = adj[0][i][j].first;
				int tam = adj[0][i][j].second;

				if(dist[0][i] + dist[1][vizinho] + tam == D){
					proibida[i][vizinho] = 1;
					proibida[vizinho][i] = 1;
				}
			}
		}

		mem(processado, 0);
		mem(dist, -1);

		bfs(ini, 0);

		cout << dist[0][fim] << endl;

		cin >> n >> m;
	}
}
