#include <iostream>
using namespace std;

int main(){
	string s;
	bool x = 1;
	char v[50];
	int ind = 0;
	
	cin >> s;
	
	for(int i=0; i < s.size(); i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			v[ind] = s[i];
			ind++;
		} 
	}
	
	for(int i=0; i < ind; i++){
		if(v[i] != v[ind - 1 - i]) x = 0;
	}
	
	if (x) cout << "S" << endl;
	else cout << "N" << endl;
	
	return 0;
}
