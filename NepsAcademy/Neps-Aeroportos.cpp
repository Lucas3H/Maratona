#include <bits/stdc++.h>

using namespace std;

int main(){
	int testes = 1;
	int aeroportos, voos;
	
	cin >> aeroportos >> voos;
	
	while(aeroportos != 0 || voos != 0){
		int a[110];
		
		for(int i = 0; i <= aeroportos+1; i++) a[i] = 0; 
				
		for(int i = 0; i < voos; i++){
			int x, y;
			cin >> x >> y;
			
			a[x]++;
			a[y]++;
		}
		
		int maior = -1;
		
		for(int i=1; i <= aeroportos; i++){
			if(maior < a[i]) maior = a[i];
		}
		
		cout << "Teste " << testes++ << endl;
		
		for(int i = 1; i <= aeroportos; i++){
			if(maior == a[i]) cout << i << " ";
		}
		
		cout << endl << endl;
		
		cin >> aeroportos >> voos;
	}
	
	return 0;
}
