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

int n;
ll k;

matrix operator*(matrix a, matrix b){
    matrix ans(n, vector<ll>(n));

    fr(i, n){
        fr(j, n){
            ans[i][j] = 0;

            fr(k, n) ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%MOD;
        }
    }

    return ans;
}

matrix fastxp(matrix a, ll e){
    if(e == 1) return a;

    matrix ans = fastxp(a, e/2);
    ans = (ans*ans);

    if(e%2 == 1) ans = ans*a;

    return ans;
}

int sumbits(ll a){
    int sum = 0;

    while(a > 0){
        sum+=a%2;
        a/=2;
    }

    return sum;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> k;

    matrix aux(n, vector<ll>(n));
    matrix v(n, vector<ll>(n));

    fr(i, n){
        fr(j, n){
            aux[i][j] = 0;
            v[i][j] = 0;
        }
    }

    fr(i, n) v[i][0] = 1;

    ll a[110];
    fr(i, n) cin >> a[i];

    fr(i, n){
        fr(j, n){
            if(sumbits( (a[i]^a[j]) )%3 == 0) aux[i][j] = 1;
        }
    }

    if(k == 1){
        cout << n << endl;
        return 0;
    }
    else{
        matrix ans = fastxp(aux, k-1);

        v = ans*v;

        ll sum = 0;
        fr(i, n){
            sum = (sum + v[i][0])%MOD;
        }

        cout << sum << endl;
    }
}
