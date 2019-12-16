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

ll n;
int m, k;

matrix operator*(matrix a, matrix b){
    matrix ans(m, vector<ll>(m));

    fr(i, m){
        fr(j, m){
            ans[i][j] = 0;

            fr(k, m) ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%MOD;
        }
    }

    return ans;
}

matrix fastxp(matrix a, ll e){
    if(e == 1) return a;

    matrix ans = fastxp(a, e/2);
    ans = (ans*ans);

    if(e%2 == 1) ans = (a*ans);

    return ans;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    matrix mtx(m, vector<ll>(m));
    matrix v(m, vector<ll>(m));

    fr(i, m){
        fr(j, m){
            mtx[i][j] = (ll)1;
            v[i][j] = (ll)0;
        }
    }

    fr(i, m) v[i][0] = (ll)1;

    char x, y;
    fr(i, k){
        cin >> x >> y;

        int v1, v2;
        if(x >= 'a' && x <= 'z') v1 = x - 'a';
        else v1 = x - 'A' + 26;

        if(y >= 'a' && y <= 'z') v2 = y - 'a';
        else v2 = y - 'A' + 26;

        mtx[v2][v1] = 0;
    }

    matrix ans(m, vector<ll>(m));

    if(n == 1){
        cout << m << endl;
        return 0;
    }
    else ans = fastxp(mtx, n-1);

    v = ans*v;

    ll resp = 0;

    fr(i, m) resp = (resp + v[i][0])%MOD;

    cout << resp << endl;
}
