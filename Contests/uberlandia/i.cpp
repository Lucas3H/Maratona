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

int dp[2][501][2];
int p[MAXN], aux[MAXN], c[MAXN];

int n, k;

void solve(){
	for(int i = 0; i < k; i++){
		dp[1][i][1] = -p[1];
	}

	for(int dia = 2; dia <= n; dia++){
		dp[dia%2][k][0] = dp[(dia-1)%2][k][0];
		for(int i = 0; i < k; i++){
			dp[dia%2][i][0] = max(dp[(dia-1)%2][i][1] + p[dia] + c[dia], dp[(dia-1)%2][i][0]);
		}

		for(int i = 0; i < k; i++){
			dp[dia%2][i][1] = max(dp[(dia-1)%2][i][1], dp[dia%2][i-1][0] - p[dia]);
		}

		/*
		cout << dia << endl;
		for(int i = 0; i <= k; i++){
			cout << dp[dia%2][i][0] << " ";
		}
		cout << endl;
		for(int i = 0; i <= k; i++){
			cout << dp[dia%2][i][1] << " ";
		}
		cout << endl;
		*/
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	frr(i, n){
		cin >> p[i];
	}
	for(int i = 2; i <= n; i++) cin >> c[i];

	solve();

	int ans = 0;
	for(int i = 0; i <= k; i++){
		ans = max(ans, dp[n%2][i][0]);
	}
	cout << ans << endl;
}
