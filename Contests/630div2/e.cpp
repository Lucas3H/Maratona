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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 998244353
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll fastxp(ll b, ll e){
	if(e == 1) return b;
	else{
		ll ans = fastxp(b, e/2);
		ans = (ans*ans)%MOD;

		if(e%2 == 1){
			ans = (ans*b)%MOD;
		}

		return ans;
	}
}

int main(){
	ios::sync_with_stdio(false);

	ll i, j, l, r;
	cin >> i >> j >> l >> r;

	ll v = fastxp(r - l + 1, i*j);

	if((i*j)%2 == 1){
		cout << v << endl;
	}
	else{
		if((r - l)%2 == 1){
			cout << (v*fastxp(2, MOD-2))%MOD << endl;
		}
		else{
			cout << ((v + 1)*fastxp(2, MOD - 2))%MOD << endl;
		}
	}
}
