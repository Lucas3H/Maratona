#include <bits/stdc++.h>

using namespace std;

int main(){
	int salas;
	cin >> salas;
	int s[50010];
	
	for(int i=0; i < salas; i++) cin >> s[i];
	
	int resp = 0, maior = 0;
	
	for(int i=0; i < salas; i++){
		maior = max(maior+s[i], 0);
		
		resp = max(maior, resp);
	}
	
	cout << resp << endl;
	
	return 0;
}
