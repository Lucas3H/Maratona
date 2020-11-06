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
ll a[5*MAXN];

map<ll, ll> m;
set<ll> v;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b); 
}

void solve(ll i){
	set<ll> aux;
	for(auto x: v){
		aux.insert(gcd(x, a[i]));
	}
	aux.insert(a[i]);

	v = aux;
	for(auto x: v){
		m[x] = 1;
	}	
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n;

	frr(i, n){
		cin >> a[i];
	}

	m[a[1]] = 1;
	v.insert(a[1]);

	for(ll i = 2; i <= n; i++){
		solve(i);
	}

	ll ans = 0;

	for(auto x: m){
		ans++;
	}

	cout << ans << endl;
}
