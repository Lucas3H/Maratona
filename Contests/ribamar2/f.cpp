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

#define COMECA 0
#define TERMINA 1

ll n;
map<ll, ll> y;
ll pares[4*MAXN];
ll nd[4*MAXN], lz[4*MAXN];
set<ll> auxY;
ll val[4*MAXN], ans[4*MAXN], vy[MAXN];
ll N;

void push(ll i, ll l, ll r){
	if(lz[i]%2 == 0) return;
	pares[i] = 1 - pares[i];

	ans[i] = val[i] - ans[i];

	if(l < r){
		lz[2*i]++;
		lz[2*i+1]++;
	}

	lz[i] = 0;
}

void update(ll i, ll l, ll r, ll ql, ll qr){
	push(i, l, r);

	if(ql > r || l > qr) return;
	else if(ql <= l && r <= qr){
		lz[i]++;
		push(i, l, r);
	}
	else{
		ll m = (l+r)/2;

		update(2*i, l, m, ql, qr);
		update(2*i+1, m+1, r, ql, qr);

		ans[i] = ans[2*i] + ans[2*i+1];
	}
}


void build(ll i, ll l, ll r){

	if(l == r){
		val[i] = vy[l + 1] - vy[l];
	}
	else{
		ll m = (l+r)/2;

		build(2*i, l, m);
		build(2*i+1, m+1, r);

		val[i] = val[2*i] + val[2*i+1];
	}


	//cout << i << " " << l << " " << r <<  " " << val[i] << endl;
}

struct query{
	ll y0, h, x, tipo;
};

bool comp(query a, query b){
	return a.x < b.x;
}

vector<query> line;

void read(){
	cin >> n;

	fr(i, n){
		ll X[2], Y[2];
		query q1, q2;
		cin >> X[0] >> Y[0] >> X[1] >> Y[1];

		if(X[0] > X[1]) swap(X[0], X[1]);
		if(Y[0] > Y[1]) swap(Y[0], Y[1]);

		q1.x = X[0];
		q1.y0 = Y[0];
		q1.h = Y[1] - Y[0];
		q1.tipo = COMECA;

		q2.x = X[1];
		q2.y0 = Y[0];
		q2.h = Y[1] - Y[0];
		q2.tipo = TERMINA;

		line.pb(q1);
		line.pb(q2);
	
		auxY.insert(Y[0]);
		auxY.insert(Y[1]);
	}

	vector<ll> ay;
	for(ll yu: auxY){
		ay.pb(yu);
	}

	N = ay.size() - 1;

	for(ll i = 0; i <= N; i++){
		y[ay[i]] = i + 1;
		vy[i + 1] = ay[i];
	}
/*
	for(auto ax: y) cout << ax.f << " " << ax.s << endl;
	db;
*/
	sort(line.begin(), line.end(), comp);

	build(1, 1, N);
}

void solve(){
	ll i = 0;

	ll ansTotal = 0;

	ll ansT = 0, x0 = line[0].x;

	while(i < 2*n){
		ll x = line[i].x;
/*
		cout << i << endl;
		cout << line[i].x << " " << line[i].y0 <<" " << line[i].h << " " << line[i].tipo << endl;
*/

		//cout << ans[1] << endl;

		ansTotal += ans[1] * (x - x0);
		x0 = x;

		while(line[i].x == x){
			//cout << y[line[i].y0] <<" " << y[line[i].y0 + line[i].h] - 1 << endl;

			update(1, 1, N, y[line[i].y0], y[line[i].y0 + line[i].h] - 1);
			i++;
		}
	}

	cout << ansTotal << endl;
}


int main(){
	ios::sync_with_stdio(false);
	read();

	solve();
}
