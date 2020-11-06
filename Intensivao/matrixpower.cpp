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

matrix id(ll n){
    matrix ans(n, vector<ll>(n));
    fr(i, n) ans[i][i] = 1;
    return ans;
}

matrix operator *(matrix a, matrix b){
    int n = a[0].size();
    int m = a.size();
    int k = b[0].size();
    int l = b.size();

    matrix ans(m, vector<ll>(k));

    fr(i, m){
        fr(j, k){
            fr(t, n) {
                ans[i][j] += a[i][t]*b[t][j];
                ans[i][j] = ans[i][j]%MOD;
            }
        }
    }

    return ans;
}

matrix fastxp(matrix base, int e){
    matrix ans = id(base.size());

    while(e > 0){
        if(e%2 == 1){
            ans=ans*base;
        }

        base = base*base;
        e = e/2;
    }

    return ans;
}

int main(){
		ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    int n, m;
    while(tests--){
        cin >> n >> m;

        matrix v(n, vector<ll>(n));

        fr(i, n){
            fr(j, n) cin >> v[i][j];
        }

        v = fastxp(v, m);

        fr(i, n){
            fr(j, n) cout << v[i][j] << " ";

            cout << endl;
        }
    }

    return 0;
}
