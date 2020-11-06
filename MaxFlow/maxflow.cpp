#define MAXE 20000
#define MAXN 100
#define INF 1000000000

struct graph{
    int n, n_edges;
    long long cap[MAXN][MAXN];

    vector<int> adj[MAXN];

    void read(){
        cin >> n >> n_edges;

        for(int i = 0; i < n_edges; i++){
            int v1, v2;
            ll c;
        
            cin >> v1 >> v2 >> c;

            cap[v1][v2] += c;
        
            adj[v1].pb(v2);
        }
    }

    void build_residual(graph g){
        n = g.n;
        n_edges = g.n_edges;

        for(int i = 0; i < n; i++){
            for(auto x: g.adj[i]) {
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cap[i][j] = graph.cap[i][j];
            }
        }
    }

    // To find the augmenting path
    int bfs(int s, int t, vector<int> &parent){ 
        for(int i = 0; i < path.size(); i++) path[i] = -1;
        
        parent[s] = -2;
        queue<pair<int, int>> fila;
     
        fila.push({s, INF});

     
        while (!fila.empty()) {
            int cur = fila.front().first;
            int flow = fila.front().second;
            fila.pop();

            for (int next : adj[cur]) {
                if (parent[next] == -1 && cap[cur][next]) {
                    parent[next] = cur;
                    int new_flow = min(flow, cap[cur][next]);
                    
                    if (next == t) return new_flow;
                    
                    fila.push({next, new_flow});
                }
            }
        }   

        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;

        while (new_flow = bfs(s, t, parent)) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
            }
        }

       return flow;
    }
};

