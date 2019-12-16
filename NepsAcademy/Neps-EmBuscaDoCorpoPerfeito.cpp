#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];

int a, p;

int prot[2005], peso[2005];

int comer(int pedaco, int aguenta){
	if(dp[pedaco][aguenta] != -1) return dp[pedaco][aguenta];
	
	if(pedaco == p || aguenta == 0) return 0;
	
	if(peso[pedaco] > aguenta) return dp[pedaco][aguenta] = comer(pedaco+1, aguenta);
	
	else{
		return dp[pedaco][aguenta] = max(comer(pedaco+1, aguenta), comer(pedaco+1, aguenta-peso[pedaco]) + prot[pedaco]);
	} 
}

int main(){
	cin >> a >> p;
	
	for(int i=0; i<p; i++) cin >> peso[i] >> prot[i];
	
	memset( dp, -1, sizeof(dp));
	
	cout << comer(0, a) << endl;
	
	return 0;
}
