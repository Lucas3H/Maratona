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

#define MAXN 100010
#define MOD 1000000007

matrix operator *(matrix a, matrix b){
    matrix ans(2, vector<ll>(2));

    fr(i, 2){
        fr(j, 2){
            fr(k, 2) ans[i][j]+=a[i][k]*b[k][j];
            ans[i][j] = ans[i][j]%MOD;
        }
    }

    return ans;
}

matrix fastxp(matrix base, ll e){
    if(e == 1) return base;

    matrix ans = fastxp(base, e/2);

    ans = ans*ans;
    if(e%2 == 1) ans = ans*base;

    return ans;
}
int main(){
		ios::sync_with_stdio(false);
     ll a, b, x, n;
     cin >> a >> b >> n >> x;

     matrix base(2, vector<ll>(2));

     base[0][0] = a%MOD;
     base[0][1] = b%MOD;
     base[1][0] = 0;
     base[1][1] = 1;

     matrix ini(2, vector<ll>(2));
     ini[0][0] = x%MOD;
     ini[1][0] = 1;

     matrix ans = fastxp(base, n);
     ans = ans*ini;

     cout << ans[0][0]%MOD << endl;
}
