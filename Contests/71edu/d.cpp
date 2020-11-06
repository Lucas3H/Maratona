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
typedef pair<ll, ll> ponto;
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

bool cp(pii a, pii b){
	if(a.s == b.s) return a.f < b.f;
	else return a.s < b.s;
	
}

ll fac[3*MAXN];
void build(int n){
	fac[0] = (ll)1;
	frr(i, n){
		fac[i] = (fac[i-1]*i)%MOD;

	}
}

int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;

	build(n);

	pii p[3*MAXN];
	fr(i, n){
		cin >> p[i].f >> p[i].s;
	}

	sort(p, p + n);

	int deu = 1;
	fr(i, n-1){
		if(p[i].s > p[i+1].s){
			deu = 0;
			break;
		}
	}

	ll rep = 0;

	if(deu){
		rep = 1;
		ll size = 1, a = -1, b = -1;
		fr(i, n){
			if(p[i].f == a && p[i].s == b) size++;
			else{
				rep*=fac[size];
				rep = rep%MOD;
				size = 1;
				a = p[i].f;
				b = p[i].s;
			}
		}

		rep*=fac[size];
		rep = rep%MOD;
	}

	ll ans1 = 1;
	ll size = 1, a = -1;
	fr(i, n){
		if(p[i].f == a) size++;
		else{
			ans1*=fac[size];
			ans1 = ans1%MOD;
			size = 1;
			a = p[i].f;
		}
	}
	ans1*=fac[size];
	ans1 = ans1%MOD;

	sort(p, p + n, cp);

	ll ans2 = 1, b = -1;
	size = 1;
	fr(i, n){
		if(p[i].s == b) size++;
		else{
			ans2*=fac[size];
			ans2 = ans2%MOD;
			size = 1;
			b = p[i].s;
		}
	}
	ans2*=fac[size];
	ans2 = ans2%MOD;

	

//	cout << ans1 << endl << ans2 << endl << rep << endl;

	cout << (fac[n] - ans1 - ans2 + rep + 2*MOD)%MOD << endl;
}