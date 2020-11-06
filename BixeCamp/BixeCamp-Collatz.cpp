#include <bits/stdc++.h>

using namespace std; 

int collatz(int n){
	if(n%2 == 0) return n/2;
	else return 3*n+1;
}

int main(){
	int n, q = 0;
	cin >> n;

	while(n > 1){
		q++;
		n = collatz(n);
	}

	cout << q << endl;

	return 0;
}