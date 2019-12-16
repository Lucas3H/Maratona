// https://codeforces.com/contest/1217/problem/D

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define fs first
#define sc second

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

#define MAXN 50010
#define MOD 1000000007

vector<pii> adj[MAXN];
int processado[MAXN];
int edges[MAXN];

int ord[MAXN];

int n, m, v1, v2;
int k = 1;

void dfs(int v){
    if(processado[v]) return;

    processado[v] = 1;

    fr(i, adj[v].size()){
        int u = adj[v][i].first;
        int e = adj[v][i].second;

        if(!processado[u]) dfs(u);
        else if(ord[u] == 0) {
            k = 2;
            edges[e] = 1;
        }
    }

    ord[v] = 1;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> m;
    frr(i, m){
        cin >> v1 >> v2;

        adj[v1].pb(mp(v2, i));
    }

    frr(i, n) dfs(i);

    cout << k << endl;
    frr(i, m) cout << edges[i] + 1 << " ";
}
