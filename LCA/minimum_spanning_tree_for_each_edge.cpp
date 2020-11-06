//https://codeforces.com/problemset/problem/609/E

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int, ll> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007

int n, m, maxl;
vector<pii> adj[MAXN];
int tin[MAXN], tout[MAXN];
int tempo;

int pr[MAXN];
int anc[MAXN][35];
ll max_edge[MAXN][35];
ll MST = 0;

void dfs(int v, int pai, ll ed){
	pr[v] = 1;

	anc[v][0] = pai;
	frr(i, maxl){
		anc[v][i] = anc[anc[v][i-1]][i-1];
	}

	max_edge[v][0] = ed;
	frr(i, maxl){
		max_edge[v][i] = max(max_edge[v][i-1], max_edge[anc[v][i-1]][i-1]);
	}

	tin[v] = tempo++;

	for(auto u: adj[v]){
		if(!pr[u.f]){
			dfs(u.f, v, u.s);
		}
	}

	tout[v] = tempo++;
}

bool is_ancestor(int v, int u){
	return tin[v] <= tout[u] && tout[v] >= tout[u];
}

int lca(int v, int u){
	if(is_ancestor(v, u)) return v;
	if(is_ancestor(u, v)) return u;

	frm(i, maxl+1){
		if(!is_ancestor(anc[u][i], v)) u = anc[u][i];
	}

	return anc[u][0];
}

int pai[MAXN], peso[MAXN];

int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

int join(int v, int u){
	v = find(v);
	u = find(u);

	if(v == u) return 0;

	if(peso[v] > peso[u]) swap(v, u);

	pai[u] = v;
	peso[v]+=peso[u];

	return 1;
}

ll maximo(int v, int ancestral){
	ll ans = 0;
	int i = maxl;

	while(v != ancestral && i >= 0){
		if(is_ancestor(ancestral, anc[v][i])){
			ans = max(ans, max_edge[v][i]);
			v = anc[v][i];
		}

		i--;
	}

	return ans;
}

pair<ll, pii> e[MAXN], e0[MAXN];

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> m;
	maxl = ceil(log(n)/log(2));

	fr(i, m){
		int v1, v2, w;
		cin >> v1 >> v2 >> w;

		e[i] = mp(w, mp(v1, v2));
		e0[i] = mp(w, mp(v1, v2));
	}

	sort(e, e + m);

	frr(i, n){
		pai[i] = i;
		peso[i] = 1;
	}

	fr(i, m){
		if(join(e[i].s.f, e[i].s.s)) {
			MST+=e[i].f;

			adj[e[i].s.f].pb(mp(e[i].s.s, e[i].f));
			adj[e[i].s.s].pb(mp(e[i].s.f, e[i].f));
		}
	}

	dfs(1, 1, 0);

	fr(i, m){
		int l = lca(e0[i].s.f, e0[i].s.s);

		cout << MST + e0[i].f - max(maximo(e0[i].s.f, l), maximo(e0[i].s.s, l)) << endl;
	}
}
