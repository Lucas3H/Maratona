#include<iostream>
#include<algorithm>

using namespace std;

struct Caixa{
	int peso;
	int resistencia;
	int pesoAte;
};

Caixa pilha[1010];

bool compara(Caixa a, Caixa b){
	return a.peso < b.peso;
}

int cabe(int tamanho, int peso, int resistencia){
	for(int i=tamanho; i>=0; i--){
		if(pilha[i].resistencia-pilha[i].pesoAte<peso){
			return -1;
		}
		if(pilha[i].resistencia-pilha[i].pesoAte>=peso && pilha[i].pesoAte<=resistencia){//Peso até esse momento é<=resistencia
			return i;
		}
	}
	
	return -1;
}

int main(){
	int n;
	cin>>n;
	Caixa c[n+10];
	
	for(int i=1; i<=n; i++){
		cin>>c[i].peso>>c[i].resistencia;
		
		c[i].resistencia-=c[i].peso;
	}
	
	sort(c+1, c+n+1, compara);
	
	int resp=0;
	pilha[0].peso=0;
	pilha[0].resistencia=1001000;
	pilha[0].pesoAte=0;
	
	for(int i=1; i<=n; i++){
		
		int x=cabe(resp, c[i].peso, c[i].resistencia);
		
		if(x!=-1){
			
			int k=pilha[x].pesoAte;
			
			for(int j=resp; j>=x; j--){
				pilha[j].pesoAte+=c[i].peso;
				pilha[j+1]=pilha[j];
			}
			
			pilha[x]=c[i];
			pilha[x].pesoAte=k;
			
			resp++;
		}
	}
	
	cout<<resp<<endl;
	
	return 0;
}
