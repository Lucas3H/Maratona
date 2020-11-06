#include<bits/stdc++.h>

#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
#define fr(i, n) for(int i = 0; i < n; i++) 
#define frm(i, n) for(int i = n-1; i >= 0; i--) 
#define MAXN 100010

using namespace std;

int pai[100010], peso[100010], pontos[100010];

int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(int x, int y){
	int a = find(x), b = find(y);

	if(a == b) return;

	if(peso[a] > peso[b]){
		pai[b] = a;
		pontos[a] += pontos[b];
	} 
	else if(peso[b] > peso[a]){
		pai[a] = b;
		pontos[b] += pontos[a];
	}
	else{
		pai[b] = a;
		peso[a]++;
		pontos[a] += pontos[b];
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n ,&m);

	while(n != 0 || m != 0){

		for(int i = 1; i <= n; i++) scanf("%d ", &pontos[i]);

		for(int i = 1; i <= n; i++){
			pai[i] = i;
			peso[i] = 1;
		}

		int resp = 0;
		int op, g1, g2;
		
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &op, &g1, &g2);

			if(op == 1) join(g1, g2);

			else{
				int a, b;
				int x = find(1);

				if(find(g1) == x){
					a = x;
					b = find(g2);

					if(pontos[a] > pontos[b]) resp++;
				}

				else if(find(g2) == find(1)){
					a = x;
					b = find(g1);

					if(pontos[a] > pontos[b]) resp++;
				}
			}
		}

		printf("%d\n", resp);

		scanf("%d %d", &n ,&m);

	}

	return 0;
}