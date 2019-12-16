#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	vector<int> v;

	cin >> n;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}

	cin >> m;

	vector<int> saiu;

	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		saiu.push_back(x);
	}

	
	sort(saiu.begin(), saiu.end());

	int i = 0;
	while(saiu.size() > 0){

		int ini = 0, fim = saiu.size();
		int meio = (ini+fim)/2;

		while(ini < fim){
			if(saiu[meio] == v[i]){
				v.erase(v.begin() + i);
				saiu.erase(saiu.begin() + meio);
				i--;
				break;
			}
			else if(saiu[meio] < v[i]) ini = meio + 1;
			else fim = meio;

			meio = (ini+fim)/2;
		}

		i++;
	}
	

	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";

	return 0;	
}