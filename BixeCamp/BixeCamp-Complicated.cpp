#include <iostream>
using namespace std;

int p[10010];

bool func(int ini, int fim, int pos){
	if(pos < ini || pos > fim) return 1;
	
	int menores = 0;
	for(int i = ini; i <= fim; i++){
		if(p[i] < p[pos]) menores++;
	}	
	
	if(menores == pos - ini) return 1;
	else return 0;
}

int main(){
	int n, sorts;
	cin >> n >> sorts;
	
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	for(int i = 0; i < sorts; i++){
		
		int ini, fim, x;
		cin >> ini >> fim >> x;
		
		if(func(ini, fim, x)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
