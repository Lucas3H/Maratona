#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	int c[300010];
	for(int i = 0; i < n; i++) cin >> c[i];

	int left, right;

	for(int i = 0; i < n; i++){
		if(c[i] != c[0]) {
			left = i;
			break;
		}
	}

	for(int i = n-1; i >= 0; i--){
		if(c[i] != c[n-1]){
			right = i;
			break;
		}
	}

	int m = max(n-1 - left, right);

	if(c[0]!=c[n-1]) cout << n-1 << endl;
	else cout << m << endl;

	return 0;
}