#include <bits/stdc++.h>

using namespace std;

int main(){
	queue<int> fila;
	for(int i = 0; i < 16; i++) fila.push(i);

	for(int i = 0; i < 15; i++){
		int a, b;

		cin >> a >> b;
		if(a > b){
			fila.push(fila.front());
			fila.pop();
			fila.pop();
		}
		else if(a < b){
			fila.pop();
			fila.push(fila.front());
			fila.pop();	
		}
	}

	cout << char(fila.front() + 65) << endl;

	return 0;
}