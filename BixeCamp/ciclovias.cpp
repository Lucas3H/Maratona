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

pii edge[10*MAXN];
int ini[MAXN], fim[MAXN];
int memo[10*MAXN];

int dp(int e){
    if(memo[e] != -1) return memo[e];
    int a = edge[e].first;
    int b = edge[e].second;

    int ans = 0;
    for(int i = ini[b]; i <= fim[b]; i++){
        int u = edge[i].second;

        if(u > a) ans = max(ans, dp(i));
    }

    return memo[e] = ans + 1;
}

int main(){
		ios::sync_with_stdio(false);

    mem(memo, -1);

    int n, m;
    cin >> n >> m;

    int v1, v2;
    fr(i, m){
        cin >> v1 >> v2;
        edge[2*i] = mp(v1, v2);
        edge[2*i+1] = mp(v2, v1);
    }

    sort(edge, edge + 2*m);

    int j = 0;
    frr(i, n){
        if(edge[j].first != i){
            ini[i] = 0;
            fim[i] = -1;
            continue;
        }
        ini[i] = j;
        while(j < 2*m && edge[j].first == i) j++;
        fim[i] = j-1;
    }

//    fr(i, 2*m) cout << edge[i].first << " " << edge[i].second << endl << dp(i) << endl;

    frr(i, n){
        int ans = 0;
        for(int j = ini[i]; j <= fim[i]; j++){
            ans = max(ans, dp(j));
        }

        cout << ans+1 << " ";
    }

    cout << endl;
}
