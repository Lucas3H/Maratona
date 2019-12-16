#include<iostream>
#include<algorithm>

#define MAXN 10100

using namespace std;

struct Consulta{
	int inicio, fim;
};

bool comparaFim(Consulta a, Consulta b){
	return a.fim < b.fim;
}

int n, qtd=0;
		
Consulta C[MAXN];

int main(){
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>C[i].inicio>>C[i].fim;
	}
	
	sort(C+1, C+n+1, comparaFim);
	
	int fim=0;
	
	for(int i=1; i<=n; i++){
		if(C[i].inicio>=fim){
			fim=C[i].fim;
			qtd++;
		}
	}
	
	cout<<qtd<<"\n";
	
	return 0;
}
