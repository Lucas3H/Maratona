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
int n, c;
		
int v[MAXN];

void update(int i, int l, int r, int ql, int qr, int value){
	if(ql <= l && r <= qr){
		v[i] += value*(r-l+1);
	}

	else if(ql > r || qr < l) return;
	else{
		int mid = (l+r)/2;

		update(2*i, l, mid, ql, qr, value);
		update(2*i+1, mid+1, r, ql, qr, value);

		v[i] = v[2*i] + v[2*i+1];
	}
}

int query(int i, int l, int r, int ql, int qr){
	
	if(ql <= l && r <= qr) return v[i];
	
	else if(ql > r || qr < l) return 0;
	
	else{
		int mid = (l+r)/2;

		return query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, ql, qr);
	}
}

int main(){
	int tests;
	cin >> tests;

	while(tests--){
		cin >> n >> c;

		mem(v, 0);

		while(c--){
			int x;
			cin >> x;

			if(x == 0){
				int y, z, w;
				cin >> y >> z >> w;

				update(1, 1, n, y, z, w);
			}
			else{
				int y, z;
				cin >> y >> z;
				cout << query(1, 1, n, y, z) << endl;
			}
		}
	}

	return 0;
}