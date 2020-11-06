#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long double ll;
typedef pair<int,int> pii;
typedef pair<long double, long double> pll;
typedef pair<long double, long double> ponto;
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

const long double val = 1000;

vector<int> resp[MAXN];

class CHT{
	public:
		deque<pair<pll, int>> Hull;
		bool type=0; //0 max e 1 min

		ll getVal(pair<pll, int> a, ll x) {return a.f.f*x + a.f.s;}

		ll cmp(pair<pll, int> a, pair<pll, int> b, pair<pll, int> c){
			//cout << ((b.f.s - c.f.s)/(c.f.f - b.f.f)) <<" " << ((a.f.s - b.f.s)/(b.f.f - a.f.f)) << endl;
			return ((b.f.s - c.f.s)*(b.f.f - a.f.f) <= (a.f.s - b.f.s)*(c.f.f - b.f.f));
		}

		void insert(ll inc, ll y, int ind){
	        Hull.push_front({{inc,y}, ind});
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
	    	set<int> aux;
	    	for(auto x: Hull){
	    		for(auto y: resp[x.s]){
	        		aux.insert(y);
	        	}
	        }

	        for(auto x: aux){
	        	cout << x << " ";
	        }
	        cout << endl;
	    }
};

//14034 28469 51162 105995 106984 136414 175766


int n;
vector<pair<pll, int>> x;
pair<pair<int, int>, int> p[MAXN];
CHT c;
map<pair<int, int>, int> m;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	if(a.f.f == b.f.f) {
		if(a.f.s == b.f.s) return a.s < b.s;
		else return a.f.s > b.f.s;
	}
	else return a.f.f > b.f.f;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	fr(i, n){
		pair<pair<int, int>, int> aux;
		cin >> aux.f.f >> aux.f.s;
		aux.s = i + 1;

		if(m[{aux.f.f, aux.f.s}] == 0){
			m[{aux.f.f, aux.f.s}] = i + 1;
			resp[i + 1].pb(i + 1);
		}
		else{
			//cout << m[{aux.f.f, aux.f.s}] << " " << i + 1 << endl;
			resp[m[{aux.f.f, aux.f.s}]].pb(i + 1);
		}

		p[i] = aux;
	}

	sort(p, p + n, comp);
/*
	fr(i, n){
		cout << p[i].f.f << ' ' << p[i].f.s << " " << p[i].s << endl;
	}
*/
	x.pb({{(long double)p[0].f.f, (long double)p[0].f.s}, (long double)p[0].s});
	for(int i = 1; i < n; i++){
		if((long double)p[i].f.f == x.back().f.f || (long double)p[i].f.s <= x.back().f.s) continue;
		x.pb({{(long double)p[i].f.f, (long double)p[i].f.s}, (long double)p[i].s});
	}

	for(int i = 0; i < x.size(); i++){
	    //cout << -x[i].f.s << " " << val - val*x[i].f.s/x[i].f.f << " " << x[i].s << endl;
		c.insert(-x[i].f.s, val - val*x[i].f.s/x[i].f.f, x[i].s);
	}	

	c.print();
}
