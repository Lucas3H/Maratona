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
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll h[MAXN];
vector<ll> pref;
ll a, n, m, r;

void read(){
	cin >> n >> a >> r >> m;
	m = min(m, a + r);

	frr(i, n) cin >> h[i];
	sort(h + 1, h + n + 1);
	pref.pb(0);
	frr(i, n){
		pref.pb(pref.back() + h[i]);
	}
}

ll val(ll x){
	ll p1 = lower_bound(h + 1, h + n + 1, x) - h;

	ll p = (p1 - 1)*x - pref[p1-1], q = pref.back() - pref[p1-1] - (n - p1 + 1)*x;

	if(p >= q)
		return a*(p - q) + m*q;
	else
		return r*(q - p) + m*p;
}

int main(){
	ios::sync_with_stdio(false);
	read();

	ll l = 0, r = MOD;

	while(l < r-2){
		ll m1 = (2*l + r)/3, m2 = (l + 2*r)/3;

		if(val(m1) < val(m2))
			r = m2;
		else
			l = m1;
	}

	ll ans = min(val(r), min(val(l), val((l+r)/2)));
	cout << ans << endl;
}
