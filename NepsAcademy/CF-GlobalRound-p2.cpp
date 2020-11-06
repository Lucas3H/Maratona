#include <bits/stdc++.h>

using namespace std;

int n;
long long h;
long long v[1010];

bool ordenacao(int a, int b){
	return a > b;
}

int works(int k){
	int resp = 1, H = h;

	long long x[1010];
	for(int i = 0; i <= k; i++) x[i] = v[i];

	sort(x, x + k + 1, ordenacao);

	for(int i = 0; i < (k+1)/2; i++){
		if(H < 0) return 0;
		else H -= max(x[2*i], x[2*i + 1]);
	}

	if(H >= 0) return 1;
	else return 0;
}

int main(){

	cin >> n >> h;

	for(int i = 0; i < n; i++) cin >> v[i+1];

	v[0] = 0;

	int ini = 1, fim = n + 1, j = 0, meio;
	
		while(ini < fim && j < 20){
		meio = (ini+fim)/2;

		if(works(meio) == 1) ini = meio;
		else fim =  meio;

		j++;
	}

	cout << ini << endl;

	return 0;
}