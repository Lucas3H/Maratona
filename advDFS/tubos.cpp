// https://br.spoj.com/problems/TUBOS/
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

#define MAXN 1010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int n, m;
vector<int> adj[MAXN];

int pr[MAXN], tin[MAXN], low_link[MAXN];
int t, deu;

void dfs(int v, int pai){
	pr[v] = 1;
	tin[v] = t++;
	low_link[v] = tin[v];

	for(auto x: adj[v]){
		if(x == pai) continue;

		if(!pr[x]){
			dfs(x, v);

			low_link[v] = min(low_link[v], low_link[x]);

			if(low_link[x] > tin[v]) deu = 0;
		}
		else{
			low_link[v] = min(low_link[v], tin[x]);
		}
	}
}

int read(){
	cin >> n >> m;

	if(n == 0 && m == 0) return 0;
	
	t = 0;
	deu = 1;
	frr(i, n){
		pr[i] = 0;
		adj[i].clear();
	}
	
	fr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}
	
	return 1;
}

int main(){
	ios::sync_with_stdio(false);

	while(read()){
		dfs(1, 1);
		if(deu) cout << "S" << endl;
		else cout << "N" << endl;
	}
	cout << endl;
}
