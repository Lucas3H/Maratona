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

int n, c;

vector<int> g[MAXN];

void solve(int x, int y, int r){
	for(int i = max(x - r, 0); i <= x + r; i++){
		int lim = (sqrt(r*r - (x - i)*(x - i) + 0.00001));
		int ini = lower_bound(g[i].begin(), g[i].end(), y - lim) - g[i].begin();
		int j = ini;

		while(j < g[i].size() && g[i][j] <= y + lim){
			j++;
		}

		g[i].erase(g[i].begin() + ini, g[i].begin() + j);
	}
}

void read(){
	cin >> n;
	fr(i, n){
		int x, y;
		cin >> x >> y;

		g[x].pb(y);
	}

	fr(i, MAXN) {
		g[i].pb(MAXN);
		sort(g[i].begin(), g[i].end());
	}
	cin >> c;

	fr(i, c){
		int x, y, r;
		cin >> x >> y >> r;
	
		solve(x, y, r);
	}
}

int main(){
	ios::sync_with_stdio(false);

	read();

	int ans = 0;
	fr(i, MAXN) ans += g[i].size() - 1;

	cout << ans << endl;
}
