#include <bits/stdc++.h>
using namespace std;

int main(){
	int v[11];
	int k;
	char x;
	
	memset (v, 0, sizeof(v));
	
	cin >> k;
	
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin >> x;
			if(x=='.') v[0]++;
			else if(x=='1') v[1]++;
			else if(x=='2') v[2]++;
			else if(x=='3') v[3]++;
			else if(x=='4') v[4]++;
			else if(x=='5') v[5]++;
			else if(x=='6') v[6]++;
			else if(x=='7') v[7]++;
			else if(x=='8') v[8]++;
			else if(x=='9') v[9]++;
		}
	}
	
	bool y=1;
	
	for(int i=1; i<10; i++){
		if(v[i] > 2*k) y = 0;
	}
	
	if(y) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
