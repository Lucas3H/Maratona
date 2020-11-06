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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 1000010
#define MOD 1000000007
#define INF 1000000000
#define MAXL 30
#define ROOT 1

struct graph{
	int v, e;
	set<int> adj[MAXN]; // Evitar arestas múltiplas
	int tin[MAXN], pr[MAXN], comp[MAXN], low_link[MAXN];
};

int t = 0;

int up_to[MAXN];

graph g, meta;
stack<int> s;
int n_scc = 1;

void makeComp(int id){
	while(true){
		int st = s.top();

		g.low_link[st] = INF; // Evitar cross-edges
		g.tin[st] = INF; // Evitar cros-edges
		g.comp[st] = n_scc;
		s.pop();
		
		if(st == id) break;
	}

	n_scc++;
}
void dfs(int v){
	g.pr[v] = 1;
	g.tin[v] = t++;
	g.low_link[v] = g.tin[v];
	s.push(v);

	for(auto x: g.adj[v]){
		if(!g.pr[x]){
			dfs(x);
		}

		g.low_link[v] = min(g.low_link[v], g.low_link[x]);
	}

	if(g.low_link[v] == g.tin[v]){
		makeComp(v);
	}
}

pair<pii, pii> p[MAXN];
int e;
	
int read(){
	edge.clear();

	cin >> g.v >> e;

	if(g.v == 0 && e == 0) return 0;

	frr(i, e){
		int op, a, b;
		cin >> op >> a >> b;

		if()
	}

	g.v += g.v;

	return 1;
}

void build(int r){

	t = 0;
	n_scc = 1;

	frr(i, g.v){
		g.adj[i].clear();

		meta.adj[i].clear();
		g.tin[i] = 0;
		g.pr[i] = 0;
		g.comp[i] = 0;
		g.low_link[i] = 0;

		meta.tin[i] = 0;
		meta.pr[i] = 0;
		meta.comp[i] = 0;
		meta.low_link[i] = 0;
	}

	fr(i, up_to[l]){
		int v1, v2, op;
		v1 = p[i].f.f;
		v2 = p[i].f.s;
		
		if(p[i].s.f*p[i].s.s == -1){
			g.adj[v1 + g.v/2].insert(v2);
			g.adj[v2 + g.v/2].insert(v1);

			g.adj[v1].insert(v2 + g.v/2);
			g.adj[v2].insert(v1 + g.v/2);
		}
		else{
			g.adj[v1 + g.v/2].insert(v2 + g.v/2);
			g.adj[v2 + g.v/2].insert(v1 + g.v/2);

			g.adj[v1].insert(v2);
			g.adj[v2].insert(v1);
		}
	}
}

void tarjan(){
	frr(i, g.v){
		if(!g.pr[i]){
			t = 0;
			dfs(i);
		}
	}
}

int solve(){
	int deu = 1;

	frr(i, g.v/2){
		if(g.comp[i] == g.comp[i + g.v/2] && g.comp[i] != 0) return 0;
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(false);

	read();

	//frr(i, e) cout << p[i].f.f << " " << p[i].f.s << ' ' << p[i].s.f << " " << p[i].s.s << endl;

	int l = 1, r = e, mid;

	build(e);
	tarjan();
/*
	frr(i, g.v){
		cout <<i << endl;
		for(auto x: g.adj[i]) cout << x << " ";
		cout << endl;
	}
*/
	if(solve()){
		frr(i, e) cout << "Yes\n";
	}
	else{
		while(l < r - 1){
			mid = (l+r)/2;

			build(mid);
			tarjan();

			if(solve()) l = mid;
			else r = mid - 1;
		}

		frr(i, l) cout << "Yes\n";
		for(int i = l + 1; i <= e; i++) cout << "No\n";
	}
}
