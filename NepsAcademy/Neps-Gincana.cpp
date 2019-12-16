#include <bits/stdc++.h>
	
using namespace std;
	
vector<int> student[1010];
int alunos, amizades;
int component[1010];
	
void dfs(int st){
	for(int i = 0; i < student[st].size(); i++){
		if(component[student[st][i]] == -1){
			component[student[st][i]] = component[st];
			dfs(student[st][i]);
		}
	}
}	
	
int main(){
	memset(component, -1, sizeof(component));
	
	cin >> alunos >> amizades;
	
	for(int i = 0; i < amizades; i++){
		int a, b;
		cin >> a >> b;
		
		student[a].push_back(b);
		student[b].push_back(a);
	}
	
	int resp = 1;
	
	component[1] = resp;
	dfs(1);
	
	for(int i = 1; i <= alunos; i++){
		if(component[i] == -1){
			component[i] = ++resp;
			dfs(i);
		}
	}
	
	cout << resp << endl;

	return 0;
}
