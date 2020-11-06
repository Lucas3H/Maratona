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

#define MAXN 100010
#define MOD 1000000007

int n;
int pr[MAXN];
vector<int> adj[MAXN];

int ans = 0;

int dfs(int v){
  pr[v] = 1;

  int m1 = 0, m2 = 0;
  fr(i, adj[v].size()){
    int u = adj[v][i];

    if(pr[u] == 0){
      m2 = max(dfs(u), m2);
      if(m2 > m1) swap(m1, m2);
    }
  }

//  cout << v << " " << m1 << " " << m2 << endl;

  ans = max(ans, m1 + m2);

  return m1 + 1;
}

int main(){
		ios::sync_with_stdio(false);

    cin >> n;

    int u, v;
    fr(i, n-1){
      cin >> u >> v;

      adj[u].pb(v);
      adj[v].pb(u);
    }

    int k = dfs(1);

    cout << ans << endl;
}
