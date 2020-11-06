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

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	int d[110], h[110], s[110];

	while(t--){
		int n, x;
		cin >> n >> x;

		frr(i, n) cin >> d[i] >> h[i];
		frr(i, n) s[i] = h[i] - d[i];

		sort(s+1, s+n+1);
		sort(d+1, d+n+1);

		if(x <= d[n]) cout << 1 << endl;
		else if(s[1]>=0) cout << -1 << endl;
		else cout << (x-d[n]-1)/(-s[1]) + 2 << endl;


	}
}
