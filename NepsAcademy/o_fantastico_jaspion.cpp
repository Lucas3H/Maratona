#include<bits/stdc++.h>

using namespace std;

int main(){
	int traducoes;
	cin >> traducoes;

	while(traducoes--){
		int n, m;
		cin >> n >> m;

		map<string, string> traducao;
		for(int i = 0; i < n; i++){
			string a, b;
			cin >> a >> b;

			traducao.insert(make_pair(a, b));
		}

		for(int i = 0; i < m; i++){
			vector<char> linha;
			string p;

			while(cin >> p){

				//string s = traducao.find(p)->second;
				/*for(int j = 0; j < s.size(); j++){
					linha.push_back(s[j]);
				}

				linha.push_back(' ');*/
				//cout << s << endl;
			}

			//for(int j = 0; j < linha.size(); j++) cout << linha[j];
		}

		cout << endl;
	}

	return 0;
}