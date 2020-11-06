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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll m, n, k;

matrix operator *(matrix a, matrix b){
    matrix ans(m, vector<ll>(m));

    fr(i, m){
        fr(j, m){
            ans[i][j] = 0;

            fr(k, m) ans[i][j] = (a[i][k]*b[k][j] + ans[i][j])%MOD;
        }
    }

    return ans;
}

matrix fastxp(matrix a, ll e){
    if(e == 1) return a;

    matrix b = fastxp(a, e/2);

    b = b*b;
    if(e%2 == 1) b=b*a;

    return b;
}

ll fastxP(ll n, ll e){
    if(e == 0) return 1;
    ll ans = fastxp(n, e/2);

    ans = (ans*ans)%MOD;

    if(e%2 == 1) ans *= n;

    return (ans)%MOD;
}

ll v[210];
ll y[210];
	
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> m;

	matrix x(m, vector<ll>(m));
	frr(i, k) v[i%m]++;
	v[0] = 0;

	fr(i, m){
		fr(j, m){
			x[i][j] = v[(i - j + m)%m];
		}
	}
	/*
	fr(i, m){
		fr(j, m) cout << x[i][j] << " ";
		cout << endl;
	}
	*/

	x = fastxp(x, n-1);
	ll tot = 0;
	fr(i, m){
		fr(j, m){
			y[i] = (x[i][j]*v[j] + y[i])%MOD;
		}
		tot = (tot + y[i])%MOD;
	}

	cout << (y[0]*fastxp(tot, MOD - 2))%MOD << endl;
}

