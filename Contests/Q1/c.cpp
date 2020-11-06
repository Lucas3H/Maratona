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

string s, t;
int dp[2][MAXN];

void solve(){
	frr(i, s.size()){
		int start = max(1, i - 1000);
		int end = min((int)t.size(), i + 1000);
		
		for(int j = start; j <= end; j++){
			if(s[i-1] == t[j-1]){
				dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j-1] + 1);
			}

			dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j]);
			dp[i%2][j] = max(dp[i%2][j], dp[i%2][j-1]);
		}
	}

	if(dp[(s.size())%2][t.size()]*100 >= 99*s.size())
		cout << "Long lost brothers D:\n";
	else
		cout << "Not brothers :(\n";
}

int main(){
	cin >> s >> t;
	solve();
}
