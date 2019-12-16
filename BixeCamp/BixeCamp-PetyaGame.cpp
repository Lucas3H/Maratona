#include <iostream>
#include <cmath>

using namespace std;

int ehprimo(int p){
	if(p == 1) return 0;
	if(p == 2) return 1;
	
	for(int i = 2; i < p; i++){
		if(p%i==0) return 0;
	}
	
	return 1;
}

int main(){
	int n, resp = 0, p = 0;
	cin >> n;
	int primos[1001];
	
	for(int i = 1; i <= n ; i++){
		if(ehprimo(i)){
			p++;
			primos[p] = i;
			resp += floor((log10(n)/log10(i)));
		}
	}
	
	cout << resp << endl;
	for(int i = 1; i <= p; i++){
		for(int j = 1; pow(primos[i], j) <= n; j++){
			cout << pow(primos[i], j) << " ";
		}
	}
	
	return 0;
}
