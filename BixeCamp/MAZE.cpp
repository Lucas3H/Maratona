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

#define MAXN 510
#define MOD 1000000007

int mov_x[4] = {1, -1, 0, 0};
int mov_y[4] = {0, 0, 1, -1};

int processado[MAXN][MAXN];
char tab[MAXN][MAXN];
int n, m, k;

int dfs(int x, int y){
    int filhos = 0;

    processado[x][y] = 1;

    fr(i, 4){
      int u = x + mov_x[i], v = y + mov_y[i];

      if(u > n ||u < 1 || v > m || v < 1) continue;
      if(tab[u][v] == '#') continue;

      if(!processado[u][v]){
        filhos += dfs(u, v);
      }
    }

    if(filhos == 0 && k > 0){

        tab[x][y] = 'X';
        k--;
    }

//    cout << x << " " <<y << " " << filhos << endl;

    return filhos;
}

int main(){
		ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    int x, y;
    frr(i, n){
        frr(j, m){
          cin >> tab[i][j];
          if(tab[i][j] == '.'){
              x = i;
              y = j;
          }
        }
    }

    int l = dfs(x, y);

    frr(i, n){
        frr(j, m) cout << tab[i][j];
        cout << endl;
    }
}
