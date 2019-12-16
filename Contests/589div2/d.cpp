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

#define MAXN 300010
#define MOD 1000000007

int nao_pode_ser[MAXN][4];

int impossivel = 0;
int processado[MAXN];
vector<int> adj[MAXN];

int cor[MAXN];

void dfs(int v){
    if(processado[v]) return;

    int COR = 0;
    if( !nao_pode_ser[v][1] ) COR = 1;
    else if( !nao_pode_ser[v][2] ) COR = 2;
    else if( !nao_pode_ser[v][3] ) COR = 3;
    else impossivel = 1;

    processado[v] = 1;
    cor[v] = COR;

    fr(i, adj[v].size()) nao_pode_ser[adj[v][i]][COR] = 1;


    fr(i, adj[v].size()){
        if(processado[adj[v][i]]) continue;

        dfs(adj[v][i]);
    }
}

int main(){
	ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int a, b;
    fr(i, m){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    frr(i, n) dfs(i);

    if(impossivel){
        cout << -1 << endl;
        //cout << "OK" << endl;
        return 0;
    }

    int v[4];
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;

    frr(i, n) v[cor[i]]++;


    frr(i, 3){
        if(v[i] == 0){
            cout << -1 << endl;
            return 0;
        }
    }
//    cout << v[1] <<" " << v[2] << " " << v[3] << endl;


    //frr(i, n) cout << cor[i] << " ";

    frr(i, n){
        //cout << adj[i].size() << " " << v[cor[i]] << endl;
        if(adj[i].size() + v[cor[i]] != n){
            //cout << i << endl;
            cout << -1 << endl;
            return 0;
        }
    }

    frr(i, n) cout << cor[i] << " ";
    cout << endl;
}
