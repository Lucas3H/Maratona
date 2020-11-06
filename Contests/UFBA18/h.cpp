#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
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
#define INF 1000000000000000100

int main(){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;

		if(n == 1){
			cout << 1 << endl;
			continue;
		}

		ll ans = 0;

		ll p2 = (ll)2, sum = (ll)1;

		while(p2 <= n){
			ll tot = n/p2;

			tot = (tot + (ll)1)/2;

			for(ll k = 0; k < sum; k++){
				ll x = sum - k;
				ans += tot*x*(((ll)1 << (x-1)));
			}
			//cout << tot << " " << ans << endl;
			sum++;
			p2*=(ll)2;
		}

		cout << ans << endl;
	}
}
