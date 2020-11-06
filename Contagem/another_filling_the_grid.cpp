#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

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

ll fastxp(ll base, ll e){
	if(e == 0) return 1;
    ll ans = fastxp(base, e/2);

    ans *= ans;
    ans = ans%MOD;
    if(e%2 == 1) ans*= base;
    ans = ans%MOD;

    return ans;
}

ll fac[MAXN];
ll facInv[MAXN];

ll b[260][260];

ll bin(ll sup, ll inf){
	if(inf > sup) return 0;
	if(inf == 0) return 1;

	if(b[sup][inf] != 0) return b[sup][inf];

	ll ans = fac[sup]*facInv[inf];
	ans = ans%MOD;

	return b[sup][inf] = (ans*facInv[sup-inf])%MOD;
}

ll dp[260][260];
ll n, k;
ll termo;

ll K[260];
ll Km[260];

void DP(){

	fr(i, n + 1){
		dp[1][i] = bin(n, i)*(Km[n-i]);
		dp[1][i] = dp[1][i]%MOD;
	}

	for(ll i = 2; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			ll aux = ( K[j] - Km[j] + MOD)%MOD;
			termo = (dp[i-1][j]*aux)%MOD;
			termo = (termo*Km[n-j])%MOD;
			dp[i][j] = (dp[i][j] + termo)%MOD;


			for(ll l = 1; l <= j - 1; l++){
				termo = (bin(n - j + l, l)*dp[i - 1][j - l])%MOD;
				termo = (termo*K[j-l])%MOD;
				termo = (termo*Km[n-j])%MOD;

				dp[i][j] += termo;
				dp[i][j] = dp[i][j]%MOD;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> k;

	ll f = 1;
	fac[0] = 1;
	facInv[0] = 1;

	K[0] = 1;
	Km[0] = 1;

	frr(i, n){
		f *= i;
		f = f%MOD;

		fac[i] = f;
		facInv[i] = fastxp(fac[i], MOD-2);

		K[i] = fastxp(k, i);
		Km[i] = fastxp(k-1, i);
	}

	mem(dp, 0);

	DP();

	cout << dp[n][n] << endl;
}
