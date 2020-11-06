#include<bits/stdc++.h>
using namespace std;

int m, l;
int d;
char nome[10][22];
int lou[10], p[10]; 

int dp[10][1205][1005];
int cnt[10];

int go(int b, int L, int P){
	if(L == 0 && P == 0) return 1;
	else if(L < 0 || P < 0) return 0;

	if(b < 0) return 0;

	if(dp[b][L][P] != -1) return dp[b][L][P];

	return dp[b][L][P] = max(go(b, L - lou[b], P - p[b]), go(b-1, L, P));
} 

void re(int b, int L, int P){
	if(L == 0 && P == 0) return ;
	else if(L < 0 || P < 0) return ;

	if(b < 0) return ;

	if(dp[b][L][P] == go(b, L - lou[b], P - p[b])){
		cnt[b]++;
		re(b, L - lou[b], P - p[b]);
	}
	else re(b-1, L, P);
} 

int main(){
	memset(dp, -1, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));

	int m1, m2, l1, l2; 
	scanf("%d.%d %d.%d %d", &m1, &m2, &l1, &l2, &d);

	m = 100*m1+m2;
	l = l1*60 + 6*l2;

	for(int i = 0; i < d; i++){
		int L, tamanho;
		int p1, p2;

		scanf(" %s %d %*d/%d %d.%d", nome[i], &L, &tamanho, &p1, &p2);

		p[i] = 100*p1 + p2;
		lou[i] = L*60/tamanho;
	}

	if(go(d-1, l, m)){
		re(d-1, l ,m);

		for(int i = 0; i < d; i++){
			if(cnt[i] > 0) printf("%s %d\n", nome[i], cnt[i]);
		}
	}
	else printf("IMPOSSIBLE\n");
}