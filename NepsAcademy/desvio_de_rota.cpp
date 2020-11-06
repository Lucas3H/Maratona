#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 1000100

int n, m, c, k;
int dist[251], processado[251], dist_c[251];
vector<pii> v[251];

void Dijk(int S){
	dist[S] = 0;
	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, S));
	int davez = -1;

	while(davez != c-1){
		davez = -1;

		while(!fila.empty()){
			if(!processado[fila.top().second]){
				davez = fila.top().second;
				processado[davez] = 1;
				break;
			}
			else fila.pop();
		}

		if(davez == -1) break;

		for(int i = 0; i < v[davez].size(); i++){
			int d = v[davez][i].first, y = v[davez][i].second;

			if(dist[y] > dist[davez] + d && davez >= c){
				dist[y] = dist[davez] + d;

				fila.push(mp(dist[y], y));
			}
		}
	}
}

int u, t, p;
int main(){
	cin >> n >> m >> c >> k;

	while(n != 0 || m != 0 || c != 0 || k != 0){
		memset(processado, 0, sizeof(processado));
		fr(i, n) dist[i] = MAXN;
		fr(i, n) v[i].clear();

		fr(i, m){
			cin >> u >> t >> p;
			v[u].pb(mp(p, t));
			v[t].pb(mp(p, u));
		}

		int distancia = 0;

		for(int i = c-1; i > 0; i--){
			dist_c[i] = distancia;
			int j = 0;
			while(v[i][j].second != i-1) j++;

			distancia += v[i][j].first;
		}
		dist_c[0] = distancia;

		Dijk(k);

		int mi = 2*MAXN;
		fr(i, c){
			if(mi > dist_c[i] + dist[i]) mi = dist_c[i] + dist[i];
		}

		cout << mi << endl;

		cin >> n >> m >> c >> k;

	}
}
