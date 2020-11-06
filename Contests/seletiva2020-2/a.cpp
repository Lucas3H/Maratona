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

#define MAXN 2010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int ans[MAXN];
vector<int> adj[MAXN];

int n;

void read(){
	int x, y;
	cin >> n >> x >> y;

	frr(i, n-1){
		adj[i].pb(i+1);
		adj[i+1].pb(i);
	}

	adj[x].pb(y);
	adj[y].pb(x);
}

void bfs(int v){
	queue<pii> q;
	int dist[MAXN];
	frr(i, n) dist[i] = -1;

	q.push(mp(0, v));

	dist[v] = 0;

	while(!q.empty()){
		pii p = q.front();
		q.pop();

		//cout << p.s << endl;

		for(int z: adj[p.s]){
			if(dist[z] == -1){
				q.push(mp(dist[p.s] + 1, z));
				dist[z] = dist[p.s] + 1;
			}
		}
	}


	frr(i, n) ans[dist[i]]++;
}

int main(){
	ios::sync_with_stdio(false);
	read();

	//bfs(1);

	frr(i, n) bfs(i);

	frr(i, n-1) cout << ans[i]/2 << endl;

}
