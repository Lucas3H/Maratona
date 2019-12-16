#include<iostream>

using namespace std;

int main(){
	int bancos, debentures;
	int reserva[20];
	
	while(1){
		cin>>bancos>>debentures;
		if(bancos==0 && debentures==0){
			break;
		}
		for(int i=0; i<bancos; i++){
			cin>>reserva[i];
		}
		
		for(int i=0; i<debentures; i++){
			int devedor, credor, divida; 
			cin>>devedor>>credor>>divida;
			reserva[devedor-1]-=divida;
			reserva[credor-1]+=divida;
		}
		
		bool x=0;
		for(int i=0; i<bancos; i++){
			if(reserva[i]<0){
				x=1;
			}
		}
		if(x==1){
			cout<<"N\n";
		}
		else{
			cout<<"S\n";
		}
	}
	
	return 0;
}
