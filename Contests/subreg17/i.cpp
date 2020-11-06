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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
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
#define INF 1000000000000000100

int n, c;
int ouro[MAXN], pr[MAXN];
int ans = 0;
vector<pii> adj[MAXN];

void dfs(int v){
	pr[v] = 1;

	for(auto x: adj[v]){
		if(!pr[x.f]){
			dfs(x.f);
			ans += 2*x.s*((ouro[x.f] - 1)/c + 1);
			ouro[v] += ouro[x.f];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> c;

	frr(i, n) cin >> ouro[i];
	frr(i, n-1){
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}

	dfs(1);

	cout << ans << endl;
}
