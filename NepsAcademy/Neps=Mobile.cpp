#include <bits/stdc++.h>

using namespace std;

int v[100010];
vector<int> mobile[100010];

int dfs(int n){
	int tamanho = 1;
	
	for(int i = 0; i < mobile[n].size(); i++){
		tamanho += dfs(mobile[n][i]);
	}
	
	return v[n] = tamanho;
}

int main(){
	int mobiles;
	
	cin >> mobiles;
	
	for(int i = 0; i < mobiles; i++){
		int a, b;
		
		cin >> a >> b;
		
		mobile[b].push_back(a);
	}
	
	dfs(0);
	
	bool x = 1;
	
	for(int i = 0; i <= mobiles; i++){
		int j = 1;
		while(j < mobile[i].size()){
			if(v[mobile[i][j]] != v[mobile[i][j-1]]) x = 0;
			j++;
		}
	}
	
	if(x) cout << "bem" << endl;
	else cout << "mal" << endl;
	
	return 0;
}
