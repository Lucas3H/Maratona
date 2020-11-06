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

#define MAXN 10010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

ll n, k;
ll v[MAXN];

void read(){
	cin >> n >> k;

	fr(i, n){
		fr(j, k){
			ll x;
			cin >> x;
			v[i] += ((ll)1 << j)*(x%2);
		}
	}
}

vector<ll> base;

ll firstBit(ll x){
	return (x&-x);
}

ll add(ll val){
	vector<ll> aux;
	for(auto x: base) aux.pb(x);
	aux.pb(val);

	fr(i, aux.size()){
		ll ind = firstBit(aux[i]);
		if(aux[i] == 0) return 0;

		for(ll j = i+(ll)1; j < aux.size(); j++){
			if((aux[j] & ind) != 0){
				aux[j] ^= aux[i];
			}
		}
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	read();
  	sort(v, v + n);
  	
	if(v[n-1] > 0)
  		base.pb(v[n-1]);
  	else{
  		cout << "S\n" << endl;
    	return 0;
  	}

	frm(i, n-1){
		if(add(v[i]))
			base.pb(v[i]);
	}

	if(base.size() == k && n > k){
		cout << "N\n";
	}
	else{
		cout << "S\n";
	}
}
