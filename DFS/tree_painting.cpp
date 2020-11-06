// https://codeforces.com/problemset/problem/1187/E
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000

ll n;
vector<ll> adj[MAXN];
ll pr[MAXN], ans[MAXN], tam[MAXN];

ll maior = 0;

ll dfs_compute(ll v){
	pr[v] = 1;
	
	ll ret = 0;
	for(auto x: adj[v]){
		if(!pr[x]) {
			ret += dfs_compute(x);
			tam[v] += tam[x];
		}
	}

	tam[v]++;

	if(ret == 0) return tam[v] = 1;
	else return ret + tam[v];
}

void dfs_ans(ll v){
	pr[v] = 1;

	for(auto x: adj[v]){
		if(!pr[x]){
			ans[x] = ans[v] + n - 2*tam[x];
			maior = max(maior, ans[x]);
			dfs_ans(x);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	fr(i, n-1){
		ll v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	ans[1] = dfs_compute(1);

	mem(pr, 0);

	dfs_ans(1);

	cout << maior << endl;
}
