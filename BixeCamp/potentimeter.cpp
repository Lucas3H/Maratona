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

#define MAXN 200010

int nd[4*MAXN], res[MAXN];
int n;

void build(int i, int l, int r){
	if(l == r) nd[i] = res[l];
	else{
		int mid = (l+r)/2;
		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		nd[i] = nd[2*i] + nd[2*i+1];
	}
}

void update(int i, int l, int r, int pos, int value){
	if(l == r) nd[i] = value;
	else{
		int mid = (l+r)/2;

		if(mid >= pos)update(2*i, l, mid, pos, value);
		else update(2*i+1, mid+1, r, pos, value);

		nd[i] = nd[2*i] + nd[2*i+1];
	}
}

int query(int i, int l, int r, int ql, int qr){
		if(ql <= l && r <= qr) return nd[i];
		if(ql > r || qr < l) return 0;

		int mid = (l+r)/2;

		return query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, r, ql, qr);
}

int main(){

	int tests = 1;
	cin >> n;

	while(n != 0){

		frr(i, n) cin >> res[i];

		build(1, 1, n);

		string s;
		cin >> s;

		cout << "Case " << tests << ":" <<  endl;
		while(s != "END"){
			int a, b;
			cin >> a >> b;

			if(s == "S"){
				update(1, 1, n, a, b);
				res[a] = b;
			}
			else cout << query(1, 1, n, a, b) << endl;

			cin >> s;
		}

		tests++;
		cin >> n;
		if(n != 0) cout << endl;
	}
}