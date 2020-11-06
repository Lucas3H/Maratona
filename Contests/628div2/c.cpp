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

vector<pii> adj[MAXN];
int n;
int edge[MAXN];
int used[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	fr(i, n-1){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(mp(v2, i));
		adj[v2].pb(mp(v1, i));
		edge[i] = -1;
	}

	vector<int> folhas;
	frr(i, n){
		if(adj[i].size() == 1){
			folhas.pb(i);
		}
	}

	if(folhas.size() == 2){
		fr(i, n-1) cout << i << "\n";
	}
	else{	
		edge[adj[folhas[0]][0].s] = 0;
		edge[adj[folhas[1]][0].s] = 1;
		edge[adj[folhas[2]][0].s] = 2;
		
		int tot = 3;

		fr(i, n-1){
			if(edge[i] == -1){
				edge[i] = tot++;
			}
		}

		fr(i, n-1){
			cout << edge[i] << endl;
		}
	}
}
