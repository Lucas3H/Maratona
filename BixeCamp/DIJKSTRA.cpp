#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<long long,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int pr[MAXN], pai[MAXN];
ll d[MAXN];
vector<pii> adj[MAXN];

vector<int> a[MAXN];

void bfs(int v){
    pq<pair<ll, pii>> fila;
    fila.push(mp(0, mp(v, v)));

    while(true){
       int davez = -1;

       while(!fila.empty()){
          int u = fila.top().second.first;

          if(!pr[u]){
              pr[u] = 1;
              d[u] = -fila.top().first;
              pai[u] = fila.top().second.second;
              davez = u;
              break;
          }

          fila.pop();
       }

       if(davez == -1) break;

       fr(i, adj[davez].size()){
          int v = adj[davez][i].first, e = adj[davez][i].second;

          if(!pr[v]){
              fila.push(mp(-d[davez] - e, mp(v, davez)));
          }
       }
    }
}

int main(){
		ios::sync_with_stdio(false);

    int n, e;
    cin >> n >> e;

    int x, y, w;
    fr(i, e){
        cin >> x >> y >> w;
        adj[x].pb(mp(y, w));
        adj[y].pb(mp(x, w));
    }

    mem(d, -1);

    bfs(1);

    if(d[n] == -1) cout << -1 << endl;
    else{
        int x = n;
        stack<int> ans;
        while(pai[x] != x){
            ans.push(x);
            x = pai[x];
        }

        ans.push(1);

        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }

        cout << endl;
    }
}
