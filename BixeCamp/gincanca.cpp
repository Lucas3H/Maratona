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

vector<int> aresta[1010];

int componente[1010];

void dfs(int v){
	fr(i, aresta[v].size()){
		int e = aresta[v][i];

		if(componente[e] == -1){
			componente[e] = componente[v];
			dfs(e);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	frr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		aresta[v1].pb(v2);
		aresta[v2].pb(v1);
	}

	mem(componente, -1);

	int resp = 0;
	frr(i, n){
		if(componente[i] == -1){
			componente[i] = i;
			resp++;
			dfs(i);
		}
	}

	cout << resp << endl;

	return 0;
}
