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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int dp[55][MAXN];

int main(){
	ios::sync_with_stdio(false);

	ll t, m, n;
	cin >> t >> m >> n;

	for(ll i = m; i <= n; i++) dp[1][i] = 1;

	for(ll i = 2; i <= t; i++){
		for(ll j = m; j <= n; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;
		}
	}

	ll ans = 0;

	for(ll i = m; i <= n; i++){
		ans = (dp[t][i] + ans)%MOD; 
	}

	cout << ans << endl;

}
