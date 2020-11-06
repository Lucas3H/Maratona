// 
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
#define MAXY 1000010
#define MOD 10000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

#define LINE 0
#define MONSTER 1

struct query{
	ll tipo, x, ind;
};
struct monstro{
	ll x, y, coins;
};

ll n, M, p;
ll maximo[4*MAXY], lz[4*MAXY];

vector<query> line;

ll yaxis[MAXY];

pair<ll, ll> ly[MAXN], lx[MAXN];
monstro m[MAXN];

void build(ll i, ll l, ll r){
	if(l == r){
		maximo[i] = -yaxis[l];
	}
	else{
		ll mid = (l+r)/2;
		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		maximo[i] = max(maximo[2*i], maximo[2*i+1]);
	}
}

void push(ll i, ll l, ll r){
	maximo[i] += lz[i];
	if(l < r){
		lz[2*i] += lz[i];
		lz[2*i+1] += lz[i];
	}
	lz[i] = 0;
}

void update(ll i, ll l, ll r, ll val, ll ql, ll qr){
	push(i, l, r);
	if(ql > r || qr < l) return;
	else if(ql <= l && r <= qr){
		lz[i] += val;
		push(i, l, r);
	}
	else{
		ll mid = (l+r)/2;
		update(2*i, l, mid, val, ql, qr);
		update(2*i + 1, mid + 1, r, val, ql, qr);
		
		maximo[i] = max(maximo[2*i], maximo[2*i+1]);
	}
}

bool comp(query a, query b){
	if(a.x == b.x) return a.tipo < b.tipo;
	else return a.x < b.x;
}

void read(){
	cin >> n >> M >> p;

	fr(i, MAXY) yaxis[i] = MOD;

	frr(i, n){
		cin >> lx[i].f >> lx[i].s;
		
		query q;
		q.x = lx[i].f;
		q.tipo = LINE;
		q.ind = i;

		line.pb(q);
	}

	frr(i, M){
		cin >> ly[i].f >> ly[i].s;
		yaxis[ly[i].f] = min(ly[i].s, yaxis[ly[i].f]);
	}

	frr(i, p){
		cin >> m[i].x >> m[i].y >> m[i].coins;

		query q;
		q.tipo = MONSTER;
		q.ind = i;
		q.x = m[i].x;

		line.pb(q);
	}

	build(1, 1, MAXY - 1);

	sort(line.begin(), line.end(), comp);
}

void solve(){
	ll ans = -2*MOD;

	fr(i, line.size()){
		if(line[i].tipo == MONSTER){
			ll ind = line[i].ind;
			update(1, 1, MAXY - 1, m[ind].coins, m[ind].y + 1, MAXY - 1);
		}
		else{
			ans = max(ans, maximo[1] - lx[line[i].ind].s);
		}

	}

	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);

	read();
	solve();
}
