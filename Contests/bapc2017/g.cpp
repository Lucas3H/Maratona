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

int n, m;
int a[30];

void read(){
	cin >> m >> n;

	fr(i, n){
		int x, y, z;
		cin >> x >> y >> z;

		a[x]+=z;
		a[y]-=z;
	}
}

int is_zero(int mask){
	int sum = 0;
	int ind = 0;

	while(mask > 0){
		if(mask%2 == 1)
			sum += a[ind];

		ind++;
		mask /= 2;
	}

	if(sum == 0) return 1;
	else return 0;
}

int dp[(1 << 21)];

int solve(int mask){
	//cout << mask << endl;

	if(mask == 0) return 0;
	else if(dp[mask] > -1) return dp[mask];
	
	int ans = 0;

	fr(i, m){
		if(((1 << i)&mask) > 0)
			ans = max(ans, solve(mask^(1 << i)));
	}

	return dp[mask] = ans + (int)is_zero(mask);
}

int main(){
	ios::sync_with_stdio(false);

	mem(dp, -1);

	read();

	cout << m - solve(((1 << m) - 1)) << endl;
/*
	fr(i, (1 << m)){
		cout << i << " " << dp[i] << " " << is_zero(i) << endl;
	}
	*/
}
