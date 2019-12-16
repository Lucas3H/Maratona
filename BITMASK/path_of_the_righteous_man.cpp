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

int a[52][52];
int dist[52][52][1030], processado[52][52][1030];
int mx[4] = {0, 0, 1, -1}, my[4] = {-1, 1, 0, 0};
int a1, a2, a3, a4, n;


void bfs(int sx, int sy, int MASK){
    queue< tuple<int, int, int> > fila;
    fila.push(make_tuple(sx, sy, MASK));

    //cout << sx << " asd " << sy << endl;

    while(true){
        tuple<int, int, int> davez = make_tuple(-1, -1, -1);

        while(!fila.empty()){

            a2 = get<0>(fila.front()), a3 = get<1>(fila.front());
            a4 = get<2>(fila.front());

            fila.pop();

            //cout << a2 << " " <<a3 << " " << a4 << endl;

            if(!processado[a2][a3][a4]){
                davez = make_tuple(a2, a3, a4);
                //cout << a2 << " " << a3 << " " << a4 << endl;
                processado[a2][a3][a4] = 1;
                //cout << a2 << " " << a3 << " " << -a1 << endl;
                break;
            }

        }

        if(get<1>(davez) == -1) break;

        fr(i, 4){
            a1 = get<0>(davez), a2 = get<1>(davez), a3 = get<2>(davez);
            int x = a1 + mx[i], y = a2 + my[i], msk = a3;

            if(x < 1 || x > n || y < 1 || y > n || processado[x][y][a3]) continue;

            //cout << "OKo" << endl;

            if(((1 << a[x][y]) & msk) > 0){
                fila.push(make_tuple(x, y, msk));
                //cout << dist[a1][a2][a3] << "OKOKO " << endl;
                dist[x][y][msk] = min(dist[a1][a2][a3], dist[x][y][msk]);
            }
            else {
                fila.push(make_tuple(x, y, ((1 << a[x][y]) | msk)));
                dist[x][y][((1 << a[x][y]) | msk)] = min(dist[a1][a2][a3] + 1, dist[x][y][((1 << a[x][y]) | msk)]);
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        cin >> n;

        frr(i, n){
            frr(j, n) {
                cin >> a[i][j];

                fr(k, (1 << 10)) {
                    dist[i][j][k] = 100;
                    processado[i][j][k] = 0;
                }
            }
        }

        int sr, sc;
        int er, ec;

        cin >> sr >> sc >> er >> ec;

        //cout << sr << " sdsasdsd  " << sc << endl;

        dist[sr + 1][sc + 1][1 << a[sr][sc]] = 1;
        bfs(sr+1, sc+1, (1 << a[sr][sc]));

        int ans = 100;

        frr(i, n){
            frr(j, n){
                ans = 100;

                fr(k, (1 << 10)){
                    ans = min(ans, dist[i][j][k]);
                }
                cout << ans << " ";
            }

            cout << endl;
        }

        fr(k, (1 << 10)){
            ans = min(ans, dist[er+1][ec+1][k]);
        }

        //if(sr == er && sc == ec) ans = 0;

        cout << ans << endl;
    }
}
