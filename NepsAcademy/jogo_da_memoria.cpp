#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1)
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 50010
#define MAXL 17
int n;

vector<int> aresta[MAXN];
int pai[MAXN], nivel[MAXN], carta[MAXN];
vector<pii> par;

int ancestral[MAXN][MAXL+2];

void dfs(int u){
	fr(i, aresta[u].size()){
		int e = aresta[u][i];

		if(nivel[e] == -1){
			nivel[e] = nivel[u] + 1;
			pai[e] = u;
			dfs(e);
		}
	}
}

int lca(int a, int b){

	if(nivel[a] < nivel[b]) swap(a, b);

	frm(i, MAXL){
		if(nivel[a] - pow(2, i) >= nivel[b]) a = ancestral[a][i];
	}

	if(a == b) return a;

	frm(i, MAXL){
		if(ancestral[a][i] != -1 && ancestral[a][i] != ancestral[b][i]){
			a = ancestral[a][i];
			b = ancestral[b][i];
		}
	}

	return ancestral[a][0];
}

int main(){
	cin >> n;

	mem(carta, 0);

	frr(i, n){
		int x;
		cin >> x;

		if(carta[x] == 0) carta[x] = i;
		else par.pb(mp(carta[x], i));
	}

	fr(i, n-1){
		int a, b;
		cin >> a >> b;

		aresta[a].pb(b);
		aresta[b].pb(a);
	}

	mem(nivel, -1);
	nivel[1] = 0;
	pai[1] = 1;
	dfs(1);

	mem(ancestral, -1);

	frr(i, n) ancestral[i][0] = pai[i];

	frr(j, MAXL-1){
		frr(i, n) ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
	}

	int soma = 0;

	fr(i, n/2){
		int a = par.back().first, b = par.back().second;
		par.pop_back();

		soma += nivel[a] + nivel[b] - 2*nivel[lca(a, b)];
	}

	cout << soma << endl;
}
