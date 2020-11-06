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
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll MOD = (((ll)1 << 31) - (ll)1); 

/*
	Resto / menor / bitmask
*/
ll dp[102][102][1024];

ll n, k;
ll light[102];
ll P;
vector<ll> p;
vector<ll> ex;

void decompose(){
	ll i = 2;
	while(i <= n){
		if(k%i == 0){
			p.pb(i);
			ll e = 0;
			while(k%i == 0){
				k/=i;
				e++;
			}

			ex.pb(e);
		}

		i++;
	}
}

ll fastxp(ll b, ll e){
	if(e == 1) return b;
	else{
		ll ans = fastxp(b, e/2);
		ans = (ans*ans)%MOD;

		if(e%2 == 1) ans = (ans*b)%MOD;

		return ans;
	}
}

ll fac[102], invFac[102], inv[102];

void build(){
	frr(i, n){
		fr(j, p.size()){
			ll power = 1;
			fr(l, ex[j]) power*=p[j];

			if(i%power == 0) light[i]|=(1 << j);
		}
	}

	fac[0] = 1;
	invFac[0] = 1;
	frr(i, n){
		fac[i] = (fac[i-1]*i)%MOD;
		inv[i] = fastxp(i, MOD - 2);
		invFac[i] = (invFac[i-1]*inv[i])%MOD;
	}
 
 	P = p.size();
 	P = ((1 << P) - 1);
}

ll solve(ll resto, ll menor, ll mask){
	//cout << resto << " " << menor << endl;

	if(dp[resto][menor][mask] > -1) {
		return dp[resto][menor][mask];
	}
	if(resto == 0){
		if(mask != P) return dp[resto][menor][mask] = 0;
		else {
			return dp[resto][menor][mask] = fac[n];
		}
	}
	else if(menor > resto) return dp[resto][menor][mask] = 0;

	ll sum = menor, rep = 1;
	ll ans = solve(resto, menor + 1, mask);
	ll den = 1;

	while(sum <= resto){
		den = (den*inv[menor])%MOD;
		ll aux = ((den*invFac[rep])%MOD);
		aux = (aux*solve(resto - sum, menor + 1, mask|light[menor]))%MOD;
		ans = (ans + aux)%MOD;
		rep++;
		sum+=menor;
	}

	return dp[resto][menor][mask] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	mem(dp, -1);
	cin >> n >> k;

	decompose();
	build();

	cout << solve(n, 1, 0) << endl;
}
