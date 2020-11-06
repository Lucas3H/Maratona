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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

vector<pii> edges[MAXN];
vector<ll> adj[MAXN];
ll peso[MAXN], pai[MAXN];
ll n, m;
ll ans = 0;

ll find(ll x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(ll a, ll b, ll w){
	a = find(a);
	b = find(b);

	if(a == b) return;
	if(peso[a] < peso[b]) swap(a, b);

	peso[a]+= peso[b];
	pai[b] = a;
	ans = (w + ans)%MOD;
}

void read(){
	cin >> n >> m;

	fr(i, m){
		ll u, v, w;
		cin >> u >> v >> w;

		adj[u].pb(v);
		adj[v].pb(u);

		edges[w].pb(mp(u, v));
	}

	frr(i, n){
		pai[i] = i;
		peso[i] = 1;
	}
}

ll solve(ll tam){
	if(edges[tam].size() == 0){
		return 1;
	}
	else if(edges[tam].size() == 1){
		join(edges[tam][0].f, edges[tam][0].s, tam);
		return 1;
	}
	else if(edges[tam].size() == 2){
		ll u[2], v[2];

		fr(i, 2){
			u[i] = find(edges[tam][i].f);
			v[i] = find(edges[tam][i].s);

			if(u[i] > v[i]) swap(u[i], v[i]);

			//cout << u[i] << " " << v[i] << endl;
		}

		join(u[0], v[0], tam);
		join(u[1], v[1], tam);	

		if((u[0] == v[0]) || (u[1] == v[1])) return 1;

		if(u[0] == u[1] && v[0] == v[1]) return 2;
		else return 1;
	}
	else{
		ll u[3], v[3];
		set<ll> aux;

		fr(i, 3){
			u[i] = find(edges[tam][i].f);
			v[i] = find(edges[tam][i].s);

			if(u[i] > v[i]) swap(u[i], v[i]);

			aux.insert(u[i]);
			aux.insert(v[i]);
		}

		join(u[0], v[0], tam);
		join(u[1], v[1], tam);	
		join(u[2], v[2], tam);	

		if(u[0] == v[0]) {
			v[0] = -1;
			aux.clear();
		}
		if(u[1] == v[1]) {
			v[1] = -2;
			aux.clear();
		}
		if(u[2] == v[2]) {
			v[2] = -3;
			aux.clear();
		}

		if(u[0] == u[1] && v[0] == v[1] && u[0] == u[2] && v[0] == v[2]) return 3;
		else if(u[0] == u[1] && v[0] == v[1]) return 2;
		else if(u[0] == u[2] && v[0] == v[2]) return 2;
		else if(u[1] == u[2] && v[1] == v[2]) return 2;
		else if(aux.size() == 3) return 3;
		else return 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();

	ll tot = 1;

	frr(i, 1000000){
		tot = (tot*solve(i))%MOD;
	}

	cout << ans << " " << tot << endl;
}
