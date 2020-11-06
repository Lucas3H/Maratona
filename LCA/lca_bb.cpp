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

/*Variaveis do LCA*/
int ancestor[MAXN][MAXL];

void dfs(int v, int pai){
    pr[v] = 1;

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

/*Retorna o k-ésimo elemento no caminho de v até o ROOT*/
int kth(int v, int k){
	int i = maxl;
    k--;

	while(k > 0){
		if((1 << i) <= k){
			k -= (1 << i);
			v = ancestor[v][i];
		}

		i--;
	}

	return v;
}

void restart(){
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        pr[i] = 0;
    }
    tempo = 0;

}

int main(){
    maxl = ceil(log(n)/log(2));

    dfs(ROOT, ROOT);
}