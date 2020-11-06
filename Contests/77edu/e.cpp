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
typedef pair<ll, ll> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007

int main(){
	ll n;
	cin >> n;

	ll total = floor((log(n + 0.0000001))/log(2));

	ll a[(1 << 18) + 10];
	frr(i, n) cin >> a[i];

	ll i = 1;
	while(a[i] != -1) i++;

	ll no_bribe = floor((log(i + 0.0000001))/log(2));

	ll j = total - no_bribe;

	sort(a + i + 1, a + n + 1);

	ll ans = (ll)0;
	for(ll k = i + 1; k < j + i + 1; k++) ans += (ll)a[k];

	cout << ans << endl;
}