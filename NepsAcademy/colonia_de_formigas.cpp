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

#define MAXN 100001
#define MAXL 17

int n, q, L;
int v1, v2;
int a, l;			

vector<pii> aresta[MAXN];
int nivel[MAXN], pai[MAXN];
ll dist[MAXN];
int ancestral[MAXN][MAXL+1];

void dfs(int v){

	fr(i, aresta[v].size()){
		
		int e = aresta[v][i].first; 
		
		if(nivel[e] == -1){
			nivel[e] = nivel[v] + 1;
			pai[e] = v;
			dist[e] = dist[v] + aresta[v][i].second; 

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
	scanf("%d", &n);

	while(n != 0){

		fr(i, n) aresta[i].clear();

		frr(i, n-1){
			scanf("%d %d", &a, &l);
			
			aresta[a].pb(mp(i, l));
			aresta[i].pb(mp(a, l));
		}

		
		fr(i,n) dist[i] = 0;
		fr(i,n) pai[i] = -1;
		pai[0] = 0;
		fr(i, n) nivel[i] = -1;
		nivel[0] = 1;	
		dfs(0);

		memset(ancestral, -1, sizeof(ancestral));

		fr(i, n) ancestral[i][0] = pai[i];

		frr(j, MAXL){
			fr(i, n) ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
		}

		scanf("%d", &q);

		fr(i, q){
			scanf("%d %d", &v1, &v2);

			L = lca(v1, v2);

			ll r = dist[v1] + dist[v2] - 2*dist[L];

			printf("%lld ", r);

		}

		printf("\n");

		scanf("%d", &n);
	}

	return 0;	
}
