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

ll n, k;
vector<ll> adj[MAXN];
ll pr[MAXN], tipo[MAXN], peso[MAXN], dist[MAXN];
ll ans = 0;

void dfs(ll v){
	pr[v] = 1;
	peso[v] = 1;
	for(ll u: adj[v]){
		if(!pr[u]){
			dfs(u);
			peso[v]+=peso[u];
		}
	}
}

void bfs(){
	pq<pii> fila;
	fila.push(mp(peso[1], 1));
	pr[1] = 1;



	while(!fila.empty()){
		pii davez = fila.top();
		fila.pop();

		tipo[davez.s] = 1;
		k--;

		if(k == 0) return;

		//cout << davez.s << " sad  " << endl;

		for(ll u: adj[davez.s]){
			if(!pr[u]){
				pr[u] = 1;
				dist[u] = dist[davez.s] + 1;
				fila.push(mp(peso[u] - dist[u], u));
				//cout << u << " dsadasd" << endl;
			}
		}
	}
}

ll dfsAns(ll v){
	pr[v] = 1;
	ll ret = 0;

	for(ll u: adj[v]){
		if(!pr[u]){
			ret+=dfsAns(u);
			if(tipo[v] == 1 && tipo[u] == 0) ret += peso[u];
		}
	}

	if(tipo[v] == 1){
		ans += ret;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	k = n-k;
	fr(i, n-1){
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	frr(i, n) pr[i] = 0;

	bfs();
	frr(i, n) pr[i] = 0;

	//frr(i, n) cout << tipo[i] << endl;

	ll a = dfsAns(1);
	cout << ans << endl;

}
