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

int memo[102][102];
int v[102];
int n, k;

int dp(int item, int restou){
    if(memo[item][restou] != -1) return memo[item][restou];
    if(item == 0 && restou > 0) return memo[item][restou] = 1000000;
    if(restou == 0) return memo[item][restou] = 0;

    int i = 1;
    int ans = 1000000;
    while(i <= restou){
        if(v[i] != -1) ans = min(ans, dp(item - 1,restou - i) + v[i]);
        i++;
    }

    //cout << item << " " << restou << " " << ans << endl;

    return memo[item][restou] = ans;
}

int main(){
		ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while(tests--){
        mem(memo,-1);
        cin >> n >> k;
        frr(i, k) cin >> v[i];

        int d = dp(n, k);
        if(d >= 1000000) cout << -1 << endl;
        else cout << d << endl;
    }
}
