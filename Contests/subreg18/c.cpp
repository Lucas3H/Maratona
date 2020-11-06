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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

class INV_COUNT{
public:
	map<ll, ll> m;
	set<ll> s;
	ll bit[4*MAXN], v[4*MAXN];
	ll n;

	void update(ll i, ll v){
	    while(i <= n){
	        bit[i]+=v;
	        i += i &(-i);
	    }
	}

	ll query(ll i){
	    ll sum = 0;
	    while(i > 0){
	        sum += bit[i];
	        i -= i&(-i);
	    }

	    return sum;
	}

	ll build(){
		frr(i, n){
	        s.insert(v[i]);
	    }

	    ll i = (ll)1;
	    for(auto x: s) m[x] = i++;

	    fr(i, n+1) bit[i] = 0;

		ll inv = 0;
	    frr(i, n) {
	    	//cout << m[v[i]] << " " << v[i] << endl;
	        inv += i - (ll)1 - query(m[v[i]]);
	        update(m[v[i]], (ll)1);
	    }

	    return inv;
	}
};

ll x, y, h, l;
INV_COUNT H, L;

ll hInt = 0, lInt;

int main(){
	ios::sync_with_stdio(false);
    cin >> x >> y >> h >> l;

    pii v[MAXN];

    frr(i, h) cin >> v[i].f >> v[i].s;
    sort(v + 1, v + h + 1);

    H.n = h;
    frr(i, h){
    	H.v[i] = v[i].s;
    	//cout << H.v[i] << endl;
    }

    hInt = H.build();

    frr(i, l) cin >> v[i].f >> v[i].s;
    sort(v + 1, v + l + 1);

    L.n = l;
    frr(i, l)
    	L.v[i] = v[i].s;

    lInt = L.build();

    cout << hInt + lInt + h + l + h*l + (ll)1 << endl;
}

