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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

ll n, TOT, p;

pii infEsq, supDir;
vector<pair<pii, pii>> rec;
vector<pair<pii, pii>> river;

void genRecs(ll d){
	rec.clear();

	for(auto x: river){
		pii inf = {max(x.f.f - d, infEsq.f), max(x.f.s - d, infEsq.s)};
		pii sup = {min(x.s.f + d, supDir.f), min(x.s.s + d, supDir.s)};
		rec.pb({inf, sup});
	}
}


ll nd[4*MAXN], cover[4*MAXN];
namespace seg{

	void update(ll i, ll l, ll r, ll ql, ll qr, ll val){
		if(ql <= l && r <= qr){
			cover[i] += val;

			if(cover[i] > 0) nd[i] = r - l;
			else nd[i] = nd[2*i] + nd[2*i + 1];
		}
		else if(l > qr || r < ql) return;
		else{
			ll mid = (l+r)/2;

			if(l + 1 == r) return;

			update(2*i, l, mid, ql, qr, val);
			update(2*i+1, mid, r, ql, qr, val);

			if(cover[i] > 0) nd[i] = r - l;
			else nd[i] = nd[2*i] + nd[2*i+1];
		}
	}
}

vector<pair<pii, pii>> line;

ll sweepLine(ll d){
	genRecs(d);

	line.clear();

	for(auto x: rec){
		line.pb({{x.f.f, 0}, {x.f.s, x.s.s}});
		line.pb({{x.s.f, 1}, {x.f.s, x.s.s}});
	}

	sort(line.begin(), line.end());

	seg::update(1, 0, 100000, line[0].s.f, line[0].s.s, 1);

	ll ans = 0;

	for(ll i = 1; i < (ll)line.size(); i++){

		ans += (line[i].f.f - line[i-1].f.f)*(nd[1]);

		if(line[i].f.s == 0) seg::update(1, 0, 100000, line[i].s.f, line[i].s.s, 1);
		else seg::update(1, 0, 100000, line[i].s.f, line[i].s.s, -1);
	}

	//cout << d << " " << ans << endl;

	if(ans*100 >= p*TOT)
		return 1;
	else 
		return 0;
}

void read(){
	cin >> n;

	fr(i, n){
		pii inf, sup;
		cin >> inf.f >> inf.s >> sup.f >> sup.s;

		if(inf.s > sup.s || inf.f > sup.f){
			swap(inf, sup);
		}

		river.pb({inf, sup});
	}

	cin >> p;
	cin >> infEsq.f >> infEsq.s >> supDir.f >> supDir.s;

	TOT = (supDir.f - infEsq.f)*(supDir.s - infEsq.s);
}

int main(){
	ios::sync_with_stdio(false);

	read();

	ll l = 0, r = 100000, m;

	while(l < r - 1){
		m = (l + r)/2;

		if(sweepLine(m))
			r = m;
		else l = m;
	}

	cout << r << endl;
}
