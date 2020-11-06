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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll s[MAXN], d[MAXN], x[MAXN], peso[MAXN];
ll n;

ll t[MAXN], pr[MAXN], ans[MAXN];
vector<pii> adj[MAXN];

void read(){
	cin >> n;

	frr(i, n) cin >> t[i];

	fr(i, n-1){
		ll v, u, w;
		cin >> v >> u >> w;

		adj[v].pb(mp(u, w));
		adj[u].pb(mp(v, w));
	}
}

void dfsBuild(ll v){
	pr[v] = 1;
	x[v] = t[v];
	peso[v] = 1;

	for(pii pa: adj[v]){
		if(!pr[pa.f]){
			dfsBuild(pa.f);

			x[v] += x[pa.f];
			peso[v] += peso[pa.f];
		}
	}
}

pii dfsFindRoot(ll v, ll cam){
	pr[v] = 1;

	ll ret = 0;
	ret += t[v]*cam;
	ll ret1 = cam;

	for(pii pa: adj[v]){
		if(!pr[pa.f]){
			pii y = dfsFindRoot(pa.f, pa.s + cam);
			ret += y.f;
			ret1 += y.s;
		}
	}

	return mp(ret, ret1);
}

void dfs(ll v, ll X, ll P){
	pr[v] = 1;
	ans[v] = d[v]*t[v] + s[v];

	for(pii pa: adj[v]){
		if(!pr[pa.f]){
			ll p2 = P + peso[v] - peso[pa.f];
			ll x2 = X + x[v] - x[pa.f];
			d[pa.f] = d[v] + pa.s*(p2 - peso[pa.f]);
			s[pa.f] = s[v] + pa.s*(x2 - x[pa.f]);

			dfs(pa.f, x2, p2);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();
	dfsBuild(1);
	frr(i, n) pr[i] = 0;

	pii y = dfsFindRoot(1, 0);
	
	ans[1] = y.f + y.s*t[1];
	d[1] = y.s;
	s[1] = y.f;

	frr(i, n) pr[i] = 0;

	dfs(1, 0, 0);

	frr(i, n){
		cout << ans[i] << endl;
	}
/*
	frr(i, n){
		cout << s[i] << " " << d[i] << " " << ans[i] << " " << peso[i] << " " << x[i] << endl;
	}

*/
}
