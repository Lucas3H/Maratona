#include<iostream>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

typedef long long ll;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll dp[(1 << 15) + 10][18];
ll n, e;
ll adj[18][18];

void read(){
	cin >> n >> e;
	fr(i, n){
		fr(j, n) adj[i][j] = MOD;
	}

	fr(i, e){
		ll v1, v2;
		cin >> v1 >> v2;
		cin >> adj[v1][v2];
	}

	fr(i, (1 << n)){
		fr(j, n + 1){
			dp[i][j] = MOD;
		}
	}
}

ll solve(ll mask, ll ultimo){
	if(mask == ((1 << n) - 1)) return adj[ultimo][0];
	if(dp[mask][ultimo] < MOD) return dp[mask][ultimo];
	
	ll ans = MOD;
	frr(i, n-1){
		if(((1 << i) & mask) == 0 && adj[ultimo][i] < MOD){
			ans = min(ans, solve(mask | (1 << i), i) + adj[ultimo][i]);
		}
	}

	return dp[mask][ultimo] = ans;
}

int main(){
	read();

	ll k = solve(1, 0);

	if(k >= MOD) {
		cout << -1 << endl;
	}
	else{
		cout << k << endl;
	}
}
