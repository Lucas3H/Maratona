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

map<int, int> m;

int main(){
	ios::sync_with_stdio(false);

	ll k, n;
	cin >> n >> k;

	fr(i, n){
		ll x;
		cin >> x;

		m[x]++;
	}

	vector<int> v;

	for(auto x: m){
		v.pb(x.s);
	}

	int t = v.size();

	if(t < k){
		cout << 0 << endl;
		return 0;
	}

	ll sum[1010];
	fr(i, 1010) sum[i] = 0;

	sum[0] = 1;

	for(int i = 1; i <= t; i++){
		ll novo[1010];

		for(int j = 1; j <= i; j++){
			novo[j] = (sum[j] + v[i - 1]*sum[j-1])%MOD;
		}

		frr(j, i) sum[j] = novo[j];
		/* 
		frr(j, t) cout << sum[j] <<" ";
		cout << endl;
		*/
	}

	cout << sum[k] << endl;
}
