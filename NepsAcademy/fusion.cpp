#include<bits/stdc++.h>

#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
#define fr(i, n) for(int i = 0; i < n; i++) 
#define frm(i, n) for(int i = n-1; i >= 0; i--) 
#define MAXN 100010

using namespace std;

//ver for (set<int>::iterator it=a.begin(); it!=a.end(); ++it)

int pai[MAXN], geracao[MAXN];

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void uni(int x, int y){
	int a = find(x), b = find(y);
	if(a == b) return;

	if(geracao[a] > geracao[b]){
		pai[b] = a;
	}
	else if(geracao[a] < geracao[b]){
		pai[a] = b;
	}
	else{
		pai[a] = b;
		geracao[b]++;
	}

}

int n, k;

int main(){
	cin >> n >> k;

	for(int i = 1; i <= n;i++){
		geracao[i] = 1;
		pai[i] = i;
	}

	int x, y;
	char tipo;

	for(int i = 0; i < k; i++) {
		cin >> tipo >> x >> y;

		if(tipo == 'F') uni(x, y);
		else{
			if(find(x) == find(y)) printf("S\n");
			else printf("N\n");
		}

	}

	return 0;
}