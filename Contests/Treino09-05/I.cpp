#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010


int main() {
	/*
		Negativar todos os negativos do menor para o maior
		Se faltar negações a soma fica a maior possível
		Se sobrar negações, todos os números serão não negativos e então a soma será a maior possível
		Jogar fora pares de negações fazendo a negação da negação em qualquer número (mod 2)
		Se sobrou mod 2 == 0 imprimir a maior soma possível
		Se sobrou mod 2 == 1 negar o menor número
	*/ 
	int t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		int lista[n];
		fr(i, n) {
			cin >> lista[i];
		}
		sort(lista, lista+n);
		fr(i, k) {
			if (lista[i] < 0) {
				lista[i] = -lista[i];
			} else {
				int restante = k - i;
				restante %= 2;
				if (restante == 1) {
					sort(lista, lista+n);
					lista[0] = -lista[0];
				}
				break;
			}
		}
		int soma = 0;
		fr(i,n) {
			soma += lista[i];
		}
		cout << soma << endl;
	}
} 

/*

int main() {
	int testCases, n, k;
	cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		cin >> n >> k;
		int lista[10010];

		for (int j = 0; j < n; j++) {
			cin >> lista[j];
		}
		sort(lista, lista+n);
		long long soma = 0;
		
		for (int j = 0; j < k; j++) {
			*for (int a = 0; a < n; a++) {
				cout << lista[a] << " ";
			}
			cout << endl;*
			if (lista[j] < 0) {
				lista[j] *= -1;
			} else {
				int rest = (k - j) % 2;
				if (rest == 1) {
					sort(lista, lista+n);
					lista[0] *= -1;
				}

				break; 
			}
		}
		for (int j = 0; j < n; j++) {
			soma += lista[j];
		}
		cout << soma << endl;
	}
}*/
 