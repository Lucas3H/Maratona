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
#define INF 1e9

ll conta[MAXN];
ll max_left[4*MAXN], max_right[4*MAXN], sum_total[4*MAXN];
ll num_max_left[4*MAXN], num_max_right[4*MAXN], maximo[4*MAXN], num_maximo[4*MAXN];
int n;

struct trio{
	pair<ll,ll> l;
	pair<ll, ll> r;
	pair<ll, ll> t;
	pair<ll, ll> resp;
	bool valido;
};

trio v[4*MAXN];

pair<ll, ll> soma(pair<ll, ll> a, pair<ll, ll> b){
	int x = a.first + b.first, y = a.second+b.second;
	return mp(x, y);
}

trio junta(trio *left, trio *right){
	if(left->valido == 0) return *right;
	else if(right->valido == 0) return *left;

	trio c;

	c.t = soma((*left).t, (*right).t);
	c.l = max( (*left).l, soma((*left).t, (*right).l ) );
	c.r = max( (*right).r, soma((*left).r, (*right).t ) );

	c.resp = max(c.t, max(c.l, max(c.r, soma( (*left).r, (*right).l) ) ) );

	c.resp = max(c.resp, left->resp);
	c.resp = max(c.resp, right->resp);
	
	c.valido = 1;

	return c;
}

void build(int i, int l, int r){
	if(l == r){
		v[i].l = mp(conta[l], 1);
		v[i].r = mp(conta[l], 1);
		v[i].t = mp(conta[l], 1);
		v[i].resp = mp(conta[l], 1);
		v[i].valido = 1;
	}
	else{
		int mid = (l+r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		v[i] = junta(&v[2*i], &v[2*i+1]);
	}
}

trio res;
void query(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		res = junta(&res, &v[i]);
	}
	else if(ql > r || l > qr) return;
	else{
		int mid = (l+r)/2;

		trio left, right;

		query(2*i, l, mid, ql, qr);
		query(2*i+1, mid+1, r, ql, qr);
	}
}

int main(){
	int instancias;
	scanf("%d", &instancias);

	while(instancias--){
		scanf("%d", &n);
		
		frr(i, n) scanf("%lld", &conta[i]);
		build(1, 1, n);

	//	frr(i, 30) cout << max_left[i] << " " << max_right[i] << " " << sum_total[i] << endl;
		int k;
		scanf("%d", &k);

		fr(i, k){
			int a, b;
			scanf("%d %d", &a, &b);

			res.l = mp(-INF, -MAXN);
			res.r = mp(-INF, -MAXN);
			res.resp = mp(-INF, -MAXN);
			res.t = mp(-INF, -MAXN);

			query(1, 1, n, a, b);
			//cout << re.r << " " << re.l << ' ' << re.t << endl;
			printf("%lld %lld\n", res.resp.first, res.resp.second);
		}
	}
}