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

int n, E;
int pd[10*MAXN];
vector<pii> edges;
vector<int> adj[MAXN];
int ini[MAXN];

int res[MAXN];

int dp(int e){
    //cout << e << endl;

    if(pd[e] > -1) return pd[e];

    int en = edges[e].s, beg = edges[e].f;

    //cout << "b " << beg <<" " << en << endl;

    int ans = 2;

    int ind = upper_bound(adj[en].begin(), adj[en].end(), beg) - adj[en].begin();

    //cout << beg <<" " << en << " " << ind << endl;

    for(int i = ind; i < adj[en].size(); i++) ans = max(ans, dp(ini[en] + i) + 1);

    res[beg] = max(res[beg], ans);

    return pd[e] = ans;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> E;

    fr(i, 2*n) pd[i] = -1;
    frr(i, n) res[i] = 1;

    int v1, v2;
    fr(i, E){
        cin >> v1 >> v2;

        edges.pb(mp(v1, v2));
        edges.pb(mp(v2, v1));

        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    sort(edges.begin(), edges.end());

    fr(i, edges.size()) cout << edges[i].f << " " << edges[i].s << endl;

    int j = 0;
    fr(i, n+1){
        while(j < edges.size() && edges[j].first == i) j++;
        ini[i+1] = j;

        sort(adj[i].begin(), adj[i].end());
    }

    int d;
    fr(i, edges.size()) d = dp(i);

    frr(i, n) cout << res[i] << " ";
    cout << endl;
}
