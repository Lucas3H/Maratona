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
vector<pii> adj[MAXN];
int dist[MAXN], processado[MAXN], pai[MAXN];

void bfs(int V){
	pq<pair<int, pii>> fila;
	fila.push(mp(0, mp(V, 0)));

	while(true){
		int davez = -1;

		while(!fila.empty()){
			int atual = fila.top().second.first;

			if(!processado[atual]){
				pai[atual] = fila.top().second.second;
				dist[atual] = -fila.top().first;
				davez = atual;
				processado[davez] = 1;
	
				break;
			}
		
			fila.pop();	
		}

		if(davez == -1) break;

		fr(i, adj[davez].size()){
			int e = adj[davez][i].second, v = adj[davez][i].first;
			
			if(!processado[v]){
				pai[v] = davez;
				fila.push(mp(-dist[davez] - e, mp(v, davez)));
			}
		}
	}
}

int main(){
	cin >> n >> m;

	fr(i, m){
		int v1, v2, e;
		cin >> v1 >> v2 >> e;

		adj[v1].pb(mp(v2, e));
		adj[v2].pb(mp(v1, e));
	}

	mem(pai, 0);
	mem(dist, -1);
	mem(processado,0);

	bfs(1);

	vector<int> resp;
	int ind = n;

	if(dist[n] != -1){
		
		while(pai[ind] != 0){
			resp.pb(ind);
			ind = pai[ind];
		}
		resp.pb(1);

		frm(i, resp.size()){
			cout << resp[i] << " ";
		}

	}
	else{
		cout << -1 << endl;
	}
	

	return 0;
}