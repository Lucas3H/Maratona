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
#define INF 987654321

ll n;
map<ll, ll> pos;
set<ll> cord;
pair<ll, pair<ll, ll>> p[MAXN];

bool deu(ll ind, ll x, ll y){
	if((p[ind].s.f - x)*(p[ind].s.f - x) + (p[ind].s.s - y)*(p[ind].s.s - y) < p[ind].s.s*p[ind].s.s) {
		return 1;
	}
	else return 0;
}

set<ll> nd[4*MAXN];

void update(ll i, ll l, ll r, ll ql, ll qr, ll val){
	if(ql <= l && r <= qr) nd[i].insert(val);
	else if(ql > r || l > qr) return;
	else{
		ll m = (l + r)/2;
		update(2*i, l, m, ql, qr, val);
		update(2*i + 1, m + 1, r, ql, qr, val);
	}
}

void update2(ll i, ll l, ll r, ll ql, ll qr, ll val){
	if(ql <= l && r <= qr) nd[i].erase(val);
	else if(ql > r || l > qr) return;
	else{
		ll m = (l + r)/2;
		update(2*i, l, m, ql, qr, val);
		update(2*i + 1, m + 1, r, ql, qr, val);
	}
}

set<ll> s;
void query(ll i, ll l, ll r, ll x){
	//cout <<l << " " << r << endl;
	if(l == r){
		for(auto z: nd[i]) s.insert(z);
	}
	else{
		ll m = (l + r)/2;
		if(m >= x)
			query(2*i, l, m, x);
		else
			query(2*i + 1, m + 1, r, x);

		for(auto z: nd[i]) s.insert(z);
	}
}

int ind = 1;
	
void read(){
	cin >> n;

	frr(i, n){
		cin >> p[i].f >> p[i].s.f >> p[i].s.s;
		if(p[i].f == 1){
			cord.insert(p[i].s.f - p[i].s.s);
			cord.insert(p[i].s.f + p[i].s.s);
		}
		else{
			cord.insert(p[i].s.f);
		}
	}

	for(auto x: cord){
		pos[x] = ind++;
	}
}

int main(){
	ios::sync_with_stdio(false);

	read();

	//cout << ind << endl;
	ind--;
	//for(auto x: cord) cout << x<< endl;
	frr(i, n){
		if(p[i].f == 1){
			update(1, 1, ind, pos[p[i].s.f - p[i].s.s], pos[p[i].s.f + p[i].s.s], i);
		}
		else{
			s.clear();
			query(1, 1, ind, pos[p[i].s.f]);

			ll achou = 0;

			for(auto x: s){
				if(deu(x, p[i].s.f, p[i].s.s)){
					cout << x << endl;
					achou = 1;
					update2(1, 1, ind, pos[p[x].s.f - p[x].s.s], pos[p[x].s.f + p[x].s.s], x);
					break;
				}
			}

			if(!achou) cout << -1 << endl;
		}
	}
}
