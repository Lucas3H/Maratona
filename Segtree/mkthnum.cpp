// 
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

map<int, int> m;
int v[MAXN];
int v_inv[MAXN];
int n, q;

no * versao[MAXN];

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

void buildArrays(){
	cin >> n >> q;

	frr(i, n){
		cin >> v[i];
		m[v[i]]= 1;
	}

	int it = 1;
	for(auto x: m){
		v_inv[it] = x.f;
		m[x.f] = it++;
	}
}

void buildVersions(){
	versao[0] = new no;
	build(versao[0], 1, n);

	frr(i, n){
		versao[i] = new no;
		update(versao[i], 1, n, m[v[i]], 1, versao[i-1]);
	}
}

void solve(){
	while(q--){
		int l, r, k;
		cin >> l >> r >> k;

		cout << query(versao[l-1], versao[r], 1, n, k) << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	buildArrays();
	buildVersions();
	solve();
}
