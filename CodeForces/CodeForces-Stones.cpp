#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int resp = 0;
	if(n > 1){
		for(int i = 1; i < n; i++){
			if(s[i] == s[i-1]) resp++;
		}	
	}
	
	cout << resp << endl;
	
	return 0;
}
