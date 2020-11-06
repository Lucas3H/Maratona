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

#define MAXN 100010
#define MOD 1000000007

int n, e;
vector<int> adj[2*MAXN];

int maior_da_comp[2*MAXN], pai[2*MAXN];
int processado[2*MAXN];

int dfs(int v, int p){
    if(processado[v] == 1) return 0;
    processado[v] = 1;

    int maior = v;

    fr(i, adj[v].size()){
        int u = adj[v][i];

        if(!processado[u]){
            pai[u] = v;
            maior = max(dfs(u, p), maior);
        }
    }

    return maior;
}

int find(int x){
    if(pai[x] == x)return x;
    else return pai[x] = find(pai[x]);
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> e;

    frr(i, n){
        processado[i] = 0;
        pai[i] = i;
    }

    int v1, v2;
    fr(i, e){
        cin >> v1 >> v2;

        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    frr(i, n){
        if(pai[i] == i){
            maior_da_comp[i] = dfs(i, i);
        }

        //cout << i << "   " << maior_da_comp[find(i)] << endl;
    }

    int ans = 0;
    frr(i, n-1){
        if(maior_da_comp[find(i)] > i+1){
            //cout << i << endl;
            if(find(i+1) != find(i)){

                maior_da_comp[find(i)] = max(maior_da_comp[find(i)], maior_da_comp[find(i+1)]);
                pai[i+1] = find(pai[i]);
                ans++;
            }
        }

       // frr(j, n) cout << j << "   " << maior_da_comp[find(j)] << endl;

        //cout << endl << endl;
    }

    cout << ans << endl;
}
