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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

/*
	É dada uma árvore com N vértices e o vértice i está associado a um valor v[i], também dado.
	Há Q queries com u e v, e cada uma quer saber o número de valores distintos que tem no caminho
	entre u e v.

	Primeiramente, vou linearizar a árvore, marcando na linha do tempo o tin e o tout de cada vértice.

	Agora, usando o algoritimo de Mo e a estrutura de dados SQRT decomp. , dá para resolver o problema
	com o seguinte porém: se um vértice aparece duas vezes no mesmo intervalo, siginifica que ele não
	pertence ao caminho entre u e v, portanto, eu retiro ele.

	É necessário as funçoes de LCA também

	Todas as queries são feita em O((N + Q)*sqrt(N)). Não pode ser usada quando há update.
*/

/*------------------------LCA------------------------*/
/*Variaveis do Grafo*/
int n, maxl, v1, v2, e;
vector<int> adj[MAXN];
int pr[MAXN];
int linha[2*MAXN];

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
    
	linha[tempo] = v;
    tin[v] = tempo++;

    for(int u: adj[v]){
        if(!pr[u]) dfs(u, v);
    }

	linha[tempo] = v;
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
/*------------------------ FIM LCA-------------------------*/

struct Query{
	int l, r, idx, LCA;
};

ll len;
vector<int> a, b;

void build(){
	ll aux;
	a.clear();

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> aux;
		a.push_back(aux);
	}

	len = (int) sqrt (n + .0) + 1; 
/*------------Restart LCA--------------*/
	for(int i = 1; i <= n; i++) {
        adj[i].clear();
        pr[i] = 0;
    }
    tempo = 0;

}

bool comp(Query a, Query b){
	if((a.l)/len == (b.l)/len) return a.r < b.r;
	else return (a.l)/len < (b.l)/len;
}

void queryResults(int n_queries){
	vector<Query> q;
	Query aux;
	fr(i, n_queries){
		int u, v;
		cin >> u >> v;
		aux.idx = i;
		
		if(tin[u] > tin[v]) swap(u, v);

		int LCA = lca(aux.l, aux.r);
		if(LCA == aux.l || LCA == aux.r){
			aux.LCA = -1;
			aux.l = tin[u];
			aux.r = tin[v];
		}
		else {
			aux.LCA = LCA;
			aux.l = tout[u];
			aux.r = tin[v];
		}
		q.push_back(aux); 
	}

	sort(q.begin(), q.end(), comp);
	
	int curL = 0, curR = 0; 
    ll curAns = 0; 

	ll ans[MAXN];
	ll app[MAXN];
	fr(i, n+1) app[i] = 0;

	fr(i, n_queries){
		int L = q[i].l, R = q[i].r;
		app[a[q[i].LCA]]++;
		if(app[a[q[i].LCA]] == 1) curAns++;
		
		while (curL > L) { 
			app[a[curL-1]]++;
            if(app[a[curL - 1]] == 1) curAns++; 
            curL--; 
        } 
        while (curR <= R) { 
			app[a[curR]]++;
            if(app[a[curR]] == 1) curAns++;
            curR++; 
        }

		while (curL < L) { 
			app[a[curL]]--;
            if(app[a[curL]] == 0) curAns--;
            curL++; 
        } 

		while (curR > R+1) { 
			app[a[curR - 1]]--;
            if(app[a[curR - 1]] == 0) curAns--;
            curR--; 
        }

		ans[q[i].idx] = curAns;
	}
}

int main(){
	ios::sync_with_stdio(false);

	build();
    maxl = ceil(log(n)/log(2));
    dfs(ROOT, ROOT);
}
