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

#define MAXN 4010
#define MOD 1000000007

int memo[MAXN];
int n, a, b, c;
int dp(int l){
    if(l == 0) return 0;
    if(l < 0) return -100000;
    if(memo[l] != -1) return memo[l];

    int ans = -100000;
    ans = max(ans, dp(l-a) + 1);
    ans = max(ans, dp(l-b) + 1);
    ans = max(ans, dp(l-c) + 1);

    return memo[l] = ans;
}


int main(){
		ios::sync_with_stdio(false);

    mem(memo, -1);
    cin >> n >> a >> b >> c;

    cout << dp(n) << endl;
}
