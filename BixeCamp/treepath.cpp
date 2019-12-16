#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

vector<int> adj[MAXN];
int dist[MAXN], processado[MAXN];

void bfs(int S){
    pq<pii, vector<pii>, greater<pii>> fila;
    fila.push(mp(0, S));

    while(true){
        int davez = -1;

        while(!fila.empty()){
            int u = fila.top().second;
            fila.pop();

            if(!processado[u]){
                davez = u;
                processado[u] = 1;
                break;
            }
        }

        if(davez == -1) break;

        fr(i, adj[davez].size()){
            int u = adj[davez][i];

            if(!processado[u]){
                dist[u] = dist[davez] + 1;
                fila.push(mp(dist[u], u));
            }
        }
    }
}

int main(){
		ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int x, y;
    fr(i, n-1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    mem(dist, -1);

    dist[1] = 0;
    bfs(1);

    int maior = 0;
    frr(i, n){
        if(dist[i] > dist[maior]) maior = i;
    }

    mem(dist, -1);
    mem(processado, 0);

    dist[maior] = 0;
    bfs(maior);

    frr(i, n){
        if(dist[i] > dist[maior]) maior = i;
    }

    cout << dist[maior] << endl;
}
