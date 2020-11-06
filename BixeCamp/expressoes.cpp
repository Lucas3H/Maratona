#include<bits/stdc++.h>

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 

//typedef pii pair<int,int>;

#define mk make_pair
#define pq priority_queue

#define MAXN 100010

using namespace std;

int main(){
	int t;

	cin >> t;

	while(t--){
		string s;
		cin >> s;
		stack<char> aberto;

		int x = 1;

		for(int i = 0; i < s.size(); i++){
			if(s[i] == '{') aberto.push('{');
			else if(s[i] == '[') aberto.push('[');
			else if(s[i] == '(') aberto.push('(');

			else if(s[i] == '}' && aberto.empty()) x = 0;
			else if(s[i] == ')' && aberto.empty()) x = 0;
			else if(s[i] == ']' && aberto.empty()) x = 0;


			else{
				
				if(s[i] == '}' && aberto.top() == '{') aberto.pop();
				else if(s[i] == ')' && aberto.top() == '(') aberto.pop();
				else if(s[i] == ']' && aberto.top() == '[') aberto.pop();

				else{
					x = 0;
				}
			}
		}

		if(!aberto.empty()) x = 0;

		if(x) cout << "S" << endl;
		else cout << "N" << endl;
	}	
}
