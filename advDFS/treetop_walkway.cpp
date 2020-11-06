// https://codeforces.com/gym/101670/attachments/download/6514/20172018-ctu-open-contest-en.pdf
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
#define INF 1000000000

struct graph{
	int v, e;
	set<int> adj[MAXN]; // Evitar arestas múltiplas
	set<int> din[MAXN];
	int tin[MAXN], pr[MAXN], comp[MAXN], low_link[MAXN];
};

int t = 0;

graph g, meta;
stack<int> s;
int n_scc = 1;

int rep[MAXN];

void makeComp(int id){
	int st = s.top();

	while(st != id){
		g.low_link[st] = INF; // Evitar cross-edges
		g.tin[st] = INF; // Evitar cros-edges
		g.comp[st] = n_scc;
		s.pop();
		st = s.top();
	}

	g.low_link[id] = INF; // Evitar cros-edges
	g.tin[id] = INF; // Evitar cros-edges
	rep[n_scc] = id;
	g.comp[id] = n_scc++;
	s.pop();
}
void dfs(int v){
	g.pr[v] = 1;
	g.tin[v] = t++;
	g.low_link[v] = g.tin[v];
	s.push(v);

	for(auto x: g.adj[v]){
		if(!g.pr[x]) dfs(x);

		g.low_link[v] = min(g.low_link[v], g.low_link[x]);
	}

	if(g.low_link[v] == g.tin[v]){
		makeComp(v);
	}
}

void read(){

	t = 0;
	n_scc = 1;
	
	frr(i, g.v){
		g.adj[i].clear();
		g.pr[i] = 0;

		meta.din[i].clear();
		meta.adj[i].clear();
	}


	fr(i, g.e){
		int v1, v2;
		cin >> v1 >> v2;

		g.adj[v1].insert(v2);
	}
}

stack<int> source_no_child;
vector<int> source_w_child;
int sink[MAXN];

int dfs_meta(int i){
	//cout << i << endl;
	meta.pr[i] = 1;
	if(meta.adj[i].size() == 0){
		sink[i]= source_w_child.size();
		return 1;
	}	
	int ret = 0;
	for(auto x: meta.adj[i]){
		if(!meta.pr[x]){
			ret = max(ret, dfs_meta(x));
		}
	}

	return ret;
}

void tarjan(){
	frr(i, g.v){
		if(!g.pr[i]){
			t = 0;
			dfs(i);
		}
	}

	/*------------Build metagraph------------*/

	meta.v = n_scc-1;

	frr(i, g.v){
		int v1 = g.comp[i], v2;
		for(auto x: g.adj[i]){
			v2 = g.comp[x];
			if(v1 == v2) continue; // Evitar v -> v

			meta.adj[v1].insert(v2);
			meta.din[v2].insert(v1);
		}
	}

	int din = 0, dout = 0;

	frr(i, meta.v){
		if(meta.adj[i].size() == 0 ) dout++;
		if(meta.din[i].size() == 0 ) din++;

		meta.pr[i] = 0;
		sink[i] = -1;

		//cout << i << " " << meta.adj[i].size() << " " << meta.din[i].size() << endl;
	}

	source_w_child.clear();

	frr(i, meta.v){
		if(meta.din[i].size() == 0){
			//cout << "Ini " << i << endl;

			if(dfs_meta(i)){
				source_w_child.pb(i);
			}
			else{
				source_no_child.push(i);
			}

			//cout << "OK" << i << endl;
		}
	}

	int tam = source_w_child.size();
	int used[MAXN];
	fr(i, meta.v + 1) used[i] = 0;

	//cout << "tam " << source_no_child.size() << endl;

	//frr(i, meta.v) cout << rep[i] << " ";
	//cout << endl;

	if(meta.v == 1) cout <<  0 << endl;
	else {
		int fst_sink;
		
		cout << max(din, dout) << endl;
		frr(i, meta.v){
			if(sink[i] > -1){
				//cout << "TESt " << i << ' ' << source_w_child[(sink[i] + 1)%tam] << endl;
				if(!used[sink[i]] || source_no_child.size() == 0){
					cout << rep[i] << " " << rep[source_w_child[(sink[i] + 1)%tam]] << endl;
					used[sink[i]] = 1;
					fst_sink = i;
				}
				else{
					cout << rep[i] << " " << rep[source_no_child.top()] << endl;	
					source_no_child.pop();	
				}
			}
		}

		//cout << "tam1 " << source_no_child.size() << endl;

		while(!source_no_child.empty()){
			cout << rep[fst_sink] << " " << rep[source_no_child.top()] << endl;
			source_no_child.pop();
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	while(cin >> g.v >> g.e){
		read();
		tarjan();
	}
}

