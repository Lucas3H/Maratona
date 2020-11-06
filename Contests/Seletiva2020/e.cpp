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

int n, m, v1, v2;
vector<int> adj[MAXN];
int pr[MAXN], milk[MAXN], ans[MAXN];

int tin[MAXN], tout[MAXN];
int tempo = 0;

int ancestor[MAXN][MAXL + 3];

void dfsLCA(int v, int pai){
    pr[v] = 1;

    ancestor[v][0] = pai;
    for(int i = 1; i <= MAXL; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }
    
    tin[v] = tempo++;

    for(auto u: adj[v]){
        if(!pr[u]) dfsLCA(u, v);
    }

    tout[v] = tempo++;
}

bool is_ancestor(int v, int u){
    return (tin[v] <= tin[u] && tout[v] >= tout[u]);
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;

    for (int i = MAXL; i >= 0; --i) {
        if (!is_ancestor(ancestor[a][i], b))
            a = ancestor[a][i];
    }

    return ancestor[a][0];
}

vector<pair<int, pii>> q[MAXN];

void read(){
	cin >> n >> m;
	frr(i, n) cin >> milk[i];
	
    fr(i, n-1){
		cin >> v1 >> v2;
		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	dfsLCA(1, 1);

	frr(i, m){
		int a, b, c;
		cin >> a >> b >> c;

		int l = lca(a, b);

		q[a].pb(mp(i, mp(l, c)));
		q[b].pb(mp(i, mp(l, c)));
	}
    
    frr(i, n) pr[i] = 0;
}

stack<int> available[MAXN];

void dfs(int v){
    pr[v] = 1;

    available[milk[v]].push(v);

    for(auto x: q[v]){
        if(!available[x.s.s].empty() && is_ancestor(x.s.f, available[x.s.s].top())){
            ans[x.f] = 1;
        }
    }

    for(auto x: adj[v]){
        if(!pr[x]) dfs(x);
    }

    available[milk[v]].pop();
}

int main(){
	ios::sync_with_stdio(false);
    read();
    dfs(1);

    frr(i, m)cout << ans[i];
    cout << endl;
}
