#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1e18+1

ll dist[1010][1010];
ll n, k, m;
ll ini[1010], fim[1010], u[1010];

class Graph{
	public:
		vector<pii> adj[1010];

		void dijkstra(ll v){
			frr(i, n) dist[v][i] = INF;

			pq<pii, vector<pii>, greater<pii>> fila;
			fila.push(mp(0, v));

			while(true){
				ll davez = -1;

				while(!fila.empty()){
					pii p = fila.top();
					fila.pop();

					if(dist[v][p.s] > p.f){
						dist[v][p.s] = p.f;
						davez = p.s;

						break;
					}
				}

				if(davez == -1) break;

				for(pii e: adj[davez]){
					if(dist[v][e.f] > dist[v][davez] + e.s){
						fila.push(mp(dist[v][davez] + e.s, e.f));
					}
				}
			}
		}

		void read(){
			cin >> n >> m;

			frr(i, m){
				ll v1, v2, w;
				cin >> v1 >> v2 >> w;

				adj[v1].pb(mp(v2, w));
				adj[v2].pb(mp(v1, w));
			}
		}
};

ll solve(ll d){
	/*dp[i] é o menor tempo de se entregar as pizzas 1 ... i e parar na casa i*/
	ll dp[1010], tempo_max[1010]; 
	dp[0] = 0;
	frr(i, k) {
		tempo_max[i] = ini[i] + d;
		dp[i] = INF;
	}
	for(ll i = 0; i < k; i++){
		ll limite = INF, tempo_ant = dp[i] + dist[u[i]][1], tempo_atu, tempo_chegada = dp[i] + dist[u[i]][1];	
		ll j = i+1, para = 0;
		ll aux = 0;

	//	cout << i << " " << tempo_ant << endl;

		if(tempo_ant < fim[j]) tempo_ant = fim[j];
		tempo_atu = tempo_ant + dist[u[j]][1];

		if(tempo_max[j] >= tempo_atu){
			limite = min(limite, tempo_max[j] - tempo_atu);
			dp[j] = min(dp[j], tempo_atu);
			tempo_ant = tempo_atu;
		}
		else continue;

		for(j = i+2; j <= k; j++){
			if(tempo_chegada >= fim[j]){
				tempo_atu = tempo_ant + dist[u[j]][u[j-1]];

				if(tempo_max[j] >= tempo_atu){
					limite = min(limite, tempo_max[j] - tempo_atu);
					dp[j] = min(dp[j], tempo_atu);
					tempo_ant = tempo_atu;
				}
				else break;
			}
			else{
				tempo_atu = tempo_ant + fim[j] - max(fim[j-1], tempo_chegada) + dist[u[j]][u[j-1]];

				if(limite >= fim[j] - max(fim[j-1], tempo_chegada) && tempo_max[j] >= tempo_atu){
					limite -= (fim[j] - max(fim[j-1], tempo_chegada));
					limite = min(limite, tempo_max[j] - tempo_atu);
					dp[j] = min(dp[j], tempo_atu);
					tempo_ant = tempo_atu;
				}
				else break;
			}
		}	
	}

	//frr(i, k) cout << dp[i] << endl;

	if(dp[k] <= tempo_max[k]) return 1;
	else return 0;

}

ll bb(){
	ll l = -1, r = INF, m;
	while(l < r - 1){
		m = (l + r)/2;

		if(solve(m)) r = m;
		else l = m;
	}

	return r;
}

Graph G;

int main(){
	ios::sync_with_stdio(false);

	G.read();

	cin >> k;
	frr(i, k)
		cin >> ini[i] >> u[i] >> fim[i];

	frr(i, n)
		G.dijkstra(i);

	//cout << solve(8) << endl;

	cout << bb() << endl;
}
