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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 10010
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
    for (ll i = 0; i <= v; i++) dist[i] = -1;

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
        for (ll i = 0; i <= v; i++) visted_edges[i] = 0;
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

char m[110][110];
int lin_blocks, col_blocks;
int tipo_lin_block[110][110];
int tipo_col_block[110][110];

int n;

void build(){
	lin_blocks = 0;
	col_blocks = 0;

	fr(i, n){
		frr(j, n){
			if(m[i][j] == 'X' && m[i][j-1] != 'X'){
				int k = j - 1;

				lin_blocks++;
				while(k >= 0 && m[i][k] == '.'){
					tipo_lin_block[i][k] = lin_blocks;
					k--;
				}
			}
		}
	}

	fr(i, n){
		frr(j, n){
			if(m[j][i] == 'X' && m[j-1][i] != 'X'){
				int k = j - 1;

				col_blocks++;
				while(k >= 0 && m[k][i] == '.'){
					tipo_col_block[k][i] = col_blocks;
					k--;
				}
			}
		}
	}

	frr(i, lin_blocks) addEdge(0, i, 1);
	frr(i, col_blocks) addEdge(i + lin_blocks, lin_blocks + col_blocks + 1, 1);

	fr(i, n){
		fr(j, n){
			if(m[i][j] != 'X') addEdge(tipo_lin_block[i][j], tipo_col_block[i][j] + lin_blocks, 1);
		}
	}

	s = 0;
	t = lin_blocks + col_blocks + 1;
	v = lin_blocks + col_blocks + 1;
}

int main(){
	while(cin >> n){

		fr(i, n){
			fr(j, n) {
				cin >> m[i][j];
				tipo_col_block[i][j] = 0;
				tipo_lin_block[i][j] = 0;
			}
			m[i][n] = 'X';
		}

		fr(i, n){
			m[n][i] = 'X';
		}

		build();

		//cout << lin_blocks <<  " " << col_blocks << endl;
		//fr(i, idd) cout << E[i].u << " " << E[i].v << " " << E[i].cap << endl;
/*
		fr(i, n){
			fr(j, n) cout << tipo_lin_block[i][j] << ' ';
			cout << endl;
		}

		fr(i, n){
			fr(j, n) cout << tipo_col_block[i][j] << ' ';
			cout << endl;
		}
*/
		cout << Dinic() << endl;

		E.clear();
		fr(i, v + 1){
			adj[i].clear();
		}

		idd = 0;
	}
    
    return 0;
}
