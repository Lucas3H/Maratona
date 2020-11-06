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

struct no{
	no * l, * r;
	int val;
};

	map<int, int> m;
int v[MAXN];
int v_inv[MAXN];
int n, q;

no * versao[MAXN];

void build(no * i, int l, int r){
	if(l == r){
		i->val = 0;
	}
	else{
		int mid = (l + r)/2;

		no * esq = new no;
		no * dir = new no;

		i->val = 0;
		i->l = esq;
		i->r = dir;

		build(esq, l, mid);
		build(dir, mid + 1, r);
	}
}

void update(no * i, no * ai, int l, int r, int ql, int qr, int val){
	if(ql <= l && r <= qr){
		push(i, l, r, val);
	}
	else if(l > qr || ql > r){
		return;
	}
	else{	
		push(i, l, r, val);
	
		int mid = (l + r)/2;

		if(pos <= mid){
			no * esq = new no;
			i->l = esq;
			i->r = ai->r;
			update(esq, ai->l, l, mid, ql, qr, val);
		}
		else{
			no * dir = new no;
			i->l = ai->l;
			i->r = dir;
			update(dir, ai->r , mid + 1, r, ql, qr, val);
		}

		i->val = i->l->val + i->r->val;
	}
}

int query(no * i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return i->val;
	else if(ql > r || l > qr) return i->val;
	else{
		int mid = (l + r)/2;

		return query(i->l, l, mid, ql, qr) + query(i->r, mid + 1, r, ql, qr);
	}
}


int main(){
	ios::sync_with_stdio(false);
}
