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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int processado[MAXN];
int filhos[MAXN];

vector<int> adj[MAXN];
int n;

void dfs(int v){
    int ans = 0;
    processado[v] = 1;
    fr(i, adj[v].size()){
        if(!processado[adj[v][i]]) {
            dfs(adj[v][i]);
            ans+=filhos[adj[v][i]];
        }
    }

    filhos[v] = ans + 1;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n;

    int a, b;
    fr(i, n-1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);

    int mini = MAXN;
    frr(i, n){
        mini = min(mini, abs(n - 2*filhos[i]));
        //cout << filhos[i] << " ";
    }

    //cout << endl;

    cout << mini << endl;
}
