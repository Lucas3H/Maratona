#include <bits/stdc++.h>

using namespace std;

int n, m;
int s1[2005], s2[2005];
int dp[2005][2005];

int lcs(int a, int b){
	if(dp[a][b] >= 0) return dp[a][b];
	
	if(a == 0 || b == 0) return dp[a][b] = 0;
	
	if(s1[a-1] == s2[b-1]) return dp[a][b] = lcs(a-1, b-1) + 1;
	
	return dp[a][b] = max(lcs(a-1, b), lcs(a, b-1));
}

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++) cin >> s1[i];
	for(int i=0; i<m; i++) cin >> s2[i];
	
	memset( dp, -1, sizeof(dp));
	
	cout << n - lcs(n, m) << " " << m - lcs(n, m) << endl;
}
