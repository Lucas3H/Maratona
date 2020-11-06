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
#define INF 987654321

int n, m;
int ans[MAXN];
vector<pii> adj[MAXN];
int inD[MAXN];

void read(){
	cin >> n >> m;

	fr(i, m){
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].pb(mp(v, w));
		inD[v]++;
	}
}

void solve(){
	int faltam = n;

	while(faltam > 0){
		vector<int> davez;
		frr(j, n){
			if(inD[j] == 0){
				davez.pb(j);
				faltam--;
			}
		}

		for(int x: davez){
			for(pii v: adj[x]){
				ans[v.f] = max(ans[v.f], ans[x] + v.s); 
				inD[v.f]--;
			}

			inD[x] = -1;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();
	solve();
	int maior = 0;
	frr(i, n){
		maior = max(ans[i], maior);
	}

	cout << maior << endl;
}
