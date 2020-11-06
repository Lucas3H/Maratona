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
int v[MAXN];
int n, q;

struct vetor{
	int v[9];		
};

void build(int i, int l, int r){
	if(l == r) {
		m[i][0] = 0;
		m[i][1] = 1;
		for(int j = 2; j < 9; j++) m[i][j] = 0;
	}
	else{
		int mid = (l+r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		m[i][0] = 0;
		m[i][1] = r - l + 1;
		for(int j = 2; j < 9; j++) m[i][j] = 0;
	}
}

void push(int i, int l, int r){
	for(int j = l; j<= r; j++){
		m[i][j] += lz[i];
		m[i][j] = m[i][j]%9;
	}
	lz[i] = 0;
	lz[2*i] += lz[i];
	lz[2*i+1]+=lz[i];
}

vetor query(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		vetor tt;
		push(i, l, r);

		fr(j, 9) tt.v[i] = m[i][j];
		return tt;
	}
	if(ql > r || qr < l){
		vetor tt;

		fr(j, 9) tt.v[i] = 0;
		return tt;
	}

	vetor tt;
	push(i, l, r);

	int mid = (l + r)/2;
	vetor left = query(2*i, l, mid, ql, qr), right = query(2*i+1, mid+1, r, ql, qr);
	fr(j, 9) tt.v[j] = left.v[j] + right.v[j];

	return tt;
}

void update(int i, int l, int r, int ql, int qr, int value){
	if(ql <= l && r <= qr){
		lz[i] += value;
		push(i, l, r);
	}
	else if(ql > r || qr < l) return;
	else{
		int mid = (l+r)/2;

		push(i, l, r);

		update(2*i, l, mid, ql, qr, value);
		update(2*i+1, mid+1, r, ql, qr, value);2
	
		fr(j, 9){
			m[i][j] = m[2*i][j] + m[2*i+1][j];
			m[i][j] = m[i][j]%9;
		}
	}
}

int main(){
	cin >> n >> q;

	mem(lz, 0);

	fr(i, n) v[i] = 1;
	build(1, 0, n-1);

	fr(i, q){
		int a, b;
		cin >> a >> b;

		vetor vf = query(1, 0, n-1, a, b);

		int f = -1, mf = -1;

		fr(i, 9){
			if(vf.v[i] > mf){
				mf = vf.v[i];
				f = i;
			}
		}

		//2cout << f << endl;

		update(1, 0, n-1, a, b, f);
	}

	fr(i, n) cout << v[i] << endl;
}