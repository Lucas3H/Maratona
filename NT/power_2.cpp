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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

map<ll, ll> m;

pii achar2(ll v){
	for(int i = 0; i < 33; i++){
		if(m[v - (1 << i)] > 0 && m[v + (1 << i)] > 0){
			return mp(v - (1 << i), v + (1 << i));
		}
	}

	return mp(-1, -1);
}

int achar1(ll v){
	for(int i = 0; i < 33; i++){
		if(m[v - (1 << i)] > 0)
			return (v - (1 << i));
		else if( m[v + (1 << i)] > 0){
			return (v + (1 << i));
		}
	}

	return -MOD;
}

int main(){
	ll n;
	cin >> n;

	ll x[2*MAXN];

	fr(i, n){
		cin >> x[i];

		m[x[i]]++;
	}

	fr(i, n){
		pii ans = achar2(x[i]);
		if(ans != mp((ll)-1, (ll)-1)){
			cout << 3 << endl;
			cout << ans.f <<" " << x[i] << " " << ans.s << endl;
			return 0;
		}
	}


	fr(i, n){
		int ans = achar1(x[i]);
		if(ans != -MOD){
			cout << 2 << endl;
			cout << x[i] << " " << ans << endl;
			return 0;
		}
	}

	cout << 1 << endl;
	cout << x[0] << endl;
}
