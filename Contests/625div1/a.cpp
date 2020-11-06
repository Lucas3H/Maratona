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

vector<ll> b_pos[3*MAXN];
ll b[MAXN];
ll n;
ll dp[MAXN];

int main(){
	cin >> n;
	frr(i, n){
		scanf("%lld", &b[i]);

		dp[i] = b[i];

		b_pos[i - b[i] + 400000].pb(i);
	}

	ll sum = 0;
	ll ans = 0;
	fr(i, 3*MAXN){
		sum = 0;
		for(auto x: b_pos[i]){
			sum+=b[x];
		}

		ans = max(sum, ans);
	}


	cout << ans << endl;
}
