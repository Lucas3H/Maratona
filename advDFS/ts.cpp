// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2499 
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

#define MAXN 100010
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

graph g, meta;
stack<int> s;
int n_scc = 1;

void makeComp(int id){
	int st = s.top();

	while(st != id){
		g.low_link[st] = INF; // Evitar cross-edges
		g.tin[st] = INF; // Evitar cros-edges
		g.comp[st] = n_scc;
		s.pop();
		st = s.top();
	}

	g.low_link[id] = INF; // Evitar cros-edges
	g.tin[id] = INF; // Evitar cros-edges
	g.comp[id] = n_scc++;
	s.pop();
}

void dfs(int v){
	g.pr[v] = 1;
	g.tin[v] = t++;
	g.low_link[v] = g.tin[v];
	s.push(v);

	for(auto x: g.adj[v]){
		if(!g.pr[x]){
			dfs(x);

			g.low_link[v] = min(g.low_link[v], g.low_link[x]);
		}
		else{
			g.low_link[v] = min(g.low_link[v], g.tin[x]);
		}
	}

	if(g.low_link[v] == g.tin[v]){
		makeComp(v);
	}
}

void read(){
	cin >> g.v >> g.e;

	t = 0;
	n_scc = 1;

	frr(i, g.v){
		g.adj[i].clear();
		g.pr[i] = 0;
		meta.adj[i].clear();
	}

	fr(i, g.e){
		int v1, v2;
		cin >> v1 >> v2;

		g.adj[v1].insert(v2);
	}
}

void tarjan(){
	frr(i, g.v){
		if(!g.pr[i]){
			t = 0;
			dfs(i);
		}
	}

	frr(i, g.v){
		int v1 = g.comp[i], v2;

		for(auto x: g.adj[i]){
			v2 = g.comp[x];
			if(v1 == v2) continue;
			meta.adj[v2].insert(v1);
		}
	}

	int ans = 0;
	frr(i, n_scc-1){
		if(meta.adj[i].size() == 0) ans++;
	}

	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);

	int ts;
	cin >> ts;
	frr(t, ts){
		read();
		tarjan();
	}
}
