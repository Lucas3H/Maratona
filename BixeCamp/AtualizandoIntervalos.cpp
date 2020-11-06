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

int t[4*MAXN];

// Nó raiz é 1. Os filhos são 2*i e 2*i+1

// Estudar lazy propagatio

void update(int i, int l, int r, int ql, int qr, int x){
	if(ql <= l && r <= qr){
		t[i]+=x;
	}
	if(ql > r || qr < l) return;

	int m = (l+r)/2;

	return query(2*i, l, m, ql, qr) + return query(2*i+1, m+1, r, ql, qr);
}

int query(int i, int l, int r, int pos, int valor){
	if(l==r){
		return t[i];
	}
	else{
		int m = (l+r)/2;

		if(pos <= m) return t[i] + query(2*i, l, m, p);
		else return t[i] + query(2*i + 1, m+1, r, p);
	}
}

int main(){

}