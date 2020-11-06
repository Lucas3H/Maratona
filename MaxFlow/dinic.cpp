/*
	Code from https://github.com/PetarV-/Algorithms/blob/master/Graph%20Algorithms/Dinic%27s%20Algorithm.cpp
	with small adaptations.
	Original Author: Petar 'PetarV' Velickovic
	Algorithm: Dinic's Algorithm

	Complexity: O(V^2 * E)
*/

#include <bits/stdc++.h>

#define MAXN 5010
#define INF 10000000000000
#define db printf("Debug\n");

using namespace std;
typedef long long ll;

vector<int> adj[MAXN];

struct Edge
{
    ll u, v, cap;
    ll flow;
};
vector<Edge> E;

ll v, e;
ll s, t;
ll dist[MAXN];
ll visted_edges[MAXN]; 

ll idd = 0;

int INI = 1, FIM = v;

bool BFS(){
    for (ll i = INI; i <= FIM; i++) dist[i] = -1;

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


ll Dinic(){
    ll flow = 0;

    while (true){
        for (ll i = INI; i <= FIM; i++) visted_edges[i] = 0;
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

void read(){
	cin >> v >> e;
    s = 1;
    t = v;
    FIM = v;

    E.clear();
	for(int i = INI; i <= FIM; i++) adj[i].clear();
	idd = 0;

	for(ll i = 0; i < e; i++){
		ll from, to, cap;
		cin >> from >> to >> cap;
		addEdge(from, to, cap);
        addEdge(to, from, cap);
	}
}

int main() {
	read();
    printf("%lld\n",Dinic());
    
    return 0;
}
