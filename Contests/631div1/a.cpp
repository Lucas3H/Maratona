// 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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

ll n, m;
ll l[MAXN], ans[MAXN], s[MAXN];
ll tot = 0;

void read(){
	cin >> n >> m;
	ll sum = 0;
	frr(i, m){	
		cin >> l[i];
		sum += l[i];
		s[i] = sum;
	}

	tot = sum;
}

int main(){
	ios::sync_with_stdio(false);
	
	read();

	ll lim = 0;

	while(lim <= m && tot - s[lim] >= n - lim){
		lim++;
	}

	frr(i, m){
		if(l[i] > n - i + 1) lim = 0;
	}

	if(lim == 0){
		cout << -1 << endl;
		return 0;
	}

	ll fim = n;
	for(ll i = m; i >= lim; i--){
		ans[i] = fim - l[i] + 1;
		fim -= l[i];
	}

	//cout << lim << endl;

	frr(i, lim) ans[i] = i;
	frr(i, m) cout << ans[i] << ' ';
	cout << endl;

}
