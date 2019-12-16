#include <bits/stdc++.h>

using namespace std;

bool ordenacao(pair<int, string> a, pair<int, string>b){
	return a > b;
}

int main(){
	vector<pair<int, string>> v;

	int n, teams;
	cin >> n >> teams; 

	for(int i = 0; i < n; i++){
		int hab;
		string nome;
		cin >> nome >> hab;

		v.push_back(make_pair(hab, nome));
	}

	sort(v.begin(), v.end(), ordenacao);

	for(int i = 0; i < teams; i++){
		cout << "Time " << i+1 << endl;

		vector<string> time;
		int j = 0;
		while(teams*j + i < n){
			time.push_back(v[teams*j + i].second);
			j++;
		}

		sort(time.begin(), time.end());

		for(int i = 0; i < time.size(); i++) cout << time[i] << endl;

		cout << endl;
	}
}