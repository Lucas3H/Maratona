#include<bits/stdc++.h>

using namespace std;

int f[100000];

int fibonacci(int n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(f[n] > -1) return f[n];

	return f[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	int n;
	cin >> n;

	memset(f, -1, sizeof(f));

	cout << fibonacci(n) << endl;

	return 0;
}