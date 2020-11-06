// https://docs.google.com/spreadsheets/d/1QT-p_Nzb-c6bTdDcnBHq_qRJ7B9biH75014ItH1IIKU/edit#gid=0

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,ll> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int n, maxl, ROOT = 1, q;

vector<pii> adj[MAXN];
pair<ll, pii> e[MAXN];
int pr[MAXN], pai[MAXN], peso[MAXN];
int anc[MAXN][33];

int tin[MAXN], tout[MAXN];
ll dist[MAXN];
int tempo = 0;

int v1Extra, v2Extra;
ll pesoExtra;

void dfs(int v, int pai){
	pr[v] = 1;

	anc[v][0] = pai;
	frr(i, maxl){
		anc[v][i] = anc[anc[v][i-1]][i-1];
	}

	tin[v] = tempo++;

	for(auto u: adj[v]){
		//cout << u.f << " " << v << endl;
		if(pr[u.f] == 0){
			dist[u.f] = dist[v] + (ll)u.s;
			//cout << u.f <<" " << v << " "<< dist[v] << " " << u.s << endl;
			dfs(u.f, v);
		}
	}

	tout[v] = tempo++;
}

bool is_ancestor(int u, int v){
	return (tin[u] <= tin[v]) && (tout[u] >= tout[v]); 
}

int lca(int v, int u){
	if(is_ancestor(v, u)) return v;
	if(is_ancestor(u, v)) return u;

	frm(i, maxl+1){
		if(!is_ancestor(anc[u][i], v)){
			u = anc[u][i];
		}
	}

	return anc[u][0];
}

void restart(){
	tempo = 0;
	fr(i, n+1){
		adj[i].clear();
	}

	frr(i, n) pr[i] = 0;
}

int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(peso[a] > peso[b]) swap(a, b);

	pai[b] = a;
	peso[a]+=peso[b];
}

void extra(){
	frr(i, n) {
		pai[i] = i;
		peso[i] = 1;
	}
	fr(i, n){
		int v1, v2;
		ll et;
		cin >> v1 >> v2 >> et;

		e[i] = mp(et, mp(v1, v2));
	}

	sort(e, e + n);

	fr(i, n){
		int v1, v2;
		ll et;
		v1 = e[i].s.f;
		v2 = e[i].s.s;
		et = e[i].f;

		if(find(v1) == find(v2)){
			v1Extra = v1;
			v2Extra = v2;
			pesoExtra = et;
		}
		else{
			adj[v1].pb(mp(v2, et));
			adj[v2].pb(mp(v1, et));

			join(v1, v2);
		}
	}

}

ll d(int v1, int v2){
	return dist[v1] + dist[v2] - 2*dist[lca(v1, v2)];
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		cin >> n >> q;
		maxl = ceil(log(n)/log(2));

		restart();
		extra();

		dist[1] = 0;
		dfs(1, 1);
/*
		frr(i, n) cout << dist[i] <<" ";
		cout << endl;

		cout << v1Extra << " " << v2Extra << " " << pesoExtra << endl;
*/
		while(q--){
			int v1, v2;
			cin >> v1 >> v2;

			ll ans = d(v1, v2);
			//cout << "OLa" << ans << " " << lca(v1, v2) <<  endl;

			ans = min(ans, d(v1, v1Extra) + pesoExtra + d(v2, v2Extra));
			ans = min(ans, d(v1, v2Extra) + pesoExtra + d(v2, v1Extra));
		
			cout << ans << endl;
		}
	}
}
