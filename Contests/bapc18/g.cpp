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

int v[3][MAXN];
int n, x[3];
string s;

int get_int(int c, int l, int r){
	if(l > r) return 0;
	return v[c][r] - v[c][l-1];
}

int solve(int a, int b, int c){
	int ret = n;
	for(int i = 0; i <= x[a]; i++){
		//cout << "-----------\n";
		int ans = 0;
		ans += (i - get_int(a, 1, i));
		ans += (x[b] - get_int(b, i + 1, i + x[b]));
		ans += (x[c] - get_int(c, i + x[b] + 1, i + x[b] + x[c]));
		ans += (x[a] - i - get_int(a, i + x[b] + x[c] + 1, n));

		ret = min(ans, ret);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> s;

	frr(i, n){
		fr(j, 3) v[j][i] = v[j][i-1];

		v[s[i-1] - 'A'][i] = v[s[i-1] - 'A'][i-1] + 1;
		x[s[i-1] - 'A']++;
	}

	//frr(i, n) cout << v[0][i] << endl;

	int ans = n;
	ans = min(ans, solve(0, 1, 2));
	ans = min(ans, solve(0, 2, 1));
	ans = min(ans, solve(1, 0, 2));
	ans = min(ans, solve(1, 2, 0));
	ans = min(ans, solve(2, 1, 0));
	ans = min(ans, solve(2, 0, 1));

	cout << ans << endl;
}
