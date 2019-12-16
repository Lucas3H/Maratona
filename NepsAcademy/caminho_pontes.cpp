#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mp make_pair
#define pq priority_queue

#define ll long long

#define mem(v, k) memset(v, k, sizeof(v))

#define MAXN 1000000000

int processado[1010], dist[1010];
vector<pii> v[1010];
int n, m;

void Dijk(int S){
	pq<pii, vector<pii>, greater<pii>> fila;
	dist[S] = 0;
	fila.push(mp(0, S));

	while(true){
		int davez = -1;

		while(!fila.empty()){
			if(!processado[fila.top().second]){
				davez = fila.top().second;
				fila.pop();
				processado[davez] = 1;

				break;
			}
			else fila.pop();
		}

		if(davez == -1) break;

		for(int i = 0; i < v[davez].size(); i++){
			int d = v[davez][i].first, y = v[davez][i].second;

			if(dist[y] > dist[davez] + d){
				dist[y] = dist[davez] + d;
				fila.push(mp(dist[y], y)); 
			}
		}
	}

}

int main(){
	cin >> n >> m;

	mem(processado, 0);
	fr(i, n+2) dist[i] = MAXN;

	int s, t, d;
	fr(i, m){
		cin >> s >> t >> d;
		v[s].pb(mp(d, t));
		v[t].pb(mp(d, s));
	}

	Dijk(0);

	cout << dist[n+1] << endl;
}
