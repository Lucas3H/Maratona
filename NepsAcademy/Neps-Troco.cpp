#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int t(vector<int> &v, int change){
	
	if(change == 0) return 0;
	if(change < 0) return -1;
	if(dp[change] >= -1) return dp[change];
	
	int min = 1001;
	
	for(int i=0; i<v.size(); i++){
		if(t(v, change - v[i]) >= 0 && t(v, change - v[i]) < min) min = t(v, change - v[i]);
	}
	
	if(min < 1001) return dp[change] = min + 1;
	return dp[change] = -1;
}

int main(){
	int moedas, troco;
	cin >> moedas >> troco;
	
	vector<int> c;
	
	for(int i=0; i < moedas; i++){
		int x;
		cin >> x;
		c.push_back(x);
	}
	
	memset(dp, -2, sizeof(dp));
	
	if(t(c, troco) < 10 && t(c, troco) >= 0) cout << "S" << endl;
	else cout << "N" << endl;
}
