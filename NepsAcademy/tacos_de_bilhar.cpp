#include<bits/stdc++.h>

using namespace std;

int main(){
	int c, resp = 0;
	cin >> c;

	set<int> est;
	for(int i = 0; i < c; i++){
		int x;
		cin >> x;
		
		if(est.find(x) == est.end()){
			est.insert(x);
			resp+=2;
		}
		else est.erase(x);
	}

	cout << resp << endl;

	return 0;
}