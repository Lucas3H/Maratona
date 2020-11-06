// https://acm.timus.ru/problem.aspx?num=1471

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

int n, l;
vector<pii> adj[MAXN];
int tin[MAXN];
int tout[MAXN];
int t;
int dist[MAXN];

int ancestor[MAXN][30];

void dfs(int v, int p){
	tin[v] = t++;

	ancestor[v][0] = p;
	for(int i = 1; i <= l; ++i){
		ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
	}

	for(pii u: adj[v]){
		if(u.f != p){
			dist[u.f] = dist[v] + u.s;
			dfs(u.f, v);
		}
	}

	tout[v] = t++;
}

bool is_ancestor(int a, int b){
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b){
	if(is_ancestor(a, b)) return a;
	if(is_ancestor(b, a)) return b;

	for(int i = l; i >= 0; i--){
		if(!is_ancestor(ancestor[a][i], b)) a = ancestor[a][i];
	}

	return ancestor[a][0];
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n;
	l = ceil(log(n)/log(2));

	fr(i, n-1){
		int v1, v2, e;
		cin >> v1 >> v2 >> e;

		v1++;
		v2++;

		adj[v1].pb(mp(v2, e));
		adj[v2].pb(mp(v1, e));
	}

	dist[1] = 0;
	dfs(1, 1);

	int q;
	cin >> q;

	while(q--){
		int v1, v2;
		cin >> v1 >> v2;

		v1++;
		v2++;

		cout << dist[v1] + dist[v2] - 2*dist[lca(v1, v2)] << endl;
	}
}
