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

#define MAXN 500010
#define MOD 1000000007

vector<int> adj[MAXN];
int pr[MAXN];

int visited = 0;

void dfs(int v){
	pr[v] = 1;
	visited++;

	for(auto x: adj[v]){
		if(!pr[x]) dfs(x);
	}
}

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	pii seg[MAXN];
	int line[2*MAXN];

	frr(i, n){
		cin >> seg[i].f >> seg[i].s;
	
		line[seg[i].f] = i;
		line[seg[i].s] = -i;
	}

	int edges = 0;

	/* Vai armazenar somente o lado direito do segmento*/
	set<pii> open;

	frr(i, 2*n){
		if(edges >= n) break;

		if(line[i] < 0) open.erase(mp(seg[-line[i]].s, -line[i]));
		else{
			int seg_davez = line[i];

			for(auto seg_it: open){
				if(seg_it.f > seg[seg_davez].s) break;

				adj[seg_davez].pb(seg_it.s);
				adj[seg_it.s].pb(seg_davez);
				edges++;

				if(edges >= n) break;
			}

			open.insert(mp(seg[seg_davez].s, seg_davez));
		}
	}	
	
	dfs(1);

	if(visited == n && edges == n-1) cout << "YES\n";
	else cout << "NO\n";

}
