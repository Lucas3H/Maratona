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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000000

ll memo[3*MAXN][3];
ll a[3*MAXN], b[3*MAXN];
ll n, q;

ll dp(int ind, int ant_cresceu){
	if(ind == n+1) return 0;
	if(memo[ind][ant_cresceu] > -1) return memo[ind][ant_cresceu];

	ll ans = INF;

	if(a[ind] != a[ind-1] + ant_cresceu) ans = min(ans, dp(ind+1, 0));
	if(a[ind] + 1 != a[ind-1] + ant_cresceu) ans = min(ans, dp(ind+1, 1) + b[ind]);
	if(a[ind] + 2 != a[ind-1] + ant_cresceu) ans = min(ans, dp(ind+1, 2) + 2*b[ind]);

	return memo[ind][ant_cresceu] = ans;
}

int main(){
	ios::sync_with_stdio(false);

	cin >> q;

	while(q--){
		cin >> n;
		frr(i, n){
			memo[i][0] = -1;
			memo[i][1] = -1;
			memo[i][2] = -1;
		}

		frr(i, n) cin >> a[i] >> b[i];

		cout << dp(1, 0) << endl;

		//frr(i, n) cout << memo[i][0] << " " << memo[i][1] <<" " << memo[i][0] << endl;
	}
}
