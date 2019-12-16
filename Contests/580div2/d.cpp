#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000009

vector<int> adj[MAXN + 70];
int processado[MAXN + 70];
int dist[MAXN + 70]
int n, ans = MAXN;
ll a[MAXN];


void bits(ll k, int ind){
	int i = 0;

	while(k > 0){
		if(k%2 == 1){
			adj[i + n].pb(ind);
			adj[ind].pb(i + n);
		}
		i++;
		k/=2;
	}
}

void bfs(int v){
	pq<pii> fila;
	fila.push(mp(0, v));

	while(true){
		int davez = -1;

		while(fila.empty()){
			int u = fila.top().f;

			if(!processado[u]){
				davez = u;
				processado[u] = 1;
				dist[u] = fila.top().f;

				break;
			}

			fila.pop();
		}

		if(davez == -1) break;

		fr(i, adj[davez].size()){
			int u = adj[davez][i];

			if(processado[u] == 0){
				fila.push(dist[davez] + 1, u);
			}
			else{
				if(dist)
			}
		}
	}
}

int main(){
	cin >> n;
	fr(i, n) {
		cin >> a[i];
		bits(a[i], i);
	}
/*
	fr(i, n + 10){
		cout << i << " ";
		fr(j, adj[i].size()) cout << adj[i][j] << " ";
		cout << endl;
	}
*/
	fr(i, n + 67){
		if(processado[i] == 0) bfs(i);
	}

	for(int i = n; i < n + 67; i++) if(adj[i].size() >= 3) ans = 3;

	if(ans == MAXN) cout << -1 << endl;
	else cout << ans << endl;
}
