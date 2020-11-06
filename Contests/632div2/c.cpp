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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;

	ll a[MAXN];
	frr(i, n) cin >> a[i];

	map<ll, ll> m;

	ll sum[MAXN];
	sum[0] = 0;
	m[0] = 0;
	
	ll maxl = -1;

	set<ll> ap;
	ap.insert(0);

	ll ans = 0;

	frr(i, n){
		sum[i] = sum[i-1] + a[i];
		
		if(ap.find(sum[i]) != ap.end()) {
			maxl = max(maxl, m[sum[i]]);
		}

		if(maxl > -1) ans += maxl + 1;
		ap.insert(sum[i]);
		m[sum[i]] = i;

		//cout << ans << endl;
	}
	
	cout << n*(n+1)/2 - ans << endl;
}
