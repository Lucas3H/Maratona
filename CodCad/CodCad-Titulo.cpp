#include <iostream>
#include <cctype>
using namespace std;

string title(string s){
	
	if(isalpha(s[0]) and islower(s[0])) 
		s[0] = s[0]-32;
	for (int i = 1; s[i]; ++i){
		if(isalpha(s[i])){
			if(s[i-1] == ' ' and islower(s[i]))
				s[i] = s[i]-32;
			else if(s[i-1] != ' ' and isupper(s[i]))
				s[i] = s[i]+32;
		}
	}

	return s;
}

int main(){
	string s;
	getline(cin,s);

	cout << title(s) << endl;
}
