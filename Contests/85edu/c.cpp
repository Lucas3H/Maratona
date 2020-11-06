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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;

		ll a[3*MAXN], b[3*MAXN];


		fr(i, n) {
			cin >> a[i] >> b[i];
		}

		ll ans = 0;
		ll minimo = 1e12;

		fr(i, n){
			if(b[i] < a[(i+1)%n]){
		/*		db;
				cout << a[(i+1)%n] << " " << b[i] << endl;
		*/		ans += a[(i+1)%n] - b[i];
				a[(i+1)%n] = b[i];

		//		cout << ans << endl;
			}

			minimo = min(a[(i+1)%n], minimo);
		//	cout << minimo << endl;
		}

		ans += minimo;

		cout << ans << endl;
/*
		set<pii> p;
		fr(i, n){
			p.insert(mp(a[i], i));
		}

		while(p.size() > 0 ){
			vector<ll> v;
			ll davez = (*p.begin()).f;

			while(p.size() > 0 && (*p.begin()).f == davez){
				v.pb((*p.begin()).s);
				p.erase(p.begin());
			}

			for(auto x: v){
				a[x] = 0;
				if(a[(i+1)%n] <= a[i] + b[i])
			}

		}

*/	
	}


}
