#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<long long,long long> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321


class CHT{
	public:
		deque<pll> Hull;
		ll type=0; //0 max e 1 min

		ll getVal(pll a, ll x) {return a.f*x + a.s;}

		//ll cmp(pll a, pll b, pll c){return (type^((b.s - c.s)*(b.f - a.f) <= (a.s - b.s)*(c.f - b.f)));}
		ll cmp(pll a, pll b, pll c){return ((double)(b.s - c.s)/(c.f - b.f) <= (double)(a.s - b.s)/(b.f - a.f));}

		void insert(ll inc, ll y){
	        Hull.push_front({inc,y});
	        while((Hull.size())> 2 && cmp(Hull[0],Hull[1],Hull[2]))
	            Hull[1]=Hull[0], Hull.pop_front();
		}
		ll query(ll x) {
	        int l = -1, r = Hull.size() - 1;
	        while (r - l > 1) {
	            int m = (l + r) / 2;
	            if (type^(getVal(Hull[m], x) <= getVal(Hull[m + 1], x)))
	            	l = m;
	            else
	                r = m;
	        }
	        return getVal(Hull[r], x);
	    }
	    void print(){
	        for(auto x: Hull){
	            cout << x.first << " " << x.second << endl;
	        }
	    }
};

bool cmpLine(pair<pll, ll> a, pair<pll, ll> b){
	if(a.f.f == b.f.f) return a.f.s > b.f.s;
	return a.f.f < b.f.f;
}

long long n;
CHT c;

pair<pll, ll> r[MAXN];
ll dp[MAXN];

void build(){
	cin >> n;

	frr(i, n){
		long long x, y, z;
		cin >> x >> y >> z;
		r[i].f.f = x;
		r[i].f.s = y;
		r[i].s = z;
	}

	sort(r + 1, r + n + 1, cmpLine);

	dp[1] = r[1].f.f*r[1].f.s - r[1].s;
	c.insert(-r[1].f.f, dp[1]);
	for(ll i = 2; i <= n; i++){
		ll q = c.query(r[i].f.s);
		dp[i] = r[i].f.f*r[i].f.s - r[i].s + max(q, (ll)0);
		c.insert(-r[i].f.f, dp[i]);
	}
}

int main(){
	ios::sync_with_stdio(false);

	build();
	ll ans = 0;
	frr(i, n)
		ans = max(ans, dp[i]);

	cout << (long long)ans << endl;
}