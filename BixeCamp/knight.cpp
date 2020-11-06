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

int processado[10][10], d[10][10];
int mx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int my[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

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
                d[u][v] = -D;
                davez = mp(u, v);

                break;
            }
        }

        if(davez == mp(-1, -1)) break;

        fr(i, 8){
            int u = davez.first + mx[i], v = davez.second + my[i];

            if(u < 1 || u > 8 || v < 1 || v > 8) continue;

            if(!processado[u][v]){
                fila.push(mp(-d[davez.first][davez.second] - 1, mp(u, v)));
            }
        }
    }
}

int main(){
		ios::sync_with_stdio(false);
     int tests;
     cin >> tests;

     while(tests--){
        char a, b, c, e;
        cin >> a >> b >> c >> e;

        mem(d, 0);
        mem(processado, 0);


        bfs(a - 'a' + 1, b - '0');

        cout << d[c - 'a' + 1][e - '0'] << endl;
     }
}
