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
#define MOD 1000000009
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll dp[1010][150], nbs[1010][150];
ll k, b;
ll invK;

int main(){
	cin >> k >> b;

	dp[1%k][1] = 1;
	nbs[0][0] = 1;

	fr(i, b){
		fr(j, k){
			//nbs[j][i + 1] = (nbs[j][i + 1] + nbs[j][i])%MOD;
			nbs[(2*j)%k][i + 1] = (nbs[(2*j)%k][i + 1] + nbs[j][i])%MOD;
			nbs[(2*j + 1)%k][i + 1] = (nbs[(2*j + 1)%k][i + 1] + nbs[j][i])%MOD;
		}
	}

	frr(i, b-1){
		fr(j, k){
			dp[(2*j)%k][i + 1] = (dp[(2*j)%k][i + 1] + dp[j][i])%MOD;
			dp[(2*j + 1)%k][i + 1] = (dp[(2*j + 1)%k][i + 1] + dp[j][i] + nbs[j][i])%MOD;
		}
	}
	
	cout << dp[0][b] << endl;
}