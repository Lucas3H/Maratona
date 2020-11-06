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
#define MOD 998244353
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll fastxp(ll base, ll exp){
	if(exp == 0) return (ll)1;
	else{
		ll ans = fastxp(base, exp/2);
		ans = (ans*ans)%MOD;

		if(exp%2 == 1) ans = (ans*base)%MOD;

		return ans;
	}
}

int main(){
	ll n, m, prod = 1, dois = 1, bin = 1, d1 = 1, d2 = 1;


	ios::sync_with_stdio(false);
	cin >> n >> m;

	if(n == 2){
		cout << 0 << endl;
		return 0;
	}

	fr(i, n-3){
		dois = (dois*2)%MOD;
	}

	frr(i, m) bin = (bin*i)%MOD;
	frr(i, n - (ll)1) d1 = (d1*i)%MOD;
	frr(i, m - n + (ll)1) d2 = (d2*i)%MOD;

	//cout << bin << " " << d1 <<" " << d2 << endl;

	d1 = fastxp(d1, MOD - 2);
	d2 = fastxp(d2, MOD - 2);

	bin = (bin*d1)%MOD;
	bin = (bin*d2)%MOD;

	ll ans = (bin*(n-(ll)2))%MOD;
	ans = (ans*dois)%MOD;


	//cout << prod << " " << dois << " " << bin << endl;

	cout << ans << endl;
}
