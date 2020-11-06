#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
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
#define INF 90087654321

/*
	Min é dado em ordem crescente e max é dado em ordem decrescente (lembrar de fazer tratamento de caras
	com inclinação igual)
*/

class CHT{
	public:
		deque<pair<pll, int>> Hull;
		ll type=1; //0 max e 1 min

		ll getVal(pair<pll, int> a, ll x) {return a.f.f*x + a.f.s;}

		//ll cmp(pll a, pll b, pll c){return (type^((b.s - c.s)*(b.f - a.f) <= (a.s - b.s)*(c.f - b.f)));}
		ll cmp(pair<pll, int> a, pair<pll, int> b, pair<pll, int> c){
			return ((double)(b.f.s - c.f.s)/(c.f.f - b.f.f) <= (double)(a.f.s - b.f.s)/(b.f.f - a.f.f));
		}

		void insert(ll inc, ll y, ll ind){
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
		/*
	    void print(){
	    	cout << "-----------\n";
	        for(auto x: Hull){
	            cout << x.first << " " << x.second << endl;
	        }
	    	cout << "-----------\n";
	    }
		*/
};

pair<pll, int> h[MAXN], c[MAXN];
ll n;
CHT maximo, minimo;

bool compH(pair<pll, int> a, pair<pll, int> b){
	if(a.f.f == b.f.f) return a.f.s > b.f.s;
	else return a.f.f > b.f.f;
}

bool compC(pair<pll, int> a, pair<pll, int> b){
	if(a.f.f == b.f.f) return a.f.s < b.f.s;
	else return a.f.f < b.f.f;
}

bool empate[MAXN];

void build(){
	cin >> n;

	frr(i, n){
		cin >> h[i].f.s >> h[i].f.f;
		h[i].s = i;

		cin >> c[i].f.s >> c[i].f.f;
		c[i].s = i;
	}

	sort(h + 1, h + 1 + n, compH);
	sort(c + 1, c + 1 + n, compC);

	for(int i = 1; i <= n; i++){
		if(h[i].f.f != h[i-1].f.f){
			maximo.insert(h[i].f.f, h[i].f.s, h[i].s);
		}
		else{
			if(h[i].f.s == h[i-1].f.s){
				empate[h[i-1].s] = true;
			}
		}
		if(c[i].f.f != c[i-1].f.f){
			minimo.insert(c[i].f.f, c[i].f.s, c[i].s);
		}
		else{
			if(c[i].f.s == c[i-1].f.s){
				empate[c[i-1].s] = true;
			}
		}
	}
}

pair<double, double> th[MAXN], tc[MAXN];

double intersec(pair<pll, int> b, pair<pll, int> c){
	return (double)(b.f.s - c.f.s)/(c.f.f - b.f.f);
}

/*lidar com empates*/

int main(){
	ios::sync_with_stdio(false);
	build();

	frr(i, n){
		th[i] = {0, -10};
		tc[i] = {0, -10};
	}

	if(maximo.Hull.size() == 1){
		th[maximo.Hull[0].s] = {-10, (double)INF};
	}
	else{
		for(int i = 0; i < maximo.Hull.size(); i++){
			if(i == 0){
				th[maximo.Hull[i].s] = {-10, intersec(maximo.Hull[i], maximo.Hull[i+1])};
			}
			else if(i == maximo.Hull.size() - 1){
				th[maximo.Hull[i].s] = {intersec(maximo.Hull[i-1], maximo.Hull[i]), (double)INF};	
			}
			else{
				th[maximo.Hull[i].s] = {intersec(maximo.Hull[i-1], maximo.Hull[i]), intersec(maximo.Hull[i], maximo.Hull[i+1])};	
			}
		}
	}
	if(minimo.Hull.size() == 1){
		tc[maximo.Hull[0].s] = {-10, (double)INF};
	}
	else{
		for(int i = 0; i < minimo.Hull.size(); i++){
			if(i == 0){
				tc[minimo.Hull[i].s] = {-10, intersec(minimo.Hull[i], minimo.Hull[i+1])};
			}
			else if(i == minimo.Hull.size() - 1){
				tc[minimo.Hull[i].s] = {intersec(minimo.Hull[i-1], minimo.Hull[i]), (double)INF};	
			}
			else{
				tc[minimo.Hull[i].s] = {intersec(minimo.Hull[i-1], minimo.Hull[i]), intersec(minimo.Hull[i], minimo.Hull[i+1])};	
			}
		}
	}
	

	int ans = 0;
	frr(i, n){
/*
		cout << i << " ----------\n";
		cout << th[i].f << " " << th[i].s << endl;
		cout << tc[i].f << " " << tc[i].s << endl;
*/		

		if(th[i].s < 0 || tc[i].s <= 0) continue;

		if(th[i].s > tc[i].f && th[i].f < tc[i].s){
			if(!empate[i]) ans++;
		}
	}

	cout << ans << endl;	
}