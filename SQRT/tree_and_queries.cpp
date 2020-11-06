// https://codeforces.com/problemset/problem/375/D
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
	int l, r, k, idx;
};

int n, m, len;
int cl[MAXN], pr[MAXN], tin[MAXN], tout[MAXN], v[MAXN];
vector<int> adj[MAXN];
int t = 0;

query q[MAXN];

void dfs(int u){
	pr[u] = 1;

	v[t] = cl[u];
	tin[u] = t++;

	for(auto x: adj[u]){
		if(!pr[x]) dfs(x);
	}

	tout[u] = t - 1;
}

bool cmp(query a, query b){
	if(floor(a.l/len) == floor(b.l/len)) return a.r < b.r;
	else return (a.l)/len < (b.l)/len;
}

void read(){
	cin >> n >> m;
	len = (int)sqrt(n+.0) + 1;
	frr(i, n) cin >> cl[i];

	fr(i, n-1){
		int a, b;
		cin >> a >> b;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1);

	fr(i, m){
		int aux;
		cin >> aux >> q[i].k;
		q[i].l = tin[aux];
		q[i].r = tout[aux];
		q[i].idx = i;
	}

	sort(q, q + m, cmp);
}

int b[400], a[MAXN]; /*Quantidade de cores com i vértices*/
int n_cor[MAXN]; /*Quantidade de vértices da cor i*/

void update(int cor, int val){
	b[(n_cor[cor]/len)]--;
	a[(n_cor[cor])]--;
	n_cor[cor]+=val;
	b[(n_cor[cor]/len)]++;
	a[(n_cor[cor])]++;
}

int query(int pos){
	int sum = 0;
	for(int i = pos; i <= n;){
		if(i%len == 0 && i + len-1 <= n){
			//cout << sum << " " << i << " " << i/len << endl;
			sum+=b[i/len];
			i+=len;
		}
		else{
			sum+=a[i];
			i++;
		}
		//cout << i << " OLA " << sum << endl;
	}
	
	//cout << pos << " " << sum << endl;

	return sum;
}

void solve(){
	int ans[MAXN];
	int curL = 0, curR = 0;
	
	fr(i, m){
		int L = q[i].l, R = q[i].r, k = q[i].k;

		while(curR <= R){
			update(v[curR], 1);
			curR++;
		}

		while(curL > L){
			update(v[curL-1], 1);
			curL--;
		}

		while(curR > R + 1){
			update(v[curR-1], -1);
			curR--;
		}

		while(curL < L){
			/*
			cout << "Antes " << curL << " " << curR<< endl;
			fr(i, n+1) cout << a[i] << " ";
			cout << endl;
			fr(i, n+1) cout << n_cor[i] << " ";
			cout << endl;
			*/
			update(v[curL], -1);
			curL++;
		/*
			cout << "Depois " << curL << " " << curR<< endl;
			fr(i, n+1) cout << a[i] << " ";
			cout << endl;
			fr(i, n+1) cout << n_cor[i] << " ";
			cout << endl;
*/		}


		ans[q[i].idx] = query(k);
	}

	fr(i, m) cout << ans[i] << endl;
}

int main(){
	ios::sync_with_stdio(false);

	read();
	solve();

}
