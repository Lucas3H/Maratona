#include<iostream>

using namespace std;

int main(){
	int N, B;
	int b[91];
	
	while(1){
		cin>>N>>B;
		if(N==0 && B==0){
			break;
		}
		
		bool y=1;
		
		for(int i=1; i<B+1; i++){
			cin>>b[i];
		}
	
		for(int i=1; i<N+1; i++){
			bool x=0;
		
			for(int j=1; j<B+1; j++){
				for(int k=1; k<B+1; k++){
					if((b[k]-b[j]==i)||(b[j]-b[k]==i)){
						x=1;
						break;
					}	
				}
				if(x==1){
					break;
				}
			}	
			
			if(x==0){
				y=0;
				break;
			}
		}
		
		if(y==0){
			cout<<"N\n";
		}
		else{
			cout<<"Y\n";
		}
	}
}
