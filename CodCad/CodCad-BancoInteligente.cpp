#include<iostream>
#define MAXS 5001

using namespace std;

int n[8][MAXS], f[8][MAXS], q[8], v[8]={-1, 1, 2, 5, 10, 20, 50, 100};

int funcao(int k, int s){
	
	if(n[k][s]) return f[k][s];
	
	if(s==0) return 1;
	if(k==0) return 0;
	
	int notas=0;
	f[k][s]=0;
	
	while(notas<=q[k] && s-notas*v[k]>=0){
		f[k][s]+=funcao(k-1, s-notas*v[k]);
		notas++;
	}
	
	n[k][s]=1;
	
	return f[k][s];
} 

int main(){
	int soma;
	cin>>soma;
	
	for(int i=1; i<8; i++) cin>>q[i];
	
	for(int i=0; i<MAXS; i++){
		for(int j=0; j<7; j++){
			n[j][i]=0;
		}
	}
	
	cout<<funcao(7, soma)<<endl;
	
	return 0;
}
