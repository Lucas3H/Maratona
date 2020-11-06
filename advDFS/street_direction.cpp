// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551 
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

int n, edges;
vector<int> adj[MAXN];
int tin[MAXN], pr[MAXN];
int t = 0;

int low_link[MAXN];
pii edge[2*MAXN];
int is_bridge[2*MAXN];
int visited[2*MAXN];


void dfs(int v, int pai){
	pr[v] = 1;
	tin[v] = t++;
	low_link[v] = tin[v];

	for(auto x: adj[v]){
		int u = edge[x].s;
		
		if(u == pai) continue;

		if(x%2 == 0 && !visited[x + 1]) visited[x] = 1;
		if(x%2 == 1 && !visited[x-1]) visited[x] = 1;

		if(!pr[u]){
			dfs(u, v);

			
			low_link[v] = min(low_link[v], low_link[u]);
		
			if(low_link[u] > tin[v]){
				int k = x/2;
				is_bridge[2*k] = 1;
				is_bridge[2*k+1] = 1;
			}
		}
		else{
			if(low_link[v] <= tin[u]){
				is_bridge[x] = 0;
			}
			low_link[v] = min(low_link[v], tin[u]);
		}
	}

	tin[v] = MOD;
}

int detect_bridges(){
	cin >> n >> edges;
	
	if(n == 0 && edges == 0) return 0;

	frr(i, n) {
		low_link[i] = 0;
		adj[i].clear();
		tin[i] = 0;
		pr[i] = 0;
		t = 0;
	}

	fr(i, 2*edges) {
		visited[i] = 0;
		is_bridge[i] = 0;
	}

	fr(i, edges){
		int v1, v2;
		cin >> v1 >> v2;

		edge[2*i] = mp(v1, v2);
		edge[2*i+1] = mp(v2, v1);

		adj[v1].pb(2*i);
		adj[v2].pb(2*i+1);
	}

	for(int i = 1; i <= n; i++){
		if(!pr[i]) dfs(i, i);
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(false);

	int ts = 1;
	while(detect_bridges()){
		cout << ts++ << endl << endl;

		//if(ts == 8) cout << n << " op " << edges << endl;
		fr(i, 2*edges){
			//if(ts == 8) cout << edge[i].f << " " << edge[i].s << endl; 
			//if(is_bridge[i]) cout << "FDP " << edge[i].f << " " << edge[i].s << endl;

			if(is_bridge[i] || visited[i]) cout << edge[i].f << " " << edge[i].s << endl;
		}

		cout << '#' << endl;
	}
}