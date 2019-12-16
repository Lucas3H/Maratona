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

#define MAXN 1010
#define MOD 1000000007

int a[MAXN][MAXN], peso[MAXN][MAXN];
pii pai[MAXN][MAXN];
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int n, m, q;

int lig = 0, livres;
/*
pii find(pii x){
    if(pai[x.f][x.s] == x) return x;
    else return pai[x.f][x.s] == find(pai[x.f][x.s]);
}
*/
pii find(pii x){
    if(pai[x.first][x.second] == x) return x;
    else return pai[x.first][x.second] = find(pai[x.first][x.second]);
}

void join(pii b, pii c){
    if(b.f > n || b.f < 1 || b.s > m || b.s < 1 || a[b.f][b.s] > 0) return;
    if(c.f > n || c.f < 1 || c.s > m || c.s < 1 || a[c.f][c.s] > 0) return;

    b = find(b);
    c = find(c);

    if(b == c) return;

    if(peso[c.f][c.s] > peso[b.f][b.s]) swap(c, b);

    lig++;
    pai[c.f][c.s] = b;
    peso[b.f][b.s] += peso[c.f][c.s];
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> m >> q;

    livres = n*m;

    frr(i, n){
        frr(j, m){
            pai[i][j] = mp(i, j);
            peso[i][j] = 1;
        }
    }

    int x1[10010], x2[10010], y1[10010], y2[10010];
    frr(i, q){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        if(x1[i] == x2[i]) for(int j = y1[i]; j <= y2[i]; j++) a[x1[i]][j]++;
        else for(int j = x1[i]; j <= x2[i]; j++) a[j][y1[i]]++;
    }

    frr(i, n){
        frr(j, m){
            if(a[i][j] > 0){
                livres--;
                continue;
            }

            fr(k, 4) join(mp(i, j), mp(i + mx[k], j + my[k]));
        }
    }

    //cout << "asd " << livres << " " << lig << endl;

    vector<int> ans;
    ans.pb(livres - lig);

    for(int i = q; i >= 1; i--){

        if(x1[i] == x2[i]){
            for(int j = y1[i]; j <= y2[i]; j++){
                a[x1[i]][j]--;

                if(a[x1[i]][j] > 0) continue;
                livres++;

                fr(k, 4) join( mp(x1[i] + mx[k], j + my[k]), mp(x1[i], j) );
            }
        }
        else{
            for(int j = x1[i]; j <= x2[i]; j++){
                a[j][y1[i]]--;

                if(a[j][y1[i]] > 0) continue;
                livres++;

                fr(k, 4) join( mp(j + mx[k], y1[i] + my[k]), mp(j, y1[i]) );
            }

        }

        //2cout << "asd " << livres << " " << lig << endl;

        ans.pb(livres - lig);
    }

    frm(i, ans.size() - 1) cout << ans[i] << endl;
}
