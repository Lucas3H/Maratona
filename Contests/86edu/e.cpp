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

ll fastxp(ll b, ll e){
	if(e == 1) return b;
	else{
		ll ans = fastxp(b, e/2);
		ans = (ans*ans)%MOD;

		if(e%2 == 1) ans = (ans*b)%MOD;

		return ans;
	}
}

ll fac[2*MAXN];
ll facInv[2*MAXN];

ll bin(ll a, ll b){
	if(b > a) return 0;
	ll ans = (fac[a]*facInv[b])%MOD;
	return (ans*facInv[a - b])%MOD;
}

ll n, k;
	
void build(){
	fac[0] = 1;
	facInv[0] = 1;

	frr(i, n){
		fac[i] = (fac[i-1]*i)%MOD;
		facInv[i] = (facInv[i-1]*fastxp(i, MOD-2))%MOD;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;

	build();

	if(k >= n){
		cout << 0 << endl;
	}
	else if(k == 0){
		cout << fac[n] << endl;
	}
	else{
		ll i = n - k;
		ll ans = 0;

		frr(j, i){
			if((i-j)%2 == 0){
				ll aux = (fastxp(j, n)*bin(i, i - j))%MOD;
				ans = (ans + aux)%MOD;
			}
			else{
				ll aux = (fastxp(j, n)*bin(i, i - j))%MOD;
				ans = (ans - aux + MOD)%MOD;
			}
		}

		ans = (ans*bin(n, i))%MOD;

		cout << (2*ans)%MOD << endl;
	}
}
