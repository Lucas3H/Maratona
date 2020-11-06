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

vector<int> adj[MAXN];
int dist[MAXN], processado[MAXN];
int maior;

void bfs(int V){
	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, V));

	while(true){
		int davez = -1;

		while(!fila.empty()){
			if(!processado[fila.top().second]){
				davez = fila.top().second;
				maior = davez;

				fila.pop();
				processado[davez] = 1;
				break;
			}
			else fila.pop();
		}

		if(davez == -1) break;

		fr(i, adj[davez].size()){
			int v = adj[davez][i];

			if(!processado[v]){
				dist[v] = dist[davez] + 1;
				fila.push(mp(dist[v], v));
			}
		}
	}
}

int main(){
	int n;
	cin >> n;

	fr(i, n-1){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	mem(dist, -1);
	mem(processado, 0);

	dist[1] = 0;
	bfs(1);

	mem(dist, -1);
	mem(processado, 0);

	dist[maior] = 0;
	bfs(maior);

	int greatest_path = 0;
	frr(i, n){
		if(dist[i] > greatest_path) greatest_path = dist[i];
	}

	cout << greatest_path << endl;

	return 0;
}