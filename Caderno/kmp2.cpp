#include<bits/stdc++.h>

using namespace std;

#define MAXALFA 50

int dfa[MAXALFA][MAXALFA];

void buildDFA(string s){
	int x = 0; /*Maior prefixo que é sufixo*/

	dfa[s[0] - 'a'][0] = 1;

	for(int i = 1; i < s.size(); i++){
		dfa[i] = dfa[x];
		dfa[i][s[i] - 'a'] = i+1;
		x = dfa[x][s[i] - 'a'];
	}	
}

/*
	Retorna o início da primeira vez que encontra o padrão e -1 caso contrário.
*/
int find(string pat, string word){
	buildDFA(pat);

	for(int i = 0, j = 0; i < pat.size() && j < word.size(); j++){
		i = dfa[i][word[j] - 'a'];
		if(i == pat.size()) return j - pat.size();
	}

	return -1;
}

int main(){

}