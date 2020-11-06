// https://acm.timus.ru/problem.aspx?space=1
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

int INI = 0, FIM = v + 1;

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


vector<int> adj0[MAXN], adjin[MAXN];
int pr[MAXN];

set<int> A, B;

void dfs0(int V, int pai){
	pr[V] = 1;

	if(adj0[V].size() == 0){
		A.insert(pai);
		B.insert(V);
		addEdge(pai, V, 1);

		return;
	}

	for(auto x: adj0[V]){
		if(!pr[x]) dfs0(x, pai);
	}
}

int ans[MAXN], corners = 0, tot;
	
void read(){
	cin >> v;
    s = 0;
    t = v + 1;
	FIM = t;

	frr(i, v) ans[i] = 1;

    E.clear();
	for(int i = INI; i <= FIM; i++) adj[i].clear();
	idd = 0;

	frr(i, v){
		frr(j, v){
			int aux;
			cin >> aux;

			if(aux) {
				adj0[i].pb(j);
				adjin[j].pb(i);
			}
		}
	}

	frr(i, v){
		frr(j, v) pr[j] = 0;

		if(adjin[i].size() == 0 && adj0[i].size() > 0) dfs0(i, i);
	}

	for(auto x: A) {
		addEdge(s, x, 1);
		ans[x] = 0;

		tot++;
	}
	for(auto x: B) {
		addEdge(x, t, 1);
		ans[x] = 0;

		tot++;
	}
}

int main() {
	
	read();
	
	///fr(i, idd) cout << E[i].u << " " << E[i].v << " " << E[i].cap << endl;
	frr(i, v) {
		if(adj0[i].size() == 0 && adjin[i].size() == 0) {
			ans[i] = 0;
			corners++;
		}
	}

	//cout << corners << endl;

    printf("%lld\n", tot - Dinic() + corners);
	
	fr(i, idd){
		int to = E[i].v, from = E[i].u, cap = E[i].cap, E[i].f = E[i].flow;

		if(from != s && to != t && E[i].cap > 0 && E[i].)
	}

	frr(i, v) {
		if(adj0[i].size() == 0 && adjin[i].size() == 0) {
			ans[i] = 0;
		}
	}
/*
	for(auto x: A) cout <<x << " A ";
	cout << endl;

	for(auto x: B) cout <<x << " B ";
	cout << endl;*/
	
	frr(i, v) if(!ans[i]) cout << i << " ";
	cout << endl;


    return 0;
}
