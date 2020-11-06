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

vector<int> adj[MAXN];
vector<int> special;

int dist[2][MAXN], pr[2][MAXN];

void bfs(int v, int ind){
	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, v));

	while(true){
		int davez = -1;

		while(!fila.empty()){
			if(pr[ind][fila.top().s] == 0){
				davez = fila.top().s;
				dist[ind][davez] = fila.top().f;
				pr[ind][fila.top().s] = 1;
				break;
			}	

			fila.pop();
		}

		if(davez == -1) break;

		for(auto x: adj[davez]){
			if(pr[ind][x] == 0){
				fila.push(mp(dist[ind][davez] + 1, x));
			}
		}
	}
}

int is_special[MAXN];

bool comp(int a, int b){
	return dist[0][a] > dist[0][b];
}

int main(){
	ios::sync_with_stdio(false);
	int n, m, k;

	cin >> n >> m >> k;

	frr(i, n) {
		dist[0][i] = MAXN;
		dist[1][i] = MAXN;
	}

	frr(i, k){
		int x;
		cin >> x;

		special.pb(x);
		is_special[x] = 1;
	}

	int deu = 0;

	frr(i, m){
		int u, v;
		cin >> u >> v;

		adj[u].pb(v);
		adj[v].pb(u);

		if(is_special[u]*is_special[v] == 1) deu = 1;
	}

	bfs(1, 0);
	bfs(n, 1);
/*
	frr(i, n){
		cout << dist[0][i] << " " << dist[1][i] << endl;
	}
*/
	int maior1 = special[0];
	int maior2 = special[1];

	int ans = MAXN;

	if(!deu){
		sort(special.begin(), special.end(), comp);

		fr(i, k){
			ans = min(ans, dist[0][special[i]] + dist[1][special[i]]);
		}

		int melhor = 0;
		fr(i, k-1){
			melhor = max(dist[0][special[i+1]] + dist[1][special[i]], melhor);
		}

		//cout << melhor << "     " << ans <<  " " << k << endl;

		ans = min(ans, melhor + 1);
	}

	cout << min(ans, dist[0][n]) << endl;
}
