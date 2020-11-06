#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, m;
vector<int> adj[MAXN], adj_inv[MAXN];
int dist[MAXN], pr[MAXN], dif_paths[MAXN];
int s, t;

void bfs(int v){
	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, v));

	while(true){
		int davez = -1;

		while(!fila.empty()){
			pii vt = fila.top();
			if(!pr[vt.s]){
				pr[vt.s] = 1;
				dist[vt.s] = vt.f;
				davez = vt.s;
				fila.pop();
				break;
			}

			fila.pop();
		}

		if(davez == -1) break;

		for(auto x: adj[davez]){
			if(!pr[x]){
				fila.push(mp(dist[davez] + 1, x));
			}
		}
	}
}

int main(){
	cin >> n >> m;
	fr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v2].pb(v1);
		adj_inv[v1].pb(v2);
	}

	int path[MAXN];
	int p;
	cin >> p;
	fr(i, p){
		cin >> path[i];
	}

	bfs(path[p-1]);

	frr(i, n){	
		for(auto x: adj_inv[i]){
			if(dist[x] == dist[i] - 1){
				dif_paths[i]++;
			}
		}
	}
/*
	frr(i, n){
		cout << dif_paths[i] << " ";
	}

	cout << endl;
*/
	int minimo = 0, maximo = 0;
	fr(i, p - 1){
		if(dist[path[i]] <= dist[path[i + 1]]){
			minimo++;
			maximo++;
		}
		else if(dif_paths[path[i]] > 1){
			maximo++;
		}
	}

	cout << minimo << " " << maximo << endl;
}
