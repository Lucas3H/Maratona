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

#define MAXN 10010

vector<int> adj[MAXN];
int processado[MAXN];
pii maior_galho[MAXN];

int dfs(int v){
	processado[v] = 1;

	int g1 = 0, g2 = 0;
	fr(i, adj[v].size()){
		int e = adj[v][i];

		if(processado[e] == -1){
			int x = dfs(e);
			
			if(x > g1){
				g2 = g1;
				g1 = x;
			} 
			else if(x > g2) g2 = x;
		}
	}

	maior_galho[v] = mp(g1, g2);
	return g1 + 1;
}

int main(){
	int n;
	cin >> n;

	fr(i, n-1){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	mem(processado, -1);

	int g = dfs(1);

	int M = 0;
	frr(i, n){
		if(M < maior_galho[i].first + maior_galho[i].second) M = maior_galho[i].first + maior_galho[i].second;
	}

	cout << M << endl;
}
