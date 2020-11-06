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

ll a[MAXN], b[MAXN];


int main(){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;

	while(t--){
		ll n, m;
		cin >> n >> m;

		ll pos[MAXN];

		frr(i, n){
			cin >> a[i];
			pos[a[i]] = i;
		}
		frr(i, m){
			cin >> b[i];
		}

		ll maior = 0;
		ll ans = 0;
		frr(i, m){
			if(maior < pos[b[i]]){
				maior = pos[b[i]];
				ans += 2*(pos[b[i]] - 1 - i + 1) + 1;
			}
			else ans++;
		}

		cout << ans<< endl;
	}
}
