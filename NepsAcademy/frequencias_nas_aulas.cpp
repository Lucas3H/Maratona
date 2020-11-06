#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	set<int> no;

	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		no.insert(num);
	}

	cout << no.size() << endl;

	return 0;
}