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
#define MOD 1000000

matrix operator *(matrix a, matrix b){
    matrix ans(2, vector<ll>(2));

    fr(i, 2){
        fr(j, 2){
            fr(k, 2) ans[i][j] += (a[i][k]*b[k][j]);

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
	//	ios::sync_with_stdio(false);

    ll n, k, l;

    while(cin >> n >> k >> l){
        n = n/5;
        k = k%MOD;
        l = l%MOD;

        if(n == 1){
          printf("%06lld\n", (k)%MOD);
          continue;
        }
        if(n == 2){
            printf("%06lld\n", (k*k + l)%MOD);
            continue;
        }

        matrix ini(2, vector<ll>(1));
        ini[0][0] = (k*k + l)%MOD;
        ini[1][0] = k;

        matrix base(2, vector<ll>(2));
        base[0][0] = k;
        base[0][1] = l;
        base[1][0] = 1;
        base[1][1] = 0;

        matrix ans = fastxp(base, n-2);
        ini = ans*ini;

        printf("%06lld\n", (ini[0][0])%MOD);
    }
}
