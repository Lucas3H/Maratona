#include <bits/stdc++.h>

using namespace std;

int n;
long long a[1001], b[1001];
int dp[1001][1001];

int lcs(int x, int y){
	if(dp[x][y] >= 0) return dp[x][y];
	
	if(x == 0 || y == 0) return dp[x][y] = 0;
	
	if(a[x-1] == b[y-1]) return dp[x][y] = lcs(x-1, y-1) + 1;
	
	return dp[x][y] = max(lcs(x-1, y), lcs(x, y-1));
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	
	sort(b, b+n);
	
	memset( dp, -1, sizeof(dp));
	
	cout << lcs(n,n) << endl;
	
	return 0;
}
