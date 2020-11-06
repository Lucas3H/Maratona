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

class Graph{
	public:
    int pai[MAXN];

	    /*Variaveis do Grafo*/
    int n, maxl, v1, v2, e;
    set<int> adj[MAXN];
    int pr[MAXN];

    /*Servem paia verificar se um grafo é ancestral do outro ou não*/
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

/*Vertices são 1, 2, ..., n*/
class Centroid{
	public:
    Graph G, CT; /*Centroid tree*/
	int pai[MAXN], size[MAXN];

	void dfs(int u,int p){
		size[u]=1;
		for(auto x: G.adj[u]){
			if(x != p){
				dfs(x,u);
				size[u]+=size[x];
			}
		}
	}
	
	int find_centroid(int u, int p, int sz){
		for(auto x: G.adj[u]){
			if(x!=p && size[x] > sz/2)
				return find_centroid(x, u, sz);
		}
		return u;
	}

	void decompose(int root, int p){
		dfs(root,root);
		int c = find_centroid(root,root, size[root]);
		
		pai[c] = p;

		for(auto x: G.adj[c]){
			G.adj[x].erase(c);
			decompose(x, c);
		}
		G.adj[c].clear();
	}
};

multiset<int> ans[MAXN];
Centroid C;

void update(int u){
	int x = u;
    while(x != 0){
        ans[x].insert(C.G.dist(x, u));
		x = C.pai[x];
	}
}

void remove(int u){
    int x = u;
	while(x != 0){
        auto it = ans[x].find(C.G.dist(x, u));
		ans[x].erase(it);
		x = C.pai[x];
	}
}

int query(int u){
	int x = u;
	int ret = INF;

	while(x != 0){
		ret = min(ret ,C.G.dist(u,x) + *(ans[x].begin()));
        x = C.pai[x];
	}
	return ret;
}

int n, m;
void read(){
	cin >> n;

	fr(i, n-1){
		int u, v;
		cin >> u >> v;
		C.G.adj[v].insert(u);
		C.G.adj[u].insert(v);
	}
	
    frr(i, n) ans[i].insert(INF);

	C.G.maxl = ceil(log2(n));
	C.G.dfs(1, 1);

	C.decompose(1, 0);
}

int cor[MAXN];

void solve(){
    cin >> m;
	while(m--){
		int a, b;
		cin >> a >> b;

		if(a == 0){
			if(cor[b])
                remove(b);
            else
                update(b);
            cor[b]^=1;    
        }
		else{
			int aux = query(b);
            if(aux == INF) cout << -1 << endl;
            else printf("%d\n", query(b));
        }
	}
}

int main(){
	read();
	solve();
}
