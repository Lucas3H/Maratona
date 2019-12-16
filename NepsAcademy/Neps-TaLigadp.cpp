#include <bits/stdc++.h>

using namespace std;

int main(){
	int ilhas, interacoes;
	
	cin >> ilhas >> interacoes;
	
	vector<int> island[100010];
	
	for(int i = 0; i < interacoes; i++){
		int a, b, x;
		cin >> x >> a >> b;
		
		if(x){
			island[a].push_back(b);
			island[b].push_back(a);
		}
		else{
			bool y = 0;
			
			for(int i = 0; i < island[a].size(); i++){
				if(island[a][i] == b) y = 1;
			}
			
			cout << y << endl;
			
		}
	}
	
	return 0;
}
