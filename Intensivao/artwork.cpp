#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 1010

struct stroke{
    int x1, x2, y1, y2;
};

int mtx[MAXN][MAXN];
int peso[MAXN][MAXN];
pii pai[MAXN][MAXN];
int n, m, q;
vector<stroke> s;

pii find(pii x){
    if(pai[x.first][x.second] == x) return x;
    else return pai[x.first][x.second] = find(pai[x.first][x.second]);
}

int join(pii a, pii b){
    if(a.first > m || a.first < 1 || a.second > n || a.second < 1) return 0;
    if(b.first > m || b.first < 1 || b.second > n || b.second < 1) return 0;
    if(mtx[a.first][a.second] > 0 || mtx[b.first][b.second] > 0) return 0;

    a = find(a);
    b = find(b);

    if(a == b) return 0;

    if(peso[a.first][a.second] < peso[b.first][b.second]) swap(a, b);

    pai[b.first][b.second] = a;
    peso[a.first][a.second] += peso[b.first][b.second];

    return 1;
}

int main(){
		ios::sync_with_stdio(false);

    cin >> n >> m >> q;

    fr(i, q){
        stroke aux;
        cin >> aux.x1 >> aux.y1 >> aux.x2 >> aux.y2;

        for(int j = aux.x1; j <= aux.x2; j++) mtx[aux.y1][j]++;
        for(int j = aux.y1; j <= aux.y2; j++) mtx[j][aux.x1]++;

        mtx[aux.y1][aux.x1]--;

        s.pb(aux);
    }

    frr(i, m){
        frr(j, n) {
            peso[i][j] = 1;
            pai[i][j] = mp(i, j);
        }
    }

    int livres = 0;
    frr(i, m){
        frr(j, n){
          //  cout << mtx[i][j] << " ";
            if(mtx[i][j] == 0) livres++;
        }

        //cout << endl;
    }

    int ligacoes = 0;

    frr(i, m){
        frr(j, n-1){
            ligacoes += join(mp(i, j), mp(i, j+1));
        }
    }

    frr(i, n){
        frr(j, m-1){
            ligacoes += join(mp(j, i), mp(j+1, i));
        }
    }

    //cout << livres << " " << ligacoes << endl;

    int componentes = livres - ligacoes;

    vector<int> resp;

    frm(i, s.size()){
        stroke aux = s[i];

        resp.pb(componentes);

        for(int j = aux.x1; j <= aux.x2; j++){
            mtx[aux.y1][j]--;
            if(mtx[aux.y1][j] == 0){
                livres++;

                ligacoes += join(mp(aux.y1, j), mp(aux.y1, j+1));
                ligacoes += join(mp(aux.y1, j), mp(aux.y1, j-1));
                ligacoes += join(mp(aux.y1, j), mp(aux.y1+1, j));
                ligacoes += join(mp(aux.y1, j), mp(aux.y1-1, j));

              //cout << ligacoes << " " << j << " " << aux.x1 << endl;
            }
        }
        for(int j = aux.y1+1; j <= aux.y2; j++) {
            mtx[j][aux.x1]--;

            if(mtx[j][aux.x1] == 0){
                livres++;

                ligacoes += join(mp(j, aux.x1), mp(j, aux.x1+1));
                ligacoes += join(mp(j, aux.x1), mp(j, aux.x1-1));
                ligacoes += join(mp(j, aux.x1), mp(j+1, aux.x1));
                ligacoes += join(mp(j, aux.x1), mp(j-1, aux.x1));

                //cout << ligacoes << " " << j << " "  << aux.x1 << endl;
            }
        }

      //  cout << livres << " " <<ligacoes << endl;

        componentes = livres - ligacoes;
    }

    frm(i, resp.size()) cout << resp[i] << endl;
}
