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

ll n;
vector<ll> v[20];
ll sum = 0;
ll po[20];
ll ini[20]; 

void read(){
	frr(i, n){
		ll a;
		cin >> a;
		frr(j, 16){
			ll aux = po[j];
			v[j].pb(a%(aux));
		}
	}
	frr(i, 16) sort(v[i].begin(), v[i].end());
}

void update(){
	frr(j, 16){
		ll aux = po[j];
		ll lok = (aux - (sum)%aux);
		ll l = lower_bound(v[j].begin(), v[j].end(), lok) - v[j].begin();
		ini[j] = l%n;
	}
}

ll query(ll t){
	ll md = po[t];	
	ll val = po[t-1];

	if((v[t][((ini[t] - 1 + n)%n)] + sum)%md < val)
		return 0;
	if((v[t][ini[t]] + sum)%md >= val){
		return n;
	}

	ll l = ini[t], r = ini[t] - 1 + n, mid;

	while(l < r-1){
		mid = (l+r)/2;

		if((v[t][(mid%n)] + sum)%md >= val)
			r = mid;
		else 	
			l = mid;
	}
/*
	cout << "Tot " << ini[t] << " " << l << " " << val <<  " " << md << endl;
	fr(i, n) cout << v[t][i] <<  " ";
	cout << endl;
*/
	return (ini[t] - l + 2*n - 1)%n;
}

int main(){
	po[0] = 1;
	frr(i, 17){
		po[i] = 2*po[i-1];
	}

	cin >> n;

	int ts = 1;

	while(n != -1){
		read();

		char op;
		cin >> op;

		ll ans = 0;
		sum = 0;

		while(op != 'E'){
			ll ind;
			cin >> ind;
				
			if(op == 'Q'){
				if(n > 0) ans += query(ind + 1);
				//cout << ans << endl;
			}
			else{
				sum=(ind + sum)%(po[16]);
				if(n > 0) update();
			}

			cin >> op;
		}

		cout << "Case " << ts++ << ": " << ans <<"\n";

		cin >> n;

		frr(i, 16) {
			v[i].clear();
			ini[i] = 0;
		}
	}
}
