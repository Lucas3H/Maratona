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

#define MOD 1000000007
#define MAXN 100010

matrix operator *(matrix a, matrix b){
    matrix ans(2, vector<ll>(2));

    fr(i, 2){
        fr(j, 2){
            fr(k, 2) ans[i][j] += a[i][k]*b[k][j];

            ans[i][j] = (ans[i][j])%MOD;
        }
    }

    return ans;
}

ll fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    matrix base(2, vector<ll>(2));
    base[0][0] = 1;
    base[0][1] = 1;
    base[1][0] = 1;
    base[1][1] = 0;

    matrix ans(2, vector<ll>(1));
    ans[0][0] = 1;
    ans[1][0] = 0;

    n = n-1;
    while(n > 0){
        if(n%2 == 1) ans = base*ans;

        base = base*base;

        n/=2;
    }

    return ans[0][0];
}

int main(){
		ios::sync_with_stdio(false);

    int n, m, tests;
    cin >> tests;

    while(tests--){
        cin >> n >> m;

        cout << (fib(m+2) - fib(n+1) + MOD)%MOD << endl;
    }
}
