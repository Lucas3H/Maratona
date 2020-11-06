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

int n, edges, a, b;
set<int> adj[MAXN];
int pr[MAXN], val[MAXN];

void read(){
	cin >> n >> edges >> a >> b;

	frr(i, n){
		adj[i].clear();
		pr[i] = 0;
		val[i] = 0;
	}
	fr(i, edges){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].insert(v2);
		adj[v2].insert(v1);
	}
}

void dfs(int v, int t){
	pr[v] = 1;
	val[v]+=t;

	for(auto x: adj[v]){
		if(t == 1 && x == b) continue;
		else if(t == 2 && x == a) continue;

		if(!pr[x]) dfs(x, t);
	}
}

int main(){
	int t;
	cin >> t;

	while(t--){
		read();
		dfs(a, 1);

		frr(i, n) pr[i] = 0;
		dfs(b, 2);

		ll a1 = -1, b1 = -1;

		frr(i, n){
			if(val[i] == 1) a1++;
			else if(val[i] == 2) b1++;
		}

		cout << a1*b1 << endl;
	}
}