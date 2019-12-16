#include<iostream>

using namespace std;

int main(){
	int soma=0, n, var=0;
	int q[10][10];
	bool x=1;
	cin>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>q[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		soma+=q[i][n-1-i];
		var+=q[i][i];
	}
	
	if(soma!=var){
		x=0;
	}
	
	for(int i=0; i<n; i++){
		var=0;
		for(int j=0; j<n; j++){
			var+=q[i][j];
		}
		if(soma!=var){
			x=0;
		}
	}
	
	for(int i=0; i<n; i++){
		var=0;
		for(int j=0; j<n; j++){
			var+=q[j][i];
		}
		if(soma!=var){
			x=0;
		}
	}
	if(x==0){
		cout<<-1;
	}
	else{
		cout<<soma;
	}
}
