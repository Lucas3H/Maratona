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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

pair<pii, ll> p[MAXN];
vector<ll> y;

ll a, b, ta, tb, t, c;

bool comp(pair<pii, ll> w, pair<pii, ll> l){
	return w.f.s < l.f.s;
}

void read(){
	cin >> a >> b >> t >> ta >> tb >> c;

	frr(i, c) cin >> p[i].f.f >> p[i].f.s;

	sort(p + 1, p + c + 1, comp);

	frr(i, c){
		p[i].s = i;
		y.pb(p[i].f.s);
	}

	sort(p + 1, p + c + 1);
}

ll bit[MAXN];

void update(ll i, ll val){
    while(i <= c){
        bit[i] += val;
        i += i & (-i);
    }
}

ll query(ll i){
    ll sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= i & (-i);
    }

    return sum;
}

ll ans = 0;

void solve(){
	ll i = 1;

	while(i <= c && p[i].f.f <= a){
		update(p[i].s, 1);
		i++;
	}

	ll resto = t;
	ll posso = resto/tb;

	ll k = upper_bound(y.begin(), y.end(), posso + b) - y.begin();
	ans = max(ans, query(k));

	while(i <= c && (p[i].f.f - a)*ta <= t){
		resto = t - (p[i].f.f - a)*ta;
		posso = resto/tb;

		update(p[i].s, 1);

		k = upper_bound(y.begin(), y.end(), posso + b) - y.begin();

		//cout << k << " " << resto << " " << posso << endl;

		ans = max(ans, query(k));

		i++;
	}
}

int main(){
	ios::sync_with_stdio(false);

	read();
	solve();

	cout << ans << endl;
}
