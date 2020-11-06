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

ll n;
ll x[MAXN];
vector<ll> adj[MAXN];
ll ans;
map<ll, ll> m[MAXN];

int processado[MAXN];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

void dfs(int v){
    processado[v] = 1;

    fr(i, adj[v].size()){
        ll u = adj[v][i];

        if(processado[u]) continue;

        for(auto y: m[v]){
            m[u][gcd(y.f, x[u])] += y.s;
        }

        m[u][x[u]]++;

        dfs(u);
    }
}

int main(){
	ios::sync_with_stdio(false);
    cin >> n;
    frr(i, n) cin >> x[i];

    ll v1, v2;
    fr(i, n-1){
        cin >> v1 >> v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    m[1][x[1]]++;
    dfs(1);

    frr(i, n){
        for(auto y: m[i]){
            ans = (ans + y.s*y.f)%MOD;
        }
    }

    cout << ans << endl;
}
