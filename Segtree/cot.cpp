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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

struct no{
	no * l, * r;
	int val;
};

//Seg [0...n-1]
// Quando for estudar o código, tentar transformar para [1...n]
int n;
no * versao[MAXN];

namespace seg {
	map<int, int> m;
	int v_inv[MAXN];
	void build(no * i, int l, int r){
		if(l == r){
			i->val = 0;
		}
		else{
			int mid = (l + r)/2;

			no * esq = new no;
			no * dir = new no;

			i->val = 0;
			i->l = esq;
			i->r = dir;

			build(esq, l, mid);
			build(dir, mid + 1, r);
		}
	}

	void update(no * i, int l, int r, int pos, int val, no * aux){
		if(l == r){
			i -> val = val;
		}
		else{
			int mid = (l + r)/2;

			if(pos <= mid){
				no * esq = new no;
				i->l = esq;
				i->r = aux->r;
				update(esq, l, mid, pos, val, aux->l);
			}
			else{
				no * dir = new no;
				i->l = aux->l;
				i->r = dir;
				update(dir, mid + 1, r, pos, val, aux->r);
			}

			i->val = i->l->val + i->r->val;
		}
	}

	int query(no * nl, no * nr, int l, int r, int k){
		if(l == r){
			return v_inv[r];
		}
		else{
			int mid = (l + r)/2;
			
			if(nr->l->val - nl->l->val >= k)
				return query(nl->l, nr->l, l, mid, k);
			else
				return query(nl->r, nr->r, mid + 1, r, k - nr->l->val + nl->l->val);
		}
	}

	void buildArrays(int v[]){
		frm(i, n){
			v[i+1] = v[i];
		}
		frr(i, n){
			m[v[i]]= 1;
		}

		int it = 1;
		for(auto x: m){
			v_inv[it] = x.f;
			m[x.f] = it++;
		}

		versao[0] = new no;
		build(versao[0], 1, n);

		frr(i, n){
			cout << v[i] << " ";
			versao[i] = new no;
			update(versao[i], 1, n, m[v[i]], 1, versao[i-1]);
		}
		cout << endl;	
	}
}

namespace hld {
	vector<int> adj[MAXN];
	int pos[MAXN], sz[MAXN];
	int val[MAXN], pai[MAXN];
	int h[MAXN], t;
	int v[MAXN];

	void build_hld(int k, int p = -1, int f = 1) {
		pos[k] = t++;
		v[pos[k]] = val[k]; sz[k] = 1;
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
		seg::buildArrays(v);
	}
	ll query_path(int a, int b, int k) {
		if (pos[a] < pos[b]) swap(a, b);

		cout << a << " " << b << " " << k << endl;

		if (h[a] == h[b]){ 
			return seg::query(versao[pos[b]], versao[pos[a] + 1], pos[b] + 1, pos[a] + 1, k);
		}
		if(versao[pos[a] + 1]->val - versao[pos[h[a]]]->val >= k){
			return seg::query(versao[pos[h[a]]], versao[pos[a] + 1], pos[h[a]] + 1, pos[a] + 1, k);
		}
		else{
			return query_path(pai[h[a]], b, k - (versao[pos[a] + 1]->val - versao[pos[h[a]]]->val));
		}
	}
}

int q;

void read(){
	cin >> n >> q;

	fr(i, n){
		cin >> hld::val[i];
	}

	fr(i, n-1){
		int a, b;
		cin >> a >> b;

		hld::adj[a-1].pb(b-1);
		hld::adj[b-1].pb(a-1);
	}

	hld::build();
}

int main(){
	read();
	while(q--){
		int l, r, k;
		cin >> l >> r >> k;

		cout << hld::query_path(l, r, k) << endl;
	}
}