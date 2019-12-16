#include<iostream>

using namespace std;

int main(){
	int n, m; 
	long long distancia=0;
	cin>>n>>m;
	int medidas[n+1];
	medidas[0]=0;
	
	for(int i=1; i<=n; i++){
		cin>>medidas[i];
		if(medidas[i]>m-medidas[i]){
			medidas[i]=m-medidas[i];
		}
	}
	
	for(int i=1; i<=n; i++){
		if(medidas[i-1]<=medidas[i]){
			distancia+=medidas[i];
		}
		else if(medidas[i-1]>medidas[i] && medidas[i-1]<=m-medidas[i]){
			medidas[i]=m-medidas[i];
			distancia+=medidas[i];
		}
		else if(medidas[i-1]>medidas[i] && medidas[i-1]>m-medidas[i]){
			distancia = -1;
			break;
		}
	}
	
	cout<<distancia<<"\n";
	
	return 0;
}
