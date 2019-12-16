#include <bits/stdc++.h>

using namespace std;

int m[1010], dp[1010];
int moedas;

int t(int x){
	if(x == 0) return 1;
	if(x < 0) return 0;
	if(dp[x] >= 0) return dp[x];
	
	for(int i=0; i < moedas; i++){
		if(t(x-m[i])) return dp[x] = 1;
	} 
	
	return 0;
}

int main(){
	int troco, resp = 0;
	
	cin >> moedas >> troco;
	
	for(int i = 0; i < moedas; i++) cin >> m[i];
	
	memset( dp, -1, sizeof(dp));
	
	for(int i=1; i < troco; i++){
		if(!t(i)) resp++;
	}
	
	cout << resp << endl;
	
	return 0;
}
