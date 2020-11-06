#include<bits/stdc++.h>

using namespace std;

#define MAXALFA 50

int dfa[MAXALFA][MAXALFA];
/*
void buildDFA(string s){
	int x = 0;

	if(s[0] == '?'){
		for(int j = 0; j < 26; j++)
			dfa[0][j] = 1;
	}
	else{
		dfa[0][s[0] - 'a'] = 1;
	}

	for(int i = 1; i < s.size(); i++){
		for(int j = 0; j < 26; j++)
			dfa[i][j] = dfa[x][j];
		
		if(s[i] == '?'){
			for(int j = 0; j < 26; j++)
				dfa[i][j] = i + 1;

			x = dfa[x][0];
		}
		else{
			dfa[i][s[i] - 'a'] = i+1;
			x = dfa[x][s[i] - '0'];
		} 
	}	
}

int find(string pat, string word){
	buildDFA(pat);

	for(int i = 0, j = 0; i < pat.size() && j < word.size(); j++){
		i = dfa[i][word[j] - 'a'];
		if(i == pat.size()) return j - pat.size();
	}

	return -1;
}
*/

void buildDFA(string s){
	dfa[s[0] - 'a'][0] = 1;
	for (int X = 0, j = 1; j < s.size(); j++) {
	   for (int c = 0; c < 26; c++)
	      dfa[c][j] = dfa[c][X];     // copia casos de conflito

	   dfa[s[j] - 'a'][j] = j+1;  // define casos de casamento
	   X = dfa[s[j] - 'a'][X];    // atualiza estado de reinício
	}
}

int find(string pat, string word){
	buildDFA(pat);

    for (int i = 0, j = 0; i < word.size() && j < pat.size(); i++){
        j = dfa[word[i] - 'a'][j];
      	if (j == pat.size()) return i - pat.size();
      	else        return word.size();
    }
}

int main(){
	ios::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	cout << find(a, b) << endl;
} 
