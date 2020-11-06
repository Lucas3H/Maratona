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
#define MAXB 1000001
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

struct monster{
	ll a, d, c;
};

struct node{
	ll x, tipo, ind;
};

ll bit[MAXB];
ll n;

void update(ll i, ll val){
    while(i <= MAXB){
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

#define WEAPON 0
#define MONSTER 1

ll n_a, n_d, n_m;
pii a[MAXN];
pii d[MAXN];
monster m[MAXN];
vector<node> line;

ll cheapest_greater[MAXB];

bool comp(node a, node b){
	if(a.x == b.x && a.tipo == b.tipo) return a.ind < b.ind;
	else if(a.x == b.x) return a.tipo < b.tipo;
	else return a.x < b.x;
}

void read(){
	cin >> n_a >> n_d >> n_m;

	fr(i, n_a){
		cin >> a[i].f >> a[i].s;
		
		node t;
		t.x = a[i].f;
		t.tipo = WEAPON;
		t.ind = i;
		line.pb(t);
	}
	fr(i, n_d){
		cin >> d[i].f >> d[i].s;
	}
	fr(i, n_m){
		cin >> m[i].d >> m[i].a >> m[i].c;

		node t;
		t.x = m[i].d;
		t.ind = i;
		t.tipo = MONSTER;

		line.pb(t);
	}

	sort(line.begin(), line.end(), comp);
}

bool compd(pii a, pii b){
	if(a.s == b.s) return a.f > b.f;
	else return a.s < b.s;
}

void build_cheapest(){
	sort(d, d + n_d, compd);

	ll last_cheapest = -1;

	mem(cheapest_greater, -1);

	for(ll j = 0; j < d[0].f; j++){
		cheapest_greater[j] = 0;
	}

	last_cheapest = 0;

	frr(i, n_d-1){
		if(d[i].f > d[last_cheapest].f){
			for(ll j = d[last_cheapest].f; j < d[i].f; j++){
				cheapest_greater[j] = i;
			}

			last_cheapest = i;
		}
	}
}

void solve(){
	ll ans = -(ll)2*MOD;
	ll best_line = 0;
	ll best_cost = -d[0].s;

	for(auto x: line){
		if(x.tipo == MONSTER){
			ll cur_line = cheapest_greater[m[x.ind].a];
			update(m[x.ind].a, m[x.ind].c);
			
			if(d[best_line].f > m[x.ind].a){
				best_cost += m[x.ind].c;
			}

			if(cur_line == -1) continue;

			ll cur_cost = query(d[cur_line].f - 1) - d[cur_line].s;

			if(cur_cost >= best_cost){
				best_cost = cur_cost;
				best_line = max(cur_line, best_line);
			}
		}
		else{
			ans = max(ans, (ll)best_cost - (ll)a[x.ind].s);
		}
	}

	cout << ans << endl;
}

int main(){
	read();
	build_cheapest();
	solve();
}
