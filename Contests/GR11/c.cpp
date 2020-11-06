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

int r, n;

int dp[10*MAXN], best[10*MAXN];
int t[10*MAXN], x[10*MAXN], y[10*MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> r >> n;

	dp[0] = 0;
	x[0] = 1, y[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> x[i] >> y[i];

		dp[i] = 0;
		if(t[i] >= abs(x[i] - 1) + abs(y[i] - 1)){
			dp[i] = 1;
		}
		for(int j = i-1; j >= 1; j--){
			if(t[i] - t[j] > 2*r){
				dp[i] = max(dp[i], best[j] + 1);
				break;
			}

			if(t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]) && dp[j] > 0){
				dp[i] = max(dp[i], dp[j] + 1);
				//cout << i << " " << j<< endl;
			}
		}

		best[i] = max(best[i-1], dp[i]);
		//cout << best[i] << endl;
	}

	cout << best[n] << endl;
}
