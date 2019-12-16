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

ll fastxp(ll n, ll e){
    if(e == 0) return 1;
    ll ans = fastxp(n, e/2);

    ans = (ans*ans)%MOD;

    if(e%2 == 1) ans *= n;

    return (ans)%MOD;
}

int main(){
	ios::sync_with_stdio(false);

    ll a, b, n, x;
    cin >> a >> b >> n >> x;

    if(a == 1){
        n = n%MOD;
        cout << (x + n*b)%MOD << endl;
        return 0;
    }

    ll ans = 0;

    ans = (fastxp(a-1, MOD-2)*(fastxp(a, n) - 1))%MOD;
    ans = (ans*b)%MOD;
    ans = (ans + fastxp(a, n)*x)%MOD;

    cout << ans << endl;
}
