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

#define MAXN 510
#define MOD 1000000007

int n, m;
vector<int> adj[MAXN];
int ans[MAXN];
int k[2] = {1, 3};
int pai[MAXN];
int tam[MAXN];

void dfs(int v, int p){
    fr(i, adj[v].size()){
        int u = adj[v][i];

        if(ans[u] == 0){
            ans[u] = ans[p];
            pai[u] = p;
            dfs(u, p);
        }
    }
}

int main(){
		ios::sync_with_stdio(false);

    cin >> n >> m;

    frr(i, n) ans[i] = 0;

    int u, v;
    fr(i, m){
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    frr(i, n){
        if(adj[i].size() == n-1) ans[i] = 2;
    }

    int diferentes = 0;

    frr(i, n){
        if(ans[i] == 0){
            if(diferentes > 1){
                cout << "No" << endl;
                return 0;
            }

            ans[i] = k[diferentes];
            pai[i] = i;
            diferentes++;

            dfs(i, i);
        }
    }

    frr(i, n){
      tam[ans[i]]++;
    }

  //s  cout << tam[1]<< tam[2] << tam[3] << endl;

    frr(i, n){
        if(ans[i] != 2){
            if(adj[i].size() != tam[ans[i]] - 1 + tam[2]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    frr(i, n) {
      cout << char(ans[i] + 'a' - 1);
    }
    cout << endl;
}
