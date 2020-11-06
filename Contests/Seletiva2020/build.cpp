#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)

int main(){
	int n = 100;
	cout << n << "\n";
	fr(i, n){
		fr(j, 50) {
			if((random())%2 == 0) cout << 'a';
			else cout << 'b';
		}
		cout << '\n';
	}
	cout << 0 << "\n";
}