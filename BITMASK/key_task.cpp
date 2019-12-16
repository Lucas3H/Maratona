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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int dist[102][102][20], processado[102][102][20];
char m[102][102];
int mx[4] = {0, 0, 1, -1}, my[4] = {-1, 1, 0, 0};
int r, c;

map<char, int> associate;

int ans;
int a1, a2, a3, a4;

void bfs(int sx, int sy){
    pq< tuple<int, int, int, int> > fila;
    fila.push(make_tuple(0, sx, sy, 0));

    while(true){
        tuple<int, int, int> davez = make_tuple(-1, -1, -1);

        while(!fila.empty()){

            a1 = get<0>(fila.top()), a2 = get<1>(fila.top());
            a3 = get<2>(fila.top()), a4 = get<3>(fila.top());

            fila.pop();

            //cout << a2 << " " <<a3 << " " << a4 << endl;

            if(!processado[a2][a3][a4]){
                if(-a1 > ans) break;

                davez = make_tuple(a2, a3, a4);

                //if(a2 == 1 && a3 == 5) cout << a4 << endl;

                dist[a2][a3][a4] = -a1;
                processado[a2][a3][a4] = 1;

                break;
            }

        }

        if(get<0>(davez) == -1) break;
        //cout << a4 << endl;

        fr(i, 4){
            a1 = get<0>(davez), a2 = get<1>(davez), a3 = get<2>(davez);
            int x = a1 + mx[i], y = a2 + my[i], msk = a3;

            if(x < 1 || x > r || y < 1 || y > c || m[x][y] == '#' || processado[x][y][msk]) continue;

            if(m[x][y] == 'X') ans = min(ans, dist[a1][a2][a3] + 1);
            else if('Z' >= m[x][y] && 'A' <= m[x][y] && (msk/associate[m[x][y]])%2 == 0){
                //cout << x << " " << y << endl;
                continue;
            }
            else if(m[x][y] >= 'a')msk = (msk | associate[m[x][y]]);

            tuple<int, int, int, int> t = make_tuple(-dist[a1][a2][a3] - 1, x, y, msk);

            //cout << dist[a1][a2][a3] + 1 << " " << x << " " << y << " " << msk << endl;

            fila.push(t);
        }
    }

    return;
}

int main(){

    cin >> r >> c;

    associate['B'] = 8;
    associate['b'] = 8;
    associate['Y'] = 4;
    associate['y'] = 4;
    associate['R'] = 2;
    associate['r'] = 2;
    associate['G'] = 1;
    associate['g'] = 1;

    while(r > 0){
        int start_x, start_y, end_x, end_y;

        ans = MOD;

        frr(i, r){
            frr(j, c) {
                cin >> m[i][j];

                if(m[i][j] == '*'){
                    start_x = i;
                    start_y = j;
                }
                else if(m[i][j] == 'X'){
                    end_x = i;
                    end_y = j;
                }

                fr(k, 17) processado[i][j][k] = 0;
            }
        }

        bfs(start_x, start_y);
/*
        frr(i, r){
            frr(j, c) cout << dist[i][j][0] << " ";
            cout << endl;
        }
*/
        if(ans == MOD) printf("The poor student is trapped!\n");
        else printf("Escape possible in %d steps.\n", ans);

        cin >> r >> c;
    }
}
