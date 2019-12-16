#include<iostream>
#include<algorithm>

using namespace std;

struct Bolsa{
	int tempo;
	int entrega;
};

bool compara(Bolsa a, Bolsa b){
	return a.entrega < b.entrega;
}

int main(){
	int n, soma=0, maior=0;
	cin>>n;
	
	Bolsa b[10001];
	
	for(int i=1; i<=n; i++){
		cin>>b[i].tempo>>b[i].entrega;
	}
	
	sort(b+1, b+n+1, compara);
	
	for(int i=1; i<=n; i++){
		soma+=b[i].tempo;
		if(soma-b[i].entrega>maior){
			maior=soma-b[i].entrega;
		}
	}
	
	cout<<maior<<endl;
	
	return 0;
}
