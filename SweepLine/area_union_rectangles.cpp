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
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

struct Rectangle{
	ll xl, xr, yu, yd;
};

struct Query{
	ll x, operation, idx;
};

ll n;
Rectangle r[MAXN];
Query q[2*MAXN];

pair<ll, ll> x;
ll nd[4*MAXN], cover_all_interval[4*MAXN];
ll y[2*MAXN];

void build(ll i, ll l, ll r){
	nd[i] = 0;
	cover_all_interval[i] = 0;

	if(l < r - 1){
		ll mid = (l+r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid, r);
	}
}

void update(ll i, ll l, ll r, ll ql, ll qr, ll val){
	if(ql <= y[l] && y[r] <= qr){
		cover_all_interval[i] += val;

		if(cover_all_interval[i] > 0) nd[i] = y[r] - y[l];
		else nd[i] = nd[2*i] + nd[2*i + 1];
	}
	else if(y[l] > qr || y[r] < ql) return;
	else{
		ll mid = (l+r)/2;

		if(l + 1 == r) return;

		update(2*i, l, mid, ql, qr, val);
		update(2*i+1, mid, r, ql, qr, val);

		if(cover_all_interval[i] > 0) nd[i] = y[r] - y[l];
		else nd[i] = nd[2*i] + nd[2*i+1];
	}

	//cout << i << ' ' << y[l] << " " << y[r] << " " << nd[i] << " " << cover_all_interval[i] << endl; 
}

bool comp(Query a, Query b){
	return a.x < b.x;
}

void read(){
	cin >> n;

	for(ll i = 0; i < n; i++){
		cin >> r[i].xl >> r[i].yd >> r[i].xr >> r[i].yu;

		q[2*i].x = r[i].xl;
		q[2*i].operation = 0;
		q[2*i].idx = i;

		q[2*i+1].x = r[i].xr;
		q[2*i+1].operation = 1;
		q[2*i+1].idx = i;

		y[2*i + 1] = r[i].yd;
		y[2*i + 2] = r[i].yu;
	}

	sort(q, q + 2*n, comp);

	build(1, 1, 2*n);
	sort(y + 1, y + 2*n + 1);
}

ll rectangles_union_area(){
	ll ans = 0;

	update(1, 1, 2*n, r[q[0].idx].yd, r[q[0].idx].yu, 1);

	for(ll i = 1; i < 2*n; i++){

		ans += (q[i].x - q[i-1].x)*(nd[1]);

		if(q[i].operation == 0) update(1, 1, 2*n, r[q[i].idx].yd, r[q[i].idx].yu, 1);
		else update(1, 1, 2*n, r[q[i].idx].yd, r[q[i].idx].yu, -1);
 
	}

	return ans;
}

int main(){
	read();
	cout << rectangles_union_area() << endl;
}
