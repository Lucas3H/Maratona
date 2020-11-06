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
#define INF 987654321

class acu{
	public:
	map<ll, ll> freq;
	ll v[MAXN], dist[MAXN];
	ll n = 0;

	void insere(ll d){
		freq[d]++;
	}

	void ready(){
		ll i = 0;
		for(auto x: freq){
			v[i] = x.s;
			if(i > 0){
				v[i] += v[i-1];
			}
			dist[i] = x.f;
			i++;
		}
		n = i;
	}

	ll query(ll x){
		ll l = 0, r = n, m;
		if(x < dist[0]) return 0;

		while(l < r - 1){
			m = (l + r)/2;
			if(dist[m] > x) r = m;
			else l = m;
		} 

		return v[l];
	}

	void clear(){
		freq.clear();
	}

	void imprime(){
		for(auto x: freq){
			cout<< x.f << " " << x.s << endl;
		}
	}
};

class Graph{
	public:
    ll n;
    set<pii> adj[MAXN];
};

ll n, q;
vector<pii> query[MAXN];
ll ans[MAXN];
/*Vertices são 1, 2, ..., n*/
class Centroid{
	public:
    Graph G, CT; /*Centroid tree*/
	ll dist[MAXN], size[MAXN];

	acu princ, aux;

	void dfs(ll u,ll p){
		size[u]=1;
		for(auto x: G.adj[u]){
			if(x.f != p){
				dfs(x.f,u);
				size[u]+=size[x.f];
			}
		}
	}
	
	ll find_centroid(ll u, ll p, ll sz){
		for(auto x: G.adj[u]){
			if(x.f != p && size[x.f] > sz/2)
				return find_centroid(x.f, u, sz);
		}
		return u;
	}

	void build_acu(ll u, ll p, ll d){
		dist[u] = dist[p] + d;
		princ.insere(dist[u]);
		for(auto x: G.adj[u]){
			if(x.f != p){
				build_acu(x.f, u, x.s);
			}
		}
	}

	void build_acu_aux(ll u, ll p, ll d){
		aux.insere(dist[u]);
		for(auto x: G.adj[u]){
			if(x.f != p){
				build_acu_aux(x.f, u, x.s);
			}
		}
	}

	void solve(ll u, ll p){			
		for(auto x: query[u]){
			ans[x.f] +=  princ.query(x.s - dist[u]) - aux.query(x.s - dist[u]) ;
		}
		for(auto x: G.adj[u]){
			if(x.f != p){
				solve(x.f, u);
			}
		}
	}

	void decompose(ll root, ll p){
		dfs(root,root);
		ll c = find_centroid(root,root, size[root]);
		dist[c] = 0;
		build_acu(c, c, 0);
		princ.ready();

		for(auto x: G.adj[c]){
			build_acu_aux(x.f, c, 0);
			aux.ready();

			solve(x.f, c);

			aux.clear();
		}
		
		for(auto x: query[c]){
			ans[x.f] += princ.query(x.s);
		}

		princ.clear();
		for(auto x: G.adj[c]){
			G.adj[x.f].erase({c, x.s});
			decompose(x.f, c);
		}
	}
};

Centroid C;

void read(){
	cin >> n >> q;

	fr(i, n-1){
		ll a, b, c;
		cin >> a >> b >> c;
		C.G.adj[a].insert({b, c});
		C.G.adj[b].insert({a, c});
	}

	frr(i, q){
		ll a, b;
		cin >> a >> b;
		query[a].pb({i, b});
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();
	C.decompose(1, 0);
	frr(i, q){
		cout << ans[i] << endl;
	}
}
