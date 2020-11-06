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

int dp[100][100];
string s;
string p;

int solve(int pos, int ind){
	if(dp[pos][ind] > -1) return dp[pos][ind];

	if(ind >= 26) return 0;
	if(pos >= s.size()) return 26 - ind;

	if(s[pos] - 'a' == ind) return dp[pos][ind] = solve(pos + 1, ind + 1);
	else return dp[pos][ind] = min(solve(pos, ind + 1) + 1, solve(pos + 1, ind));
}

int main(){
	ios::sync_with_stdio(false);
	mem(dp, -1);

	fr(i, 26){
		p += 'a' + i;
	} 

	cin >> s;
	cout << solve(0, 0) << endl;
}
