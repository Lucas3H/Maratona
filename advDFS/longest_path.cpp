// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=941F 
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

int n, s;
vector<int> adj[110];

pii dp[110];

pii dfs(int v){
	if(dp[v] != mp(-1, -1)) return dp[v];

	pii ans = mp(0, v);
	pii aux;

	for(auto x: adj[v]){
		aux = dfs(x);

		if(aux.f >= ans.f) ans = mp(aux.f + 1, aux.s);
		else if(aux.f == ans.f - 1 && aux.s < ans.s) ans = mp(ans.f, aux.s); 
	}

	return dp[v] = ans;
}

int read(){
	scanf("%d", &n);

	if(n == 0) return 0;
	
	scanf("%d", &s);

	frr(i, n) {
		adj[i].clear();
		dp[i] = mp(-1, -1);
	}
	int a, b;
	scanf("%d %d", &a, &b);

	while(a != 0 && b != 0){
		adj[a].pb(b);
		scanf("%d %d", &a, &b);
	}

	return 1;
}

int main(){
	int cnt = 1;
	while(read()){
		pii aux = dfs(s);

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cnt++, s, aux.f, aux.s);
	}
}
