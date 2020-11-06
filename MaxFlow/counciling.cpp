// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1421 
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

map<string, int> member_list;
map<int, string> member_list_inv;

map<string, int> party_list;
map<int, string> party_list_inv;

map<string, int> club_list;
map<int, string> club_list_inv;

int n_clubs;

void read(){
	v = 2;
	member_list.clear();
	member_list_inv.clear();

	party_list.clear();
	party_list_inv.clear();

	club_list.clear();
	club_list_inv.clear();

	E.clear();
	n_clubs = 0;
	for(int i = 0; i <= 1010; i++) adj[i].clear();
	idd = 0;

	string S, T;
	int member, party, club; 

    while(true){
		getline(cin, S);

		if(S.size() == 0) break;
		//cout << S << " --------- contando" << endl;
    	stringstream X(S); 

		
		getline(X, T, ' ');
		if(member_list[T] == 0){
			member_list[T] = v;
			member_list_inv[v++] = T;
		}

		member = member_list[T];

		getline(X, T, ' ');
		if(party_list[T] == 0){
			party_list[T] = v;
			party_list_inv[v++] = T;
		}

		//cout << T << " | "  << party_list[T] << endl;
		party = party_list[T];

		addEdge(party, member, 1);

   		while (getline(X, T, ' ')) { 
        	
			if(club_list[T] == 0){
				club_list[T] = v;
				club_list_inv[v++] = T;

				n_clubs++;
			}

			club = club_list[T];

			addEdge(member, club, 1);
    	}	 
	} 

	//cout << "--------------------------------------------" << endl;

	for(auto x: party_list){
		//cout << x.f << " ------ " << x.s << endl;
		//int tam = (int)adj[x.s].size()/2;
		addEdge(1, x.s, (n_clubs - 1)/2);
	}

	for(auto x: club_list){
		addEdge(x.s, v, 1);
	}

    s = 1;
    t = v;

}

int main(){
	string ts;

	int tests;
	cin >> tests;

	getline(cin, ts);
	getline(cin, ts);

	while(tests--){
		read();
	
		int flow = Dinic();

		//cout << flow << " " << n_clubs << endl;

		if(flow == n_clubs){
			for(auto x: club_list){
				int Club = x.s;
				for(auto y: adj[Club]){
					int to = E[y].v;

					if(to != t && E[y].cap > E[y].flow){
						cout << member_list_inv[to] << " " << club_list_inv[Club] << endl;;
						break;
					}
				}
			}

			cout << endl;
		}
		else{
			printf("Impossible.\n\n");
		}
	}

    return 0;
}
