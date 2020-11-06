// https://codeforces.com/contest/220/problem/B
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

int n, len, m;
vector<int> a(MAXN);
query q[MAXN];

bool cmp(query a, query b){
	if((a.l)/len == (b.l)/len) return a.r < b.r;
	else return (a.l)/len < (b.l)/len;
}

void build(){
	scanf("%d %d", &n, &m);
	fr(i, n) scanf("%d", &a[i]);
	len = (int)sqrt(n + .0) + 1;

	fr(i, m){
		int l, r;
		scanf("%d %d", &l, &r);
		q[i].l = l -1;
		q[i].r = r-1;
		q[i].idx = i;
	}

	sort(q, q + m, cmp);
}

void queries(){
	int curL = 0, curR = 0, curAns = 0;
	int app[MAXN];
	int ans[MAXN];
	fr(i, n+1) app[i] = 0;

	fr(i, m){
		int L = q[i].l, R = q[i].r;

		while(curR <= R){
			if(a[curR] <= n){ 
				app[a[curR]]++;
				if(app[a[curR]] == a[curR]) curAns++;
				if(app[a[curR]] == a[curR]+1) curAns--;
			}
			curR++;
		}
		while(curL > L){
			if(a[curL - 1] <= n){ 
				app[a[curL - 1]]++;
				if(app[a[curL - 1]] == a[curL - 1]) curAns++;
				if(app[a[curL - 1]] == a[curL - 1]+1) curAns--;
			}
			curL--;
		}

		while(curR > R + 1){
			if(a[curR - 1] <= n){

				app[a[curR - 1]]--;
				if(app[a[curR - 1]] == a[curR - 1]) curAns++;
				if(app[a[curR - 1]] == a[curR - 1]-1) curAns--;
			}
			curR--;
		}
		while(curL < L){
			if(a[curL] <= n){
				app[a[curL]]--;
				if(app[a[curL]] == a[curL]) curAns++;
				if(app[a[curL]] == a[curL]-1) curAns--;
			}
			curL++;
		}
/*
		cout << curR << " " << curL << endl;
		cout << R << " " << L << endl;
		

		frr(i, n) cout << app[i] << " ";
		cout << endl;
*/
		ans[q[i].idx] = curAns;
	}

	fr(i, m) printf("%d\n", ans[i]);
}

int main(){
	build();
	queries();
}
