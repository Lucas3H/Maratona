// https://www.spoj.com/problems/QTREE2/

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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
ll dist[MAXN], tin[MAXN], tout[MAXN], hgt[MAXN], pr[MAXN];
int t;

int anc[MAXN][32];

void dfs(int v, int p){
	pr[v] = 1;
	tin[v] = t++;

	anc[v][0] = p;
	for(int i = 1; i <= l; i++){
		anc[v][i] = anc[anc[v][i-1]][i-1];
	}

	for(pii u: adj[v]){
		if(pr[u.f] != 1){
			dist[u.f] = dist[v] + u.s;
			hgt[u.f] = hgt[v]+1;
			dfs(u.f, v);
		}
	}

	tout[v] = t++;
}

bool is_anc(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b){
	if(is_anc(a, b)) return a;
	if(is_anc(b, a)) return b;

	for(int i = l; i >= 0; i--){
		if(!is_anc(anc[a][i], b)) a = anc[a][i];
	}

	return anc[a][0];
}

int kth(int v, int k){
	int i = l;
	k--;

	while(k > 0){
		if((1 << i) <= k){
			k -= (1 << i);
			v = anc[v][i];
		}

		i--;
	}

	return v;
}

int main(){
	ios::sync_with_stdio(false);

	int ts;
	cin >> ts;

	while(ts--){
		t = 0;

		cin >> n;
		l = ceil(log(n)/log(2)) + 1;

		frr(i, n) {
			pr[i] = 0;
			adj[i].clear();
		}
		
		ll v1, v2, e;
		fr(i, n-1){
			cin >> v1 >> v2 >> e;

			adj[v1].pb(mp(v2, e));
			adj[v2].pb(mp(v1, e));
		}

		hgt[1] = 0;
		dist[1] = 0;
		dfs(1, 1);

		string s;
		cin >> s;

		while(s[1] != 'O'){
			cin >> v1 >> v2;
			
			int L = lca(v1, v2);
				
			if(s[1] == 'I'){
				cout << dist[v1] + dist[v2] - 2*dist[lca(v1, v2)] << endl;
			}
			else{
				cin >> e;

				if(hgt[v1] - hgt[L] + 1 >= e) cout << kth(v1, e) << endl;
				else cout << kth(v2, hgt[v1] + hgt[v2] - 2*hgt[L] + 2 - e) << endl;
			}

			cin >> s;
		}

		if(ts > 0)cout << endl;
	}
}
