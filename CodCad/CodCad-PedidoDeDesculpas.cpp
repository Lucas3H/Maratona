#include <bits/stdc++.h>
using namespace std;

int car_no_cartao, frases;

int dp[1001][51];
int caracteres[51], desculpas[51];

int dscp(int aguenta, int fr){
	if(dp[aguenta][fr] != -1) return dp[aguenta][fr];
	
	if(aguenta == 0 || fr == frases) return dp[aguenta][fr] = 0;
	
	if(aguenta < caracteres[fr]) return dp[aguenta][fr] = dscp(aguenta, fr+1);
	else return dp[aguenta][fr] = max(dscp(aguenta, fr+1), dscp(aguenta - caracteres[fr], fr+1) + desculpas[fr]);
}

int main(){
	cin >> car_no_cartao >> frases;
	
	int testes = 1;
	while(car_no_cartao != 0 && frases != 0){
		for(int i=0; i<frases; i++) cin >> caracteres[i] >> desculpas[i];
		
		memset( dp, -1, sizeof(dp));
		
		cout << "Teste " << testes << endl << dscp(car_no_cartao, 0) << endl << endl;
		
		testes++;
		
		cin >> car_no_cartao >> frases; 
	}
	
	return 0;
}
