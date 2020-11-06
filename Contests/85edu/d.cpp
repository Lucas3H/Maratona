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

void prllK(ll k, ll l, ll r){
	ll tam = 2*(k-1);

	for(ll i = l; i <= r; i++){
		if(i%2 == 1){
			cout << k << " ";
		}
		else cout << i/2 + k << " ";
	}
}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while(t--){
		ll n, l, r;
		cin >> n >> l >> r;

		ll sum = 0;
		ll it = 1;

		while(sum + 2*(n - it) < l && it <= n){
			sum += 2*(n - it);
			it++;
			//cout << it << endl;
		}

		while(sum < r && it < n){
			prllK(it, max(l - sum, (ll)1), min(2*(n - it), r - sum));

			sum += 2*(n - it);
			it++;
		}

		if(n*(n-1) + 1 == r) cout << 1 << " ";

		cout << endl;
	}
}
