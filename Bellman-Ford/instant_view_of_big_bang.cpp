// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2768 
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

vector<int> adj[MAXN];
int ans[MAXN];

void dfs(int v){
	ans[v] = 1;
	for(auto x: adj[v]){
		if(!ans[x]) dfs(x);
	}
}

set<int> aux[MAXN];
int pr[MAXN];

void dfs_aux(int v, int ini){
	pr[v] = 1;
	for(auto x: aux[v]){
		if(x == ini) dfs(x);
		if(!pr[x]) dfs_aux(x, ini);
	}
}

void bellman(int ts){
	int n, m;
	cin >> n >> m;

	fr(i, n){
		adj[i].clear();
		ans[i] = 0;

		aux[i].clear();
		pr[i] = 0;
	}

	vector<pair<int, pii>> e;
	fr(i, m){
		int v1, v2, w;
		cin >> v1 >> v2 >> w;

		e.pb(mp(w, mp(v1, v2)));
		adj[v2].pb(v1);
	}

	vector<int> dist(n, MOD);
	vector<int> NEW(n, 0);

	fr(i, n){

		for(auto x: e){
			if(dist[x.s.s] > dist[x.s.f] + x.f){
				dist[x.s.s] = dist[x.s.f] + x.f;
			}
		}
	}

	set<int> atualizado;

	fr(i, n){
		fr(i, n) NEW[i] = MOD;
		
		for(auto x: e){
			if(dist[x.s.s] > dist[x.s.f] + x.f){

				NEW[x.s.s] = min(NEW[x.s.s], dist[x.s.f] + x.f);
				
				aux[x.s.s].insert(x.s.f);
				atualizado.insert(x.s.s);
			}
		}

		fr(i, n) dist[i] = min(NEW[i], dist[i]);
	}
/*
	fr(i, n){
		cout << i << " ";
		for(auto x: aux[i]) cout << x << " ";
		cout << endl;
	}
*/
	for(auto x: atualizado){
		fr(i, n) pr[i] = 0;
		dfs_aux(x, x);
	}

	vector<int> resp;
	fr(i, n){
		if(ans[i]){
			resp.pb(i);
		}
	}
	if(resp.size() == 0) cout << "impossible";
	else{
		fr(i, resp.size() - 1) cout << resp[i] << " ";
		cout << resp[resp.size() - 1];
	}

	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	frr(ts, t){
		cout << "Case " << ts << ": "; 
		bellman(ts);
	}
}
