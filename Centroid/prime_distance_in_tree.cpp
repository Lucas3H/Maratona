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

class Graph{
	public:
    ll n;
    set<ll> adj[MAXN];
};

ll acu[MAXN];
ll acu_aux[MAXN];
ll ans = 0;
ll n;
ll not_prime[MAXN];
vector<ll> p;

/*Vertices são 1, 2, ..., n*/
class Centroid{
	public:
    Graph G, CT; /*Centroid tree*/
	ll size[MAXN];

	void dfs(ll u,ll pai){
		size[u]=1;
		for(auto x: G.adj[u]){
			if(x != pai){
				dfs(x,u);
				size[u]+=size[x];
			}
		}
	}
	
	void build_acu(ll u, ll pai, ll d){
		acu[d]++;
		for(auto x: G.adj[u]){
			if(x != pai){
				build_acu(x, u, d + 1);
			}
		}
	}

	void clear_acu(ll u, ll pai, ll d){
		acu[d]--;
		for(auto x: G.adj[u]){
			if(x != pai){
				clear_acu(x, u, d + 1);
			}
		}
	}

	void build_acu_aux(ll u, ll pai, ll d){
		acu_aux[d]++;
		for(auto x: G.adj[u]){
			if(x != pai){
				build_acu_aux(x, u, d + 1);
			}
		}
	}

	void clear_acu_aux(ll u, ll pai, ll d){
		acu_aux[d]--;
		for(auto x: G.adj[u]){
			if(x != pai){
				clear_acu_aux(x, u, d + 1);
			}
		}
	}

	ll find_centroid(ll u, ll pai, ll sz){
		for(auto x: G.adj[u]){
			if(x!=pai && size[x] > sz/2)
				return find_centroid(x, u, sz);
		}
		return u;
	}

	void decompose(ll root, ll pai){
		dfs(root,root);
		ll c = find_centroid(root,root, size[root]);
		
		build_acu(c, c, 0);
/*
		cout << "carai " << c << endl;
		fr(i, 4){
			cout << acu[i] << endl;
		}
*/
		for(auto x: G.adj[c]){
			build_acu_aux(x, c, 1);

			for(ll i = 1; i < MAXN; i++){
				if(acu_aux[i] == 0) break;
				for(ll j = 0; j < p.size(); j++){
					if(i > p[j]) continue;
					if(acu[p[j] - i] == 0) break;
					//cout << c << " " << i << " " << p[j] << endl;
					ans += (acu_aux[i])*(acu[p[j] - i] - acu_aux[p[j] - i]);
				}
			}

			clear_acu_aux(x, c, 1);
		}

		fr(i, p.size()){
			if(acu[p[i]] == 0)break;
			ans += acu[p[i]];
		}

		clear_acu(c, c, 0);

		for(auto x: G.adj[c]){
			G.adj[x].erase(c);
			decompose(x, c);
		}
	}
};

Centroid C;
void crivo(ll n){
	for(ll i = 2; i <= n; i++){
		if(!not_prime[i]){
			p.pb(i);
		
			for(ll j = 2; j*i <= n; j++){
				not_prime[j*i] = 1;
			}
		}
	}
}
int main(){
	ll n;
	cin >> n;

	crivo(n);

	fr(i, n-1){
		ll x, y;
		cin >> x >> y;
		C.G.adj[x].insert(y);
		C.G.adj[y].insert(x);
	}

	C.decompose(1, 0);
	printf("%.6lf\n", (double)(ans)/(n*(n-1)));
}
