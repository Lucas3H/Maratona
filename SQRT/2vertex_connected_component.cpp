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

int n, edges;
vector<int> adj[MAXN];
int tin[MAXN], pr[MAXN];
int t = 0;

int low_link[MAXN], is_art[MAXN];
pii edge[2*MAXN];

vector<vector<int>> comp;
stack<int> aux;

void makeComp(int id){
	vector<int> newComp;

	while(!aux.empty() && aux.top() != id){
		newComp.pb(aux.top());
		aux.pop();
	}

	comp.pb(newComp);
}

void dfs(int v, int pai){
	pr[v] = 1;
	tin[v] = t++;
	low_link[v] = tin[v];

	for(auto x: adj[v]){
		int u = edge[x].s;

		if(u == pai) continue;
		if(!pr[u]){
			aux.push(x);
			dfs(u, v);

			low_link[v] = min(low_link[v], low_link[u]);
		
			if(low_link[u] >= tin[v]) {
				is_art[v] = 1;
				makeComp(x);
			}
		}
		else{
			low_link[v] = min(low_link[v], tin[u]);
		}
	}
}

void find_2vcc(){
	cin >> n >> edges;
	
	frr(i, n) {
		is_art[i] = 0;
		low_link[i] = 0;
		adj[i].clear();
		tin[i] = 0;
		pr[i] = 0;

		t = 0;
	}


	fr(i, edges){
		int v1, v2;
		cin >> v1 >> v2;

		edge[2*i] = mp(v1, v2);
		edge[2*i+1] = mp(v2, v1);

		adj[v1].pb(2*i);
		adj[v2].pb(2*i+1);
	}

	for(int i = 1; i <= n; i++){
		if(!pr[i]){

			dfs(i, i);

			makeComp(-1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	find_2vcc();
}
