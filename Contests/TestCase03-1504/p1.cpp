#include <bits/stdc++.h>

using namespace std;

int main(){
	int routes, t;

	cin >> routes >> t;

	int s[105], d[105];

	for(int i = 0; i < routes; i++) cin >> s[i] >> d[i];

	int x[105];

	for(int i = 0; i < routes; i++){
		if(t <= s[i]){
			x[i] = s[i];
		}
		else{
			x[i] = (t-s[i])/d[i];
			x[i] = (x[i]+1)*d[i] + s[i];	
		}	
	}

	int min = x[0], ind = 0;

	for(int i = 0; i < routes; i++){
		if(x[i] < min){
			min = x[i];
			ind = i;
		}
	}

	cout << ind + 1 << endl;

}