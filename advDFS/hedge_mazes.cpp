// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3785
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

int r, c, q;

vector<int> adj[MAXN];
int t;
int tin[MAXN], low_link[MAXN], pr[MAXN], comp[MAXN];
pii e[2*MAXN];
int is_bridge[2*MAXN];


void dfs_find_bridges(int v, int pai){
	pr[v] = 1;
	tin[v] = t++;
	low_link[v] = tin[v];

	for(auto x: adj[v]){
		int u = e[x].s;
		if(u == pai) continue;

		int k = x/2;

		if(!pr[u]){
			dfs_find_bridges(u, v);

			low_link[v] = min(low_link[u], low_link[v]);

			if(low_link[u] > tin[v]) {
				is_bridge[2*k] = 1;
				is_bridge[2*k + 1] = 1;
			}
			else {
				is_bridge[2*k] = 0;
				is_bridge[2*k + 1] = 0;
			}
		}
		else{
			low_link[v] = min(low_link[v], tin[u]);
			is_bridge[2*k] = 0;
			is_bridge[2*k + 1] = 0;
		}
	}

}

void dfs_find_comp(int v){
	pr[v] = 1;

	for(auto x: adj[v]){
		if(!is_bridge[x]) continue;

		int u = e[x].s;
		if(!pr[u]){
			comp[u] = comp[v];
			dfs_find_comp(u);
		}
	}
}

void solve(){
	frr(i, r){
		if(!pr[i]){
			dfs_find_bridges(i, i);
			t = 0;
		}
	}
/*
	frr(i, r) cout << tin[i] << " ";
	cout << endl;

	frr(i, r) cout << low_link[i] << " ";
	cout << endl;

	fr(i, 2*c) cout << e[i].f << " " << e[i].s << " " << is_bridge[i] <<endl;
	cout << endl; 
*/
	frr(i, r) pr[i] = 0;

	frr(i, r){
		if(!pr[i]){
			comp[i] = i;
			dfs_find_comp(i);
		}
	}

	frr(i, q){
		int a, b;
		cin >> a >> b;

		if(comp[a] == comp[b]) cout << "Y" << endl;
		else cout << "N" << endl;
	}

	cout << "-\n";
}

int read(){
	cin >> r >> c >> q;

	if(r == 0 && c == 0 && q == 0) return 0;

	t = 0;
	frr(i, r){
		pr[i] = 0;
		adj[i].clear();
	}

	fr(i, c){
		int v1, v2;
		cin >> v1 >> v2;

		e[2*i] = mp(v1, v2);
		e[2*i+1] = mp(v2, v1);

		adj[v1].pb(2*i);
		adj[v2].pb(2*i+1);
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	while(read()){
		solve();
	}
}
