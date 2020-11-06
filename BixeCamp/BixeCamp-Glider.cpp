#include <bits/stdc++.h>

using namespace std;

long long height, n_flows, q_flows = 0;

long long endd[200010], beg[200010], f[200010];

long long binary_search(int b){

	long long ini = b, fim = n_flows + 1; 

	int i = 0, meio;

	while(ini <= fim && i < 40){
		meio = (ini + fim)/2;

		if(height + f[meio] - f[b-1] <= endd[meio] - beg[b]) fim = meio;
		else ini = meio + 1;

		i++;
	}

	return height + f[meio - 1] - f[b-1]; 
}

int main(){

	cin >> n_flows >> height;

	f[0] = 0;

	for(int i = 1; i <= n_flows; i++){
		cin >> beg[i] >> endd[i];

		q_flows += endd[i] - beg[i];

		f[i] = q_flows;
	}

	f[n_flows + 1] = 2000000010;

	long long max = 0;

	for(int i = 1; i <= n_flows; i++){
		long long x = binary_search(i);

		if(x > max) max = x;
	}

	cout << max << endl;

	return 0;
}








































