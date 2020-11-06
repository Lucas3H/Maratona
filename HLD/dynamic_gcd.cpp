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

#define MAXN 50010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

ll n;
ll v[MAXN], valor[MAXN];

namespace bit{
	ll bit[MAXN];

    void update_aux(ll i, ll val){
        while(i <= n){
            bit[i] += val;
            i += i & (-i);
        }
    }

    ll query_aux(ll i){
        ll sum = 0;

        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }

        return sum;
    }
	ll query(ll pos){
		pos++;
		return query_aux(pos) - query_aux(pos-1);
	}

	void update(ll l, ll r, ll x){
		l++, r++;
		update_aux(l, x);
		update_aux(r+1, -x);
	}
}

namespace seg_gcd {
	ll nd[4*MAXN];
	void build_rec(ll i, ll l, ll r){
		if(l == r) nd[i] = v[l];
		else{
			ll m = (l + r)/2;

			build_rec(2*i, l, m);
			build_rec(2*i + 1, m + 1, r);

			nd[i] = gcd(nd[2*i], nd[2*i+1]);
		}
	}

	void build(){
		fr(i, n) bit::update_aux(i + 1, v[i]);
		fr(i, n-1) {
			v[i] = v[i+1] - v[i];
			//cout << v[i] <<' ';
		}
		build_rec(1, 0, n-2);
	}

	ll query_rec(ll i, ll l, ll r, ll ql, ll qr){
		//cout << l << " " <<r  << " " << i << " " << nd[i] << endl;
		if(l > qr || ql > r) return 0;
		else if(ql <= l && r <= qr)return nd[i];
		else{
			ll m = (l + r)/2;
			return gcd(query_rec(2*i, l, m, ql, qr), query_rec(2*i + 1, m + 1, r, ql, qr));
		}
	}

	ll query(ll ql, ll qr){ 
		//cout << ql << " " << qr << endl;
		if(ql == qr) return bit::query(ql);
		else{
			qr--;

			//cout << ql << ' ' << qr << " " << query_rec(1, 0, n-2, ql, qr) <<" " << v[1] << endl;
			return gcd(bit::query(ql), query_rec(1, 0, n-2, ql, qr));
		}
	}

	void update_rec(ll i, ll l, ll r, ll pos){
		if(l == r) nd[i] = v[l];
		else{
			ll m = (l + r)/2;

			if(m >= pos) update_rec(2*i, l, m, pos);
			else update_rec(2*i + 1, m + 1, r, pos);
		}
		//cout << i << " " << l << " " << r << " " << nd[i] << endl;
	}

	void update(ll ql, ll qr, ll x){
		//cout << ql << " " << qr << " " << x << endl;
		bit::update(ql, qr, x);

		if(ql > 0) v[ql-1]+=x;
		v[qr] -= x;

		update_rec(1, 0, n-2, ql-1);
		update_rec(1, 0, n-2, qr);
	}

}

namespace hld {
	vector<ll> adj[MAXN];
	ll sz[MAXN];
	ll val[MAXN], pai[MAXN], pos[MAXN];
	ll h[MAXN], t;

	void build_hld(ll k, ll p = -1, ll f = 1) {
		pos[k] = t++;
		v[pos[k]] = valor[k]; sz[k] = 1;
		for (auto& i : adj[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == adj[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[adj[k][0]] or adj[k][0] == p) swap(i, adj[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(ll root = 0) {
		t = 0;
		build_hld(root);
		seg_gcd::build();
	}
	ll query_path(ll a, ll b) {
		//cout << a << " | " << b << endl;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg_gcd::query(pos[b], pos[a]);
		return gcd(seg_gcd::query(pos[h[a]], pos[a]), query_path(pai[h[a]], b));
	}
	void update_path(ll a, ll b, ll x) {
		if (pos[a] < pos[b]) swap(a, b);
		if (h[a] == h[b]) seg_gcd::update(pos[b], pos[a], x);
		else {seg_gcd::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);}
	}
}

void read(){
	cin >> n;
	
	fr(i, n-1){
		ll x, y;
		cin >> x >> y;

		hld::adj[x].pb(y);
		hld::adj[y].pb(x);
	}

	fr(i, n) cin >> valor[i];
	hld::build();
}

int main(){
	ios::sync_with_stdio(false);
	read();

	ll q;
	cin >> q;

	while(q--){
		char c;
		ll x, y, z;
		cin >> c >> x >> y;

		if(c == 'F'){
			cout << abs(hld::query_path(x, y)) << endl;
		}
		else{
			cin >> z;
			hld::update_path(x, y, z);
		}
	}
}
