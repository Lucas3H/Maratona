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

vector<int> jump[501];
int dp[501];
int n;
int v[501];

void build(int ini){
	stack<int> s;

	s.push(v[ini]);
	jump[ini].pb(ini + 1);

	for(int i = ini + 1; i <= n; i++){
		int davez = v[i];

		while(!s.empty() && davez == s.top()){
			s.pop();
			davez = davez + 1;
		}
		s.push(davez);

		if(s.size() == 1){
			jump[ini].pb(i + 1);
		}
	}
}

int ans(int pos){
	if(pos == n + 1) return 0;
	else if(dp[pos] < 1000) return dp[pos];
	
	int small = 1000;
	for(auto x: jump[pos]){
		small = min(small, ans(x) + 1);
	}

	return dp[pos] = small;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	frr(i, n){
		cin >> v[i];
		dp[i] = 1000;
	}

	frr(i, n){
		build(i);
	}

	cout << ans(1) << endl;
}
