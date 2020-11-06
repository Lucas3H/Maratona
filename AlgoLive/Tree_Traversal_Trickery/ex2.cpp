#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define MAXK 1010

int n, k;
vector<int> adj[MAXN];
int val[MAXN];
int pr[MAXN];

int pre_ord[MAXN];
int pos_ord[MAXN];
int ind = 1;

int dp[MAXN][MAXK];

void dfs(int v){
	pr[v] = 1;

	pre_ord[ind++] = v;
	for(int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];

		if(!pr[u]) dfs(u);
	}

	pos_ord[v] = ind;
}

int main(){
	cin >> n >> k;

	for(int i = 0; i < n-1; i++){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	for(int i = 1; i <= n; i++) cin >> val[i];

	dfs(1);

	int cur[MAXN], prv[MAXN];

	for(int cont = 0; cont < k; cont++){
		cur[ind] = -1000000000;
		
		for(int i = ind - 1; i > 0; i--){
			cur[i] = max(cur[i+1], prv[pos_ord[pre_ord[i]]] + val[pre_ord[i]]);
		}

		for(int i = 0; i <= ind; i++) prv[i] = cur[i];
	}

	cout << cur[1] << endl;


	/*Base da DP*/
/*	
	for(int i = 0; i <= ind; i++) dp[i][0] = 0;
	for(int i = 1; i <= k; i++) dp[ind][i] = -1000000000;

	for(int j = 1; j <= k; j++){
		for(int i = ind - 1; i > 0; i--){
			dp[i][j] = max(dp[pos_ord[pre_ord[i]]][j-1] + val[pre_ord[i]], dp[i+1][j]);
			//cout << i << " " << dp[i][j] << " " << pos_ord[pre_ord[i]] << " " << val[pre_ord[i]] << endl;
		}
	}
	
	cout << dp[1][k] << endl;
*/

}
