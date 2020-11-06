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

int l, c;
char m[110][110];
int pr[110][110];
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

int la, ca;

void dfs(int L, int C){
    int achou = 0;
    fr(i, 4){
        int li = L + mx[i], ci = C + my[i];

        if(li > l || li < 1 || ci > c || ci < 1) continue;

        if(!pr[li][ci] && m[li][ci] == 'H'){
            achou  = 1;
            pr[li][ci] = 1;
            dfs(li, ci);
        }
    }

    if(!achou){
        la = L;
        ca = C;
    }
}

int main(){
		ios::sync_with_stdio(false);

    cin >> l >> c;

    int l0, c0;
    frr(i, l){
        frr(j, c) {
          cin >> m[i][j];
          if(m[i][j] == 'o'){
              l0 = i;
              c0 = j;
          }
        }
    }

    pr[l0][c0] = 1;
    dfs(l0, c0);

    cout << la << " " << ca << endl;
}
