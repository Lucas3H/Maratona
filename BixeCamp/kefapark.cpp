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

int n, m;
int cat[MAXN];
vector<int> adj[MAXN];
int processado[MAXN];
int ans = 0;

void dfs(int v, int c){
    if(cat[v] == 1) c++;
    else c = 0;

    if(c > m) return;

    int filhos = 0;

    fr(i, adj[v].size()){
        int u = adj[v][i];

        if(!processado[u]){
            processado[u] = 1;
            dfs(u, c);
            filhos++;
        }
    }

    if(filhos > 0) return;
    else{
      ans++;
    //  cout << v << endl;
    }
}

int main(){
		ios::sync_with_stdio(false);

    cin >> n >> m;
    frr(i, n) cin >> cat[i];

    int x, y;
    fr(i, n-1){
       cin >> x >> y;
       adj[x].pb(y);
       adj[y].pb(x);
    }

    processado[1] = 1;

    dfs(1, 0);

    cout << ans << endl;
}
