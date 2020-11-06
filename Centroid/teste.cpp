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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll n;
class Graph{
	public:
    ll n;
    set<ll> adj[MAXN];
};

ll mask[MAXN], ans[MAXN], car[MAXN];
map<ll, ll> acu[MAXN];
/*Vertices são 1, 2, ..., n*/
class Centroid{
	public:
    Graph G, CT; /*Centroid tree*/
	ll pai[MAXN], size[MAXN];

	void dfs(ll u,ll p){
		size[u]=1;
		for(auto x: G.adj[u]){
			if(x != p){
				dfs(x, u);
				size[u]+=size[x];
			}
		}
	}
	
	ll find_centroid(ll u, ll p, ll sz){
		for(auto x: G.adj[u]){
			if(x!=p && size[x] > sz/2)
				return find_centroid(x, u, sz);
		}
		return u;
	}

	ll solve(ll u, ll p, ll root, ll ini){
		ll ret = 0;
		fr(i, 20){
			ret += (acu[root][(1 << i)^(mask[u])^(1 << car[root])] - acu[ini][(1 << i)^(mask[u])^(1 << car[root])]);
			if(mask[u] == (1 << i)) ret++;
		}
		ret += acu[root][mask[u]^(1 << car[root])] - acu[ini][mask[u]^(1 << car[root])];
		if(mask[u] == 0) ret++;
		cout << root << " 1 " << u << " " << ret << endl;
		fr(i, 10) cout << acu[root][i] << " ";
		cout << "\n";
		fr(i, 10) cout << acu[ini][i] << " ";
		cout << "\n";

		for(auto x: G.adj[u]){
			if(x != p){
				ret += solve(x,u, root, ini);
			}
		}
		ans[u] += ret;
		cout << root << " 2 " << u << " " << ret << endl;
		
		return ret;
	}

	void build_mask(ll u, ll p, ll root, ll ini){
		mask[u] = (1 << car[u])^mask[p];
		acu[root][mask[u]]++;
		acu[ini][mask[u]]++;

		for(auto x: G.adj[u]){
			if(x != p){
				build_mask(x,u, root, ini);
			}
		}	
	}

	void decompose(ll root, ll p){
		dfs(root,root);
		ll c = find_centroid(root,root, size[root]);

		mask[c] = (1 << car[c]); 
		for(auto x: G.adj[c]){
			build_mask(x, c, c, x);
		}
		/*
		cout << c << " Centroid: \n";
		for(auto x: acu[c]) cout << x.f << " " << x.s << endl;
		for(auto y: G.adj[c]){
			cout << "    " << y << "\n";
			for(auto x: acu[y]) cout << x.f << " " << x.s << endl;
		}
		/*resolver*/

		ll tot = 0;

		for(auto x: G.adj[c]){
			tot += solve(x, c, c, x);
			acu[x].clear();
		}
		fr(i, 20){
			tot += acu[c][(1 << i)];
		}
		tot += acu[c][0];
		ans[c] += tot/2 + 1	;
/*
		cout << c << endl;
		frr(i, n) cout << ans[i] <<" ";
		cout << endl;
*/
		acu[c].clear();
		for(auto x: G.adj[c]){
			G.adj[x].erase(c);
			decompose(x, c);
		}
	}
};

Centroid C;

void read(){
	cin >> n;

	fr(i, n-1){
		ll u, v;
		cin >> u >> v;
		
		C.G.adj[u].insert(v);
		C.G.adj[v].insert(u);
	}

	string s;
	cin >> s;
	frr(i, n) car[i] = s[i-1] - 'a';
}

int main(){
    read();
	//fr(i, 16) cout << acu[i] <<" ";
	//cout << endl;

	C.decompose(1, 0);

	frr(i, n) cout << ans[i] <<" ";
	cout << endl;
}