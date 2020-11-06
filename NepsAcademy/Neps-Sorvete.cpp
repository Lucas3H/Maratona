#include <bits/stdc++.h>

using namespace std;

int main(){
	int praia, sorv;
	vector<pair<int,int>> v;

	cin >> praia >> sorv;

	for(int i = 0; i < sorv; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	int ini = v[0].first;
	int fim = v[0].second;

	v.push_back(make_pair(praia+1,praia+1));

	for(int i = 1; i <= sorv; i++){
		if(v[i].second > fim){
			if(v[i].first > fim){
				cout << ini << " " << fim << endl;
				ini = v[i].first;
				fim = v[i].second;
			}
			else{
				fim = v[i].second;
			}
		}	
	}

	cout << endl;
	return 0;
}