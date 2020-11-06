// 
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

int prof[MAXN];
int pr[MAXN];
vector<int> adj[MAXN];
int n;

void dfs(int v){
	pr[v] = 1;

	for(auto x: adj[v]){
		if(pr[x] == 0){
			prof[x] = prof[v] + 1;
			dfs(x);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	vector<int> pai;

	frr(i, n){
		int x;
		cin >> x;

		if(x != -1) adj[x].pb(i);
		else pai.pb(i);
	}

	fr(i, pai.size()){
		prof[pai[i]] = 1;
		dfs(pai[i]);
	}

	int ans = 0;
	frr(i, n){
		ans = max(ans, prof[i]);
	}

	cout << ans << endl;
}
