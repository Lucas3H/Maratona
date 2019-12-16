#include <iostream>
using namespace std;

bool coprimos(int a, int b){
	if(a==1 || b==1) return 1;
	
	for(int i = 2; i <= a; i++){
		if(b%i == 0 && a%i==0) return 0;
	}
	
	return 1;
}

int main(){
	int n;
	cin >> n;
	
	int resp;
	for(int i=n/2; i > 0; i--){
		if(coprimos(i, n)) {
			resp = i;
			break;	
		}
	}
	
	cout << resp << " " << n - resp << endl;
	
	return 0;
}
