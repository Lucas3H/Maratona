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

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
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

ll fac[MAXN], ifac[MAXN];
vector<ll> p;
map<ll, ll> m;
ll d, q;
	
void build(){

	fac[0] = 1;
	frr(i, 100000) {
		fac[i] = (fac[i-1]*i)%MOD;
		ifac[i] = fastxp(fac[i], MOD - 2); 
	}

	ll i = 2;

	while(i*i <= d){
		if(d%i == 0){
			p.pb(i);
			while(i*i <= d && d%i == 0) d /= i;
		}
		i++;
	}

	if(d > 1) p.pb(d);
}

ll ans(ll a){
	if(m[a] != 0){

		return m[a];
	}
	
	ll ret = 0, A = a;
	vector<ll> v;

	for(ll x: p){
		if(a%x == 0){
			ll aux = 0;
			while(a%x == 0){
				a /= x;
				aux++;
			}

			ret+=aux;
			v.pb(aux);

		}
	}

	ret = fac[ret];

	for(ll x: v){
		ret = (ret*ifac[x])%MOD;
	}

	m[A] = ret;
	//cout << a << " " << ret << endl;

	return ret;
}

int main(){
	scanf("%lld %lld", &d, &q);
	
	build();

	while(q--){
		ll a, b;
		scanf("%lld %lld", &a, &b);

		ll g = gcd(a, b);

		printf("%lld\n", (ans(a/g)*ans(b/g))%MOD);
	}

}
