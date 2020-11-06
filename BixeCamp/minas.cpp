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

int n;
int m[110][110], processado[110][110], d[110][110];
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

void bfs(int x, int y){
    pq<pair<int, pii>> fila;
    fila.push(mp(0, mp(x, y)));

    while(true){
        pii davez = mp(-1, -1);

        while(!fila.empty()){
            int u = fila.top().second.first;
            int v = fila.top().second.second;
            int D = fila.top().first;

            fila.pop();

            if(!processado[u][v]){
                processado[u][v] = 1;
                davez = mp(u, v);
                d[u][v] = -D;

                break;
            }
        }

        if(davez == mp(-1, -1)) break;


        fr(i, 4){
            int u = davez.first + mx[i], v = davez.second + my[i];

            if(u < 1 || u > n || v < 1 || v > n) continue;

            if(!processado[u][v]){
                fila.push(mp(-d[davez.first][davez.second] - m[u][v], mp(u, v)));
            }
        }
    }
}

int main(){
		ios::sync_with_stdio(false);

    cin >> n;

    frr(i, n){
      frr(j, n) cin >> m[i][j];
    }

    d[1][1] = m[1][1];
    bfs(1, 1);

    cout << d[n][n] << endl;
}
