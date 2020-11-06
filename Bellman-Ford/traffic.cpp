// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1390 
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

#define MAXN 210
#define MOD 1000000007

vector<int> adj[MAXN];
int pr[MAXN];
vector<int> dist(MAXN, MOD);

void dfs(int v){
	pr[v] = 1;
	dist[v] = 0;

	for(auto x: adj[v]){
		if(!pr[x]) dfs(x);
	}
}

void bellman(vector<pair<int, pii>> e, int n){
	vector<int> pai(n + 1, MOD);

	frr(i, n) dist[i] = MOD;
	dist[1] = 0;

	int any, last;
	fr(i, n){

		any = 0;

		for(auto x: e){
			if(dist[x.s.f] == MOD) continue;
			if(dist[x.s.s] > dist[x.s.f] + x.f){
				dist[x.s.s] = dist[x.s.f] + x.f;
				any = 1;

				pai[x.s.s] = x.s.f;
				last = x.s.s;
			}
		}

		if(any == 0) break;
	}

	if(any){
		vector<int> app(n+1, 0);

		while(app[last] == 0){
			app[last] = 1;
			last = pai[last];
		}

		dfs(last);
	}

	int q;
	cin >> q;

	while(q--){
		int a;
		cin >> a;

		if(dist[a] < 3 || dist[a] == MOD) cout << '?' << endl;
		else cout << dist[a] << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);

	int n;
	int t = 1;

	while(cin >> n){
		int bus[210];
		frr(i, n) {
			cin >> bus[i];
			adj[i].clear();
			pr[i] = 0;
		}
		int r;
		cin >> r;

		vector<pair<int, pii>> e;

		fr(i, r){

			int v1, v2;
			cin >> v1 >> v2;

			e.pb(mp((pow(bus[v2] - bus[v1], 3)), mp(v1, v2)));
			adj[v1].pb(v2);
		}

		cout << "Set #" << t++ << endl;
		bellman(e, n);
	}
}
