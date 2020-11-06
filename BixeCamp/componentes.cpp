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

#define MAXN 200010
#define MOD 1000000007

vector<int> adj[MAXN];
int processado[MAXN];

int dfs(int v, int pai){
    int ans = 1;

    if(adj[v].size() != 2) ans = 0;

    fr(i, adj[v].size()){
        int u = adj[v][i];

        if(!processado[u]){
            processado[u] = 1;
            ans *= dfs(u, pai);
        }
    }

    return ans;
}

int main(){
		ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int x, y;

    fr(i, m){
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    int ans = 0;
    frr(i, n){
        if(!processado[i]){
            int d = dfs(i, i);

            //if(d == 1) cout << i << endl;

            ans+=d;
        }
    }

    cout << ans << endl;
}
