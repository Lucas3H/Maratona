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
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll find(ll x){
	ll i = 1;
	while(i*(i-1) <= 2*x){
		if(i*(i-1) == 2*x) return i;
		i++;
	}

	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	if(a == 0 && b == 0 && c == 0 && d == 0){
		cout << "0" << endl;
		return 0;
	}

	if(a > 0 && b == 0 && c == 0 && d == 0){
		ll n = find(a);
		if(n != -1){
			fr(i, n) cout << 0;
			cout << endl;
		}
		else{
			cout << "impossible" << endl;
		}

		return 0;
	}
  
	if(a == 0 && b == 0 && c == 0 && d > 0){
		ll n = find(d);
		if(n != -1){
			fr(i, n) cout << 1;
			cout << endl;
		}
		else{
			cout << "impossible" << endl;
		}

		return 0;
	}

	ll n = find(a), m = find(d);
	if(n == -1 || m == -1 || (n*m) != b + c){
		cout << "impossible\n";
		return 0;
	}

	ll x = b/m  + 1;
	char ans[10*MAXN];
	fr(i, x) ans[i] = '0';
	fr(i, m) ans[i + x] = '1';
	fr(i, n - x) ans[i + m + x] = '0';

	ll r = m - b%m;

	ans[x - 1] = '1';
	ans[x - 1 + r] = '0';

	fr(i, n + m) cout << ans[i];
	cout<< endl;
}
