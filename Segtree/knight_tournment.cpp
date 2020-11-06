// 
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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 300010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n;
int lz[4*MAXN], nd[4*MAXN];
pair<int, pii> q[MAXN];

void push(int i, int l, int r){
	if(lz[i] > 0){
		nd[i] = lz[i]*(r - l + 1);

		if(l < r){
			lz[2*i] = lz[i];
			lz[2*i+1] = lz[i];
		}

		lz[i] = 0;
	}
}

void update(int i, int l, int r, int ql, int qr, int val){
	push(i, l, r);

	if(ql <= l && r <= qr){
		lz[i] = val;

		push(i, l, r);
	}
	else if(ql > r || l > qr) return;
	else{
		int mid = (l+r)/2;

		update(2*i, l, mid, ql, qr, val);
		update(2*i+1, mid+1, r, ql, qr, val);

		nd[i] = nd[2*i+1] + nd[2*i];
	}
}

int query(int i, int l, int r, int ql, int qr){
	push(i, l, r);

	if(ql <= l && r <= qr) return nd[i];
	else if(ql > r || l > qr) return 0;
	else{
		int mid = (l+r)/2;

		return query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, r, ql, qr);
	}
}

int main(){
	ios::sync_with_stdio(false);

	int m;
	cin >> n >> m;

	fr(i, m){
		cin >> q[i].f >> q[i].s.f >> q[i].s.s;
	}

	frm(i, m){
		update(1, 1, n, q[i].f, q[i].s.s - 1, q[i].s.s);
		update(1, 1, n, q[i].s.s + 1, q[i].s.f, q[i].s.s);
	}

	frr(i, n) cout << query(1, 1, n, i, i) << " ";
	cout << endl;
}
