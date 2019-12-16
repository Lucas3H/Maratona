#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int m[10][10];
	
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++) cin >> m[i][j];
	}
	
	bool x = 1;
	int soma = 0;
	
	for(int i=0; i < n; i++){
		soma+=m[0][i]; 
	}
	
	for(int i=0; i < n; i++){
		int sum=0;
		for(int j=0; j < n; j++) sum+=m[i][j];
		
		if(sum != soma){
			x = 0;
			break;
		}
		
		sum = 0; 
		for(int j=0; j < n; j++) sum+=m[j][i];
		
		if(sum != soma){
			x = 0;
			break;
		}
	}
	
	int s=0;
	for(int i=0; i < n; i++){
		s+=m[i][i];
	}
	
	if(s != soma){
		x = 0;
	}
	
	s=0;
	for(int i=0; i < n; i++){
		s+=m[i][n-1-i];
	}
	
	if(s != soma){
		x = 0;
	}
	
	if(x == 0) cout << -1 << endl;
	else cout << soma << endl;
	
	return 0;
}
