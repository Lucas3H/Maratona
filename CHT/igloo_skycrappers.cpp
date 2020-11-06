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


/*
	Min é dado em ordem crescente e max é dado em ordem decrescente
*/
ll n, q, d;
ll A[MAXN], B[MAXN], a[MAXN];
pll b[MAXN];
class CHT{
	public:
		deque<pair<pll, ll>> Hull;
		ll type=0; //0 max e 1 min

		ll getVal(pair<pll, ll> a, ll x) {return a.f.f*x + a.f.s;}

		//ll cmp(pll a, pll b, pll c){return (type^((b.s - c.s)*(b.f.f - a.f.f) <= (a.s - b.s)*(c.f.f - b.f.f)));}
		ll cmp(pair<pll, ll> a, pair<pll, ll> b, pair<pll, ll> c){return ((double)(b.f.s - c.f.s)/(c.f.f - b.f.f) <= (double)(a.f.s - b.f.s)/(b.f.f - a.f.f));}

		void insert(ll inc, ll y, ll ind){
			/*
			if(Hull.size() && Hull[0].f.f == inc){
				if(Hull[0].f.s < y){
					Hull[0].f.s = y;
					Hull[0].s = ind;
				}
				return;
			}
			*/
	        Hull.push_front({{inc,y}, ind});
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
	        for(auto y: Hull){
	        	cout << getVal(y, x) << " " << y.s << endl;
	        }
*/
	        //cout << getVal(Hull[r], x) << " valor " << Hull[r].f.f << " " << Hull[r].f.s << endl;
	        return Hull[r].s;
	    }
	    void print(){
	    	cout << "-----------\n";
	        for(auto x: Hull){
	            cout << x.first.first << " " << x.first.second << " " << x.second << endl;
	        }
	    	cout << "-----------\n";
	    }
};

CHT c[500];

ll query(ll l, ll r, ll t){
	if(n == 1) return 1;

	//cout << l << " " << r << " " << t << " " << d << endl;

	ll val = 0, ind = 1;
	while((l-1)%d != 0 && l <= r){
		if(val < A[l] + B[l]*t){
			val = A[l] + B[l]*t;
			ind = l;
		}
		l++;
	}

	//cout << l << " " << r << " " << t << " " << d << " " << val << " " << ind << endl;

	while(r%d != 0 && l <= r){
		if(val < A[r] + B[r]*t){
			val = A[r] + B[r]*t;
			ind = r;
		}
		r--;
	}

	//cout << l << " " << r << " " << t << " " << d << " " << val << " " << ind << endl;

	// cout << A[42153] + B[42153]*t <<  " " << 42153%d << " " << 42153/d << endl;
	// cout << A[42184] + B[42184]*t << endl;

	while(l <= r){
		ll aux = c[(l-1)/d].query(-t);
		//cout << aux << " carai " << val << " "<< B[aux] << " " << A[aux] << endl;
		if(val < A[aux] + B[aux]*t){
			val = A[aux] + B[aux] * t;
			ind = aux;
		}
		l+=d;
	}

	//cout << "------------\n";

	return ind;
}

ll query1(ll l, ll r, ll t){
	ll val = 0, ind = 1;
	for(ll i = l; i <= r; i++){
		if(val < A[i] + B[i]*t){
			val = A[i] + B[i]*t;
			ind = i;
		}
	}

	return ind;
}

void read(){
	cin >> n >> q;
	d = sqrt(n*log2(n));

	frr(i, n) {
		cin >> a[i] >> b[i].f;
		A[i] = a[i];
		B[i] = b[i].f;
		b[i].s = i;
	}

	ll i;
	for(i = 1; i <= n; i+=d){
		sort(b + i, b + i + d);
		//cout << i << " " << i + d << endl;
		for(ll j = 0; j < d && i + j <= n; j++){
			c[(i-1)/d].insert(-b[i + j].f, a[b[i+j].s], b[i+j].s);
			//cout << "Nossa " << b[i+j].f << " " << (i - 1)/d <<  endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();
	/*
	c[32].print();
	cout << c[32].query(-354) << endl;
	*/
	frr(i, q){
		ll l, r, t;
		cin >> l >> r >> t;

		//cout << query(l, r, t) << endl;
	
		if(query(l, r, t) != query1(l, r, t)){
			int x = query(l, r, t), y = query1(l, r, t);
			//cout << l << " " << r << " " << t << " " << x << " " << y << endl;

			//cout << A[x] << " " << B[x] << " " << A[x] + B[x]*t << endl;
			cout << A[y] << " " << B[y] << " " << A[y] + B[y]*t <<endl;
		}
	
	}
}
