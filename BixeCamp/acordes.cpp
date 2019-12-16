#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

int m[4*MAXN][9], lz[4*MAXN];
int n, q;
int nota[MAXN];

void build(int i, int l, int r){
	if(l == r){
		m[i][0] = 0;
		m[i][1] = 1;
		for(int j = 2; j < 9; j++) m[i][j] = 0;
	}
	else{
		int mid = (l+r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		fr(j, 9) m[i][j] = m[2*i][j] + m[2*i+1][j];
	}
}

void push(int i, int l, int r){
	int aux[9];
	
	fr(j, 9) aux[j] = m[i][j];
	fr(j, 9) m[i][(j+lz[i])%9] = aux[j]; 
	
	if(l < r){
		lz[2*i] += lz[i];
		lz[2*i+1] += lz[i];
	}
	lz[i] = 0;
}

int res[9];
void query(int i, int l, int r, int ql, int qr){
	push(i, l, r);

	if(ql <= l && r <= qr){
		fr(j, 9) res[j] += m[i][j];
	}
	else if(ql > r || l > qr) return;
	else{
		int mid = (l+r)/2;

		query(2*i, l, mid, ql, qr);
		query(2*i+1, mid+1, r, ql, qr);
	}
}

void update(int i, int l, int r, int ql, int qr, int value){
	push(i, l, r);

	if(ql <= l && r <= qr) {
		lz[i] += value;
		push(i, l, r);
	}
	else if(ql > r || l > qr) return;
	else{
		int mid = (l+r)/2;

		update(2*i, l, mid, ql, qr, value);
		update(2*i+1, mid+1, r, ql, qr, value);

		fr(j, 9) m[i][j] = m[2*i][j] + m[2*i+1][j];
	}
}

int main(){
	//ios::sync_with_stdio(false);

	scanf("%d %d", &n, &q);

	fr(i, n) nota[i] = 1;

	build(1, 0, n-1);

	fr(i, q){
	 	int a, b;
	 	scanf("%d %d", &a, &b);

	 	mem(res, 0);
	 	query(1, 0, n-1, a, b);

	 	int maximo = -1, ind = -1;

	 	fr(i, 9){
	 		if(res[i] >= maximo){
	 			maximo = res[i];
	 			ind = i;
	 		}
	 	}

	 	update(1, 0, n-1, a, b, ind);
	}

	fr(i, n){
		mem(res, 0);
		query(1, 0 , n-1, i, i);
	
		int M = max_element(res, res+9) - res;

		printf("%d\n", M);
	}

	return 0;
}
