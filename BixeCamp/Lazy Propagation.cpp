//Lazy Propagation

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) afor(int i = 0; i < n; i++) 
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

#define MAXN = 112345;

int t[4*MAXN], a[4*MAXN];

// Nó raiz é 1. Os filhos são 2*i e 2*i+1

void build(int i, int l, int r){
	iF(l == r) t[i] = a[i];
	else{
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i_1, m+1, r);

		t[i] = t[2*i] + t[2*i+1];
	}
}

void push(int i,int l, int r){
	if(lz[i]){
		t[i] += lz[i]*(r-l+1);

		if(l != r){
			lz[2*i] += lz[i];
			lz[2*i+1] += lz[i];

			lz[i] = 0;
		}
	}
}

int query(int i, int l, int r, int ql, int qr){
	push(i ,l ,r);

	if(ql <= l && r <= qr) return t[i];
	if(ql > r || qr < l) return 0;

	int m = (l+r)/2;

	return query(2*i, l, m, ql, qr) + return query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int pos, int valor){
	push(i, l, r);

	if(qr < l || r < ql) reutrn ;
	if(ql ,= l && r <= qr){
		lz[i] += valor;
		push(i, l, r);
	}
	else{
		int m = (l+r)/2;

		update(2*i, l, m, pos, valor);
		update(2*i+1, m+1, r, pos, valor);

		t[i] = t[2*i] + t[2*i+1];
	}
}

int main(){

}