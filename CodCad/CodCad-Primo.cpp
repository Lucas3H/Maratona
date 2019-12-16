#include<iostream>

using namespace std;

bool eh_primo(int x){
	
	if(x==1){
		return 0;
	}
	else{
		for(int i=1; i<x; i++){
			if(x%i==0 && i!=1){
				return 0;
			}
		}
		return 1;
	}
}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout<<"S"<<"\n";
	}else{
		cout<<"N"<<"\n";
	}
}

