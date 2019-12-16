#include <iostream>

using namespace std;

int main(){
	int curvas;
	cin >> curvas;
	
	int x[1000], y[1000];
	
	cin >> x[0] >> y[0];
	
	int dir[1010];
	
	for(int i = 1; i <= curvas; i++) {
		cin >> x[i] >> y[i];
		
		if(x[i] == x[i-1]){
			if(y[i] > y[i-1]) dir[i] = 0; // norte
			else dir[i] = 2;  //sul
		}
		
		if(y[i] == y[i-1]){
			if(x[i] > x[i-1]) dir[i] = 1; //leste
			else dir[i] = 3; //oeste
		}
		
	}
	
	dir[curvas+1] = dir[1]; 
	
	int resp = 0;
	
	for(int i = 1; i <= curvas; i++){
		if(dir[i+1] == (dir[i]+1)%4){
			resp++;
		}
	}
	
	cout << curvas - resp << endl;
	
	return 0; 
}
