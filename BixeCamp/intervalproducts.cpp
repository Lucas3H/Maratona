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

int n, k;

int nd[4*MAXN], v[MAXN];

void build(int i, int l, int r){
	if(l == r) nd[i] = v[l];
	else{
		int mid = (l+r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		if(nd[2*i]*nd[2*i+1] == 0) nd[i] = 0;
		else if(nd[2*i]*nd[2*i+1] > 0) nd[i] = 1;
		else nd[i] = -1;
	}
}

void update(int i, int l, int r, int pos, int value){
	if(l == r) nd[i] = value;
	else{
		int mid = (l+r)/2;

		if(pos <= mid) update(2*i, l, mid, pos, value);
		else update(2*i+1, mid+1, r, pos, value);

		if(nd[2*i]*nd[2*i+1] == 0) nd[i] = 0;
		else if(nd[2*i]*nd[2*i+1] > 0) nd[i] = 1;
		else nd[i] = -1;
	}
}

int query(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return nd[i];
	if(qr < l || r < ql) return 1;

	int mid = (l+r)/2;
	
	int left = query(2*i, l, mid, ql, qr), right = query(2*i+1, mid+1, r, ql, qr);

	if(left*right == 0) return 0;
	else if(left*right > 0) return 1;
	else return -1;
}

int main(){
	while(cin >> n >> k){
		frr(i, n) cin >> v[i];

		build(1, 1, n);

		while(k--){
			int a, b;
			char c;
			cin >> c >> a >> b;

			if(c == 'P'){
				int x = query(1, 1, n, a, b);

				if(x == 0)cout << 0;
				else if(x < 0) cout << '-';
				else cout << '+';
			}
			else update(1, 1, n, a, b);
		}

		cout << endl;
	}
}