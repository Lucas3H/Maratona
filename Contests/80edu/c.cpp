#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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
#define INF 987654321

ll n, m;

ll dp[1010][12];

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> m;

	frr(i, n) dp[i][1] = (ll)1;

	for(ll i = 2; i <= m; i++){
		frr(j, n){
			frr(k, j) dp[k][i] = (dp[j][i-1] + dp[k][i])%MOD;
		}
	}


	ll ans = 0;

	frr(i, n){
		ll sum = 0;
		for(ll j = n; j >= n - i + 1; j--){
			sum = (sum + dp[j][m])%MOD;
		}

		//\cout << sum << " "<< ans << endl;

		ans = (ans + dp[i][m]*sum)%MOD;
	}

	cout << ans << endl;
}
