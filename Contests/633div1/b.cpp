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

vector<int> adj[MAXN];
int n, pr[MAXN], h[MAXN];
int root;

int par = 0, impar = 0;

void read(){
	cin >> n;
	frr(i, n-1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	frr(i, n){
		if(adj[i].size() > 1) {
			root = i;
			break;
		}
	}
}

int dfs(int v){
	int ret = 0, ap = 0;
	pr[v] = 1;
	for(int x: adj[v]){
		if(!pr[x]){
			
			h[x] = h[v] + 1;	
			ret += dfs(x);
			ret++;

			if(adj[x].size() == 1) {
				ap = 1;
				ret--;

//				cout << h[x] << endl;

				if(h[x]%2 == 0) par++;
				else impar++;
			}
		}
	}

	if(ap) {
		//cout << v << " A "<< ret + 1 << endl;
		return ret + 1;
	}
	else{
		//cout << v << " A "<< ret << endl;
		return ret + 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();

	//cout << root << endl;
	int d = dfs(root);
	if(par == 0 || impar == 0) cout << 1 << " ";
	else cout << 3 << " ";

	cout << d << endl;
}
