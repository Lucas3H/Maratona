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

int dp[10][10], m[10][10];

void solve(){
	dp[0][1] = m[1][1];

	frr(i, 3){
		frr(j, 3){
			dp[i][j] = max(dp[i-1][j]&m[i][j], dp[i][j-1]&m[i][j]);
		}
	}

	cout << dp[3][3] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int k;
	cin >> k;

	m[1][1] = (1 << 17) + k;
	m[1][2] = k;
	m[1][3] = 0;
	m[2][1] = (1 << 17);
	m[2][2] = (1 << 17) + k;
	m[2][3] = 0;
	m[3][1] = 0;
	m[3][2] = k;
	m[3][3] = k;


	cout << 3 << " " << 3 << endl;
	frr(i, 3){
		frr(j, 3) cout << m[i][j] << " ";
		cout << endl;
	}
/*
	solve();
	cout << (m[1][1]&m[1][2]&m[2][2]&m[3][2]&m[3][3]) << endl;
*/
}
