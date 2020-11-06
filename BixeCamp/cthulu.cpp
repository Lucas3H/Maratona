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

vector<int> adj[110];
int componente[110];

void dfs(int s){
	fr(i, adj[s].size()){
		int e = adj[s][i];
		if(componente[e] == -1){
			componente[e] = componente[s];
			dfs(e);
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

	int c = 0;
	mem(componente, -1);
	frr(i, n){
		if(componente[i] == -1){
			c++;
			componente[i] = i;
			dfs(i);
		}
	}

	if(c == 1 && m == n) cout << "FHTAGN!" << endl;
	else cout << "NO" << endl;
}
