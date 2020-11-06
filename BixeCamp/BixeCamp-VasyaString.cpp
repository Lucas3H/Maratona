#include <bits/stdc++.h>

using namespace std;

int n, k;
int two_pointer(string s, char x){
	int fim = 0;
	int trocas = 0, max = 0, tam = 0;

	for(int i = 0; i < n; i++){

		while((trocas < k || s[fim] != x)&& fim <= n-1){
			if(s[fim] == x) trocas++;
			tam++;
			fim++;
		}

		if(tam > max) max = tam;

		if(s[i] == x) trocas--;

		tam--;
	}

	return max;
}

int main(){
	string s;

	cin >> n >> k;
	cin >> s;
	
	int r1 = two_pointer(s, 'a');
	int r2 = two_pointer(s, 'b');

	cout << max(r1, r2)<< endl;

	return 0;
}