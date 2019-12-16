#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define MAXN 100010
#define MOD 1000000009

matrix operator *(matrix a, matrix b){
    matrix ans(3, vector<ll>(3));

    fr(i, 3){
        fr(j, 3){
            fr(k, 3){
                ans[i][j] = (a[i][k]*b[k][j] + ans[i][j]);
            }
            ans[i][j] = (ans[i][j])%MOD;
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

    ll n;
    cin >> n;

    while(n > 0){
        if(n == 1) cout << 0 << endl;
        else if(n == 2) cout << 1 << endl;
        else if(n == 3) cout << 2 << endl;
        else if(n == 4) cout << 3 << endl;
        else{
            matrix base(3, vector<ll>(3));
            base[0][0] = 1;
            base[0][1] = 1;
            base[0][2] = 1;
            base[1][0] = 1;
            base[1][1] = 0;
            base[1][2] = 0;
            base[2][0] = 0;
            base[2][1] = 1;
            base[2][2] = 0;


            matrix ini(3, vector<ll>(1));
            ini[0][0] = 2;
            ini[1][0] = 1;
            ini[2][0] = 0;

            matrix ans = fastxp(base, n-4);
            matrix x = ans*ini;

            cout << (x[0][0] + x[1][0] + x[2][0])%MOD << endl;
        }

        cin >> n;
    }
}
