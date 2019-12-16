#include <iostream>
#include <cstring>
#include <algorithm>

#define MAXN 1005

using namespace std;

struct Caixa{
	int peso;
	int resistencia;
};

bool ordenacao(Caixa A, Caixa B){
	return A.resistencia > B.resistencia;
}

Caixa c[MAXN];
int dp[MAXN][MAXN];
int numero_de_caixas;

int empilhar(int topo, int pilha){
	if(dp[topo][pilha] != -1) return dp[topo][pilha];
	if(pilha == 1) return dp[topo][pilha] = c[topo].resistencia - c[topo].peso;
	if(topo == numero_de_caixas) return 0;
	
	int max = -1;
	for(int i = 0; i < topo; i++){
		if(empilhar(i, pilha-1) > max) max = empilhar(i, pilha-1);
	}
	
	int Min = min(c[topo].resistencia, max) - c[topo].peso;
	
	return dp[topo][pilha] = Min;
}

int main(){
	cin >> numero_de_caixas;
		
	for (int i=0; i < numero_de_caixas; i++) cin >> c[i].peso >> c[i].resistencia;
	
	sort(c, c + numero_de_caixas, ordenacao);
	
	memset( dp, -1, sizeof(dp));
	
	int resp = 0, x = 0;
	
	for(int i=numero_de_caixas; i >= 0; i--){
		for(int j=0; j < numero_de_caixas; j++){
			if(empilhar(j, i) >= 0){
				resp = i;
				x = 1;
				break;
			}
		}
		
		if(x) break;
	}
	
	cout << resp << endl;
	return 0;
}
