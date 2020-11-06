// https://codeforces.com/problemsets/acmsguru/problem/99999/253
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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

ll n, m, k;
ponto pol[MAXN], pt[MAXN]; 

ll crossProd(ponto a, ponto b, ponto c){
	ll x1 = a.f - b.f, x2 = c.f - b.f;
	ll y1 = a.s - b.s, y2 = c.s - b.s;

	return x1*y2 - x2*y1; 
}

/*
	crossProd < 0 -> left
	crossProd > 0 -> right
*/

bool bb(int l, int r, ponto p){
	if(l == r - 1){
		if(crossProd(p, pol[l], pol[r]) <= 0) return 1;
		else return 0;
	}

	int mid = (l+r)/2;

	if(crossProd(pol[0], pol[mid], p) < 0) return bb(mid, r, p);
	else return bb(l, mid, p);
}

void read(){
	cin >> n >> m >> k;

	fr(i, n) cin >> pol[i].f >> pol[i].s;
	fr(i, m) cin >> pt[i].f >> pt[i].s;
}

bool is_in_polygon(ponto a){
	if(crossProd(pol[0], pol[1], a) <= 0 && crossProd(pol[n-1], pol[0], a) <= 0){
		return bb(1, n-1, a);
	}
	else return 0;
}

int main(){
	ios::sync_with_stdio(false);
	
	read();
	int ans = 0;
	fr(i, m){
		ans += is_in_polygon(p[i]);
	}

	if(ans >= k) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
