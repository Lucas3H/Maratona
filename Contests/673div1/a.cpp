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

#define MAXN 300010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int t;
vector<int> a[MAXN];
int ans[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		frr(i, n){
			a[i].clear();
			a[i].pb(0);
		}

		frr(i, n){
			int x;
			cin >> x;
			a[x].pb(i);
			ans[i] = MAXN;
		}

		frr(i, n){
			a[i].pb(n + 1);
		}

		frr(i, n){
			int dist_max = 0;
			fr(j, a[i].size() - 1){
				dist_max = max(dist_max, a[i][j + 1] - a[i][j]);
			}

			ans[dist_max] = min(i, ans[dist_max]);
		}

		for(int i = 2; i <= n; i++){
			ans[i] = min(ans[i-1], ans[i]);
		}

		frr(i, n){
			if(ans[i] > n){
				cout << -1 << " ";
			}
			else cout << ans[i] << " ";
		}

		cout << endl;
		
	}
}
