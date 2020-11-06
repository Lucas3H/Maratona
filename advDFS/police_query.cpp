// https://www.spoj.com/problems/POLQUERY/
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
#define MAXL 30
#define ROOT 1

struct graph{
	vector<int> adj[MAXN];
	int comp[MAXN], pr[MAXN], tin[MAXN], tout[MAXN];
}

int n, m;

pii e[10*MAXN];
int is_bridge[10*MAXN];

graph g, vertexCC, edgeCC;
int low_link[MAXN];
int t, children;

void dfs_g(int v, int pai){
	g.pr[v] = 1;
	tin[v] = t++;
	low_link[v] = tin[v];

	for(auto x: g.adj[v]){
		int u = e[x].s;

		if(u == pai) continue;

		int k = x/2;
		if(!pr[u]){
			g.comp[u] = g.comp[v];
			dfs(x, v);

			if(pai == v) children++;

			low_link[v] = min(low_link[v], low_link[u]);

			if(low_link[u] > tin[v]) {
				is_bridge[2*k] = 1;
				is_bridge[2*k+1] = 1;
			}
			if(low_link[u] >= tin[v]) is_art[v] = 1;
		}
		else{
			low_link[v] = min(low_link[v], tin[u]);
		}
	}
}

graph davez;

void dfs_tin(int v){
	davez.pr[v] = 1;
	davez.tin[v] = t++;

	for(auto x: davez.adj[v]){
		if(!davez.pr[x]){
			dfs_tin(x);
		}
	}

	davez.tout[v] = t -1 ;
}

void dfs_edgeCC_comp(int v){
	edgeCC.pr[v] = 1;
	for(auto x: g.adj[v]){
		if(is_bridge[x]) continue;

		int u = e[x].s;

		if(!edgeCC.pr[u]){
			edgeCC.comp[u] = edgeCC.comp[v];
			dfs_edgeCC_comp(u);
		}
	}
}

void set_adj_edgeCC(){
	frr(i, n){
		if(!edge.pr[i]){
			edge.comp[i] = i;
			dfs_edgeCC_comp(i);
		}
	}
	fr(i, 2*m){
		if(is_bridge[i]){
			int v1 = edgeCC.comp[e[i].f], v2 = edgeCC.comp[e[i].s];

			if(v1 == v2) continue;

			edgeCC.adj[v1].pb(v2);
			edgeCC.adj[v2].pb(v1);
		}
	}

	frr(i, n) edgeCC.pr[i] = 0;

	t = 0;
	davez = edgeCC;
	dfs_tin(1);
}

int n_comps = 1;
stack<int> s;

void makeComp(int id){
	set<int> compo;

	int k = comp.size();

	int it = s.top();
	while(!s.empty() && it != id){
		vertexCC.comp[e[it].f] = n_comps;
		vertexCC.comp[e[it].s] = n_comps;
		
		s.pop();
		it = s.top();
	}

	n_comps++;
}

void dfs_vertexCC_comp(int v, int pai){
	vertexCC.pr[v] = 1;
	for(auto x: g.adj[v]){
		int u = e[x].s;
		if(u == pai) continue;

		s.insert(x);

		if(!artCC.pr[u]){
			if(is_art[v]) makeComp(x);
		}
	}
}

void set_adj_vertexCC(){
	frr(i, n){
		if(!vertex.pr[i]){
			vertex.comp[i] = i;

			if(!is_art[i]){
				dfs_vertexCC_comp(i);
				makeComp(-1);
			}
		}
	}

	frr(i, n){
		if(is_art[i]){
			vertexCC.comp[i] = n_comps++;
		}
	}

	fr(i, 2*m){
		int v1 = vertexCC.comp[e[i].f], v2 = vertexCC.comp[e[i].s];

		if(v1 == v2) continue;

		if(is_art[e[i].f] || is_art[e[i].s]){
			adj[v1].pb(v2);
			adj[v2].pb(v1);
		}
	}

	frr(i, n) vertexCC.pr[i] = 0;

	t = 0;
	davez = vertexCC;
	dfs_tin(1);
}

void read(){
	scanf("%d %d", &n, &m);

	fr(i, m){
		int v1, v2;
		scanf("%d %d", &v1, &v2);

		e[2*i] = mp(v1, v2);
		a[2*i+1] = mp(v2, v1);

		adj[v1].pb(2*i);
		adj[v2].pb(2*i+1);
	}
}

bool is_ancestor_edgeCC(int v, int u){
    return (edgeCC.tin[v] <= edgeCC.tin[u] && edgeCC.tout[v] >= edgeCC.tout[u]);
}

bool is_ancestor_vertexCC(int v, int u){
    return (vertexCC.tin[v] <= vertexCC.tin[u] && vertexCC.tout[v] >= vertexCC.tout[u]);
}

bool is_in_path_edgeCC(int a, int b, int c){
	if(is_ancestor_edgeCC(a, c)) swap(a, c);

	if(is_ancestor_edgeCC(c, a)){
		if(is_ancestor_edgeCC(b, a)) return 1;
		else return 0;
	}
	else{
		
	}

}

int main(){
	read();

	dfs_g(1);
	set_adj_edgeCC();
	set_adj_vertexCC();

	int q;
}
