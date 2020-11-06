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

#define MAXN 500010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int n;
namespace seg {
	int nd[4*MAXN], lz[4*MAXN];

	void push(int i, int l, int r){
		if(lz[i] == 0) return;
		else if(lz[i] == 1){		
			nd[i] = (r - l + 1);
		}
		else if(lz[i] == -1){
			nd[i] = 0;
		}

		if(l < r){
			lz[2*i + 1] = lz[i];
			lz[2*i] = lz[i];
		}

		lz[i] = 0;
	}

	void update(int i, int l, int r, int ql, int qr, int x){
		push(i, l, r);
		if(l > qr || ql > r) return;
		else if(ql <= l && r <= qr){
			lz[i] = x;
		}
		else{
			int m = (l + r)/2;

			update(2*i, l, m, ql, qr, x);
			update(2*i + 1, m + 1, r, ql, qr, x);
		}
	}

	int query(int i, int l, int r, int pos){
		push(i, l, r);

		if(l == r) return nd[i];
		else{
			int m = (l + r)/2;
			if(m >= pos) return query(2*i, l, m, pos);
			else return query(2*i + 1, m + 1, r, pos);
		}
	}
}

namespace hld {
	vector<int> adj[MAXN];
	int pos[MAXN], sz[MAXN];
	int pai[MAXN];
	int h[MAXN], t;

	void build_hld(int k, int p = -1, int f = 1) {
		sz[k] = 1;
		pos[k] = t++;
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
	}
	void update_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(1, 0 ,n-1, pos[b], pos[a], -1);
		seg::update(1, 0, n-1, pos[h[a]], pos[a], -1); update_path(pai[h[a]], b);
	}

	void update_subtree(int a) {
		seg::update(1, 0, n-1, pos[a], pos[a]+sz[a]-1, 1);
	}
}

void solve(){
	cin >> n;
	fr(i, n-1){
		int a, b;
		cin >> a >> b;
		hld::adj[a-1].pb(b-1);
		hld::adj[b-1].pb(a-1);
	}

	hld::build();

	/*
	fr(i, n){
		cout << hld::pos[i] <<' ';
	}
	cout << endl;
	*/

	int q;
	cin >> q;

	while(q--){
		int op, v;
		cin >> op >> v;

		if(op == 1){
			hld::update_subtree(v - 1);
		}
		else if(op == 2){
			hld::update_path(v - 1, 0);
		}
		else{
			if(seg::query(1, 0, n-1, hld::pos[v - 1])){
				cout << 1 << endl;
			}
			else{
				cout << 0 << endl;
			}
		}

	}
}

int main(){
	ios::sync_with_stdio(false);
	solve();
}
