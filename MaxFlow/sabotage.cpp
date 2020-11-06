// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1421 

#include <bits/stdc++.h>

#define MAX_N 5010
#define INF 987654321
#define db printf("Debug\n");

using namespace std;
typedef long long ll;

vector<int> adj[MAX_N];

struct Edge
{
    ll u, v, cap;
    ll flow;
};
vector<Edge> E;

ll v, e;
ll s, t;
ll dist[MAX_N], tipo[MAX_N];
ll visted_edges[MAX_N]; 

ll idd = 0;


bool BFS(){
    for (ll i = 1; i <= v; i++) dist[i] = -1;

    queue<ll> fila;
    fila.push(s);
    dist[s] = 0;
    
	while (!fila.empty()){
        ll from = fila.front();
        fila.pop();

        for (ll i = 0; i < adj[from].size(); i++) {
            ll currID = adj[from][i];
            ll to = E[currID].v;

            if (dist[to] == -1 && E[currID].flow < E[currID].cap){
                fila.push(to);
                dist[to] = dist[from] + 1;
            }
        }
    }

    return (dist[t] != -1);
}


ll DFS(ll from, ll minCap) {
    if (minCap == 0) return 0;
    if (from == t) return minCap;
    
	while (visted_edges[from] < adj[from].size()) {
        ll currID = adj[from][visted_edges[from]];
        ll to = E[currID].v;

        if (dist[to] != dist[from] + 1){
            visted_edges[from]++;
            continue;
        }

        ll aug = DFS(to, min(minCap, E[currID].cap - E[currID].flow));
        
        if (aug > 0){
            E[currID].flow += aug;
            
            if (currID&1) currID--; 
            else currID++;
            
            E[currID].flow -= aug;
            return aug;
        }

        visted_edges[from]++;
    }
    return 0;
}

void dfs(int from){
	tipo[from] = 1;
	for(auto x: adj[from]){
		ll to = E[x].v;

		if(!tipo[to] && E[x].cap > E[x].flow) dfs(to);
	}
}

ll Dinic(){
    ll flow = 0;

    while (true){
        for (ll i = 1; i <= v; i++) visted_edges[i] = 0;
        if (!BFS()) break;
        
        while (true) {
            ll currFlow = DFS(s, INF);
            if (currFlow == 0) break;
            flow += currFlow;
        }

    }

    return flow;
}


void addEdge(ll u, ll v, ll cap){
    Edge E1, E2;
    
    E1.u = u, E1.v = v, E1.cap = cap, E1.flow = 0;
    E2.u = v, E2.v = u, E2.cap = 0, E2.flow = 0;
    
    adj[u].push_back(idd++);
    E.push_back(E1);

    adj[v].push_back(idd++);
    E.push_back(E2);
}

int read(){
	cin >> v >> e;
	if(v == 0 && e == 0) return 0;
    s = 1;
    t = 2;

	E.clear();
	idd = 0;
	for(int i = 1; i <= v; i++) {
		adj[i].clear();
		tipo[i] = 0;
	}

	for(ll i = 0; i < e; i++){
		ll from, to, cap;
		cin >> from >> to >> cap;
		addEdge(from, to, cap);
        addEdge(to, from, cap);
	}

	return 1;
}

int main()
{

	while(read()){
		ll k = Dinic();
		dfs(1);

		int it = 0;

		for(int i = 1; i <= v; i++){
			if(!tipo[i]) continue;
			//cout << i  << endl;
			for(auto x: adj[i]){
				ll to = E[x].v;
				
				if(!tipo[to] && E[x].cap == E[x].flow){
					if(it) cout << i << " " << to << endl;
					it = 1 - it;
				}
			}
		}

		cout << endl;
	}

    return 0;
}
