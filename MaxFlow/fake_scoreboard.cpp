// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3424 
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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321


ll a[110], b[110];
ll teams, prob;

ll sum1, sum2;

#define INI 0
#define FIM teams + prob + 1

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

int lim = 0;
int read(){
	cin >> teams >> prob;
    
	if(teams == 0 && prob == 0) return 0;

	s = 0;
    t = teams + prob + 1;
	v = t + 1;

    E.clear();
	for(int i = INI; i <= FIM; i++) adj[i].clear();
	idd = 0;

	sum1 = sum2 = 0;

	frr(i, teams) {
		cin >> a[i];
		sum1+=a[i];
	}
	frr(i, prob) {
		cin >> b[i];
		sum2+=b[i];
	}

	frr(i, teams) addEdge(0, i, a[i]);
	frr(i, prob) addEdge(i + teams, t, b[i]);

	lim = idd;

	frr(i, teams){
		//for(int j = prob; j > 0; j--) addEdge(i, j + teams, 1);
		frr(j, prob) addEdge(i, j + teams, 1);
	}

	return 1;
}

int main() {
	while(read()){
		int k = Dinic();

		char ans[100][100];

		if(sum1 == sum2 && sum1 == k){
			for(int i = lim; i < idd; i+=2){
				if(E[i].flow == 1) ans[E[i].u][E[i].v - teams] = 'Y';
				else ans[E[i].u][E[i].v - teams] = 'N';
			}

			frr(i, teams){
				frr(j, prob) cout << ans[i][j];
				cout << endl;
			}
			cout << endl;
		}
		else cout << "Impossible\n\n";
	}
    
    return 0;
}

