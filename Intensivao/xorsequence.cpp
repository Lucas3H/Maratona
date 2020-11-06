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

int sumbits(ll n){
    int sum = 0;
    while(n > 0){
        if(n%2 == 1) sum++;
        n/=2;
    }

    return sum;
}

matrix operator *(matrix a, matrix b){
    int n = a.size();

    matrix ans(n, vector<ll>(n));
    fr(i, n){
        fr(j, n){
            fr(k, n){
                ans[i][j]+=a[i][k]*b[k][j];
                mod(ans[i][j], MOD);
            }
        }
    }

    return ans;
}

matrix fastxp(matrix base, ll n){
    if(n == 1) return base;

    matrix ans = fastxp(base, n/2);
    ans = ans*ans;

    if(n%2 == 1) ans = ans*base;

    return ans;
}

int main(){
		ios::sync_with_stdio(false);

    int n;
    ll k;
    cin >> n >> k;

    matrix base(n, vector<ll>(n));
    ll a[110];

    fr(i, n) cin >> a[i];

    fr(i, n){
        for(int j = i; j < n; j++){
            if(sumbits(a[i]^a[j])%3 == 0){
                base[i][j] = 1;
                base[j][i] = 1;
            }
        }
    }

    if(k == 1){
        cout << n << endl;
        return 0;
    }

    matrix ans = fastxp(base, k-1);
    matrix ini(n, vector<ll>(n));

    fr(i, n){
        ini[i][0] = 1;
    }

    ans = ans*ini;

    ll sum = 0;
    fr(i, n){
        sum+=ans[i][0];
        mod(sum,MOD);
    }

    cout << sum << endl;

    return 0;
}
