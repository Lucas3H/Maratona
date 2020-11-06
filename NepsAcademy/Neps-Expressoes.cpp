#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		stack<char> pilha;

		string s;
		cin >> s;

		int definido = 1;

		for(int j = 0; j < s.size(); j++){
			if(s[j] == '{' || s[j] == '(' || s[j] == '[') pilha.push(char(s[j]));
			else{
				if(pilha.empty()){
					definido = 0;
					break;
				}
				else if(s[j] == '}' && pilha.top() == '{') pilha.pop();
				else if(s[j] == ']' && pilha.top() == '[') pilha.pop();
				else if(s[j] == ')' && pilha.top() == '(') pilha.pop();
				else{
					definido = 0;
					break;	
				}
			}
		}

		if(!pilha.empty()) definido = 0;

		if(definido == 1) cout << "S" << endl;
		else cout << "N" << endl;
	}

	return 0;
}