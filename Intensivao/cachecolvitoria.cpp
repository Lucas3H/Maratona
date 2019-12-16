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
    matrix ans(27, vector<ll>(27));

    fr(i, 27){
        fr(j, 27){
            fr(k, 27){
                ans[i][j] += a[i][k]*b[k][j];
                ans[i][j] = ans[i][j]%MOD;
            }
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

int allow(int n){
    if(n%3 == (n/3)%3) return 0;
    if((n/3/3)%3 == (n/3)%3) return 0;

    return 1;
}

int compare(int a, int b){
    if(a%3 == b%3) return 0;
    if((a/3)%3 == (b/3)%3) return 0;
    if((a/3/3)%3 == (b/3/3)%3) return 0;

    return 1;
}

int main(){
		ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    matrix base(27, vector<ll>(27));

    fr(i, 27){
        if(!allow(i)) continue;

        fr(j, 27){
            if(compare(i, j) && allow(j)) base[i][j] = 1;
        }
    }

    matrix ini(27, vector<ll>(27));

    fr(i, 27){
        if(allow(i)) ini[i][0] = 1;
    }

    if(n == 1){
        cout << 12 << endl;
        return 0;
    }

    matrix ans = fastxp(base, n-1);
    ans = ans*ini;

    ll sum = 0;

    fr(i, 27) sum += ans[i][0];
    sum = sum%MOD;

    cout <<sum << endl;

    return 0;
}
