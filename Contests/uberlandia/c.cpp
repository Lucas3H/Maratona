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

ll fastxp(ll n, ll e){
    if(e == 0) return 1;
    ll ans = fastxp(n, e/2);

    ans = (ans*ans)%MOD;

    if(e%2 == 1) ans *= n;

    return (ans)%MOD;
}

int main(){
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;

	ll f1, f2, f3, f = 1;
	for(int i = 1; i <= n + m; i++){
		f = (f*i)%MOD;

		if(i == n) f1 = f;
		if(i == m) f2 = f;
	}

	f3 = f;

	ll ans = f3;

	ans = (ans*fastxp(f1, MOD-2))%MOD;
	ans = (ans*fastxp(f2, MOD-2))%MOD;

	cout << ans << endl;
}	
