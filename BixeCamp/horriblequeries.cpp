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
ll n, c;
		
ll v[4*MAXN], lz[4*MAXN];

void push(ll i, ll l, ll r){
	v[i] += lz[i]*(r - l + 1);

	if(l < r){
		lz[2*i] += lz[i];
		lz[2*i+1] += lz[i];
	}

	lz[i] = 0;
}

void update(ll i, ll l, ll r, ll ql, ll qr, ll value){
	push(i, l, r);
	
	if(ql <= l && r <= qr) {
		lz[i] += value;
		push(i, l, r);
	}
	else if(ql > r || qr < l) return;
	else{
		int mid = (l+r)/2;

		update(2*i, l, mid, ql, qr, value);
		update(2*i+1, mid+1, r, ql, qr, value);

		v[i] = v[2*i] + v[2*i+1];
	}
}

ll query(ll i, ll l, ll r, ll ql, ll qr){
	push(i, l, r);

	if(ql <= l && r <= qr) return v[i];
	
	else if(ql > r || qr < l) return 0;
	
	else{
		ll mid = (l+r)/2;

		return query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, r, ql, qr);
	}
}

int main(){
	int tests;
	cin >> tests;

	while(tests--){
		cin >> n >> c;

		mem(v, 0);
		mem(lz, 0)

		while(c--){
			int x;
			cin >> x;

			if(x == 0){
				ll y, z, w;
				cin >> y >> z >> w;

				update(1, 1, n, y, z, w);
			}
			else{

				ll y, z;
				cin >> y >> z;
				cout << query(1, 1, n, y, z) << endl;
			}
		}
	}

	return 0;
}