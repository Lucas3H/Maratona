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
#define INF 1000000000000000100

matrix operator *(matrix a, matrix b){
    matrix ans(4, vector<ll>(4));

    fr(i, 4){
        fr(j, 4){
            ans[i][j] = 0;

            fr(k, 4) ans[i][j] = (a[i][k]*b[k][j] + ans[i][j])%MOD;
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

matrix m{{6, -8, -8, 16},{1, 0, 0, 0},{0, 1, 0, 0},{0, 0, 1, 0}	};

int main(){
	ios::sync_with_stdio(false);
	ll a[6] = {0, 2, 24, 96, 416, 1536};
	ll n;
	cin >> n;

	if(n < 6){
		cout << a[n] << endl; 
		return 0;
	}

	matrix aux = fastxp(m, n - 5);
    ll ans = 0;
    for(ll i = 5; i > 1; i--){
    	//cout << aux[0][5 - i] << endl;
    	ans = ((ans + aux[0][5 - i]*a[i])%MOD + MOD)%MOD;
    }

    cout << ans << endl;
}
