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
#define MOD 998244353
#define MAXL 30
#define ROOT 1
#define INF 987654321

int main(){
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;

	ll p[2*MAXN], sum = 0;
	vector<ll> pos;

	frr(i, n){
		cin >> p[i];
		if(p[i] >= n - k + 1){
			pos.pb(i);
			sum+=p[i];
		}
	}

	ll ans = 1;

	fr(i, pos.size() - 1){
		ans = (ans*(pos[i + 1] - pos[i]))%MOD;
	}

	cout << sum << " " << ans << endl;
}
