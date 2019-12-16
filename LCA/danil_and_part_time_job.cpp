// https://codeforces.com/problemset/problem/877/E
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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007

int nd[4*MAXN], lz[4*MAXN];
int tin[MAXN], tout[MAXN], tinm[MAXN];
vector<int> adj[MAXN];
int v[MAXN], t = 1, n, q;

void build(int i, int l, int r){
	if(l == r) nd[i] = v[tinm[l]];
	else{
		int m = (l+r)/2;

		build(2*i, l, m);
		build(2*i+1, m+1, r);

		nd[i] = nd[2*i] + nd[2*i+1];
	}
}

void push(int i, int l, int r){
	if(lz[i]){
		nd[i] = (r - l + 1) - nd[i];

		if(l < r){
			lz[2*i]^=1;
			lz[2*i+1]^=1;
		}
		lz[i] = 0;
	}
}

void update(int i, int l, int r, int ql, int qr){
	push(i, l, r);
	if(l > qr || ql > r) return;
	else if(ql <= l && r <= qr){
		lz[i]^=1;
		push(i, l, r);
	}
	else{
		int m = (l+r)/2;

		update(2*i, l, m, ql, qr);
		update(2*i+1, m+1, r, ql, qr);

		nd[i] = nd[2*i] + nd[2*i+1];
	}
}

int query(int i, int l, int r, int ql, int qr){
	push(i, l, r);

	if(l > qr || ql > r) return 0;
	else if(ql <= l && r <= qr) return nd[i];
	else{
		int m = (l+r)/2;

		return query(2*i,l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
	}
}

void dfs(int i){
	tinm[t] = i;
	tin[i] = t++;
	for(auto x: adj[i]) dfs(x);
	tout[i] = t - 1;
}

int main(){
	ios::sync_with_stdio(false);
	int v1, v2;
	cin >> n;

	fr(i, n-1){
		cin >> v1;
		adj[v1].pb(i+2);
	}

	dfs(1);

	frr(i, n) cin >> v[i];
	
	build(1, 1, n);

	cin >> q;

	string s;
	while(q--){
		cin >> s >> v1;
		if(s[0] == 'g'){
			cout << query(1, 1, n, tin[v1], tout[v1]) << endl;
		}
		else{
			update(1, 1, n, tin[v1], tout[v1]);
		}
	}
}
