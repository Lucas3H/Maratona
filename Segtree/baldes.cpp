// https://neps.academy/problem/371 
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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, m;

pii nd_max[4*MAXN], nd_min[4*MAXN];
int bola[MAXN];

void build(int i, int l, int r){
	if(l == r){
		nd_max[i] = mp(bola[l], l);
		nd_min[i] = mp(bola[l], l);
	}
	else{
		int mid = (l + r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		if(nd_min[2*i].f > nd_min[2*i + 1].f) nd_min[i] = nd_min[2*i+1];
		else nd_min[i] = nd_min[2*i];

		if(nd_max[2*i].f < nd_max[2*i + 1].f) nd_max[i] = nd_max[2*i + 1];
		else nd_max[i] = nd_max[2*i];
	}
}

void update(int i, int l, int r, int balde, int bola){
	if(l == r){
		if(nd_min[i].f > bola) nd_min[i].f = bola;

		if(nd_max[i].f < bola) nd_max[i].f = bola;
	}
	else{
		int mid = (l + r)/2;

		if( mid >= balde) update(2*i, l, mid, balde, bola);
		else update(2*i+1, mid + 1, r, balde, bola);

		if(nd_min[2*i].f > nd_min[2*i + 1].f) nd_min[i] = nd_min[2*i+1];
		else nd_min[i] = nd_min[2*i];

		if(nd_max[2*i].f < nd_max[2*i + 1].f) nd_max[i] = nd_max[2*i + 1];
		else nd_max[i] = nd_max[2*i];
	}
}

pii query_min(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return nd_min[i];
	else if(l > qr || ql > r) return mp(MOD, 0);
	else{
		int mid = (l + r)/2;

		pii left = query_min(2*i, l, mid, ql, qr);
		pii right = query_min(2*i+1, mid+1, r, ql, qr);

		if(left.f <= right.f) return left;
		else return right;
	}
}


pii query_max(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return nd_max[i];
	else if(l > qr || ql > r) return mp(0, 0);
	else{
		int mid = (l + r)/2;

		pii left = query_max(2*i, l, mid, ql, qr);
		pii right = query_max(2*i+1, mid+1, r, ql, qr);

		if(left.f > right.f) return left;
		else return right;
	}
}

void solve(int l, int r){
	pii minimo = query_min(1, 1, n, l, r);
	pii maximo = query_max(1, 1, n, l, r);

	if(minimo.s != maximo.s){
		printf("%d\n", maximo.f - minimo.f);
	}
	else{
		pii davez;
		int ans = 0;

		davez = query_min(1, 1, n, l, minimo.s - 1);
		ans = max(ans, maximo.f - davez.f);

		davez = query_min(1, 1, n, minimo.s + 1, r);
		ans = max(ans, maximo.f - davez.f);

		davez = query_max(1, 1, n, l, maximo.s - 1);
		ans = max(ans, davez.f - minimo.f);

		davez = query_max(1, 1, n, maximo.s + 1, r);
		ans = max(ans, davez.f - minimo.f);

		printf("%d\n", ans);
	}
}

int main(){
	scanf("%d %d", &n, &m);

	frr(i, n) scanf("%d", &bola[i]);

	build(1, 1, n);

	fr(i, m){
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);

		if(op == 1){
			update(1, 1, n, b, a);
		}
		else{
			solve(a, b);
		}
	}
}
