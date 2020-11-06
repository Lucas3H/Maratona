// 
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

#define MAXN 500100
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll peso[MAXN];
ll n, m;
ll pai[MAXN];
ll ans[MAXN];
map<ll, ll> ma;

void read(){
	cin >> n >> m;

	frr(i, n){
		peso[i] = 1;
	}

	fr(i, n-1){
		cin >> pai[i+2];
	}

	for(int i = n; i >= 2; i--){
		peso[pai[i]]+=peso[i];
	}
}

vector<ll> p;
bool prime[MAXN];

void crivo(){
	for(int i = 2; i < MAXN; i++){
		if(prime[i] == 0){
			p.pb(i);

			for(int j = 2; j*i < MAXN; j++) prime[i*j] = 1;
		}
	}
}

void fac(int x){
	ll i = 0;
	while(p[i]*p[i] <= x){
		if(x%p[i] == 0){
			ma[p[i]]--;
			x/=p[i];
		}
		else i++;
	}

	if(x > 1){
		ma[x]--;
	}
}

int main(){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;

	crivo();

	frr(ts, t){
		read();

		ma.clear();

		fr(i, p.size()){
			ll pdavez = p[i];

			while(pdavez < n){
				ma[p[i]] += (int)floor((n-1)/pdavez);
				pdavez*=p[i];
			}

		}

		for(int i = 2; i <= n; i++){
			fac(peso[i]);
		}

		ll resp = 1;
		for(auto x: ma){

			ll q = x.s;

			for(int j = 0; j < q; j++){
				resp = (resp*x.f)%m;
			}
		}

		cout << resp << "\n";
	}
}