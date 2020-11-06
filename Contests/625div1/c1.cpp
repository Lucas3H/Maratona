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
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321
#define MONSTER 1

#define LINE 0
#define MONSTER 1

ll n, M, p;

struct query{
	ll tipo, x, ind;
};
struct monstro{
	ll x, y, coins;
};
pii nd[4000010];

void buildY(ll i, ll l, ll r){
	if(l == r)
		nd[i] = mp(MOD, -1);
	else{
		ll mid = (l + r)/2;
		buildY(2*i, l, mid);
		buildY(2*i+1, mid+1, r);
		nd[i] = mp(MOD, -1);
	}
}

void updateY(ll i, ll l, ll r, ll pos, ll val, ll ind){
	if(l == r){
		if(nd[i].f > val){
			nd[i] = mp(val, ind);
		}
	}
	else{
		ll mid = (l+r)/2;
		if(pos <= mid) updateY(2*i, l, mid, pos, val, ind);
		else updateY(2*i+1, mid+1, r, pos, val, ind);

		if(nd[2*i].f > nd[2*i+1].f) nd[i] = nd[2*i+1];
		else nd[i] = nd[2*i];
	}
}

pii queryY(ll i, ll l, ll r, ll ql, ll qr){
	if(r < ql || qr < l) return mp(MOD, -1);
	else if(ql <= l && r <= qr) return nd[i];
	else{
		ll mid = (l+r)/2;
		pii q1 = queryY(2*i, l, mid, ql, qr);
		pii q2 = queryY(2*i+1, mid+1, r, ql, qr);
		
		if(q1.f < q2.f) return q1;
		else return q2;
	}
}

vector<query> line;

pair<ll, ll> ly[MAXN], lx[MAXN];
monstro m[MAXN];

bool comp(query a, query b){
	if(a.x == b.x) return a.tipo < b.tipo;
	else return a.x < b.x;
}

void read(){
	cin >> n >> M >> p;

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
		updateY(1, 1, 1000000, ly[i].f, ly[i].s, i);
	}

	frr(i, p){
		cin >> m[i].x >> m[i].y >> m[i].coins;

		query q;
		q.tipo = MONSTER;
		q.ind = i;
		q.x = m[i].x;

		line.pb(q);
	}

	sort(line.begin(), line.end(), comp);
}

ll bit[1000010];

void update(ll i, ll val){
    while(i <= 1000000){
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

void solve(){
	ll best_line = queryY(1, 1, 1000000, 1, 1000000).s;
	ll best_cost = 0, ans = -2*MOD;

	fr(i, line.size()){
		if(line[i].tipo == MONSTER){
			ll ind = line[i].ind;
			update(m[ind].y, m[ind].coins);

		//	cout << m[ind].y << " " << m[ind].coins << endl;

			ll cur_line = queryY(1, 1, 1000000, m[ind].y + 1, 1000000).s;
			
			if(cur_line == -1) continue;
			
			ll cur_cost = query(ly[cur_line].f);
		
			if(best_cost - ly[best_line].s < cur_cost - ly[cur_line].s){
				best_line = cur_line;
				best_cost = cur_cost;
			}
		}
		else{
			//cout << best_cost << " " << lx[line[i].ind].s << " " << ly[best_line].s << endl;
			ans = max(ans, best_cost - lx[line[i].ind].s - ly[best_line].s);
		}
	}

	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);

	buildY(1, 1, 1000000);
	read();
	solve();
}
