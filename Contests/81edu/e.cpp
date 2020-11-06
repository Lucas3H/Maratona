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

ll n;
ll nd[4*MAXN], minimo[4*MAXN], lz[4*MAXN];
ll a[MAXN], p[MAXN], p_inv[MAXN];

ll sum = 0;

void build(ll i, ll l, ll r){
	if(l == r){
		sum+=a[l];
		nd[i] = sum;
		minimo[i] = sum;
	}
	else{
		ll mid = (l+r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		nd[i] = nd[2*i] + nd[2*i+1];
		minimo[i] = min(minimo[2*i], minimo[2*i+1]);
	}
}

void push(ll i, ll l, ll r){
	nd[i] += (r - l + 1)*lz[i];
	minimo[i] += lz[i];

	if(l < r){
		lz[2*i] += lz[i];
		lz[2*i+1] += lz[i];
	}

	lz[i] = 0;
}

void update(ll i, ll l, ll r, ll ql, ll qr, ll val){
	ll k = minimo[i];

	push(i, l, r);
	if(ql <= l && r <= qr) {
		lz[i] += val;
		push(i, l, r);
	}
	else if(l > qr || ql > r) return;
	else{
		ll mid = (l+r)/2;

		update(2*i, l, mid, ql, qr, val);
		update(2*i+1, mid+1, r, ql, qr, val);

		nd[i] = nd[2*i] + nd[2*i+1];
		minimo[i] = min(minimo[2*i], minimo[2*i+1]);
	}


	//cout << i << " DEPOIS " << l << " " << r  << " " << k << " ->>> " << minimo[i] << endl;
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n;

	frr(i, n) {
		cin >> p[i];
		p_inv[p[i]] = i;
	}
	frr(i, n) cin >> a[i];

	build(1, 1, n - 1);
//	cout << sum << endl;

	ll ans = minimo[1];

	frr(i, n){
		update(1, 1, n - 1, 1, p_inv[i] - 1, a[p_inv[i]]);
		update(1, 1, n - 1, p_inv[i], n - 1, -a[p_inv[i]]);

		ans = min(ans, minimo[1]);
	}

	cout << ans << endl;
}
