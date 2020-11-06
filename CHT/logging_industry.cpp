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

class CHT{
	public:
		deque<pll> Hull;
		ll type=1; //0 max e 1 min

		ll getVal(pll a, ll x) {return a.f*x + a.s;}

		//ll cmp(pll a, pll b, pll c){return (type^((b.s - c.s)*(b.f - a.f) <= (a.s - b.s)*(c.f - b.f)));}
		ll cmp(pll a, pll b, pll c){return (((double)(b.s - c.s)/(c.f - b.f) <= (double)(a.s - b.s)/(b.f - a.f)));}

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



long long n;
CHT c;

ll a[MAXN], b[MAXN];
ll dp[MAXN];
long long aux;

void build(){
	cin >> n;

	frr(i, n){
		cin >> aux;
		a[i] = aux;
	}

	frr(i, n){
		cin >> aux;
		b[i] = aux;
	}

	c.insert(-b[1], 0);

	for(int i = 2; i <= n; i++){
		/*
		cout << "----------\n";
		c.print();
		cout << "----------\n";
		*/

		dp[i] = c.query(-a[i]);
		c.insert(-b[i], dp[i]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	build();
	/*
	frr(i, n){
		cout << dp[i] << endl;
	}
	*/
	cout << (long long)dp[n] << endl;
}
