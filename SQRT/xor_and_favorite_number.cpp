// https://codeforces.com/contest/617/problem/E
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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

struct query{
	int l, r, idx;
};

int n, m, k, len;
int a[MAXN];
int ac[MAXN];
int acINV[MAXN];
query q[MAXN];
int app[1050010], appINV[1050010];
ll ans[MAXN];

void build(){
	cin >> n >> m >> k;
	len = (int)sqrt(n + .0) + 1;

	fr(i, n) cin >> a[i];

	int sum = 0;
	frr(i, n){
		sum^=a[i-1];
		ac[i] = sum;
	}

	sum = 0;
	for(int i = n; i >= 1; i--){
		sum^=a[i-1];
		acINV[i] = sum;
	}
}

bool comp(query a, query b){
	if((a.l)/len == (b.l)/len) return a.r < b.r;
	else return (a.l)/len < (b.l)/len;
}

void solve(){
	fr(i, m){
		int l, r;
		cin >> l >> r;
		q[i].l = --l;
		q[i].r = --r;
		q[i].idx = i;
	}

	sort(q, q + m, comp);
	
	int curL = 0, curR = 0;
	ll curAns = 0;

	fr(i, 1050010) app[i] = 0;
	fr(i, 1050010) appINV[i] = 0;

	fr(i, m){
		int L = q[i].l, R = q[i].r;

		while(curR <= R){
			app[ac[curR + 1]]++;
			appINV[acINV[curR + 1]]++;
			curAns+=(ll)appINV[k^acINV[curR + 2]];
			curR++;;
		}
		while(curL > L){
			app[ac[curL -1  + 1]]++;
			appINV[acINV[curL - 1 + 1]]++;
			curAns+=(ll)app[k^ac[curL - 1]];
			curL--;
		}
	/*	cout << curL << " " << curR << endl;
		cout << 2 << " " << curAns << endl;
	*/	while(curR > R + 1){
			curAns-=(ll)appINV[k^acINV[curR + 1]];
			app[ac[curR - 1 + 1]]--;
			appINV[acINV[curR - 1 + 1]]--;
			curR--;
		}
/*
		cout << curL << " " << curR << endl;
		cout << 3 << " " << curAns << endl;
*/		while(curL < L){
			curAns-=(ll)app[k^ac[curL]];
			app[ac[curL + 1]]--;
			appINV[acINV[curL + 1]]--;
			curL++;

			//cout << curAns<< endl;
		}
/*
		cout << curL << " " << curR << endl;
		cout << 4 << " " << curAns << endl;
*/

		ans[q[i].idx] = curAns;
	}

	fr(i, m) cout << ans[i] << endl;
}

int main(){
	ios::sync_with_stdio(false);

	build();
	solve();
}
