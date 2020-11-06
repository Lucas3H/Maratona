#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;

	cin >> n;
	cin >> s;

	if(s[0] == ')' || s[n-1] == '(') cout << ":(" << endl;

	else{
		int usado[300010];
		char c[300010];

		memset(usado, 0, sizeof(usado));
		queue<char> aberto;


		for(int i = 1; i < n-1; i++){
			if(s[i] == '(') {
				aberto.push('(');
				usado[i] = 1;
				c[i] = '(';
			}
			else if(s[i] == ')' && !aberto.empty()){
				c[i] = ')';
				usado[i] = 1;
				aberto.pop();
			}
			else if(s[i] == '?' && !aberto.empty()){
				aberto.pop();
				c[i] = ')';
				usado[i] = 1;
			}
		}

		int x = 1;
		if(!aberto.empty()){
			x = 0;
		} 

		queue<char> fechado;
		for(int i = n-2; i>=1; i--){
			if(s[i] == ')' && usado[i] == 0){
				fechado.push(')');
				usado[i] = 1;
				c[i] = ')';
			}
			else if(s[i] == '?' && (!fechado.empty() && usado[i] == 0)){
				fechado.pop();
				usado[i] = 1;
				c[i] = '('; 
			}
		}

		if(!fechado.empty()){
			x = 0;
		} 		

		if(n%2==1) x= 0;

		int abe = 0;
		for(int i = 1; i < n-1; i++){
			if(abe == 0 && usado[i] == 0){
				c[i] = '(';
				abe = 1;
			}
			else if(abe == 1 && usado[i] == 0){
				c[i] = ')';
				abe = 0;
			}
		}

		c[0] = '(';
		c[n-1] = ')';

		if(x){
			for(int i = 0; i < n; i++) cout << c[i];
			cout << endl;
		}
		else cout << ":(" << endl; 
	}
}