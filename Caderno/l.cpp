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
typedef pair<ll, ll> pll;
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

class LCA{
public:
	int n, maxl, v1, v2, e;
	vector<int> adj[MAXN];
	int pr[MAXN];

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
	    int l = lca(a, b);
	    return h[a] + h[b] - 2*h[l];
	}
};

LCA L;
int q;
void read(){
    cin >> L.n >> q;
    for(int i = 0; i < L.n-1; i++){
        int u, v;
        cin >> u >> v;

        L.adj[u].push_back(v);
        L.adj[v].push_back(u);
    }
}

int main(){
	ios::sync_with_stdio(false);

	read();

	L.maxl = ceil(log(L.n)/log(2));

    L.h[1] = 0;
    L.dfs(1, 1);

	while(q--){
		pii g, h;
		cin >> g.f >> g.s >> h.f >> h.s;

		int x = L.lca(g.f, g.s), y = L.lca(h.f, h.s);

		//cout << x << " " << y << endl;

		if(!L.is_ancestor(x, y) && !L.is_ancestor(y, x)){
			cout << 0 << endl;
			continue;
		}
		else if(L.is_ancestor(y, x)){
			swap(x, y);
			swap(g, h);
		}

		int z1 = L.lca(g.f, h.f), z2 = L.lca(g.s, h.f), z;

		if(L.h[z1] > L.h[z2]) z = z1;
		else z = z2;

		int w1 = L.lca(g.f, h.s), w2 = L.lca(g.s, h.s), w;

		if(L.h[w1] > L.h[w2]) w = w1;
		else w = w2;

		//cout << z << " " << w << endl;

		if(z == w){
			if(z == y) cout << 1 << endl;
			else cout << 0 << endl;
		}
		//cout << z << ' ' << w << endl;
		else
			cout << L.dist(z, w) + 1 << endl;
	}
}
