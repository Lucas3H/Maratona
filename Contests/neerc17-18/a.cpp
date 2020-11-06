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
0 fim do círculo.
1 início do círculo
2 ponto
*/

ll n;
vector<pair<pair<ll, ll>, pair<ll, ll>>> line;
pii c[MAXN];

/*
line[i].f.f é o x
line[i].f.s é o tipo
line[i].s.f é o y
line[i].s.s é o ind 
*/

ll ans[MAXN];
set<ll> q;
void read(){
	cin >> n;

	frr(i, n){
		ll a;
		cin >> a >> c[i].f >> c[i].s;
		if(a == 1){
      		line.pb({{c[i].f - c[i].s, 1}, {c[i].s, i}});
      		line.pb({{c[i].f + c[i].s, 0}, {c[i].s, i}});
		}
		else{
			q.insert(i);
			line.pb({{c[i].f, 2}, {c[i].s, i}});
		}
	}

	sort(line.begin(), line.end());
}

bool deu(ll ind, ll x, ll y){
	if((c[ind].f - x)*(c[ind].f - x) + (c[ind].s - y)*(c[ind].s - y) < c[ind].s*c[ind].s) {
		//cout << ind << " " << x << " " << y << endl;
		return 1;
	}
	else return 0;
}

int main(){
	ios::sync_with_stdio(false);

  /*
	line[i].f.f é o x
	line[i].f.s é o tipo
	line[i].s.f é o y
	line[i].s.s é o ind 
	*/
  
	read();
	set<ll> circ;
	for(auto x: line){
		if(x.f.s == 0)
			circ.erase(x.s.s);
		else if(x.f.s == 1)
			circ.insert(x.s.s);
		else{
			ll ind = x.s.s, X = x.f.f, Y = x.s.f;
			ll achou = 0;

			for(auto y: circ){
				if(deu(y, X, Y) && y < ind){
					ans[ind] = y;
					circ.erase(y);
					achou = 1;
					break;
				}
			}

			if(!achou) ans[ind] = -1;
		}
	}

	for(auto x: q){
		cout << ans[x] << endl;
	}
}
