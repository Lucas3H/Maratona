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

int dp[2010][2010], esp[2010][2010];
string s;
int e[2010];
int n;

void build(int p){

	dp[p][p] = 1;
	esp[p][p] = e[p];
	for(int i = p-1; i >= 0; i--){
		if(s[i] == s[p]){
			int extra = e[p] + e[i];
			pii ep[3];
			ep[0] = {esp[i+1][p-1] + extra, dp[i+1][p-1] + 2};
			ep[1] = {esp[i][p-1], dp[i][p-1]};
			ep[2] = {esp[i+1][p], dp[i+1][p]};

			sort(ep, ep + 3);
			dp[i][p] = ep[2].s;
			esp[i][p] = ep[2].f;
		}
		else{
			if(esp[i][p-1] > esp[i+1][p]){
				dp[i][p] = dp[i][p-1];
				esp[i][p] = esp[i][p-1];
			}
			else if(esp[i][p-1] < esp[i+1][p]){
				dp[i][p] = dp[i+1][p];
				esp[i][p] = esp[i+1][p];
			}
			else{
				dp[i][p] = max(dp[i][p-1], dp[i+1][p]);
				esp[i][p] = esp[i+1][p];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	cin >> s;
	n = s.size();
	int E;
	cin >> E;

	fr(i, E){
		int x;
		cin >> x;

		e[x-1] = 1;
	}

	fr(i, n){
		build(i);
	}

	/*
	fr(i, n){
		fr(j, i + 1) cout << j << " " << i << " " << dp[j][i] << endl;
	}
	*/

	cout << dp[0][n-1] << endl;
}
