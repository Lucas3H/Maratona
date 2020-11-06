#include <bits/stdc++.h>

using namespace std;

int a[510][510], b[510][510];

int main(){

	int x = 1;

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for (int j = 0; i < m; j++) cin >> a[i][j];

	for(int i = 0; i < n; i++){
		for (int j = 0; i < m; j++) cin >> b[i][j];

	int ra[510], rb[510], ca[510], cb[510];

	for(int i = 0; i < n; i++){
		ra[i] = 0;
		rb[i] = 0;
		for(int j = 0; j < m; j++){
			ra[i] += a[i][j];
			rb[i] += b[i][j];
		}

		if(ra[i]%2 != rb[i]%2) x = 0;
	}

	for(int i = 0; i < m; i++){
		ca[i] = 0;
		cb[i] = 0;
		for(int j = 0; j < m; j++){
			ca[i] += a[j][i];
			cb[i] += b[j][i];
		}

		if(ca[i]%2 != cb[i]%2) x = 0;
	}

	if(x) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}