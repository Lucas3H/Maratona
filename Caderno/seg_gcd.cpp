#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int n;

namespace bit{
	int bit[MAXN];

    void update_aux(int i, int val){
        while(i <= n){
            bit[i] += val;
            i += i & (-i);
        }
    }

    int query_aux(int i){
        int sum = 0;

        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }

        return sum;
    }
	int query(int pos){
		pos++;
		return query_aux(pos) - query_aux(pos-1);
	}

	void update(int l, int r, int x){
		l++, r++;
		update_aux(l, x);
		update_aux(r+1, -x);
	}
}

namespace seg_gcd {
	int nd[4*MAXN], v[MAXN];
	void build_rec(int i, int l, int r){
		if(l == r) nd[i] = v[l];
		else{
			int m = (l + r)/2;

			build_rec(2*i, l, m);
			build_rec(2*i + 1, m + 1, r);

			nd[i] = gcd(nd[2*i], nd[2*i+1]);
		}
	}

	void build(){
		fr(i, n) bit::update_aux(i + 1, v[i]);
		fr(i, n-1) v[i] = v[i+1] - v[i];

		build_rec(1, 0, n-2);
	}

	ll query_rec(int i, int l, int r, int ql, int qr){
		//cout << l << " " <<r  << " " << i << " " << nd[i] << endl;
		if(l > qr || ql > r) return 0;
		else if(ql <= l && r <= qr)return nd[i];
		else{
			int m = (l + r)/2;
			return gcd(query_rec(2*i, l, m, ql, qr), query_rec(2*i + 1, m + 1, r, ql, qr));
		}
	}

	ll query(int ql, int qr){ 
		if(ql == qr) return bit::query(ql);
		else{
			qr--;

			//cout << ql << ' ' << qr << " " << query_rec(1, 0, n-2, ql, qr) <<" " << v[1] << endl;
			return gcd(bit::query(ql), query_rec(1, 0, n-2, ql, qr));
		}
	}

	void update_rec(int i, int l, int r, int pos){
		if(l == r) nd[i] = v[l];
		else{
			int m = (l + r)/2;

			if(m >= pos) update_rec(2*i, l, m, pos);
			else update_rec(2*i + 1, m + 1, r, pos);
		}
		//cout << i << " " << l << " " << r << " " << nd[i] << endl;
	}

	void update(int ql, int qr, int x){
		bit::update(ql, qr, x);

		if(ql > 0) v[ql-1]+=x;
		v[qr] -= x;

		update_rec(1, 0, n-2, ql-1);
		update_rec(1, 0, n-2, qr);
	}

}

void read(){
	cin >> n;
	fr(i, n){
		cin >> seg_gcd::v[i];
	}

	seg_gcd::build();
}

int main(){
	ios::sync_with_stdio(false);
	read();
	
	int q;
	cin >> q;
	while(q--){
		int l, r, op, x;
		cin >> op;
		if(op == 1){
			cin >> l >> r;
			cout << abs(seg_gcd::query(l, r)) << endl;
		}
		else{
			cin >> l >> r >> x;
			seg_gcd::update(l, r, x);
		}
	}
}
