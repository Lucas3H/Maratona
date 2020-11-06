#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e5+5;
const ll mod = 1e9+7;

int a[ms];
int ant[ms];

bool valid(int n, int l, int r, int m) {
	ant[0] = 0;
	int maior = -1e9;
	
	/*
	ant[i] é o maior k <= i tal que é possível particionar os k primeiros caras
	maior é o último cara que é >= m
	hi é o maior índice tal que a subsequencia [hi...i] é válida 
	*/

	for(int i = 1; i <= n; i++) {
		if(a[i] >= m) maior = i;
		int hi = min(maior, i - l + 1);
		if(hi > 0 && ant[hi-1] >= i - r) {
			ant[i] = i;
		} else {
			ant[i] = ant[i-1];
		}
	}

	cout << m << endl;
	for(int i = 1; i <= n; i++){
		cout << ant[i] << " ";
	}
	cout << endl;

	return ant[n] == n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, l, r;
	cin >> n >> l >> r;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int lo = 0, hi = 20;
	while(hi > lo) {
		int m = (lo+hi)/2;
		if(valid(n, l, r, m)) lo = m+1;
		else hi = m;
	}
	cout << lo - 1 << '\n';
}