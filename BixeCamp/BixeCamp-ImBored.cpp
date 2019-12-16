#include <bits/stdc++.h>

using namespace std;

int fatorial(int a){
	int f = 1;
	for(int i = a; i > 0; i--){
		f *= i;
	}

	return f;
}

int main(){
	int a, b;

	cin >> a >> b;

	int x = min(a, b);

	cout << fatorial(x) << endl;

	return 0;
}