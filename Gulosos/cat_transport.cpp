#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
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
#define INF 1e18+10

ll n, m, p;
ll x[MAXN];
pii pts[MAXN];

void read(){
	cin >> n >> m >> p;

	ll sum = 0;
	x[1] = 0;
	frr(i, n-1){
		ll d;
		cin >> d;
		sum+=d;
		x[i + 1] = sum;
	}
	frr(i, m){
		ll h, t;
		cin >> h >> t;
		pts[i] = {x[h], t};	
	}
}

/*Checar se o r >= 0*/
pii transform(pii pt, ll d){
	return {max(0, pt.s - pt.f), pt.s - pt.f + d};
}

ll solve(ll d){
	pii interval[MAXN];
	frr(i, m){
		interval[i] = transform(pts[i], d);
		if(interval[i].s < 0) return 0;
	}

	sort(interval + 1, interval + m + 1);

	ll i = 1, ans = 0;
	while(i <= m){
		ll davez = interval[i].s;

		while(davez >= interval[i].f) i++;

		ans++;
	}

	if(ans <= p) return 1;
	else return 0;
}

ll bb(){
	ll l = -1, r = 100, m;
	while(l < r - 1){
		m = (l+r)/2;
		if(solve(m)) r = m;
		else l = m;

		cout << l << " " << r<< endl;
	}

	return r;
}

int main(){
	ios::sync_with_stdio(false);
	read();
	/*
	frr(i, n) cout << x[i] << endl;
	frr(i, m) cout << pts[i].f << " " << pts[i].s << endl;
	*/
	cout << bb() << endl;
}
