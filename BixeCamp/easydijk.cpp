#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 10010
#define MOD 1000000007

vector<pii> adj[MAXN];
int dist[MAXN], pr[MAXN];

void bfs(int S){
  pq<pii, vector<pii>, greater<pii>> fila;

  fila.push(mp(0, S));

  while(true){
      int davez = -1;

      while(!fila.empty()){
        int e = fila.top().second;
        fila.pop();

        if(!pr[e]){
          davez = e;
          pr[e] = 1;
          break;
        }
      }

      if(davez == -1) break;

      fr(i, adj[davez].size()){
        int v = adj[davez][i].first;
        int e = adj[davez][i].second;

        if(!pr[v]){
          dist[v] = dist[davez] + e;
          fila.push(mp(dist[v], v));
        }
      }
  }
}

int main(){
		ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while(tests--){
      int n, e;

      cin >> n >> e;

      frr(j, n) dist[j] = 0;
      mem(pr, 0);
      mem(dist, -1);
      frr(i, n) adj[i].clear();

      int u, v, w;
      fr(i, e){
        cin >> u >> v >> w;

        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
      }

      int a, b;
      cin >> a >> b;

      dist[a] = 0;
      bfs(a);

      if(dist[b] == -1) cout <<"NO"<< endl;
      else cout << dist[b]<<endl;
    }
}
