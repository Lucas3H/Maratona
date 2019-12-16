#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100], b[100];
int dp[100][100];
// Parametros são posicao da sequencia "a", a partir da qual eu vou buscar, e posicao de "b" em que vou buscar


int lcs(int A, int B){
	if(dp[A][B] >=0 ) return dp[A][B];
	
	if(A == 0 || B == 0) return dp[A][B] = 0;
	
	if(a[A-1] == b[B-1]) return dp[A][B] = lcs(A-1, B-1) + 1;
	
	return dp[A][B] = max(lcs(A-1, B), lcs(A, B-1));
	
	
	/*if(dp[A][B] != -1) return dp[A][B];
	
	if(B == m) return dp[A][B] = 0;
	
	int ind = -1;
	
	for(int i = A; i < n; i++){
		if(a[i] == b[B]){
			ind = i;
			break;
		}
	}
	
	if(ind == -1) return dp[A][B] = seq_comum(A, B+1);
	else return dp[A][B] = max(seq_comum(ind+1, B+1) + 1, seq_comum(A, B+1));*/  
}

int main(){	
	cout << "Digite o tamanho da primeira sequência:" << endl;
	cin >> n;
	
	cout << "Digite os elementos dessa sequência:" << endl;
	for(int i=0; i<n; i++) cin >> a[i];
	
	cout << "Digite o tamanho da segunda sequência:" << endl;
	cin >> m;
	
	cout << "Digite os elementos dessa sequência:" << endl;
	for(int i=0; i<m; i++) cin >> b[i];
	
	memset( dp, -1, sizeof(dp));
	
	cout << lcs(n, m) << endl;
}
