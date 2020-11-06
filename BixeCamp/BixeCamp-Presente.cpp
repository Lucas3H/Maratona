#include<bits/stdc++.h>
#define INF 1000100010
using namespace std;

long long f[100010];

long long flowers, days, w;

bool height_possible(long long h){
	long long grow[100010];
	
	//Definir o crescimento da planta que é necessário
	for(int i=0; i<flowers; i++){
		if(h > f[i]) grow[i] = h - f[i];
		else grow[i] = 0; 
	}
	
	// s é a quantidade de vezes que em que comecei regando as últimas w-1 plantas
	long long s = 0, resp = 0;
	
	long long water[100010];


	for(int i = 0; i < w-1; i++){
		
		if(grow[i] - s > 0){
			
			water[i] = grow[i] - s;
			resp += water[i];
			s += water[i];
				
		}
		else water[i] = 0;
	}
	
	for(int i=w-1; i<flowers; i++){
		if(grow[i] - s > 0){
			
			water[i] = grow[i] - s;
			resp += water[i];
			s+=water[i] - water[i-w+1];
			
		} 
		else{
			water[i] = 0;
			s+=water[i] - water[i-w+1];
		}
	}
	
	if(resp > days) return 0;
	else return 1;
}

int main(){
	
	cin >> flowers >> days >> w;
	
	for(int i=0; i<flowers; i++) cin >> f[i];
	
	long long ini = 1, fim = INF, meio;
	
	int i = 0;

	while(i < 60){
		meio = (ini+fim)/2;
		
		if(height_possible(meio)) ini = meio;	
		else fim = meio;

		i++;
	}
	
	cout << ini << endl;
	
	return 0;
}