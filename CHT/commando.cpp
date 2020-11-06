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
	        ll l = -1, r = Hull.size() - 1;
	        while (r - l > 1) {
	            ll m = (l + r) / 2;
	            if (type^(getVal(Hull[m], x) <= getVal(Hull[m + 1], x)))
	            	l = m;
	            else
	                r = m;
	        }
/*
	        cout << r << endl;
	        cout << Hull[r].f << " " << Hull[r].s << " " << x << endl;
*/
	        return getVal(Hull[r], x);
	    }
	    void prll(){
	    	cout << "-----------\n";
	        for(auto x: Hull){
	            cout << x.first << " " << x.second << endl;
	        }
	    	cout << "-----------\n";
	    }
};

ll dp[MAXN];
ll a, b, c, n;
ll s[MAXN];
CHT cht;
void read(){
	cin >> n >> a >> b >> c;

	s[0] = 0;
	frr(i, n){
		ll x;
		cin >> x;
		s[i] = s[i-1] + x;
	}
}

void solve(){
	cht.Hull.clear();

	cht.insert(0, 0);
	if(a >= 0){
		for(ll i = 1; i <= n; i++){
			//cht.prll();
			dp[i] = a*s[i]*s[i] + b*s[i] + c + cht.query(s[i]);
			cht.insert(-2*s[i]*a, dp[i] + a*s[i]*s[i] - b*s[i]);
		}
	}
	else{
		for(ll i = 1; i <= n; i++){
			//cht.prll();
			dp[i] = a*s[i]*s[i] + b*s[i] + c + cht.query(-s[i]);
			cht.insert(2*s[i]*a, dp[i] + a*s[i]*s[i] - b*s[i]);
		}
	}	
/*
	frr(i, n){
		cout << dp[i] << endl;
	}
*/
	cout << dp[n] << endl;
	
}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while(t--){
		read();
		solve();
	}
}
