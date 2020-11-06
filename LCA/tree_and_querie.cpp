/*Binary Lifting*/

/*Algoritmo modificado de: https://cp-algorithms.com/graph/lca_binary_lifting.html */


#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define MAXL 30
#define ROOT 1

/*Variaveis do Grafo*/
int n, maxl, v1, v2, e;
vector<int> adj[MAXN];
int pr[MAXN];

/*Servem para verificar se um grafo é ancestral do outro ou não*/
int tin[MAXN];
int tout[MAXN];
int tempo = 0;
int h[MAXN];

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

void restart(){
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        pr[i] = 0;
    }
    tempo = 0;

}

void read(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int dist(int a, int b){
    int l = lca(a, b);
    return h[a] + h[b] - 2*h[l];
}

int main(){
    read();
    maxl = ceil(log(n)/log(2));

    h[ROOT] = 0;
    dfs(ROOT, ROOT);

    int q;
    cin >> q;

    while(q--){
        int a, b, x, y, k;
        cin >> a >> b >> x >> y >> k;

        int d1 = dist(a, x), d2 = dist(y, b), d3 = dist(x, b), d4 = dist(y, a), d5 = dist(x, y);

        if(k >= d1 + d2 + 1 && (k - d1 - d2 - 1)%2 == 0){
            cout << "YES\n";
            continue;
        }
        else if(k >= d3 + d4 + 1 && (k - d3 - d4 - 1)%2 == 0){
            cout << "YES\n";
            continue;
        }
        else if(k >= d5 && (k - d5)%2 == 0){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}