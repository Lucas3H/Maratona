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
typedef pair<ll, ll> pll;
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

class Graph{
	public:
    int n;
    set<int> adj[MAXN];
};

/*Vertices são 1, 2, ..., n*/
class Centroid{
	public:
    Graph G, CT; /*Centroid tree*/
	int pai[MAXN], size[MAXN], rank[MAXN];

	void dfs(int u,int p){
		size[u]=1;
		for(auto x: G.adj[u]){
			if(x != p){
				dfs(x,u);
				size[u]+=size[x];
			}
		}
	}
	
	int find_centroid(int u, int p, int sz){
		for(auto x: G.adj[u]){
			if(x!=p && size[x] > sz/2)
				return find_centroid(x, u, sz);
		}
		return u;
	}

	void decompose(int root, int p, int r){
		dfs(root,root);
		int c = find_centroid(root,root, size[root]);
		
		pai[c] = p;
		rank[c] = r;

		for(auto x: G.adj[c]){
			G.adj[x].erase(c);
			decompose(x, c, r + 1);
		}
		G.adj[c].clear();
	}
};

int n;
Centroid C;
void read(){
	cin >> n;
	fr(i, n-1){
		int a, b;
		cin >> a >> b;
		C.G.adj[a].insert(b);
		C.G.adj[b].insert(a);
	}

	C.decompose(1, 0, 0);

	for(int i = 1; i <= n; i++){
		cout << char('A' + C.rank[i]) << " ";
	}
	cout << endl;
}



int main(){
	ios::sync_with_stdio(false);
	read();
}
