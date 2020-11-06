// https://codeforces.com/contest/342/problem/E
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

int n, m;
vector<int> adj[MAXN];
int pr[MAXN];

int d[MAXN], cor[MAXN];
pii query[MAXN];

/*-------------------LCA-----------------*/
/*Variaveis do Grafo*/
int maxl;

/*Servem para verificar se um grafo é ancestral do outro ou não*/
int tin[MAXN];
int tout[MAXN];
int h[MAXN];
int tempo = 0;

/*Variaveis do LCA*/
int ancestor[MAXN][MAXL];

void dfs(int v, int pai){
    pr[v] = 1;

	h[v] = h[pai] + 1;

    ancestor[v][0] = pai;
    for(int i = 1; i <= maxl; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }
    
    tin[v] = tempo++;

    for(int u: adj[v]){
        if(!pr[u]) dfs(u, v);
    }

    tout[v] = tempo++;
}

bool is_ancestor(int v, int u){
    return (tin[v] <= tin[u] && tout[v] >= tout[u]);
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;

    for (int i = maxl; i >= 0; --i) {
        if (!is_ancestor(ancestor[a][i], b))
            a = ancestor[a][i];
    }

    return ancestor[a][0];
}

int dist(int a, int b){
	return h[a] + h[b] - 2*h[lca(a, b)];
}

//-----------------------------------------



void bfs_cor(){
	queue<int> fila;
	int p[MAXN];

	frr(i, n) {
		p[i] = 0;
		if(cor[i]){
			d[i] = 0;
			fila.push(i);
		}
		else  d[i] = MAXN;
	}


	while(!fila.empty()){
		int davez = fila.front();
		fila.pop();

		if(p[davez]) continue;
		else p[davez] = 1;

		for(auto x: adj[davez]){
			if(!p[x]){
				d[x] = min(d[davez] + 1, d[x]);
				fila.push(x);
			}
		}
	}
}

void solve(){
	int len = (int)sqrt(m +.0) + 1;
	int i = 0;

	set<int> vermelhos;
	while(i < m){
		for(int j = 0; i < m && j < len; j++) {
			int vt = query[i].s;
			if(query[i].f == 1){
				vermelhos.insert(vt);
				cor[vt] = 1;
			}
			else{
				int ans = d[vt];
				for(auto x: vermelhos) ans = min(ans, dist(vt, x));

				printf("%d\n", ans);
			}
			
			i++;
		}

		bfs_cor();	
		vermelhos.clear();
	}
}





void read(){
	cin >> n >> m;
	frr(i, n) d[i] = MAXN;
	
	fr(i, n-1){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

    maxl = ceil(log(n)/log(2));

	cor[1] = 1;
	dfs(1, 1);
	frr(i, n) d[i] = h[i] - 1;
	
	fr(i, m) cin >> query[i].f >> query[i].s;
}

int main(){

	read();
	solve();

}
