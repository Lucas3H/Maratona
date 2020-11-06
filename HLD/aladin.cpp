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


#define MAXN 100010
//Seg [1...n]
int pos[MAXN], v[MAXN], nd[4*MAXN];
int n;
namespace seg {
	void build(int i, int l, int r){
		//cout << v[l] <<" " << l << endl;
 		if(l == r) nd[i] = v[l];
		else{
			int m = (l + r)/2;
			build(2*i, l, m);
			build(2*i + 1, m + 1, r);
			nd[i] = nd[2*i] + nd[2*i + 1];
		}
	}

	void update(int i, int l, int r, int p, int x){
		if(l == r){
			nd[i] = x;
		}
		else{
			int m = (l + r)/2;

			if(p <= m) update(2*i, l, m, p, x);
			else update(2*i + 1, m + 1, r, p , x);
		
			nd[i] = nd[2*i] + nd[2*i + 1];
		}
	}

	int query(int i, int l, int r, int ql, int qr){
		if(l > qr || ql > r) return 0;
		else if(ql <= l && r <= qr) return nd[i];
		else{
			int m = (l + r)/2;

			return query(2*i, l, m, ql, qr) + query(2*i + 1, m + 1, r, ql, qr);
		}
	}
}

namespace hld {
	vector<int> g[MAXN];
	int sz[MAXN];
	int val[MAXN], pai[MAXN];
	int h[MAXN], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = val[k]; sz[k] = 1;
		//cout << k << " " << val[k] << " " << v[pos[k]] << " " << pos[k] << endl;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(1, 0, n-1);
	}
	ll query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(1, 0, n-1, pos[b], pos[a]);
		return seg::query(1, 0, n-1, pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	frr(ts, t){
		printf("Case %d:\n", ts);
		scanf("%d", &n);
		fr(i, n) hld::g[i].clear();
		fr(i, n){
			scanf("%d", &hld::val[i]);
		}
		int x, y;
		fr(i, n-1){
			scanf("%d %d", &x, &y);
			hld::g[x].pb(y );
			hld::g[y].pb(x );
		}

		hld::build();

		int q;
		scanf("%d", &q);

		while(q--){
			int op;
			scanf("%d %d %d", &op, &x, &y);
			if(op == 0){
				printf("%d\n", hld::query_path(x , y ));
			}
			else{
				seg::update(1, 0, n-1, pos[x] , y);		
			}
		}
	}
}
