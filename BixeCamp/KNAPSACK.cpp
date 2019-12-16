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

#define MAXN 2010
#define MOD 1000000007

int s, n;
int w[MAXN], v[MAXN];
int memo[MAXN][MAXN];

int dp(int item, int sobrou){
    if(item == 0) return 0;
    if(sobrou == 0) return 0;
    if(memo[item][sobrou] != -1) return memo[item][sobrou];

    int ans = dp(item - 1, sobrou);
    if(w[item] <= sobrou) ans = max(ans, dp(item - 1, sobrou - w[item]) + v[item]);

    return memo[item][sobrou] = ans;
}

int main(){
		ios::sync_with_stdio(false);
    cin >> s >> n;

    frr(i, n) cin >> w[i] >> v[i];

    mem(memo,-1);

    cout << dp(n, s) << endl;
}
