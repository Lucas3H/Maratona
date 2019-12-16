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

#define MAXN 100010

vector<int> adj[MAXN];
int cor[MAXN], bipartido = 1;

void dfs(int v, int c){
	fr(i, adj[v].size()){
		int e = adj[v][i];

		if(cor[e] == -1){
			cor[e] = (c+1)%2;
			dfs(e, c+1);
		}
		else{
			if(cor[e] == cor[v]) bipartido = 0;
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	fr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	mem(cor, -1);

	frr(i, n){
		if(cor[i] == -1){
			cor[i] = 0;
			dfs(i, 0);
		}
	}

	if(bipartido) cout << "É bipartido!" << endl;
	else cout << "Não é bipartido!" << endl;

	return 0;
}
