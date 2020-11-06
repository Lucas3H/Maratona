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

#define MAXN 1000010
#define MOD 998244353
#define MAXL 30
#define ROOT 1
#define INF 987654321

vector<ll> adj[MAXN];
ll dg[MAXN];
ll den = 0;

ll fastxp(ll b, ll e){
	if(e == 1) return b;
	else{
		ll ans = fastxp(b, e/2);
		ans = (ans*ans)%MOD;

		if(e%2 == 1){
			ans = (ans*b)%MOD;
		}

		return ans;
	}
}

pii soma(pii a, pii b){
	
	pii ans;
	
	ans.s = (a.s*b.s)%MOD;
	ans.f = (a.f*b.s + a.s*b.f)%MOD;

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;

	den = (n*n)%MOD;

	frr(i, n){
		ll x;
		cin >> x;

		fr(j, x){
			ll y;
			cin >> y;

			dg[y]++;
			adj[i].pb(y);
		}
	}

	pii num = {(ll)0, (ll)1};

	frr(i, n){
		pii davez;
		davez.s = adj[i].size();

		ll sum = 0;

		for(auto x: adj[i]){
			sum = (sum + dg[x])%MOD;
		}

		davez.f = sum;

		//cout << num.f << " " << num.s << endl;

		num = soma(davez, num);
	}

	//cout << num.f << " " << num.s << endl;


	num.s = (den*num.s)%MOD;
	
	num.s = fastxp(num.s, MOD - 2);

	cout << (num.f*num.s)%MOD << endl;
}
