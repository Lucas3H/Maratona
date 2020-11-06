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
#define INF 1000000000000000100

int v[MAXN], n;
namespace ed {
	vector<int> p[MAXN];
	void build(){
		fr(i, n + 1) p[i].clear();
		fr(i, n){
			p[v[i]].pb(i);
		}
	}

	int query(int l, int r, int x){
		//cout << x << ' ' << l <<' ' <<r << endl;
		return ((upper_bound(p[x].begin(), p[x].end(), r) - lower_bound(p[x].begin(), p[x].end(), l)));
	}
}

namespace hld {
	vector<int> adj[MAXN];
	int pos[MAXN], sz[MAXN];
	int val[MAXN], pai[MAXN];
	int h[MAXN], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = val[k]; sz[k] = 1;
		for (auto& i : adj[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == adj[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[adj[k][0]] or adj[k][0] == p) swap(i, adj[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		ed::build();
	}
	ll query_path(int a, int b, int z) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return ed::query(pos[b], pos[a], z);
		return ed::query(pos[h[a]], pos[a], z) + query_path(pai[h[a]], b, z);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int q;
	while(cin >> n >> q){
		fr(i, n) hld::adj[i].clear(), cin >> hld::val[i];
		int x, y;
		fr(i, n-1){
			cin >> x >> y;
			hld::adj[x-1].pb(y-1);
			hld::adj[y-1].pb(x-1);
		}

		hld::build();

		while(q--){
			int z;
			cin >> x >> y >> z;

			if(hld::query_path(x-1, y-1, z)){
				cout << "Find\n";
			}
			else{
				cout << "NotFind\n";
			}
		}
		cout << endl;
	}
}
