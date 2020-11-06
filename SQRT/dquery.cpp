// https://www.spoj.com/problems/DQUERY/
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
#define MAXA 1000010

struct query{
	int l, r, idx;
};

int n, len;
vector<int> a(30010);

void build(){
	scanf("%d", &n);
	fr(i, n) scanf("%d", &a[i]);
	len = (int)sqrt(n + .0) + 1;
}

bool cmp(query a, query b){
	if((a.l)/len == (b.l)/len) return a.r < b.r;
	else return (a.l)/len < (b.l)/len;
}

void queries(){
	int q;
	scanf("%d", &q);

	vector<query> v(q);
	fr(i, q){
		int l, r;
		scanf("%d %d", &l, &r);
		(v[i].l) = l - 1;
		(v[i].r) = r - 1;
		v[i].idx = i;
	}

	sort(v.begin(), v.end(), cmp);

	vector<int> ans(q);
	int curAns = 0;
	int curL = 0, curR = 0;
	int app[MAXA];
	fr(i, MAXA) app[i] = 0;

	fr(i, q){
		int L = v[i].l, R = v[i].r;

		while (curL > L) { 
			app[a[curL-1]]++;
            if(app[a[curL - 1]] == 1) curAns++; 
            curL--; 
        } 
        while (curR <= R) { 
			app[a[curR]]++;
            if(app[a[curR]] == 1) curAns++;
            curR++; 
        }

		while (curL < L) { 
			app[a[curL]]--;
            if(app[a[curL]] == 0) curAns--;
            curL++; 
        } 

		while (curR > R+1) { 
			app[a[curR - 1]]--;
            if(app[a[curR - 1]] == 0) curAns--;
            curR--; 
        }  

	/*	cout << L << " " << R << endl;
		cout << curL <<  " " << curR << endl;
*/
		ans[v[i].idx] = curAns;
	}

	fr(i, q) printf("%d\n", ans[i]);
}

int main(){
	build();
	queries();
}
