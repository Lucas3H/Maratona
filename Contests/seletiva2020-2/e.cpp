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

#define MAXN 300010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll n, k;
ll v[MAXN];
ll pref[MAXN];
pii dp[MAXN], ans;
double l = 0, r;

void read(){
	cin >> n >> k;
	ll sum = 0;

	frr(i, n){
		cin >> v[i];
		sum += v[i];
		pref[i] = sum;
		r = max((double)v[i], r);
	}
}



int solve(double t){
	double maior = (double)pref[n] - t*n;
	double x[MAXN];

	frm(i, n+1){
		maior = max(maior, pref[i] - t*i);
		x[i] = maior;
	}



	int deu = 0;

	fr(i, n + 1 - k){
		if(((double)pref[i] - t*i) < x[i+k]) return 1;
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	read();

	double mid;
	while((r - l) > 0.000001){
		mid = (l+r)/2;

		if(solve(mid)) l = mid;
		else r = mid;
	}

	printf("%.6lf\n", mid);
}
