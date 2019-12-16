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
int team[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int cor){

    fr(i, adj[v].size()){
        int u = adj[v][i];

        if(team[u] == -1){
            team[u] = (cor+1)%2;
            dfs(u, (cor+1)%2);
        }
    }
}

int main(){
		ios::sync_with_stdio(false);
    mem(team, -1);

    cin >> n;

    int x, y;
    frr(i, n){
        cin >> x;
        fr(j, x){
            cin >> y;
            adj[i].pb(y);
        }
    }

    frr(i, n){
        if(team[i] == -1){
          //  cout << i << endl;
            team[i] = 1;
            dfs(i, 1);
        }
    }

    vector<int> a[2];

    frr(i, n){
        a[team[i]].pb(i);
    }

    fr(i, a[1].size()) cout << a[1][i] << " ";
    cout << endl;
    fr(i, a[0].size()) cout << a[0][i] << " ";

}
