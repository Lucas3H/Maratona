#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, d;
	cin >> n >> d;

	vector<int> s, a, b;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.push_back(x);
	}

	int soma = 0;
	a.push_back(soma);
	for(int i = 0; i < n; i++){
		soma += s[i];
		a.push_back(soma);
	}
	for(int i = 0; i < n; i++){
		b.push_back(soma - a[i+1] + s[i]);
	}

	int resp = 0;

	for(int i = 0; i < n; i++){
		int ini = i + 1, fim = n, meio = -1, foi = 0;

		while(ini < fim){
			meio = (ini+fim)/2;
			
			if(a[meio] == a[i] + d){
//				cout << 1 << " " << meio << " " << i << endl;
				foi = 1;
				resp++;
				break;
			}
			else if(a[meio] < a[i] + d){
				ini = meio + 1;
			}
			else{
				fim = meio;
			} 
		}

		if(!foi && a[ini] == a[i] + d){
//			cout << 2 << " " << ini << " " << i << endl;
			
			resp++;
		}
	}

//	for(int i = 0; i < n; i++) cout << b[i] << " ";

//	cout<< endl;

	for(int i = 0; i < n-1; i++){
		int ini = i+1, fim = n-1, meio = -1, foi = 0;
		while(ini < fim){
			meio = (ini+fim)/2;

			if(b[meio] == d - a[i+1]){
//				cout << 3 << " " << meio << " " << i+1 << endl;
				resp++;
				foi = 1;
				break;
			}
			else if(b[meio] < d - a[i+1]){
				fim = meio;
			}
			else{
				ini = meio + 1;
			}
		}

		if(!foi && b[ini] == d - a[i+1]){
//			cout << 4 << " " << ini << " " << i+1 << endl;
			resp++;
		}
	}

	cout << resp << endl;
}