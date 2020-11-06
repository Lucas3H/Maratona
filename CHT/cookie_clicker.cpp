#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

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
#define INF 987654321

int n, s;
vector<pll> line;

class CHT{
	public:
		deque<pll> Hull;
		ll type=0; //0 max e 1 min

		ll getVal(pll a, ll x) {return a.f*x + a.s;}

		//ll cmp(pll a, pll b, pll c){return (type^((b.s - c.s)*(b.f - a.f) <= (a.s - b.s)*(c.f - b.f)));}
		ll cmp(pll a, pll b, pll c){return ((double)(b.s - c.s)/(c.f - b.f) <= (double)(a.s - b.s)/(b.f - a.f));}

		void insert(ll inc, ll y){
	        Hull.push_back({inc,y});
	        int v;
	        while((v = Hull.size())> 2 && cmp(Hull[v-3],Hull[v-2],Hull[v-1]))
	            Hull[v-2]=Hull[v-1], Hull.pop_back();
		}
		
		ll get_ceil(ll m){
			return (ll)ceil((Hull[m].s - Hull[m + 1].s)/(Hull[m + 1].f - Hull[m].f));
		}

	    ll find(ll x){
	    	int l = 0, r = Hull.size(), m1, m2;
	    	while(l < r - )


	    	return m;
	    }

	   	void print(){
	    	cout << "-----------\n";
	        for(auto x: Hull){
	            cout << x.first << " " << x.second << endl;
	        }
	    	cout << "-----------\n";
	    }
};

void read(){
	pii v[MAXN];
	cin >> n >> s;

	frr(i, n)
		cin >> v[i].f >> v[i].s;

	sort(v + 1, v + n + 1);

	line.pb({v[1].f, v[1].s});

	for(int i = 2; i <= n; i++){
		if(line.back().f == v[i].f) continue;

		while(line.size() && line.back().s >= v[i].s) line.pop_back();

		line.pb(v[i]);
	}
	/*
	for(auto x: line){
		cout << x.f << " " << x.s << endl;
	}
	*/
}

CHT c;

void solve(){
	c.insert(line[0].f, 0);

	for(int i = 1; i < line.size(); i++){
		int ind = c.find(line[i].s);
		cout <<ind << endl;
		c.insert(line[i].f, -line[i].f*(int)(ceil((double)(line[i].s - c.Hull[ind].s)/c.Hull[ind].f)));
	}

	c.print();

	ll ans = c.find(s);
	cout << ans << endl;
	cout << (int)(ceil((double)(s - c.Hull[ans].s)/c.Hull[ans].f)) << endl;

}

int main(){
	ios::sync_with_stdio(false);

	read();
	solve();
}
