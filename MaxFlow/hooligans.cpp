// https://br.spoj.com/problems/HOOLIGAN/
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


ll enfrent;

ll pt[MAXN];
ll jogos[50][50];
ll inv[MAXN];
ll jogos_time[50];
ll pts_max = 0;

bool BFS(){
    for (ll i = 0; i <= 2*v - 1; i++) dist[i] = -1;

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
			int aux = E[currID].flow, idAux;

            E[currID].flow += aug;
            
            if (currID&1) idAux = currID-1; 
            else idAux = currID+1;
            
            E[idAux].flow -= aug;

			if(aux < 0) E[inv[idAux]].cap+=aug;
			else E[inv[currID]].cap-=aug;

            return aug;
        }

        visted_edges[from]++;
    }
    return 0;
}


ll Dinic(){
    ll flow = 0;

    while (true){
        for (ll i = 0; i <= 2*v - 1; i++) visted_edges[i] = 0;
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

ll sum = 0;

int read(){
	cin >> v >> enfrent >> e;
    
	if(v == 0 && enfrent == 0) return 0;

	s = 0;
    t = 2*v - 1;

    E.clear();
	for(int i = 0; i <= 2*v - 1; i++){
		adj[i].clear();
		pt[i] = 0;
		jogos_time[i] = 0;
	}
	idd = 0;

	mem(jogos, 0);

	for(ll i = 0; i < e; i++){
		ll t1, t2;
		char res;
		cin >> t1 >> res >> t2;

		if(res == '>') pt[t1]+=2;
		else if(res == '<') pt[t2]+=2;
		else{
			pt[t1]++;
			pt[t2]++;
		}

		jogos[t1][t2]++;
		jogos[t2][t1]++;
		jogos_time[t1]++;
		jogos_time[t2]++;
	}

	pts_max = pt[0] + 2*((v - 1)*enfrent - jogos_time[0]);

	sum = 0;
	frr(i, v - 1){
		addEdge(0, i, (v - 2)*enfrent - jogos_time[i] + jogos[i][0]);
		sum += (v - 2)*enfrent - jogos_time[i] + jogos[i][0];

		if(pt[i] >= pts_max) return 2;

		addEdge(i + v - 1, 2*v - 1, pts_max - pt[i] - 1);
	}

	frr(i, v - 1){
		frr(j, i - 1){
			if(jogos[i][j] < enfrent){
				addEdge(i, j + v - 1, enfrent - jogos[i][j]);
				inv[idd-2] = idd;
				inv[idd] = idd - 2;
				addEdge(j, i + v - 1, enfrent - jogos[i][j]);
			}
		}
	}

	return 1;
}

int main()
{
	int ret = read();

	while(ret){
		//cout << ret << endl;
		if(ret == 2) {
			cout << "N\n";
			ret = read();
			continue;
		}
		//fr(i, idd) cout << E[i].u << " " << E[i].v  << ' ' << E[i].cap << endl;

		int d = Dinic();
		//cout << d << endl;

		//cout << sum << endl;

		if(d == (sum)/2) cout << "Y\n";
		else cout << "N\n";

		ret = read();
	}
    
    return 0;
}
