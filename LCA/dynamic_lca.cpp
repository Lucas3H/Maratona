//https://codeforces.com/gym/100512/attachments
#include<bits/stdc++.h>
#include <fstream>

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

int n, maxl, root, m;
vector<int> adj[MAXN];
int pr[MAXN], tin[MAXN], tout[MAXN], tempo, h[MAXN];
int anc[MAXN][35];

void dfs(int v, int pai){
	pr[v] = 1;
	h[v] = h[pai]+1;

	anc[v][0] = pai;
	frr(i, maxl){
		anc[v][i] = anc[anc[v][i-1]][i-1];
	}

	tin[v] = tempo++;
	for(auto x: adj[v]){
		if(!pr[x]) dfs(x, v);
	}

	tout[v] = tempo++;
}

bool is_ancestor(int v, int u){
	return tin[v] <= tin[u] && tout[v] >= tout[u];
} 

int lca(int v, int u){
	if(is_ancestor(v, u)) return v;
	if(is_ancestor(u, v)) return u;

	frm(i, maxl+1){
		if(!is_ancestor(anc[v][i], u)){
			v = anc[v][i];
		}
	}

	return anc[v][0];
}

void restart(){
	frr(i, n) adj[i].clear();
	tempo = 0;
	frr(i, n) pr[i] = 0;

	maxl = ceil(log(n)/log(2));

	root = 1;
}

int main(){
	freopen("dynamic.in", "r", stdin);
	freopen("dynamic.out", "w", stdout);

	cin >> n;
	while(n!=0){
		restart();

		int v1, v2;
		fr(i, n-1){
			cin >> v1 >> v2;

			adj[v1].pb(v2);
			adj[v2].pb(v1);
		}

		h[1] = 0;
		dfs(1, 1);

		cin >> m;
		fr(i, m){
			char op;
			cin >> op;

			if(op == '!'){
				int v;
				cin >> v;
				root = v;
			}
			else{
				int v1, v2;
				cin >> v1 >> v2;

				int l0 = lca(v1, v2), l1 = lca(v1, root), l2 = lca(v2, root);

				if(h[l0] >= h[l1] && h[l0] >= h[l2]) cout << l0 << endl;
				else if(h[l0] <= h[l1] && h[l1] >= h[l2]) cout << l1 << endl;
				else cout << l2 << endl;
			}
		}

		cin >> n;

	}
}
