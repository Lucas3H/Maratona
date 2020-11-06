// https://codeforces.com/problemset/problem/27/D
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

void read(){
	int aux;
	cin >> aux >> g.v;

	t = 0;
	n_scc = 1;

	frr(i, g.v + g.v){
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

	pii ed[MAXN];
	frr(i, g.v){
		int v1, v2;
		cin >> v1 >> v2;

		if(v1 > v2) swap(v1, v2);
		ed[i] = mp(v1, v2);
	}

	frr(i, g.v){
		frr(j, i - 1){
			if((ed[i].f < ed[j].f && ed[j].s < ed[i].s)) continue;
			else if(ed[i].f == ed[j].s || ed[i].f == ed[j].f || ed[i].s == ed[j].s || ed[i].s == ed[j].f) continue;
			else{
				g.e+=4;

				g.adj[i].insert(j + g.v);
				g.adj[j].insert(i + g.v);

				g.adj[i + g.v].insert(j);
				g.adj[j + g.v].insert(i);
			}
		}
	}

	g.v += g.v;
}

void tarjan(){
	frr(i, g.v){
		if(!g.pr[i]){
			t = 0;
			dfs(i);
		}
	}

	/*------------Build metagraph------------*/

	meta.v = n_scc-1;

	frr(i, g.v){
		int v1 = g.comp[i], v2;
		for(auto x: g.adj[i]){
			v2 = g.comp[x];
			if(v1 == v2) continue; // Evitar v -> v

			meta.adj[v1].insert(v2);
		}
	}
}


int ord[MAXN];
int pos = 1;

graph go;

void top_sort(){
	go = meta;

	for(int i = 1; i <= go.v; i++) ord[i] = 0;		
	pos = 1;
	set<int> in_edges[MAXN];

	for(int i = 1; i <= go.v; i++){
		for(auto x: go.adj[i]) in_edges[x].insert(i);
	}

	queue<int> fila;

	for(int i = 1; i <= go.v; i++){
		if(in_edges[i].size() == 0){
			fila.push(i);
		}
	}

	while(!fila.empty()){
		int davez = fila.front();
		fila.pop();

		ord[davez] = pos++;

		for(auto x: go.adj[davez]){

			if(in_edges[x].size() != 0){
				in_edges[x].erase(davez);

				if(in_edges[x].size() == 0) fila.push(x);
			}
		}
	}

	//frr(i, go.v) cout << ord[i] << endl;
}

void solve(){
	int deu = 1;
	int ans[MAXN];

	int x = 0;

	frr(i, g.v/2){
		if(g.comp[i] == g.comp[i + g.v/2]) deu = 0;

		else if(ord[g.comp[i]] < ord[g.comp[i + g.v/2]]) ans[i] = 0;
		else {
			ans[i] = 1;
			x++;
		}
	}

	if(deu){
		frr(i, g.v/2) {
			if(ans[i]) cout << 'i';
			else cout << 'o';
		}

		cout << endl;
	}
	else cout << "Impossible\n";
}

int main(){
	ios::sync_with_stdio(false);

	read();
	tarjan();
	//frr(i, g.v) cout << g.comp[i] << endl;

	top_sort();
	solve();
}