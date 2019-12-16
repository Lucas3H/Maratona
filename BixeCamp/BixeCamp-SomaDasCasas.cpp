#include <iostream>
using namespace std;

int main(){
	int casas, soma, c[100010];
	cin >> casas;
	
	for(int i=0; i<casas; i++) cin >> c[i];
	
	cin >> soma;
	
	int ini = 0, fim = casas-1;
	
	while(c[ini] + c[fim] != soma){
		if(c[ini]+c[fim]>soma) fim--;
		else if(c[ini]+c[fim]<soma) ini++;
	}
	
	cout << c[ini] << " " << c[fim] << endl;
	return 0; 
}
