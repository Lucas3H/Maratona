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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 300010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

ll n;
ll a[MAXN];
ll x[32][2];
ll b[MAXN][32];

vector<vector<int>> v;

void solve(int ind, ll bit){

	if(v[ind].size() <= 1 || bit == -1) return;
	
	vector<ll> z, u;
	for(auto x: ind){
		if(b[x][bit] == 0) z.pb(x);
		else u.pb(x);
	}
	v.pb(z);
	solve(v.size() - 1, bit - 1);
	v.pb(u);
	solve(v.size() - 1, bit - 1);

	ll acu = 0, t = v[ind].size();
	frm(i, t){
		if(b[v[ind][i]][bit] == 0) acu++;
		else x[bit][0] += acu;
	}

	acu = 0;
	frm(i, t){
		if(b[v[ind][i]][bit] == 1) acu++;
		else x[bit][1] += acu;
	}
}

void dec(ll ind, ll l){
	ll e = 0;
	while(l > 0){
		b[ind][e] = l%2;
		l/=2;
		e++;
	}
}

int main(){
	ios::sync_with_stdio(false);

	vector<ll> ind;
	cin >> n;
	frr(i, n) {
		cin >> a[i];
		ind.pb(i);
		dec(i, a[i]);
	}

	v.pb(ind);
	solve(0, ind);

	ll ans = 0, pwr = 1, tot = 0;

	fr(i, 30){
		//cout << x[i][0] << " " << x[i][1] << endl;
 		if(x[i][0] > x[i][1]) ans += pwr;
		pwr*=2;
		tot+=min(x[i][0], x[i][1]);
	}

	cout << tot << " " << ans << endl;
}
