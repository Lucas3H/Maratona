#include<bits/stdc++.h>

using namespace std;

int main(){
	int insta, inter;
	cin >> insta >> inter;

	map<int, int> m;
	set<int> resp;

	for(int i = 0; i < insta; i++){
		int apli, versao;
		cin >> apli >> versao;

		m[apli] = versao;
	}

	for(int i = 0; i < inter; i++){
		int apli, versao;
		cin >> apli >> versao;

		int k = m.find(apli)->first;

		if(m.find(apli) == m.end()){
			m.insert(make_pair(apli, versao));
			resp.insert(apli);
		}
		else{
			if(m[k] < versao){
				m[k] = versao;
				resp.insert(apli);
			}
		}
	}

	for (set<int>::iterator i = resp.begin(); i != resp.end(); ++i){
		cout << *i << " " << m[*i] << endl; 
	}

	return 0;
}