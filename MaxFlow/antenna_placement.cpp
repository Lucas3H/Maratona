// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1290
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

bool BFS(){
    for (ll i = 0; i <= 2*v + 1; i++) dist[i] = -1;

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
        for (ll i = 0; i <= 2*v + 1; i++) visted_edges[i] = 0;
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

int h, w;
char m[50][50];
int vtx[50][50];

bool is_inside(int i, int j){
	return (i >= 0 && i < h && j >= 0 && j < w);
}

void build(int i, int j){
	if(is_inside(i, j-1) && m[i][j-1] == '*') addEdge(vtx[i][j], vtx[i][j-1] + v, 1);
	if(is_inside(i, j+1) && m[i][j+1] == '*') addEdge(vtx[i][j], vtx[i][j+1] + v, 1);
	if(is_inside(i-1, j) && m[i-1][j] == '*') addEdge(vtx[i][j], vtx[i-1][j] + v, 1);
	if(is_inside(i+1, j) && m[i+1][j] == '*') addEdge(vtx[i][j], vtx[i+1][j] + v, 1);
}

void read(){
	cin >> h >> w;

    E.clear();
	for(int i = 0; i <= 2*v + 1; i++) adj[i].clear();
	idd = 0;
	v = 0;

	fr(i, h){
		fr(j, w) {
			cin >> m[i][j];

			if(m[i][j] == '*'){
				v++;
				vtx[i][j] = v;
			}
			else vtx[i][j] = 0;
		}
	}

	frr(i, v){
		addEdge(0, i, 1);
		addEdge(i + v, 2*v + 1, 1);
	}

	fr(i, h){
		fr(j, w) {
			if(m[i][j] == '*') build(i, j);
		}
	}

	s = 0;
	t = 2*v + 1;
}

int main() {

	int ts;
	cin >> ts;

	while(ts--){
		read();
		//cout << v << endl;
		cout << (2*v - Dinic())/2 << endl;
	}

    return 0;
}

